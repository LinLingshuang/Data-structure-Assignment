/*9. 第七章第十题
【问题描述】假设二叉树中的每个结点值为单个字符，采用二叉链存储结构存储。
二叉树 bt 可能有多个值为 x 的结点，每个这样的结点对应一个层次（根结点为第 1 层）。
请设计一个算法，求值为 x 的结点所在的最小层次。
【输入形式】
第一行输入一个整数 n，表示二叉树的结点数（1 ≤ n ≤ 1000）。
接下来 n 行，每行输入一个结点的信息，格式为：
结点值 左子结点值 右子结点值
若左子结点或右子结点为空，则用字符 # 表示。
最后一行输入一个字符 x，表示要查找的目标结点值。
【输出形式】
若左子结点或右子结点为空，则用字符 # 表示。
最后一行输入一个字符 x，表示要查找的目标结点值。
【样例输入】
7
A B C
B D E
C # F
D # #
E # #
F G #
G # #
E
【样例输出】
3
【样例说明】
【评分标准】*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct node {
    char data;
    node* left;
    node* right;
    node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(char val) {
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
    void creatTree(vector<node*>& lyar, int nodeNum, int& position) {
        vector<node*>nextlyar;
        for (int i = 0; i < lyar.size();i++) {
            position++;

            char data,ldata,rdata;
            cin >> data;
            if (data == '#') {
                continue;
            }
            cin >> ldata >> rdata;
            if (lyar[i] == NULL) {
                lyar[i] = new node(data);
            }
            else {
                lyar[i]->data = data;
            }

            if (ldata != '#') {
                lyar[i]->left = new node(ldata);
                nextlyar.push_back(lyar[i]->left);
            }
            if (rdata != '#') {
                lyar[i]->right = new node(rdata);
                nextlyar.push_back(lyar[i]->right);
            }
        }
        if (!nextlyar.empty()) {
            creatTree(nextlyar, nodeNum, position);
        }
        else {
            return;
        }
    }
    int lyarSearchTree(vector<node*>lyar,char search,int layerNum) {
        layerNum++;
        vector<node*>nextlyar;
        for (node* p : lyar) {
            if (p != NULL) {
                if (p->data == search) {
                    return layerNum;
                }
                nextlyar.push_back(p->left);
                nextlyar.push_back(p->right);
            }
        }
        if (!nextlyar.empty()) {
            return lyarSearchTree(nextlyar, search, layerNum);
        }
        else {
            return -1;
        }
    }
};


int main() {
    tree bt;
    int nodeNum;
    cin >> nodeNum;
    int position = 0;
    vector<node*>lyar;
    lyar.push_back(bt.root);
    bt.creatTree(lyar, nodeNum, position);
    bt.root = lyar[0];
    char search;
    cin >> search;
    vector<node*>lyar2;
    lyar2.push_back(bt.root);
    cout << bt.lyarSearchTree(lyar2, search, 0);
}