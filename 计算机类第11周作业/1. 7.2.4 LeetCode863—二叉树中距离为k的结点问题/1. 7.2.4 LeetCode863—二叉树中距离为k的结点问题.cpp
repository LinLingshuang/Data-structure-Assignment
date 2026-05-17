/*1. 7.2.4 LeetCode863—二叉树中距离为k的结点问题
【问题描述】
给你二叉树的根结点root、树中一个结点target和一个正整数k，
求二叉树中距离target结点为k的所有结点。假设二叉树中的所有结点值都唯一。
输入为顺序存储方式表示的二叉树字符串，如果节点为空，则输入‘#’。
例如，输入root=[3,5,1,6,2,0,8,#,#,7,4]，target=5，k=2，输出为[7，4，1]。对应的二叉树如图所示。
image.png
其中离目标结点5的距离为2的结点是7、4、1。假设给定的二叉树非空，
树中每个结点有唯一值，结点值位于0到500之间，target是其中的一个结点，0≤k≤1000。
要求设计如下成员函数：
class Solution {
public:
       vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
       {  …   }
};
【输入形式】
每个测试用例由三行，第一行是由一对方括号[]括起来的顺序存储的二叉树节点数据，
每个节点用“,”隔开，如果是空节点，则存入“#”。第二行为目标节点数据，第三行为距离。
【输出形式】
用一对方括号[]将满足要求的节点括起来后输出，如有多个节点，用“，”隔开，节点输出顺序：
优先输出目标节点的子孙节点，其次是目标节点兄弟节点的子孙节点，
最后是目标节点的祖父节点（如果有多个祖父节点的子孙节点，则从最近的开始输出），
如果在同一层从左边到右边输出。
【样例输入】
                                                      1
                           2                                                       3
               4                             5                       6                    7
        8                 9             10          11          12         13          -       -
14          15        16      17     18    19    -       -     -     -   -   -
- -       -   -    20   21  22 23  24 25 26 27
[1,2,3,4,5,6,7,8,9,10,11,12,13,#,#,14,15,16,17,18,19,#,#,#,#,#,#,#,#,#,#,20,21,22,23,24,25,26,27]
4
3
【样例输出】
[20,21,22,23,10,11,3]
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

class tree {
public:
    node* root;
    tree() {
        root = NULL;
    }
    void creatTree(string input) {
        int num = 0;
        queue<node*>treeNode;
        root = new node(-1);
        treeNode.push(root);
        for (int i = 0; i < input.length(); i++) {

            if (input[i] == '[') {
                continue;
            }          
            else if (input[i] == ']' || input[i] == ',') {
                if (num != -1) {
                    treeNode.front()->data = num;
                    num = 0;
                    treeNode.front()->left = new node(-1);
                    treeNode.front()->left->parent = treeNode.front();
                    treeNode.push(treeNode.front()->left);
                    treeNode.front()->right = new node(-1);
                    treeNode.front()->right->parent = treeNode.front();
                    treeNode.push(treeNode.front()->right);
                    treeNode.pop();
                }
                else {
                    
                    num = 0;
                    treeNode.pop();
                }
            }           
            else if (input[i] == '#') {
                num = -1;
            }
            else if (isdigit(input[i])) {
                num = num * 10 + input[i] - '0';
            }
        }

    }
    node* searchTarget(node* p,int target) {
        if (p == NULL || p->data == -1) {
            return NULL;
        }
        else if (p->data == target) {
            return p;
        }
        else {
            node* temp;
            temp = searchTarget(p->left, target);
            if (temp != NULL) {
                return temp;
            }
            temp = searchTarget(p->right, target);
            if (temp != NULL) {
                return temp;
            }
            return temp;
        }
    }

    vector<int> distanceK(node* target, int k) {
        vector<int>result;
        int cnt = 0;
        int nextcnt = cnt + 1;
        searchup(target, cnt, k, result);
        bool nextAtleft = false;
        if (target->parent != NULL) {
            if (target->parent->left == target) {
                nextAtleft = true;
            }
            else {
                nextAtleft = false;
            }
        }
        searchback(target->parent, nextcnt, k, result, nextAtleft);
        return result;
    }

    void searchup(node* p,int cnt, int k, vector<int>&result) {
        if (p == NULL || p->data == -1) {
            return;
        }
      
        else if (cnt == k) {
            result.push_back(p->data);
            return;
        }
        else {
            int nextcnt = cnt + 1;
            searchup(p->left, nextcnt, k, result);
            searchup(p->right, nextcnt, k, result);
        }
    }
    void searchback(node* p, int cnt, int k, vector<int>& result,bool atleft) {
        if (p == NULL || p->data == -1) {
            return;
        }
        else if (cnt == k) {
            result.push_back(p->data);
            return;
        }
        else {
            int nextcnt = cnt + 1;
            if (!atleft) {
                searchup(p->left, nextcnt, k, result);
            }
            else {
                searchup(p->right, nextcnt, k, result);
            }
            bool nextAtleft = false;
            if (p->parent != NULL) {
                if (p->parent->left == p) {
                    nextAtleft = true;
                }
                else {
                    nextAtleft = false;
                }
            }
            searchback(p->parent, nextcnt, k, result, nextAtleft);
        }
    }
};




int main() {
    tree myTree;

    ifstream in;
    in.open("in.txt");
    string input;
    getline(in, input);

    myTree.creatTree(input);
    
    int target ,k;
    in >> target >> k;

    node* targetNode;
    targetNode = myTree.searchTarget(myTree.root, target);
    vector<int>result = myTree.distanceK(targetNode, k);
    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}