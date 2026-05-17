/*4. 7.2.2LeetCode199—二叉树的右视图
【问题描述】
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，
返回从右侧所能看到的结点值。例如，如图下图所示的二叉树的输出结果是[1，3，4]。
二叉树节点数据为正整数，数值不超过100000，节点个数不超过100。
image.png
【输入形式】输入为一行数据，是二叉树的括号表示法的字符串。
【输出形式】输出为一行数据，右视图的结果放在方括号中，每个节点数据之间用“，”隔开
【样例输入】
1（2（，5），3（，4））
1(2(,5),3(,4))
【样例输出】[1，3，4]
【样例说明】
测试数据的文件名为in.txt
【评分标准】
该题目有10个测试用例，每通过一个测试用例，得10分。*/

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

bool isDigitChar(char c) {
    // 直接判断 ASCII 范围，完美兼容中文！
    return c >= '0' && c <= '9';
}

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
        } while (position != bt.length() && isDigitChar(bt[position]));
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
                    if (bt[position] != ')') {
                        creatTree(p->right, bt, position);
                    }
                }
            }
            position++;
        }
        else {
            return;
        }
    }
    vector<int> getRight() {
        vector<int>result;
        queue<node*>layer;
        queue<node*>nextlayer;
        if (root != NULL) {
            layer.push(root);
        }
        else {
            return result;
        }
        int temp=-1;
        do {
            while (!nextlayer.empty()) {
                nextlayer.pop();
            }
            while (!layer.empty()) {
                if (layer.front()->left != NULL&& layer.front()->left->data >=0 ) {
                    nextlayer.push(layer.front()->left);
                }
                if (layer.front()->right != NULL && layer.front()->right->data >= 0) {
                    nextlayer.push(layer.front()->right);
                }
                temp = layer.front()->data;
                layer.pop();
            }
            result.push_back(temp);
            layer = nextlayer;
        } while (!nextlayer.empty());
        return result;
    }
};




int main() {
    tree myTree;

    ifstream in;
    in.open("in.txt");
    string input;
    getline(in, input);
    int position = 0;
    myTree.creatTree(myTree.root,input, position);

    vector<int>result = myTree.getRight();
    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}