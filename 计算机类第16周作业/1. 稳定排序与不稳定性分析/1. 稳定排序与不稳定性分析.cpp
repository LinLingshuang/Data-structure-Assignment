/*1. 稳定排序与不稳定性分析
稳定排序与不稳定性分析
一、问题描述
给定一个包含多个字段（id和score）的记录数组，要求先按score降序排序，
score相同的按id升序排序。使用快速排序和归并排序分别实现，观察稳定性的影响。
本题要求使用归并排序（稳定排序）实现。
二、输入形式
第一行输入一个正整数n（1 ≤ n ≤ 100000），表示记录数量。
接下来n行，每行两个整数id和score，表示一条记录。
三、输出形式
输出排序后的记录，每行一个，格式为"id score"。
四、样例输入
5
1 90
2 85
3 90
4 85
5 95
五、样例输出
5 95
1 90
3 90
2 85
4 85
六、样例说明
按score降序排序，score相同的按id升序排序。
七、评分标准
共10个测试用例。
八、类库使用要求
可以使用vector。使用归并排序实现。*/
#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& score, vector<int>& id, int low, int mid, int high) {
	vector<int>R1(high-low+1);
	vector<int>R2(high - low + 1);
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high) {
		if (score[i] > score[j]) {
			R1[k] = score[i];
			R2[k] = id[i];
			i++; k++;
		}
		else if (score[i] == score[j]) {
			if (id[i] <= id[j]) {
				R1[k] = score[i];
				R2[k] = id[i];
				i++; k++;
			}
			else {
				R1[k] = score[j];
				R2[k] = id[j];
				j++; k++;
			}
		}
		else {
			R1[k] = score[j];
			R2[k] = id[j];
			j++; k++;
		}
	}
	while (i <= mid) {
		R1[k] = score[i];
		R2[k] = id[i];
		i++; k++;
	}
	while (j <= high) {
		R1[k] = score[j];
		R2[k] = id[j];
		j++; k++;
	}
	for (k = 0, i = low; i <= high; k++, i++) {
		score[i] = R1[k];
		id[i] = R2[k];
	}
}

void MergePass(vector<int>& score, vector<int>& id, int length) {
	int n = score.size(), i;
	for (i = 0; i + 2 * length - 1 < n; i += 2 * length) {
		Merge(score, id, i, i + length - 1, i + 2 * length - 1);
	}
	if (i + length < n) {
		Merge(score, id, i, i + length - 1, n-1);
	}
}

void MergeSort(vector<int>& score, vector<int>& id, int n) {
	for (int length = 1; length < n; length = 2 * length) {
		MergePass(score, id, length);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int>id(n);
	vector<int>score(n);
	for (int i = 0; i < n; i++) {
		cin >> id[i] >> score[i];
	}
	MergeSort(score, id, n);
	for (int i = 0; i < n; i++) {
		cout << id[i] << ' ' << score[i] << endl;
	}
}

