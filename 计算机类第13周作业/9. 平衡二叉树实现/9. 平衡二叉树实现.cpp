/*9. 平衡二叉树实现
【问题描述】
实现一个平衡二叉树算法。接受一串待插入的字母序列插入到平衡二叉树中，
再接受一串待删除的字母序列，输出删除之后二叉树的后序遍历。
【输入形式】
第一行，待插入字母个数N1；
第二行，间隔输入待插入的字母；
第三行，待删除字母个数N2；
第四行，间隔输入待删除的字母；
【输出形式】
第一行，输出后序遍历序列；
【样例输入】
6
a c g s e f
2
c s
【样例输出】
afge
【样例说明】
【评分标准】*/
/*#include<iostream>
using namespace std;

struct AVLNode {
	char data;
	int ht;
	AVLNode* lchild, * rchild;
	AVLNode(char d) {
		data = d;
		ht = 1;
		lchild = rchild = NULL;
	}
};

class AVLTree {
public:
	AVLTree* root;
	AVLTree() {
		root = NULL;
	}
	int getHt(AVLNode* p) {
		if (p == NULL)return 0;
		return p->ht;
	}

	AVLNode* left_rotate(AVLNode* a) {
		AVLNode* b = a->rchild;
		a->rchild = b->lchild;
		b->lchild = a;
		a->ht = max(getHt(a->rchild), getHt(a->lchild) + 1);
		b->ht = max(getHt(b->rchild), getHt(b->lchild) + 1);
		return b;
	}

	AVLNode* right_rotate(AVLNode* b) {
		AVLNode* a = b->rchild;
		b->lchild = a->rchild;
		a->rchild = b;
		b->ht = max(getHt(b->rchild), getHt(b->lchild) + 1);
		a->ht = max(getHt(a->rchild), getHt(a->lchild) + 1);
		return a;
	}

	AVLNode* LL(AVLNode* a) {
		return right_rotate(a);
	}
	AVLNode* RR(AVLNode* a) {
		return left_rotate(a);
	}
	AVLNode* LR(AVLNode* a) {
		AVLNode* b = a->lchild;
		a->lchild= left_rotate(b);
		return right_rotate(a);
	}
	AVLNode* RL(AVLNode* a) {
		AVLNode* b = a->rchild;
		a->rchild = right_rotate(b);
		return left_rotate(a);
	}
};
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// AVL树节点结构体
struct AVLNode {
    string val;       // 存储字符（字符串）
    AVLNode* left;
    AVLNode* right;
    int height;

    // 构造函数
    AVLNode(string val) : val(val), left(nullptr), right(nullptr), height(1) {}
};

// 获取节点高度
int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

// 更新节点高度
void updateHeight(AVLNode* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// 获取平衡因子
int getBalance(AVLNode* node) {
    return getHeight(node->left) - getHeight(node->right);
}

// 右旋
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// 左旋
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// 插入节点
AVLNode* insert(AVLNode* node, string val) {
    if (!node) {
        return new AVLNode(val);
    }

    if (val < node->val) {
        node->left = insert(node->left, val);
    }
    else if (val > node->val) {
        node->right = insert(node->right, val);
    }
    else {
        return node; // 重复值不插入
    }

    updateHeight(node);
    int balance = getBalance(node);

    // 左左
    if (balance > 1 && val < node->left->val) {
        return rightRotate(node);
    }
    // 右右
    if (balance < -1 && val > node->right->val) {
        return leftRotate(node);
    }
    // 左右
    if (balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // 右左
    if (balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// 获取最小节点
AVLNode* getMin(AVLNode* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

// 删除节点
AVLNode* deleteNode(AVLNode* node, string val) {
    if (!node) {
        return nullptr;
    }

    if (val < node->val) {
        node->left = deleteNode(node->left, val);
    }
    else if (val > node->val) {
        node->right = deleteNode(node->right, val);
    }
    else {
        // 找到待删除节点
        if (!node->left || !node->right) {
            AVLNode* child = node->left ? node->left : node->right;
            delete node; // 释放内存
            return child;
        }
        else {
            // 两个子节点，用后继替换
            AVLNode* successor = getMin(node->right);
            node->val = successor->val;
            node->right = deleteNode(node->right, successor->val);
        }
    }

    if (!node) {
        return nullptr;
    }

    updateHeight(node);
    int balance = getBalance(node);

    // 左子树失衡
    if (balance > 1) {
        if (getBalance(node->left) >= 0) {
            return rightRotate(node);
        }
        else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    // 右子树失衡
    if (balance < -1) {
        if (getBalance(node->right) <= 0) {
            return leftRotate(node);
        }
        else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

// 后序遍历
void postorder(AVLNode* node, vector<string>& out) {
    if (node) {
        postorder(node->left, out);
        postorder(node->right, out);
        out.push_back(node->val);
    }
}

// 主函数
int main() {
    vector<string> data;
    string s;
    // 读取所有输入数据
    while (cin >> s) {
        data.push_back(s);
    }

    if (data.empty()) {
        return 0;
    }

    int idx = 0;
    int n1 = stoi(data[idx++]);
    vector<string> insertLetters(data.begin() + idx, data.begin() + idx + n1);
    idx += n1;

    int n2 = stoi(data[idx++]);
    vector<string> deleteLetters(data.begin() + idx, data.begin() + idx + n2);

    AVLNode* root = nullptr;
    // 插入
    for (string ch : insertLetters) {
        root = insert(root, ch);
    }
    // 删除
    for (string ch : deleteLetters) {
        root = deleteNode(root, ch);
    }

    // 后序遍历结果
    vector<string> result;
    postorder(root, result);

    // 输出拼接结果
    for (string ch : result) {
        cout << ch;
    }
    cout << endl;

    return 0;
}