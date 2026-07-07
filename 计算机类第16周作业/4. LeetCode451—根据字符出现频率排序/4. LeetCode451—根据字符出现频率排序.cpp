/*4. LeetCode451—根据字符出现频率排序
【问题描述】
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
例如，输入"tree"，输出结果为"eert"。输入"Aabb"，输出结果为"bbAa"。要求设计满足题目条件的如下函数：
class Solution {
public:
 string frequencySort(string s)
 {  …  }
};
【输入形式】
一个字符串。其中包括键盘上的所有可打印字符，比如空格、大小写字母、数字、标点符号等。
【输出形式】
按字符出现频度由高到低的顺序排列的字符串。若字符出现的频度一样，则按ASCII码表中的顺序进行排列。
【样例输入】
tree
【样例输出】
eert
【样例说明】
b在原字符串中出现的频度最高，因此排列在最前面，字符r和t出现的频度一样，
则按ASCII码表中的顺序进行排列。测试数据存放在in.txt文件中。
【评分标准】
10个测试用例，每通过一个测试得10分。*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void Merge(vector<int>& freq, vector<int>& ascii, int low, int mid, int high) {
	vector<int>R1(high - low + 1);
	vector<int>R2(high - low + 1);
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high) {
		if (freq[i] > freq[j]) {
			R1[k] = freq[i];
			R2[k] = ascii[i];
			i++; k++;
		}
		else if (freq[i] == freq[j]) {
			if (ascii[i] <= ascii[j]) {
				R1[k] = freq[i];
				R2[k] = ascii[i];
				i++; k++;
			}
			else {
				R1[k] = freq[j];
				R2[k] = ascii[j];
				j++; k++;
			}
		}
		else {
			R1[k] = freq[j];
			R2[k] = ascii[j];
			j++; k++;
		}
	}
	while (i <= mid) {
		R1[k] = freq[i];
		R2[k] = ascii[i];
		i++; k++;
	}
	while (j <= high) {
		R1[k] = freq[j];
		R2[k] = ascii[j];
		j++; k++;
	}
	for (k = 0, i = low; i <= high; k++, i++) {
		freq[i] = R1[k];
		ascii[i] = R2[k];
	}
}

void MergePass(vector<int>& freq, vector<int>& ascii, int length) {
	int n = freq.size(), i;
	for (i = 0; i + 2 * length - 1 < n; i += 2 * length) {
		Merge(freq, ascii, i, i + length - 1, i + 2 * length - 1);
	}
	if (i + length < n) {
		Merge(freq, ascii, i, i + length - 1, n - 1);
	}
}

void MergeSort(vector<int>& freq, vector<int>& ascii, int n) {
	for (int length = 1; length < n; length = 2 * length) {
		MergePass(freq, ascii, length);
	}
}

int main() {
	string input;
	ifstream in;
	in.open("in.txt");
	getline(in, input);
	vector<int>freq;
	vector<int>ascii;
	for (char c : input) {
		int i = 0;
		bool find = false;
		for (int as : ascii) {
			if (as == c) {
				freq[i]++;
				find = true;
			}
			i++;
		}
		if (!find) {
			ascii.push_back(c);
			freq.push_back(1);
		}
	}
	MergeSort(freq, ascii, ascii.size());
	for (int i = 0; i < ascii.size(); i++) {
		char c = ascii[i];
		for (int j = 0; j < freq[i]; j++) {
			cout << c;
		}
	}
}