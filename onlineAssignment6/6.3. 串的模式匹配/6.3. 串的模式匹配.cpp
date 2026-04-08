/*3. 串的模式匹配
问题描述】子串出现次数问题：基于KMP算法实现输出字符串t在主串S中出现的次数。
【输入形式】
第一行，输入子串字符串t
第二行，输入主串字符串S
【样例输入】
abcab
aabcabcabaabcab
【样例输出】
3
【样例说明】标准输入输出
【评分标准】10个测试用例，每通过一个计10分，没有用KMP算法计0分。  
允许使用STL类库*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int myKMP(string s,string t) {
	int sum = 0;
	vector<int>next(t.length());
	next[0] = -1;
	next[1] = 0;
	int k = 0;
	int j = 1;
	while (j < t.length()-1) {
		if ( k == -1||t[k] == t[j] ) {
			k++;
			j++;
			next[j] = k;
		}
		else {
			k = next[k];
		}
	}
	int i = 0;
	int jj = 0;
	while (i < s.length() ) {
		if (jj==-1||t[jj] == s[i]) {
			jj++;
			i++;
		}
		else {
			jj = next[jj];
		}
		if (jj == t.length()) {
			sum++;
			i -= jj;
			i++;
			jj = 0;
		}
	}
	return sum;
}


int main() {
	string s, t;
	cin >> t >> s;
	cout << t << endl << s << endl;
	cout << myKMP(s, t);
}