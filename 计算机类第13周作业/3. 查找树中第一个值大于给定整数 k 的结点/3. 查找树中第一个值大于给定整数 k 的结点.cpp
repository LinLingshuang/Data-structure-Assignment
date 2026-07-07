/*3. 第九章第16题
【问题描述】
给定一个整数二叉排序树（BST），设计一个算法，查找树中第一个值大于给定整数 k 的结点。
如果存在这样的结点，返回该结点的值；否则，返回 -1。
二叉排序树的性质：
左子树的所有结点的值均小于根结点的值。
右子树的所有结点的值均大于根结点的值。
左右子树也分别是二叉排序树。
【输入形式】
第一行输入一个整数 n，表示二叉排序树的结点数量。
第二行输入 n 个整数，表示二叉排序树的结点值，按层序遍历顺序给出（空结点用 -1 表示）。
第三行输入一个整数 k，表示要查找的目标值。
【输出形式】
输出一个整数，表示二叉排序树中第一个值大于 k 的结点的值。如果不存在这样的结点，输出 -1。
【样例输入】
7
4 2 6 1 3 5 7
3
【样例输出】
4
【样例说明】
输入的二叉排序树结构如下：
    4
   / \
  2   6
 / \ / \
1  3 5  7
查找第一个值大于 3 的结点，遍历顺序为 4 -> 2 -> 3 -> 6，第一个大于 3 的结点是 4，因此输出 4。*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node* parent;
    node() {
        data = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    node(const node& n) {
        data = n.data;
        left = n.left;
        right = n.right;
        parent = n.parent;
    }
};

class tree {
public:
    node* root;
    tree() {
        root = NULL;
    }
    void creatTree(int n) {
        queue<node*>treeNode;
        root = new node(-1);
        treeNode.push(root);
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            //cout << temp << ' ';
            if (temp == -1) {
                i--;
                treeNode.front()->data = temp;
                treeNode.pop();
            }
            else {
                treeNode.front()->data = temp;
                treeNode.front()->left = new node(-1);        
                treeNode.push(treeNode.front()->left);
                treeNode.front()->right = new node(-1);            
                treeNode.push(treeNode.front()->right);
                treeNode.pop();
            }
        }
        //cout << endl;
    }
    int search(int target,node* p) {
        if (p == NULL || p->data == -1) {
            return -1;
        }
        else if (p->data > target) {
            if (p->left == NULL) {
                return p->data;
            }
            else if (p->left->data <= target) {
                int temp = search(target, p->left);
                if (temp == -1) {
                    return p->data;
                }
                else {
                    return temp;
                }
            }
        }
        else if (p->data <= target) {
            return search(target, p->right);
        }
    }
};




int main() {
    tree myTree;
    int n;
    cin >> n;
    //cout << n << endl;
    myTree.creatTree(n);

    int target;
    cin >> target;
    while (target == -1) {
        cin >> target;
    }
    //cout << target << endl;
    cout << myTree.search(target, myTree.root);
}