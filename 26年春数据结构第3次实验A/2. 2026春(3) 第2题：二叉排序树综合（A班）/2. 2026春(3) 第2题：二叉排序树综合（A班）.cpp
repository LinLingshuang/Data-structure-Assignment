/*2. 2026春(3) 第2题：二叉排序树综合（A班）
【问题描述】从标准输入读取若干整数（允许重复）、待删除整数x和待查找整数y；
构建结点包含数据值与重复出现次数的二叉排序树。依次完成以下操作：按二叉树括号表示法输出原树；
删除一个x后输出树的中序遍历序列；在该中序序列中对y执行二分查找，并输出查找比较次数（无论成功与否）。
例如，依次输入12个元素50 35 70 50 40 55 65 50 20 80 20 40，所建立的二叉排序树如图
blog.png
【实验要求】
（1）二叉排序树的构造方法可自行选择。
（2）中序遍历序列仅输出结点数据值，不输出重复次数。
（3）在二叉排序树中删除整数x：若x重复出现，则将其次数减1；若x仅出现一次，则直接删除对应结点。
【输入形式】从键盘输入三行数据：第一行为若干以空格分隔的整数（可重复），
第二行、第三行分别输入待删除整数x与待二分查找的整数y。
【输出形式】按要求输出三行内容：
第一行输出初始二叉排序树的括号表示法，
第二行输出删除元素 x后的树的中序遍历序列，
第三行输出对y进行二分查找的比较次数。
【样例输入】                        
50 35 70 50 40 55 65 50 20 80 20 40
55
66
【样例输出】 
50|3(35|1(20|2,40|2),70|1(55|1(,65|1),80|1))
20 35 40 50 65 70 80
3*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    int count;
    Node* left;
    Node* right;
    Node(int d) : data(d), count(1), left(nullptr), right(nullptr) {}
};

// 插入节点（重复则增加计数）
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val == root->data) {
        root->count++;
    }
    else if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

// 删除整个节点（不考虑重复次数，用于删除后继节点）
Node* removeAll(Node* root, int val) {
    if (!root) return nullptr;
    if (val < root->data) {
        root->left = removeAll(root->left, val);
    }
    else if (val > root->data) {
        root->right = removeAll(root->right, val);
    }
    else {
        if (root->left == nullptr) {
            Node* right = root->right;
            delete root;
            return right;
        }
        else if (root->right == nullptr) {
            Node* left = root->left;
            delete root;
            return left;
        }
        else {
            // 此处一般不会出现，但为完整性保留
            Node* minNode = root->right;
            while (minNode->left) minNode = minNode->left;
            root->data = minNode->data;
            root->count = minNode->count;
            root->right = removeAll(root->right, minNode->data);
            return root;
        }
    }
    return root;
}

// 删除一个实例（若 count>1 则减1，否则删除节点）
Node* removeOne(Node* root, int val) {
    if (!root) return nullptr;
    if (val < root->data) {
        root->left = removeOne(root->left, val);
    }
    else if (val > root->data) {
        root->right = removeOne(root->right, val);
    }
    else {
        if (root->count > 1) {
            root->count--;
            return root;
        }
        else {
            // count == 1，需要删除该节点
            if (root->left == nullptr) {
                Node* right = root->right;
                delete root;
                return right;
            }
            else if (root->right == nullptr) {
                Node* left = root->left;
                delete root;
                return left;
            }
            else {
                // 找到右子树最小节点
                Node* minNode = root->right;
                while (minNode->left) minNode = minNode->left;
                // 复制数据及重复次数到当前节点
                root->data = minNode->data;
                root->count = minNode->count;
                // 删除右子树中的该最小节点（整个节点）
                root->right = removeAll(root->right, minNode->data);
                return root;
            }
        }
    }
    return root;
}

// 输出二叉树的括号表示法
void printTree(Node* root) {
    if (!root) return;
    cout << root->data << "|" << root->count;
    if (root->left || root->right) {
        cout << "(";
        if (root->left) {
            printTree(root->left);
            if (root->right) cout << ",";
        }
        else if (root->right) {
            cout << ",";   // 左空右非空，输出逗号
        }
        if (root->right) printTree(root->right);
        cout << ")";
    }
}

// 中序遍历，结果存入 vector（仅数据值）
void inorder(Node* root, vector<int>& seq) {
    if (!root) return;
    inorder(root->left, seq);
    seq.push_back(root->data);
    inorder(root->right, seq);
}

// 在有序序列中二分查找，返回比较次数
int binarySearch(const vector<int>& seq, int target) {
    int low = 0, high = seq.size() - 1;
    int cmp = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        cmp++;
        if (seq[mid] == target) {
            return cmp;
        }
        else if (seq[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return cmp;
}

int main() {
    // 读取第一行（若干个整数）
    string line;
    getline(cin, line);
    stringstream ss(line);
    int val;
    Node* root = nullptr;
    while (ss >> val) {
        root = insert(root, val);
    }

    // 输出原树括号表示法
    printTree(root);
    cout << endl;

    // 读取待删除数 x 和待查找数 y
    int x, y;
    cin >> x >> y;

    // 删除一个 x
    root = removeOne(root, x);

    // 中序遍历得到序列
    vector<int> seq;
    inorder(root, seq);

    // 输出第二行：中序序列
    for (size_t i = 0; i < seq.size(); ++i) {
        if (i) cout << " ";
        cout << seq[i];
    }
    cout << endl;

    // 输出第三行：二分查找比较次数
    cout << binarySearch(seq, y) << endl;

    return 0;
}