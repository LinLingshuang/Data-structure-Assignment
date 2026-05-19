/*2. 2026春(2)第2题：哈夫曼编解码(A)
【实验题目】已知通信报文由 a、b、c、d、e、f、g、h 共8个字符组成，从键盘输入各字符的频率，
构建哈夫曼树,读取文件中存储的哈夫曼编码，完成解码操作，并将解码结果写入输出文件。
例如针对上述8个字母，输入频率如下：
a:0.04 
b:0.22
c:0.06
d:0.18
e:0.21
f:0.12
g:0.08
h:0.09
建立的Huffman树如下图，得到的Huffman编码如下：
a:1000 
b:01
c:1001
d:111
e:00
f:101
g:1100
h:1101
blob.png
若输入的报文文件内容如下：
11110001001001001
110100001001100100011000
0010011111100011110101
则解码文件内容为：
dacec
heecceba
ecdgbdbb

注释：
111 1000 1001 00 1001
1101 00 00 1001 1001 00 01 1000
0010011111100011110101
【输入格式】包含键盘输入和文件输入：
（1）键盘输入格式：第一行输入字母个数n，后续n行每行按字母+“:”+频率格式输入字符及对应权值。
（2）文件输入：从文件in.txt读取m行，每行对应一个哈夫曼编码测试用例（由0和1构成的合法编码串）。
输入示例：
8
a:0.04
b:0.22
c:0.06
d:0.18
e:0.21
f:0.12
g:0.08
h:0.09
输入的报文文件in.txt内容如下：
11110001001001001
110100001001100100011000
0010011111100011110101
【输出格式】输入文件out.txt包含m个测试用例，则输出文件对应m行字符串，每行对应一个测试用例的解码结果（由字母构成）。
如上例输入，则输出文件out.txt内容如下：
dacec
heecceba
ecdgbdbb
【实验要求】输入字符的频率之和为1，编码文件中的测试用例均为合法有效的哈夫曼编码。*/
#define _SILENCE_CXX20_STRING_RESERVE_WITHOUT_ARGUMENT_DEPRECATION_WARNING 
#include<iostream>
#include<fstream>
#include<string>
#include<queue>
using namespace std;

struct HFMnode {
	char data;
	double weight;

	int parent;
	int lchild;
	int rchild;

	bool atleft;

	string prgm;

	HFMnode() {
		data = 0;
		weight = 0;
		parent = -1;
		lchild = -1;
		rchild = -1;
		atleft = true;
	}
	HFMnode(char d, double w) {
		data = d;
		weight = w;
		parent = -1;
		lchild = -1;
		rchild = -1;
		atleft = true;
	}
};

HFMnode ht[200];

struct heapNode {
	double weight;
	int label;
	heapNode(double w, int l) {
		label = l;
		weight = w;
	}
	bool operator<(const heapNode& n)const {
		return (weight > n.weight) || ((weight == n.weight)&& (label > n.label));
	}
};
void createHFMtree(int n) {
	priority_queue<heapNode>pq;
	for (int i = 0; i < n; i++) {
		string input;
		cin>>input;

		char tempD = input[0];

		double tempW = stod(input.substr(2));
		ht[i] = HFMnode(tempD, tempW);
		pq.push(heapNode(tempW, i));
	}
	for (int i = n; i < 2 * n - 1; i++) {
		heapNode p1 = pq.top();
		pq.pop();
		heapNode p2 = pq.top();
		pq.pop();

		ht[i] = HFMnode();
		ht[i].weight = ht[p1.label].weight + ht[p2.label].weight;

		ht[p1.label].parent = i;
		ht[p1.label].atleft = true;
		ht[i].lchild = p1.label;

		ht[p2.label].parent = i;
		ht[p2.label].atleft = false;
		ht[i].rchild = p2.label;

		pq.push(heapNode(ht[i].weight, i));
	}
}
void getPrgm(int n) {	
	for (int i = 0; i < n; i++) {
		
		int p = ht[i].parent;	
		string ps;
		if (ht[i].atleft) {
			ps.push_back('0');
		}
		else {
			ps.push_back('1');
		}
		while (p != -1) {
			if (ht[p].parent != -1) {
				if (ht[p].atleft) {
					ps.push_back('0');
				}
				else {
					ps.push_back('1');
				}
			}
			p = ht[p].parent;
		}
		
		for (int j = ps.length() - 1; j  >= 0; j--) {
			ht[i].prgm.push_back(ps[j]);
		}
		
	}
}
void inputBW(int n) {
	ifstream in;
	in.open("in.txt");
	string input;
	string result;

	ofstream out;
	out.open("out.txt");
	while (getline(in, input)) {
		int length = 2;
		int head = 0;
		string temp = input.substr(head, length);
		while ((head + length) <= input.length()) {
			bool find = false;
			while (!find) {
				for (int i = 0; i < n; i++) {
					if (ht[i].prgm == temp) {
						find = true;
						result.push_back(ht[i].data);
						break;
					}
				}
				length++;
				if ((head + length) <= input.length()) {
					temp = input.substr(head, length);
				}
				else {
					break;
				}
			}
			head += length - 1;
			length = 2;
			if ((head + length) <= input.length()) {
				temp = input.substr(head, length);
			}
		}
		out << result << endl;
		result.clear();
	}
}

int main() {
	int n;
	cin >> n;
	createHFMtree(n);
	getPrgm(n);
	inputBW(n);
}