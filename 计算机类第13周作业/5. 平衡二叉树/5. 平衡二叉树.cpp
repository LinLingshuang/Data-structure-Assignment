/*5. 平衡二叉树
【问题描述】
使用输入构建一个二叉树，判断它是否是高度平衡的二叉树。本题中，
一棵高度平衡二叉树定义为：一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1 。
【输入形式】
一行字符串，以完全二叉树的形式表示二叉树，节点用空格分开
【输出形式】
是平衡二叉树输出”True”，否则输出”False”
【样例输入一】
balance_1.png
3 9 20 null null 15 7
【样例输出一】
True
【样例输入二】
balance_2 (1).jpg
1 2 2 3 3 null null 4 4
【样例输出二】
False
【样例说明】
测试数据的文件名为in.txt，输出文件名为out.txt
【评分标准】
该题目有10个测试用例，每通过一个测试用例得10分*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

struct node {
    int data;
    int ht = 1;
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
    void creatTree() {
        queue<node*>treeNode;
        root = new node(-1);
        treeNode.push(root);

        ifstream in;
        in.open("in.txt");
        while (in.peek() != EOF) {
            string temp;
            in >> temp;
           
            if (temp == "null") {
                if (treeNode.empty())
                    continue;
                treeNode.front()->data = -1;
                treeNode.pop();
            }
            else {
                if (treeNode.empty())
                    continue;
                treeNode.front()->data = stoi(temp);
                treeNode.front()->left = new node(-1);
                treeNode.front()->left->parent = treeNode.front();
                treeNode.front()->left->ht = treeNode.front()->ht+1;
                treeNode.push(treeNode.front()->left);
                treeNode.front()->right = new node(-1);
                treeNode.front()->right->ht = treeNode.front()->ht + 1;
                treeNode.push(treeNode.front()->right);
                treeNode.pop();
            }
        }
        
    }

    int checkAVL(node* p) {
        if ((p->left == NULL|| p->left->data == -1) && (p->right == NULL || p->right->data == -1)) {
            return p->ht;
        }
        else {
            int lht,rht;
            if (p->left == NULL || p->left->data == -1) {
                lht = p->ht;
            }
            else {
                lht = checkAVL(p->left);
            }
            if (p->right == NULL || p->right->data == -1) {
                rht = p->ht;
            }
            else {
                rht = checkAVL(p->right);
            }
            if (lht == -1 || rht == -1) {
                return -1;
            }
            else if (lht - rht < -1 || lht - rht>1) {
                return -1;
            }
            else {
                if (lht - rht < 0) {
                    return rht;
                }
                else {
                    return lht;
                }
            }
        }
    }
    
};




int main() {
    tree myTree;
    
    myTree.creatTree();
   
    ofstream out;
    out.open("out.txt");
    int result = myTree.checkAVL(myTree.root);
    if (result == -1) {
        out << "False";
    }
    else {
        out << "True";
    }
}