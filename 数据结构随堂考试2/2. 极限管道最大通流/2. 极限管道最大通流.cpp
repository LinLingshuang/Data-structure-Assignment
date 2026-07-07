/*2. 极限管道最大通流
问题描述
输水管道网络呈二叉树状，每条管道有最大流量上限（节点值代表该段管道上限）。
水流从主泵站（根）向各出水口（叶子）输送。
一条通水路线的实际流量等于路径上各段管道的最小值。工程师需要找出"流量最大"的那条通水路线。
任务
给定管道树，输出从根到任意叶子的路径上，路径最小值的最大可能值。
输入形式
输入由多行组成：
第一行为一个整数 N，表示二叉树中结点的数量。
接下来 N 行，每行描述一个结点的信息，格式为：
父节点值 左孩子值 右孩子值
如果某个孩子为空，则用 # 表示。
第一行即为根节点，格式同样为 父节点值 左孩子值 右孩子值，其中「父节点值」就是根节点自身的值。
输出形式
输出一个整数，表示最大可能的通水流量。
样例输入
5
3 2 4
2 5 #
4 # 6
5 # #
6 # #
样例输出
3
样例说明
树结构如下：
    3
   / \
  2   4
 /     \
5       6
路径 3→2→5 的瓶颈：min(3,2,5) = 2
路径 3→4→6 的瓶颈：min(3,4,6) = 3
最大瓶颈为 3。
评分标准
本题目共 10 个测试用例。
类库使用要求
禁止使用 STL 中的树形结构库（如 std::map 嵌套模拟树）
允许使用标准输入输出库（如 iostream、cstdio 等）
允许使用vector、stack、queue容器库。
需自行实现二叉树的节点结构与遍历逻辑
未按题意进行编码求解，扣减得分的50%*/
#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
struct node {
    int data;
    node* lchild;
    node* rchild;
    node(int d) {
        data = d;
        lchild = rchild = NULL;
    }
    node(const node& s) {
        data = s.data;
        lchild = s.lchild;
        rchild = s.rchild;
    }
};

struct tree {
    node* root = new node(-1);
    tree() {
        int n;
        cin >> n;
        string temp;
        getline(cin, temp);
        creattree(n);  
    }

    void creattree(int n) {
        queue<node*>treeNode;
        root = new node(-1);
        treeNode.push(root);
        for (int i = 0; i < n; i++) {
            string temp;
            getline(cin, temp);
            char temp1 = '0', temp2 = '0', temp3 = '0';
            int a=0, b=0, c=0;
            int flag = 0;
            for (int j = 0; j < temp.length(); j++) {
                if (temp[j] == ' ') {
                    flag++;
                    continue;
                }    
                if (flag == 0) {
                    if (temp[j] == '#') {
                        temp1 = '#';
                    }
                    else {
                        temp1 = '0';
                        a = a * 10 + temp[j] - '0';
                    }
                }
                else  if (flag == 1) {
                    if (temp[j] == '#') {
                        temp2 = '#';
                    }
                    else {
                        temp2 = '0';
                        b = b * 10 + temp[j] - '0';
                    }
                }
                else  if (flag == 2) {
                    if (temp[j] == '#') {
                        temp3 = '#';
                    }
                    else {
                        temp3 = '0';
                        c = c * 10 + temp[j] - '0';
                    }
                }
            }

            if (temp1 != '#') {
                treeNode.front()->data = a;
                if (temp2 != '#') {
                    treeNode.front()->lchild = new node(b);
                    treeNode.push(treeNode.front()->lchild);
                }
                if (temp3 != '#') {
                    treeNode.front()->rchild = new node(c);
                    treeNode.push(treeNode.front()->rchild);
                }
                treeNode.pop();
            }
        }
    }

    int frontMaxSmall(node* p,int small) {
        if (p == NULL||p->data==-1) {
            return small;
        }
        else {
            if (p->data <= small&&p->data!=-1) {
                small = p->data;
            }
            int ls = frontMaxSmall(p->lchild, small);
            int rs = frontMaxSmall(p->rchild, small);
            return max(ls, rs);
        }
    }
};

int main() {
    tree t;
    cout<<t.frontMaxSmall(t.root,t.root->data);
}
