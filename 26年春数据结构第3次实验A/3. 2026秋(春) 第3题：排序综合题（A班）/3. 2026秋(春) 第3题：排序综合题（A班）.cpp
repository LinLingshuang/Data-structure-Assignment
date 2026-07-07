/*3. 2026秋(春) 第3题：排序综合题（A班）
【问题描述】从标准输入中读入n个正整数元素（没有重复元素），构建大根堆，
输出大根堆序列，根据初始输入序列进行快速排序，输出第一趟快速排序（以第一个数为分割数）后结果，
根据这个结果进行冒泡排序，输出第一趟冒泡结果。
【输入形式】首先输入一个整数n表示元素个数，然后在第二行依次输入n个元素的值，每个元素之间用空格分开，例如：
10
50 35 70 15 40 55 65 20 80 25
【输出形式】输出三行，第一行为大根堆序列，第二行快速排序第一次划分后结果，第三行为第二行进行第一趟冒泡结果。
【样例输入】
10
50 35 70 15 40 55 65 20 80 25(层序）
【样例输出】
80 50 70 35 40 55 65 20 15 25
25 35 20 15 40 50 65 55 80 70
15 25 35 20 40 50 55 65 70 80
【样例说明】
输入样例有10个元素，分别为50 35 70 15 40 55 65 20 80 25，顺序存储的二叉树为左图，构建大根堆为右图。
blog.png
【评分标准】
*/
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
    vector<int> input;
    tree() {
        root = NULL;
    }
    void creatTree() {
        int n ;
        cin >> n;
        queue<node*>treeNode;
        root = new node(-1);
        treeNode.push(root);

        vector<int> R;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            R.push_back(num);
        }
        input = R;
        for (int i = n/2-1; i >=0; i--) {
            siftDown(R, i, n - 1);
        }
       

        for (int i = 0; i < n; i++) {
            int num=R[i];
            treeNode.front()->data = num;
            treeNode.front()->left = new node(-1);
            treeNode.front()->left->parent = treeNode.front();
            treeNode.push(treeNode.front()->left);
            treeNode.front()->right = new node(-1);
            treeNode.front()->right->parent = treeNode.front();
            treeNode.push(treeNode.front()->right);
            treeNode.pop();
        }
    }
    vector<int> siftDown(vector<int> &R,int low, int high) {
        int i = low;
        int j = 2 * i + 1;//i为层数，+1为左孩子，+2为右孩子
        int temp = R[i];
        while (j <= high) {
            if (j < high && R[j] < R[j + 1]) {
                j++;
            }
            if (temp < R[j]) {
                R[i] = R[j];
                i = j; j = 2 * i + 1;
            }
            else {
                break;
            }
        }
        R[i] = temp;
        return R;
    }
    
    //层序
    void lyarSearchTree(vector<node*>lyar) {
        vector<node*>nextlyar;
        for (node* p : lyar) {
            if (p != NULL) {
                if (p->data != -1)cout << p->data << ' ';
                nextlyar.push_back(p->left);
                nextlyar.push_back(p->right);
            }
        }
        if (!nextlyar.empty()) {
            lyarSearchTree(nextlyar);
        }
    }
    
    void heapSort(vector<int>&R,int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            siftDown(R, i, n - 1);
        }
        for (int i = n - 1; i > 0; i--) {
            swap(R[0], R[i]);
            siftDown(R, 0, i - 1);
        }
    }
    
    int Partition(vector<int>& R, int s, int t) {
        int base = R[s];
        int i = s, j = t;
        while (i <j) {
            while (i<j && R[j]>base)j--;
            while (i < j && R[i] <= base)i++;
            if (i < j)swap(R[i], R[j]);
        }
        swap(R[s], R[i]);
        return i;
    }
    int Partition2(vector<int>& R, int s, int t) {
        int base = R[s];
        int i = s, j = t;
        while (i < j) {
            while (i<j && R[j]>=base)j--;
            if (i < j) {
                R[i] = R[j];
                i++;
            }
            while (i < j && R[i] <= base)i++;
            if (i < j) {
                R[j] = R[i];
                j--;
            }
        }
        R[i] = base;
        return i;
    }
    void _QuickSort(vector<int>& R, int s, int t) {
        if (s < t) {
            int i = Partition(R, s, t);
            _QuickSort(R,s,i-1);
            _QuickSort(R, i+1,t);
        }
    }
    void QuickSort(vector<int>& R, int n) {
        _QuickSort(R, 0, n-1);
    }

    void display() {
        for (int i = 0; i < input.size(); i++) {
            cout << input[i] << ' ';
        }
        cout << endl;
        for (int i = input.size() - 1; i >0; i--) {
            int temp = input[i];
            if (input[i] < input[i - 1]) {
                input[i] = input[i - 1];
                input[i - 1] = temp;
            }
        }
        for (int i = 0; i < input.size(); i++) {
            cout << input[i] << ' ';
        }
    }
};




int main() {
    tree myTree;
    myTree.creatTree();
    vector<node*>nextlyar;
    nextlyar.push_back(myTree.root);
    myTree.lyarSearchTree(nextlyar);
    cout << endl;
    myTree.Partition2(myTree.input, 0, myTree.input.size() - 1);
    myTree.display();
}