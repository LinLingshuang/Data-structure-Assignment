//5. 三元组问题
//【问题描述】定义三元组(a, b, c)(a, b, c均为整数)的距离D = | a - b | +| b - c | +| c - a | 。
// 给定3个非空整数集合S1、S2和S3，集合大小分别为n, m, k，
// 分别存储在3个数组中。设a, b, c分别为S1, S2, S3中的元素，试计算并输出最小的D。
// 【输入形式】第一行包含三个整数n, m, k, 分别代表S1, S2, S3的大小
//
//第二行包含n个整数。
//第三行包含m个整数。
//第四行包含k个整数。
//【输出形式】仅包含一个数Dmin，代表所有D值中最小的值。
//【样例输入】3 4 5
//- 1 0 9
//- 25 - 10 10 11
//2 9 17 30 41
//【样例输出】2
//【样例说明】使D最小的三元组是(9, 10, 9)
//【数据范围】0 < n, m, k≤10000，对所有集合内的元素ai满足 - 1e7 < ai < 1e7
//    【评分标准】共10个测试数据，每个测试数据10分。
 //   * 本题不保证#2、#3、#5、#6、#7数据点正确性。（2026.3.5）
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double absoluteValue(double num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

int main() {
	int n, m, p;
	cin >> n >> m >> p;
	vector<pair<int, char >>num(n + m + p);
	for (int i = 0; i < n + m + p; i++) {
		if (i < n) {
			cin >> num[i].first;
			num[i].second = 'a';
		}
		else if (i < n + m) {
			cin >> num[i].first;
			num[i].second = 'b';
		}
		else {
			cin >> num[i].first;
			num[i].second = 'c';
		}
	}
	sort(num.begin(), num.end());
	bool firstfind = false;
	double min = absoluteValue(num[n + m + p-1].first - num[0].first);

	//cout << num[i].second<<':'<< num[i].first << ' ';
	int i = 0, j = 0, k = 0,x=0;
	while (x < n + m + p) {

		if (num[x].second == 'a') i = x;
		if (num[x].second == 'b') j = x;
		if (num[x].second == 'c') k = x;
		x++;
		if (num[i].second != num[j].second && num[i].second != num[k].second && num[j].second != num[k].second) {
			if (absoluteValue(num[i].first - num[j].first) + absoluteValue(num[i].first - num[k].first) + absoluteValue(num[j].first - num[k].first) < min) {
				min = absoluteValue(num[i].first - num[j].first) + absoluteValue(num[i].first - num[k].first) + absoluteValue(num[j].first - num[k].first);
			}

		}
	}
	
	cout << min;


}
/*
5 7 3
2 3 8 7 6
1 11 25 0 4 15 9
3 12 5
*/
/*#include<iostream>
#include<vector>
using namespace std;

double absoluteValue(double num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

int main() {
		int n, m, k;
	cin >> n >> m >> k;
	cout << n << ' ' << m << ' ' << k << endl;
	vector<int>a(n);
	vector<int>b(m);
	vector<int>c(k);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cout << a[i] << ' ';
	}
	
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		cout << b[i] << ' ';
	}

	for (int i = 0; i < k; i++) {
		cin >> c[i];
		cout << c[i] << ' ';
	}
}*/
/*#include<iostream>
#include<vector>
using namespace std;

double absoluteValue(double num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int>a(n);
	vector<int>b(m);
	vector<int>c(k);

	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];

	}

	for (int i = 0; i < k; i++) {
		cin >> c[i];

	}
	bool firstfind = false;
	double min = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int p = 0; p < k; p++) {
				if (!firstfind) {
					min = absoluteValue(a[i] - b[j]) + absoluteValue(a[i] - c[k]) + absoluteValue(b[j] - c[k]);
					firstfind = true;
				}
				if (absoluteValue(a[i] - b[j]) + absoluteValue(a[i] - c[k]) + absoluteValue(b[j] - c[k]) < min) {
					min = absoluteValue(a[i] - b[j]) + absoluteValue(a[i] - c[k]) + absoluteValue(b[j] - c[k]);

				}

			}

		}

	}
	cout << min;

}*/
