/*1. 2026春(1)第1题：链表实现联接运算（A班）
【问题描述】
给定两个存储整数（或字母）的二维表R（m₁行n₁列）和S（m₂行n₂列），基于单向链表实现二者的大于连接运算：
（1）大于连接规则：C=R⋈i>jS（R的第i列与S的第j列）；
（2）运算逻辑：先求R和S的笛卡尔积，再筛选出“R的第i列值>S的第j列值”的所有元组，最终结果构成二维表C。
【实验要求】
（1）数据存储：必须采用单向链表存储二维表的行/列数据（如每行数据为一个链表结点，一张表对应链表所有结点）。
（2）运算实现：大于连接的核心逻辑（笛卡尔积生成、大于筛选）需基于链表操作完成，禁止使用数组/容器等替代。
（3）结果要求：输出的结果表C需保留符合条件的所有元组，无冗余数据，行数≤m₁×m₂。
【输入格式】 in.txt文件输入多组数据（文件非空）
第一行测试用例个数k, 第二行：第一个样例数据类型（int或者char）。
第三行：两个整数m? 、n?，空格分隔，表示二维表R的行数和列数。
接下来m?行：每行n?个（或字母）整数，空格分隔，表示R的每行数据。

随后一行：两个整数m? 、 n? ，空格分隔，表示二维表S的行数和列。
接下来m?行：每行n?个整数（或字母），空格分隔，表示S的每行数据。

再一行：两个正整数i、j，空格分隔，表示大于连接的列号（i为R的列号，j为S的列号，列号从1开始计数）。重复K个测试用例。

保证有K个样例，每个二维表类型正确后续正确，但是不保证联接列号符合要求。
【样例输入】文件in.txt内容：
 4
char
3 2
a b
c b
e c
2 2
x y
b h
2 1
int
3 3
1 2 3
2 3 6
4 5 7
2 4
3 6 9 7
5 7 8 6
3 2
int
3 3
1 2 4
3 4 3
20 45 12
2 2
10 20
30 40
1 5
float
3 4
【输出格式】输出到文件out.txt
输出in.txt文件中大于联接运算结果表的所有元组，格式要求：
（1）每行包含n₁+n₂个整数（或字母），空格分隔（为R的一行数据拼接S的一行数据）。
（2）行顺序与笛卡尔积筛选结果一致，行数≤m₁×m₂（无符合条件的元组时无输出）。
（3）每个样例结果之间空一行。
【样例输出】
 对于上述in.txt输入，输出out.txt ：
第1个char样例:
e c b h
第2个int样例:
4 5 7 3 6 9 7
第3个int样例:
列号超出范围!
第4个float样例:
未知的数据类型: float
【评分标准】
要使用链表实现，否则不能得分。*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

template<class T> 
struct node {
	T data;
	node* next;
	node<T>(T val) {
		data = val;
		next = NULL;
	}
};

template<class T>
class list {
public:
	node<T>* head;
	int row, col;
	list<T>(int r, int c) {
		row = r;
		col = c;
		head = new node<T>(NULL);
	}
	list<T>() {
		row = 0;
		col = 0;
		head = new node<T>(NULL);
	}
	list<T>(const list<T>&l) {
		row = l.row;
		col = l.col;
		head = l.head;
	}

};
template<class T>
list<T> DKR(list<T> R,list<T> S) {
	list<T> Result=list<T>(R.row*S.row,R.col+S.col);
	node<T>* p = Result.head;
	node<T>* r = R.head;
	node<T>* s = S.head;
	for (int i = 0; i < R.row; i++) {
		node<T>* tempS = s;
		for (int j = 0; j < S.row; j++) {
			node<T>* tempR = r;
			for (int rc = 0; rc < R.col; rc++) {
				p->next = new node<T>(tempR->next->data);
				p = p->next;
				tempR = tempR->next;
			}

			for (int sc = 0; sc < S.col; sc++) {
				p->next = new node<T>(tempS->next->data);
				p = p->next;
				tempS = tempS->next;
			}
		}
		for (int rc = 0; rc < R.col; rc++) {
			r = r->next;
		}
	}
	return Result;
}


int main() {
	ifstream in;
	in.open("in.txt");
	int k;
	in >> k;
	cin >> k;

	ofstream out;
	out.open("out.txt");

	for (int i = 0; i < k; i++) {
		string inputClass;
		in >> inputClass;
		cin >> inputClass;
		if (inputClass == "int") {
			out<<"第"<< i+1 << "个int样例:" << endl;
			cout << "第" << i + 1 << "个int样例:" << endl;
			int col1, col2;
			list<int> myIntListR;
			list<int> myIntListS;
			for (int t = 0; t < 2; t++) {
				int row, col;
				in >> row >> col;
				cin >> row >> col;
				node<int>* p;
				if (t == 0) {
					col1 = col;
					myIntListR = list<int>(row, col);
					p = myIntListR.head;
				}
				else {
					col2 = col;
					myIntListS = list<int>(row, col);
					p = myIntListS.head;
				}
				for (int r = 0; r < row; r++) {
					for (int c = 0; c < col; c++) {
						int inputNum;
						in >> inputNum;
						cin >> inputNum;
						p->next = new node<int>(inputNum);
						p = p->next;
					}
				}
			}
			int Rcol, Scol;
			in >> Rcol >> Scol;
			cin >> Rcol >> Scol;
			if (Rcol > col1 || Scol > col2) {
				out << "列号超出范围!" << endl;
				cout << "列号超出范围!" << endl;
				continue;
			}
			list<int>Result = DKR<int>(myIntListR, myIntListS);
			node<int>* Resultp = Result.head;
			for (int er = 0; er < Result.row; er++) {
				node<int>* temp = Resultp;
				int check = 1;
				int Rcheck=0, Scheck=0;
				for (int ec = 0; ec < Result.col; ec++) {
					if (check == Rcol) {
						Rcheck = Resultp->next->data;
					}
					else if (check == col1 + Scol) {
						Scheck = Resultp->next->data;
					}
					Resultp = Resultp->next;
					check++;
				}
				if (Rcheck > Scheck) {
					for (int ee = 0; ee < Result.col; ee++) {
						out << temp->next->data << ' ';
						cout << temp->next->data << ' ';
						temp = temp->next;
					}
					out << endl;
					cout << endl;
				}
			}
			out << endl;
			cout << endl;
		}
		else if (inputClass == "char") {
			list<char>myCharListR;
			list<char>myCharListS;
			out << "第" << i + 1 << "个char样例:" << endl;
			cout << "第" << i + 1 << "个char样例:" << endl;
			int col1, col2;
			for (int t = 0; t < 2; t++) {
				int row, col;
				in >> row >> col;
				cin >> row >> col;
				node<char>* p;
				if (t == 0) {
					col1 = col;
					myCharListR = list<char>(row, col);
					p = myCharListR.head;
				}
				else {
					col2 = col;
					myCharListS = list<char>(row, col);
					p = myCharListS.head;
				}
				for (int r = 0; r < row; r++) {
					for (int c = 0; c < col; c++) {
						char inputChar;
						in >> inputChar;
						cin >> inputChar;
						p->next = new node<char>(inputChar);
						p = p->next;
					}
				}
			}
			int Rcol, Scol;
			in >> Rcol >> Scol;
			cin >> Rcol >> Scol;
			if (Rcol > col1 || Scol > col2) {
				out << "列号超出范围!" << endl;
				cout << "列号超出范围!" << endl;
				continue;
			}
			list<char>Result = DKR<char>(myCharListR, myCharListS);
			node<char>* Resultp = Result.head;
			for (int er = 0; er < Result.row; er++) {
				node<char>* temp = Resultp;
				int check = 1;
				char Rcheck = '0', Scheck = '0';
				for (int ec = 0; ec < Result.col; ec++) {
					if (check == Rcol) {
						Rcheck = Resultp->next->data;
					}
					else if (check == col1 + Scol) {
						Scheck = Resultp->next->data;
					}
					Resultp = Resultp->next;
					check++;
				}
				if (Rcheck > Scheck) {
					for (int ee = 0; ee < Result.col; ee++) {
						out << temp->next->data << ' ';
						cout << temp->next->data << ' ';
						temp = temp->next;
					}
					out << endl;
					cout << endl;
				}
			}
			out << endl;
			cout << endl;
		}
		else {
			out << "第" << i + 1 << "个"<< inputClass <<"样例:" << endl;
			out << "未知的数据类型: " << inputClass << endl;
			cout << "第" << i + 1 << "个" << inputClass << "样例:" << endl;
			cout << "未知的数据类型: " << inputClass << endl;
		}
	}
}