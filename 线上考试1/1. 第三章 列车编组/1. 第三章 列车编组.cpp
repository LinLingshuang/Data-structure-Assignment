/*1. 第三章 列车编组
【问题描述】用于列车编组的铁路转轨网络是一种栈结构其中，右边轨道是输入端，
左边轨道是输出端。当右边轨道上的车皮编号顺序为1、2、3、4时，
如果执行操作进栈、进栈、出栈、进栈、进栈、出栈、出栈，则在左边轨道上的车皮编号顺序为2、4、3、1。
设计一个算法，给定n个整数序列a表示右边轨道上的车皮编号顺序，
用上述转轨栈对这些车皮重新编号，使得编号为奇数的车皮都排在编号为偶数的车皮的前面，
要求产生所有操作的字符串op和最终结果字符串ans。
image.png
【输入形式】
第一排：车皮数量 
第二排：右边轨道上的车皮编号
【输出形式】
第一排：op 
第二排：ans
【样例输入】
4 
1 2 3 4
【样例输出】
in out in in out in out out
1 3 4 2
【样例说明】
【评分标准】
【类库使用要求】
不可以使用STL中的stack、queue、vector等库函数，可以使用字符串STL处理输入。
【说明】
要求自己设计实现栈或队列类
*/
#include<iostream>
#include<string>
using namespace std;

class stack {
public:
	int* in;
	int* out;
	int topIn;
	int topOut;
	stack(int n) {
		in = new int[n];
		out = new int[n];
		topIn = -1;
		topOut = -1;
	}
	void create(int num) {
		for (int i = 0; i < num; i++) {
			int temp;
			cin >> temp;
			if (temp % 2 == 0) {
				topIn++;
				in[topIn] = temp;
				cout << "in" << ' ';
			}
			else {
				cout << "in" << ' ' << "out" << ' ';
				topOut++;
				out[topOut] = temp;
			}
		}
		for (int i = 0; i <= topIn; i++) {
			cout << "out" << ' ';
			topOut++;
			out[topOut] = in[topIn - i];
		}
		cout << endl;
		for (int i = 0; i <= topOut; i++) {
			cout << out[i] << ' ';
		}
	}
};

int main() {
	int n;
	cin >> n;
	stack right(n);
	right.create(n);

}