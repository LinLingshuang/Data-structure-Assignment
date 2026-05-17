/*2. 【实战7.5】HDU1232—畅通工程问题
【问题描述】
某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。
省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。
问最少还需要建设多少条道路？
【输入形式】
每个测试用例的第1行给出两个正整数，分别是城镇数目n（n<1000）和道路数目m，
随后的m行对应m条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。
为简单起见，城镇从1到n编号。注意两个城市之间可以有多条道路相通，也就是说：
3 3
1 2
1 2
2 1
这种输入也是合法的。
【输出形式】对每个测试用例，在一行里输出最少还需要建设的道路数目。
【样例输入】
3 3
1 2
1 3
2 3
【样例输出】
0
【样例说明】
测试数据的文件名为in.txt
【评分标准】
该题目有10个测试用例，每通过一个测试用例，得10分。
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class city {
public:
	int name;
	bool find = false;
	vector<city*>otherCity;
	city() {
		name=0;
		bool find = false;
		otherCity= vector<city*>(0);
	}
	city(const city& c) {
		name = c.name;
		find = c.find;		
		otherCity = c.otherCity;
		
	}
};

void search(city &c, vector<city>&findcity) {
	if (!c.find) {
		findcity.push_back(c);
		c.find = true;
		for (int i = 0; i < c.otherCity.size(); i++) {
			search(*c.otherCity[i], findcity);
		}
	}
	else {
		return;
	}
	
}

int main() {
	int n, m;
	fstream in;
	in.open("in.txt");
	//cin >> n >> m;
	in >> n >> m;
	vector<city>allcity(n);
	for (int i = 0; i < n; i++) {
		allcity[i].name = i + 1;
	}
	for (int i = 0; i < m; i++) {
		int city1, city2;
		//cin >> city1 >> city2;
		in >> city1 >> city2;
		city* temp1 = &allcity[city2 - 1];
		city* temp2 = &allcity[city1 - 1];
		allcity[city1 - 1].otherCity.push_back(temp1);
		allcity[city2 - 1].otherCity.push_back(temp2);
	}
	vector<city>findcity;
	search(allcity[0], findcity);
	int result = 0;
	for (int i = 1; i < n; i++) {
		if (!allcity[i].find) {
			result++;
			search(allcity[i], findcity);
		}
		
	}
	cout << result;
}