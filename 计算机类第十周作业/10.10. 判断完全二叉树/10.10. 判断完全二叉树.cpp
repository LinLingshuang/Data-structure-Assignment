/*10. 判断完全二叉树
【问题描述】
    假设二叉树中的每个结点值为单个整数，采用二叉链结构存储，
    设计算法判断给定的二叉树是否是完全二叉树。假定每棵二叉树节点不超过2000个。
【输入形式】
    每个测试是一颗二叉树的括号表示法字符串
【输出形式】
     如果是完全二叉树，输出“1”；如果不是完全二叉树，输出“0”
【样例输入】
    1(2(4,5),3)
【样例输出】
     1
【样例说明】
   测试数据的文件名为in.txt                                                      【评分标准】
   该题目有10个测试用例，每通过一个测试用例，得10分。*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
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
    tree() {
        root = NULL;
    }
    void creatTree(node*& p, string bt, int& position) {
        int num = 0;
        do {
            num = num * 10 + bt[position] - '0';
            position++;
        } while (position != bt.length() && isdigit(bt[position]));
        p = new node(num);
        
        if (bt[position] == '(') {
            position++;
            if (bt[position] == ',') {
                position++;
                creatTree(p->right, bt, position);
                
            }
            else {
                creatTree(p->left, bt, position);
                if (bt[position] == ',') {
                    position++;
                    creatTree(p->right, bt, position);
                }
            }
            position++;
        }
        else {
            return;
        }

    }
    bool isBtree(vector<node*>lyar) {
        vector<node*>nextlyar;
        bool flag1 = true;
        bool flag2 = true;
        for (node* p : lyar) {
            if (flag1 && flag2) {
                if (p->left != NULL) {
                    nextlyar.push_back(p->left);
                    if (p->right != NULL) {
                        nextlyar.push_back(p->right);
                    }
                    else {
                        flag1 = false;
                    }
                }
                else {
                    flag2 = false;
                    if (p->right != NULL) {
                        return false;
                    }
                }
            }
            else if (!flag1) {
                if (p->left != NULL || p->right != NULL) {
                    return false;
                }
            }
            else if (!flag2) {
                if (p->left != NULL || p->right != NULL) {
                    return false;
                }
            }
        }
        if (flag1 && flag2 && !nextlyar.empty()) {
            return isBtree(nextlyar);
        }
        else if (nextlyar.empty()) {
            return true;
        }
        else {
            for (node* p : nextlyar) {
                if (p->left != NULL) {
                    return false;
                }
                if (p->right != NULL) {
                    return false;
                }
            }
            return true;
        }
    }
};


int main() {
    tree bt;
    string myTree;
    fstream in;
    in.open("in.txt");
    getline(in, myTree);
    int position = 0;

    bt.creatTree(bt.root, myTree, position);
    vector<node*>lyar;
    lyar.push_back(bt.root);
    if (bt.isBtree(lyar)) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}