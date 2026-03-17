/*5. 颜色分类
【问题描述】
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，
使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
必须在不使用库内置的 sort 函数的情况下解决这个问题。（注意！通过的代码会被复查）
【输入形式】
第一行一个正整数 n，保证 n 小于 100。
第二行 n 个用空格隔开的整数 a[1]...a[n]，取值为 0, 1, 2。
【输出形式】
一行 n 个用空格隔开的整数，表示排序后的结果
【样例输入】
6
2 0 2 1 1 0
【样例输出】
0 0 1 1 2 2
【样例说明】
【评分标准】*/
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* nums = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}

		}
	}
	for (int i = 0; i < n; i++) {
		cout << nums[i] << ' ';
	}

}