/*5. HDU2018—母牛的故事
【问题描述】
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。
请编程实现在第n年的时候，共有多少头母牛？
【输入形式】
 输入一个整数n（0<n<55），n的含义如题目中描述。
【输出形式】
输出在第n年的时候母牛的数量。
【样例输入】
 5
【样例输出】
 6
【样例说明】
第5年时共有6头母牛。测试数据存放在in.txt文件中。
【评分标准】
共10个测试用例，每通过一个测试得10分。*/
#include<iostream>
#include<fstream>
using namespace std;
//通过ai得知是斐波那契变体，自己写的复杂度较高的方法放最后了
int main() {
	int n;
	ifstream in;
	in.open("in.txt");
	in >> n;
	cin >> n;
	
	// 动态规划数组，dp[i]表示第i年的母牛数量
	long long dp[55];
	// 初始化前几年的母牛数量
	dp[1] = 1; // 第1年只有1头母牛
	dp[2] = 2; // 第2年有2头母牛
	dp[3] = 3; // 第3年有3头母牛
	
	// 从第4年开始，每一年的母牛数量等于前一年的数量加上3年前的数量
	// 因为3年前出生的母牛现在已经可以生小牛了
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i-1] + dp[i-3];
	}
	
	cout << dp[n];
}

/*5. HDU2018—母牛的故事
【问题描述】
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。
请编程实现在第n年的时候，共有多少头母牛？
【输入形式】
 输入一个整数n（0<n<55），n的含义如题目中描述。
【输出形式】
输出在第n年的时候母牛的数量。
【样例输入】
 5
【样例输出】
 6
【样例说明】
第5年时共有6头母牛。测试数据存放在in.txt文件中。
【评分标准】
共10个测试用例，每通过一个测试得10分。
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct cow {
	int age = 0;
	cow() {
		age = 0;
	}
};


int main() {
	int n;
	ifstream in;
	in.open("in.txt");
	in >> n;
	cin >> n;
	cow firstCow;
	firstCow.age = 4;
	vector<cow>cows;
	cows.push_back(firstCow);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < cows.size(); j++) {
			cows[j].age++;
			if (cows[j].age >= 4) {
				cow newCow = cow();
				cows.push_back(newCow);
			}
		}
	}
	cout << cows.size();
}*/