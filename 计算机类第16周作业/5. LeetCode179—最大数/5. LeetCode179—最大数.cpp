/*5. LeetCode179—最大数
【问题描述】
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
例如，输入[10，2]，输出结果为210。输入[3,30,34,5,9]，
输出结果为953104330。要求设计满足题目条件的如下函数：
class Solution{
public:
 string largestNumber(vector<int>& nums)
 {  …  }
};
【输入形式】
输入一组非负整数序列，整数之间用逗号隔开。
【输出形式】
输出由这些整数构成的最大整数。
【样例输入】
10,2
【样例输出】
210
【样例说明】
由整数10和2构成的最大整数为210。测试数据存放在in.txt文件中。
【评分标准】
共10个测试用例，每通过一个测试得10分。
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void combine(vector<string>num, vector<int>find, vector<string>& result,string recent,int n) {
	if (n == num.size()) {
		result.push_back(recent);
		//result.push_back(stoi(recent));
		return;
	}
	else {
		for (int i = 0; i < num.size(); i++) {
			if (!find[i]) {	
				vector<int>nextfind = find;
				nextfind[i] = 1;
				combine(num, nextfind, result, recent + num[i], n + 1);
			}
		}
	}
}

int main() {
	string input;
	ifstream in;
	in.open("in.txt");
	getline(in, input);
	//cout << input << endl;
	vector<string>num;
	string temp;
	for (char c : input) {
		if (c == ',') {
			num.push_back(temp);
			temp .clear();
		}
		else {
			temp.push_back(c);
		}
	}
	num.push_back(temp);
	vector<int>find(num.size(),0);
	vector<string>result;
	string recent;
	combine(num, find, result, recent, 0);
	string max = "0";
	for (int i = 0; i < result.size(); i++) {
		if (max < result[i])max = result[i];
	}
	cout << max;
}