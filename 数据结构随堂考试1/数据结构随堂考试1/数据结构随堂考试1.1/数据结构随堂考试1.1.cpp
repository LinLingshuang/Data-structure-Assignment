/*1. 队列——完美洗牌
问题描述
有一副 n 张的扑克牌（编号从 1 到 n），按顺序叠放（1 在最上面，n 在最下面）。
现要进行一次"完美洗牌"操作：把牌分成上下两半，然后交替从两半中取牌重新叠放。必须使用队列，详见类库使用要求
洗牌规则：
若 n 为偶数，上下各 n/2 张；上半部分为 1 到 n/2，下半部分为 n/2+1 到 n
若 n 为奇数，上半部分多一张（(n+1)/2 张），下半部分 (n−1)/2 张
重排时，先取上半部分的第一张，再取下半部分的第一张，交替进行；若上半部分有剩余，则全部接在后面
请使用两个队列模拟此洗牌过程，输出洗牌后的牌序。
输入形式
输入一行，包含一个正整数 n（1≤n≤1000），表示扑克牌的数量。
输出形式
输出一行，为 n 个整数，表示洗牌后的牌序（从上到下），整数之间用一个空格分隔。
样例输入 1
6
样例输出 1
1 4 2 5 3 6
样例说明 1
6 张牌初始顺序：1, 2, 3, 4, 5, 6
分成两半：上半 [1, 2, 3]，下半 [4, 5, 6]
交替合并：取上半的 1，取下半的 4，取上半的 2，取下半的 5，取上半的 3，取下半的 6
结果：1, 4, 2, 5, 3, 6
样例输入 2
5
样例输出 2
1 4 2 5 3
样例说明 2
5 张牌初始顺序：1, 2, 3, 4, 5
分成两半（上半多一张）：上半 [1, 2, 3]，下半 [4, 5]
交替合并：取上半的 1，取下半的 4，取上半的 2，取下半的 5，上半剩余 [3] 全部接上
结果：1, 4, 2, 5, 3
样例输入 3
1
样例输出 3
1
样例说明 3
只有一张牌，无需洗牌。
评分标准
共 10 个测试用例
类库使用要求
必须手动实现队列类（Queue），包含基本操作：enqueue（入队）、dequeue（出队）、
front（取队首）、isEmpty（判空）、size（获取队列大小，可选但建议实现）
不允许使用 std::queue 或其他 STL 队列容器
必须使用两个队列分别存储上半部分和下半部分，通过队列操作完成合并
可以使用标准数组或链表作为队列的底层存储结构
*/
#include<iostream>
#include<vector>
using namespace std;

class Queue {
public:
	vector<int>card;
	int head, rear;
	int mysize;
	Queue() {
		mysize = 0;
		head = 0;
		rear = 0;
	}
	Queue(int start,int end) {
		head = 0;
		rear = 0;
		for (int i = start; i <= end; i++) {
			enqueue(i);
		}
	}
	Queue(const Queue &q) {
		this->mysize = q.mysize;
		this->card = q.card;
		this->head = 0;
		this->rear = q.rear;
	}

	void enqueue(int num) {
		card.push_back(num);
		rear++;
		mysize++;
	}
	int dequeue() {
		if (!isEmpty()) {
			int temp = card[head];
			head++;
			mysize--;
			return temp;
		}
		else {
			return 0;
		}
	}
	int front() {
		if (!isEmpty()) {
			int temp = card[head];
			return temp;
		}
		else {
			return 0;
		}
	}
	bool isEmpty() {
		if (head==rear) {
			return true;
		}
		else {
			return false;
		}
	}

};


int main() {
	int n;
	cin >> n;
	Queue up;
	Queue down;
	if (n % 2 == 0) {
		up = Queue(1, n / 2);
		down = Queue(n / 2 + 1, n);
	}
	else {
		up = Queue(1, (n + 1) / 2);
		down = Queue((n + 1) / 2 + 1, n);
	}
	while (!(up.isEmpty() && down.isEmpty())) {
		if (!up.isEmpty()) {
			cout << up.dequeue() << ' ';
		}
		if (!down.isEmpty()) {
			cout << down.dequeue() << ' ';
		}
	}

}