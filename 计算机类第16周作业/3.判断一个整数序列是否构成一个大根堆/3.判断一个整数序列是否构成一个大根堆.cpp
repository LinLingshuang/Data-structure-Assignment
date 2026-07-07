/*3. 第十章第9题
【问题描述】
设计一个算法，判断一个整数序列 a[0..n-1] 是否构成一个 大根堆（即 最大堆）。
在 大根堆 中，所有非叶子结点的值都不小于其子结点的值。
【输入形式】
第一行输入一个整数 n，表示序列的长度（1 ≤ n ≤ 10^5）。
第二行输入 n 个整数 a[0], a[1], ..., a[n-1]，表示整数序列。
【输出形式】
如果输入序列是 大根堆，输出 YES。
否则，输出 NO。
【样例输入】
样例输入 1
6
10 9 8 5 6 7
样例输入 2
5
10 5 8 9 7
【样例输出】
样例输出 1
YES
样例输出 2
NO
【样例说明】
样例 1：10 是根结点，其子结点 9 和 8 均小于 10；
9 的子结点 5 和 6 均小于 9；8 的子结点 7 小于 8，符合 大根堆 规则，输出 YES。
样例 2：5 是 10 的左子结点，但 5 < 10，因此不满足 大根堆 规则，输出 NO。
【评分标准】
正确判断小规模数据（n ≤ 1000）是否构成大根堆
代码能在 n ≤ 10^5 时高效运行，避免 O(n^2) 复杂度
代码能处理边界情况，如 n = 1 或 n = 2
代码风格良好，变量命名清晰，可读性高。
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int>input;
	for (int i = 0; i < n; i++) {
		int temp;
		if (input.empty()) {
			cin >> temp;
			input.push(temp);
		}
		else {
			if (i + 1 < n) {
				int front = input.front();
				cin >> temp;
				if (front < temp) {
					cout << "NO";
					return 0;
				}
				else {
					input.push(temp);
				}
				cin >> temp;
				if (front < temp) {
					cout << "NO";
					return 0;
				}
				else {
					input.push(temp);
				}
				input.pop();
				i++;
			}
			else {
				int front = input.front();
				cin >> temp;
				if (front < temp) {
					cout << "NO";
					return 0;
				}
				else {
					input.push(temp);
				}
				input.pop();
			}
		}
	}
	cout << "YES";
}