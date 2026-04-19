/*6. 顺序队列基本操作
顺序队列基本操作
一、问题描述
实现一个循环队列（固定容量），支持以下操作：
ENQUEUE x：将元素x加入队尾，队列满时输出"FULL"
DEQUEUE：移除队头元素，队列空时输出"EMPTY"
FRONT：查看队头元素，队列空时输出"EMPTY"
REAR：查看队尾元素，队列空时输出"EMPTY"
SIZE：输出队列中元素个数
二、输入形式
第一行输入两个正整数n和m（1 ≤ n ≤ 100000, 1 ≤ m ≤ 100000），分别表示队列的最大容量和操作数量。
接下来m行，每行一个操作，格式如上所述。
三、输出形式
对于DEQUEUE、FRONT、REAR操作，输出对应的值或错误信息。
每个输出占一行。
四、样例输入
3 10
ENQUEUE 1
ENQUEUE 2
FRONT
REAR
DEQUEUE
SIZE
ENQUEUE 3
ENQUEUE 4
ENQUEUE 5
ENQUEUE 6
五、样例输出
1
2
1
1
FULL
六、样例说明
操作过程：
ENQUEUE 1：队列[1]
ENQUEUE 2：队列[1,2]
FRONT：队头为1
REAR：队尾为2
DEQUEUE：移除1，输出1，队列[2]
SIZE：大小为1
ENQUEUE 3：队列[2,3]
ENQUEUE 4：队列[2,3,4]
ENQUEUE 5：队列满，输出FULL
ENQUEUE 6：队列满，输出FULL
七、评分标准
共6个测试用例。
八、类库使用要求
必须使用数组实现循环队列，禁止使用STL queue。*/
#include<iostream>
#include<string>
using namespace std;

class queue {
public:
	int head, rear;
	int size;
	int capacity;
	int* data;
	queue() {
		size = 0;
		capacity = 0;
		data = new int[1];
		head = 0;
		head = rear;
	}
	queue(int ccapacity) {
		capacity = ccapacity + 1;
		size = 0;
		data = new int[capacity];
		head = 0;
		head = rear;
	}
	void ENQUEUE() {
		int temp;
		cin >> temp;
		if ((rear + 1) % capacity == head) {
			cout << "FULL" << endl;
			return;
		}
		else {
			data[rear] = temp;
			size++;
			rear = (rear + 1) % capacity;
		}
	}
	void DEQUEUE() {
		if (rear == head) {
			cout << "EMPTY" << endl;
			return;
		}
		else {
			cout << data[head] << endl;
			head = (head + 1) % capacity;
			size--;
		}
	}
	void FRONT() {
		if (rear == head) {
			cout << "EMPTY" << endl;
			return;
		}
		else {
			cout << data[head] << endl;
		}
	}
	void REAR() {
		if (rear == head) {
			cout << "EMPTY" << endl;
			return;
		}
		else {
			cout << data[(rear + capacity - 1) % capacity] << endl;
		}
	}
	void SIZE() {
		cout << size << endl;
	}
};

int main() {
	int capacity;
	cin >> capacity;
	queue myQueue(capacity);
	int op;
	cin >> op;
	for (int i = 0; i < op; i++) {
		string temp;
		cin >> temp;
		if (temp == "ENQUEUE") {
			myQueue.ENQUEUE();
		}
		else if (temp == "DEQUEUE") {
			myQueue.DEQUEUE();
		}
		else if (temp == "FRONT") {
			myQueue.FRONT();
		}
		else if (temp == "REAR") {
			myQueue.REAR();
		}
		else if (temp == "SIZE") {
			myQueue.SIZE();
		}
	}
}