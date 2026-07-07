/*8. POJ1723—士兵排列
【问题描述】
某国的n个士兵随机分布在全国各地，其位置由（x，y）整数坐标给出，
士兵可以上下左右移动一个单位（因此，他可以将其x坐标或y坐标按+1或-1修改）。
士兵们希望彼此相邻进入一条水平线，以便他们的最终位置是
（x，y），（x+1，y），…，（x+n-1，y），整数x和y以及士兵沿水平线的最终顺序是任意的。
目标是最大程度地减少所有使士兵进入这种状态的士兵移动总数。
两名或两名以上的士兵不能同时出现在相同位置。
【输入形式】
输入的第一行包含整数n（1≤n≤10000），表示士兵人数。以下n行包含士兵的初始位置，
对于每个i（1≤i≤n），输入文件的第i+1行包含一对整数x[i]和y[i]用一个空白字符分隔，
代表第i个士兵的坐标（-10000≤x[i]，y[i]≤10000）。
【输出形式】
输出一行包含将士兵带入彼此相邻的水平线的最小移动总数。
【样例输入】
5
1 2
2 2
1 3
3 -2
3 3
【样例输出】
8
【样例说明】
于输入的5个士兵的排列位置，最少移动8步可以排成一排。测试数据存放在in.txt文件中。
【评分标准】
共10个测试用例，每通过一个测试得10分。*/
#include <iostream>
#include <algorithm>
#include<fstream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ifstream in;
    in.open("in.txt");
    int n;
    in >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        in >> x[i] >> y[i];
    }

    // 1. 处理 y 坐标：取中位数
    sort(y.begin(), y.end());
    int median_y = y[n / 2];
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        total += abs(y[i] - median_y);
    }

    // 2. 处理 x 坐标：变成连续整数
    sort(x.begin(), x.end());
    for (int i = 0; i < n; ++i) {
        x[i] -= i;                // 变换：xi' = xi - i
    }
    sort(x.begin(), x.end());
    int median_x = x[n / 2];
    for (int i = 0; i < n; ++i) {
        total += abs(x[i] - median_x);
    }

    cout << total << "\n";
    return 0;
}
/*
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main() {
	int n;
	vector<pair<int, int>>man(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		man[i] = pair<int, int>(x, y);
	}
	
}
*/