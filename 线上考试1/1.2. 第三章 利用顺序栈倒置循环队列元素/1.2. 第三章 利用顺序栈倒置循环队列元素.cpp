/*2. 第三章 利用顺序栈倒置循环队列元素
【问题描述】设计一个算法，利用一个顺序栈将一个循环队列中的所有元素倒过来，使得队头变为队尾，队尾变为队头。
【输入形式】第一行输入一个整数n，表示循环队列的长度；
第二行输入n个整数，以空格分隔，表示循环队列的元素值，输入按队列的顺序给出，即第一个数是队头元素，最后一个数是队尾元素。
【输出形式】输出一行整数，表示倒置后的队列元素，元素之间以空格分隔，新的队头在最前面，新的队尾在最后面。
【样例输入】
5  
1 2 3 4 5  
【样例输出】
5 4 3 2 1
【样例说明】
【评分标准】
【类库使用要求】
不可以使用STL中的stack、queue、vector等库函数，可以使用字符串STL处理输入。
【说明】
要求自己设计实现栈或队列类
*/
#include<iostream>
using namespace std;

struct queue {
	int* head;

	queue(int n) {
		head = new int[n];
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			head[n - 1 - i] = temp;
		}
	}
	void output(int n) {
		for (int i = 0; i < n; i++) {
			cout << head[i] << ' ';
		}
	}

};

int main() {
	int n;
	cin >> n;
	queue myQ(n);
	myQ.output(n);

}