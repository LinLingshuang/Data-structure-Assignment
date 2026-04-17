/*4. 二叉树的序列化与反序列化
一、问题描述
实现二叉树的序列化和反序列化。序列化是将二叉树转换为字符串，反序列化是将字符串恢复为二叉树。
要求：
序列化：将二叉树按先序遍历序列化为字符串，空节点用#表示，节点值之间用逗号分隔
反序列化：将序列化字符串恢复为二叉树，然后输出其中序遍历序列验证正确性
二、输入形式
一行若干个整数，表示二叉树的先序遍历序列，空节点用-1表示。
三、输出形式
第一行输出序列化后的字符串。
第二行输出反序列化后二叉树的中序遍历序列。
四、样例输入
1 2 4 -1 -1 5 -1 -1 3 -1 -1
五、样例输出
1,2,4,#,#,5,#,#,3,#,#
4 2 5 1 3
六、样例说明
二叉树结构：
    1
   / \
  2   3
 / \
4   5
先序遍历：1,2,4,#,#,5,#,#,3,#,#
中序遍历：4 2 5 1 3
七、评分标准
共8个测试用例。
八、类库使用要求
必须手动实现二叉树结构，可以使用string、stringstream。*/
#include<iostream>
#include<string>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
    node(const node& n) {
        data = n.data;
        left = n.left;
        right = n.right;
    }
};

class tree {
public:
    node* root;
    string treeStr;
    tree() {
        root = NULL;
    }
    void creatTree(node*& p) {
        if (p != root) {
            treeStr.push_back(',');
        }
        int input = -1;
        if (cin.peek() == EOF) {
            treeStr.push_back('#');
            // 没有输入
        }
        else {
            cin >> input;
            if (input != -1) {
                string temp = to_string(input);
                treeStr+= temp;
            }
            else {
                treeStr.push_back('#');
            }
        }
        if (input == -1) {
            return;
        }
        else {
            p = new node(input);
            creatTree(p->left);
            creatTree(p->right);
        }
    }
    void getMiddle(node* p) {
        if (p != NULL) {
            getMiddle(p->left);
            cout << p->data << ' ';
            getMiddle(p->right);
        }
        else {
            return;
        }
    }
};

int main() {
    tree myTree;
    myTree.creatTree(myTree.root);
    cout << myTree.treeStr << endl;
    myTree.getMiddle(myTree.root);
}