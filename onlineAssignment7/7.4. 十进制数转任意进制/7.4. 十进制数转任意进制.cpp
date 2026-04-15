/*4. 十进制数转任意进制
【问题描述】
将正整数m（十进制）利用n进制表示，n是正整数且n>=2，
得到的n进制数每一位依次存储在一个数组num中，
num[0]为最高位。说明：n进制的每一位用数字i表示，i可以>=10。
【输入形式】
m n
【输出形式】
n进制表示的每一位（从高位到低位，每一位中间用空格隔开，最高位不能为0）
【样例输入】
11 2
【样例输出】
1 0 1 1
【样例说明】
输入文件名字为in.txt
输出文件名字为out.txt
【评分标准】
一共10个测试样例，每通过一个得10分*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main() {
	ifstream in;
	ofstream out;
	in.open("in.txt");
	out.open("out.txt");
	int m, n;
	in >> m >> n;
	cin >> m >> n;
	vector<int>num;
	while (m != 0) {
		num.push_back(m % n);
		m = (m-(m % n)) / n;
	}
	for (int i = num.size() - 1; i >= 0;i--) {
		out << num[i] << ' ';
		cout << num[i] << ' ';
	}
}