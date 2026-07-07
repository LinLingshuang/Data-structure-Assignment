/*2. 基数排序
一、问题描述
给定一个非负整数数组，使用基数排序算法将其按升序排列，输出排序后的数组。
二、输入形式
第一行输入一个正整数n（1 ≤ n ≤ 100000），表示数组长度。
第二行输入n个整数，表示数组元素（0 ≤ 元素 ≤ 10^9）。
三、输出形式
输出排序后的数组，元素用空格分隔。
四、样例输入
8
170 45 75 90 802 24 2 66
五、样例输出
2 24 45 66 75 90 170 802
六、评分标准
共10个测试用例。
七、类库使用要求
可以使用vector、queue。*/
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int geti(int key, int r, int i) {
	int k;
	for (int j = 0; j <= i; j++) {
		k = key % r;
		key = key / r;
	}
	return k;
}

//queue版本
void RadixSortByQueue(vector<int>& L, int d, int r) {
	queue<int>front[100];
	int p;
	for (int i = 0; i < d; i++) {
		int m = 0;
		
		while (m<L.size()) {
			p = L[m];
			int k = geti(p, r, i);
			front[k].push(p);		
			m++;
		}
		vector<int> h(L.size());
		m = 0;
		for (int j = 0; j < r; j++) {
			if (!front[j].empty()) {
				while (!front[j].empty()) {
					h[m] = front[j].front();
					front[j].pop();
					m++;
				}
			}
			L = h;
		}
		
	}
}


//list版本
template<class T>
struct node {
	T data;
	node<T>* next;
	node<T>(){
		next = NULL;
	}
	node<T>(T d) {
		data = d;
		next = NULL;
	}
	node<T>(const node<T>& n) {
		data = n.data;
		next = n.next;
	}
};
template<class T>
class list {
public:
	node<T>* head;
	list<T>() {
		head = new node<T>();
		head->next = NULL;
	}
	list<T>(vector<T>v,int n) {
		head = new node<T>();
		head->next = NULL;
		node<T>* p = head;
		for (int i = 0; i < n; i++) {
			p->next = new node<T>(v[i]);
			p = p->next;
		}
	}
	list<T>(const list<T>&l) {
		head = l.head;
	}
	void display() {
		node<T>* p = head->next;
		while (p != NULL) {
			cout << p->data << ' ';
			p = p->next;
		}
	}
};

void RadixSortByList(list<int>& L, int d, int r) {
	node<int>* front[100];
	node<int>* rear[100];
	node<int>* p, * t;
	t = NULL;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < r; j++) {
			front[j] = rear[j] = NULL;
		}
		p = L.head->next;
		while (p != NULL) {
			int k = geti(p->data, r, i);
			if (front[k] == NULL) {
				front[k] = p;
				rear[k] = p;
			}
			else {
				rear[k]->next = p;
				rear[k] = p;
			}
			p = p->next;
		}
		node<int>* h=NULL;
		for (int j = 0; j < r; j++) {
			if (front[j] != NULL) {
				if (h == NULL) {
					h = front[j];
					t = rear[j];
				}
				else {
					t->next = front[j];
					t = rear[j];
				}
			}
			t->next = NULL;
			L.head->next = h;
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int>input(n);
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		if (input[i] > max)max = input[i];
	}
	int d = log10(max) + 1;
	RadixSortByQueue(input, d, 10);
	for (int i = 0; i < n; i++) {
		cout << input[i] << ' ';
	}

	//list<int>L(input,n);
	//RadixSortByList(L, d, 10);
	//L.display();
}