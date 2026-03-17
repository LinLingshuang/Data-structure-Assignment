/*2. P2670 扫雷游戏
题目描述
扫雷游戏是一款十分经典的单机小游戏。在 n 行 m 列的雷区中有一些格子含有地雷（称之为地雷格），
其他格子不含地雷（称之为非地雷格）。玩家翻开一个非地雷格时，该格将会出现一个数字——提示周围格子中有多少个是地雷格。
游戏的目标是在不翻出任何地雷格的条件下，找出所有的非地雷格。

现在给出 n 行 m 列的雷区中的地雷分布，要求计算出每个非地雷格周围的地雷格数。

注：一个格子的周围格子包括其上、下、左、右、左上、右上、左下、右下八个方向上与之直接相邻的格子。

输入格式
第一行是用一个空格隔开的两个整数 n 和 m，分别表示雷区的行数和列数。
接下来 n 行，每行 m 个字符，描述了雷区中的地雷分布情况。字符 * 表示相应格子是地雷格，
字符 ? 表示相应格子是非地雷格。相邻字符之间无分隔符。

输出格式
输出文件包含 n 行，每行 m 个字符，描述整个雷区。用 * 表示地雷格，用周围的地雷个数表示非地雷格。相邻字符之间无分隔符。

输入 #1

3 3
*??
???
?*?
输出 #1

*10 
221 
1*1
输入 #2

2 3 
?*? 
*??
输出 #2

2*1 
*21
对于 100%的数据，1≤n≤100,1≤m≤100。
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct field {
	bool haveBomb;
	int bombNum;


};

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<field>>myfield(n, vector<field>(m));

	vector<string>inputLine(n);
	for (int i = 0; i < n; i++) {
		cin >> inputLine[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inputLine[i][j] == '*') {
				myfield[i][j].haveBomb = true;
			}
			else if (inputLine[i][j] == '?') {
				myfield[i][j].haveBomb = false;
			}
		}
	}

	vector<string>outputLine(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (myfield[i][j].haveBomb) {
				outputLine[i].push_back('*');
			}
			else if (!myfield[i][j].haveBomb) {
				int countBombNum = 0;
				if (i == 0) {
					if (n != 1) {
						if (j == 0) {
							if (m != 1)
							{
								if (myfield[i + 1][j].haveBomb)countBombNum++;
								if (myfield[i][j + 1].haveBomb)countBombNum++;
								if (myfield[i + 1][j + 1].haveBomb)countBombNum++;
								myfield[i][j].bombNum = countBombNum;
							}
							else {
								if (myfield[i + 1][j].haveBomb)countBombNum++;
								myfield[i][j].bombNum = countBombNum;
							}
						}
						else if (j == m - 1) {
							if (myfield[i + 1][j].haveBomb)countBombNum++;
							if (myfield[i][j - 1].haveBomb)countBombNum++;
							if (myfield[i + 1][j - 1].haveBomb)countBombNum++;
							myfield[i][j].bombNum = countBombNum;
						}
						else {
							if (myfield[i + 1][j].haveBomb)countBombNum++;
							if (myfield[i][j + 1].haveBomb)countBombNum++;
							if (myfield[i][j - 1].haveBomb)countBombNum++;
							if (myfield[i + 1][j + 1].haveBomb)countBombNum++;
							if (myfield[i + 1][j - 1].haveBomb)countBombNum++;
							myfield[i][j].bombNum = countBombNum;
						}
					}
					else {
						if (j == 0) {
							if (m != 1)
							{							
								if (myfield[i][j + 1].haveBomb)countBombNum++;						
								myfield[i][j].bombNum = countBombNum;
							}
							else {
								myfield[i][j].bombNum = countBombNum;
							}
						}
						else if (j == m - 1) {
							if (myfield[i][j - 1].haveBomb)countBombNum++;
							myfield[i][j].bombNum = countBombNum;
						}
						else {
							if (myfield[i][j + 1].haveBomb)countBombNum++;
							if (myfield[i][j - 1].haveBomb)countBombNum++;
							myfield[i][j].bombNum = countBombNum;
						}
					}
				}
				else if (i == n-1) {
					if (j == 0) {
						if (m != 1)
						{
							if (myfield[i - 1][j].haveBomb)countBombNum++;
							if (myfield[i][j + 1].haveBomb)countBombNum++;
							if (myfield[i - 1][j + 1].haveBomb)countBombNum++;
							myfield[i][j].bombNum = countBombNum;
						}
						else {
							if (myfield[i - 1][j].haveBomb)countBombNum++;
							myfield[i][j].bombNum = countBombNum;
						}
					}
					else if (j == m - 1) {
						if (myfield[i - 1][j].haveBomb)countBombNum++;
						if (myfield[i][j - 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j - 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}
					else {
						if (myfield[i - 1][j].haveBomb)countBombNum++;
						if (myfield[i][j + 1].haveBomb)countBombNum++;
						if (myfield[i][j - 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j + 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j - 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}
				}
				else {
					if (j == 0) {
						if (m != 1)
						{
							if (myfield[i - 1][j].haveBomb)countBombNum++;
							if (myfield[i + 1][j].haveBomb)countBombNum++;
							if (myfield[i][j + 1].haveBomb)countBombNum++;
							if (myfield[i - 1][j + 1].haveBomb)countBombNum++;
							if (myfield[i + 1][j + 1].haveBomb)countBombNum++;
							myfield[i][j].bombNum = countBombNum;
						}
						else {
							if (myfield[i - 1][j].haveBomb)countBombNum++;
							if (myfield[i + 1][j].haveBomb)countBombNum++;
							myfield[i][j].bombNum = countBombNum;
						}
					}
					else if (j == m - 1) {
						if (myfield[i - 1][j].haveBomb)countBombNum++;
						if (myfield[i + 1][j].haveBomb)countBombNum++;
						if (myfield[i][j - 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j - 1].haveBomb)countBombNum++;
						if (myfield[i + 1][j - 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}
					else {
						if (myfield[i - 1][j].haveBomb)countBombNum++;
						if (myfield[i + 1][j].haveBomb)countBombNum++;
						if (myfield[i][j + 1].haveBomb)countBombNum++;
						if (myfield[i][j - 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j + 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j - 1].haveBomb)countBombNum++;
						if (myfield[i + 1][j + 1].haveBomb)countBombNum++;
						if (myfield[i + 1][j - 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}
				}
				outputLine[i].push_back('0'+countBombNum);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << outputLine[i] << endl;
	}

	

}
/*#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct field {
	bool haveBomb;
	int bombNum;


};

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<field>>myfield(n, vector<field>(m));

	vector<string>inputLine(n);
	for (int i = 0; i < n; i++) {
		cin >> inputLine[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inputLine[i][j] == '*') {
				myfield[i][j].haveBomb = true;
			}
			else if (inputLine[i][j] == '?') {
				myfield[i][j].haveBomb = false;
			}
		}
	}

	vector<string>outputLine(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (myfield[i][j].haveBomb) {
				outputLine[i].push_back('*');
			}
			else if (!myfield[i][j].haveBomb) {
				int countBombNum = 0;
				if (i == 0) {
					if (j == 0) {
						if (myfield[i + 1][j].haveBomb)countBombNum++;
						if (myfield[i][j + 1].haveBomb)countBombNum++;
						if (myfield[i + 1][j + 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum=countBombNum;
					}
					else if (j == m-1) {
						if (myfield[i + 1][j].haveBomb)countBombNum++;
						if (myfield[i][j - 1].haveBomb)countBombNum++;
						if (myfield[i + 1][j - 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}
					else {
						if (myfield[i + 1][j].haveBomb)countBombNum++;
						if (myfield[i][j + 1].haveBomb)countBombNum++;
						if (myfield[i][j - 1].haveBomb)countBombNum++;
						if (myfield[i + 1][j + 1].haveBomb)countBombNum++;
						if (myfield[i + 1][j - 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}

				}
				else if (i == n-1) {
					if (j == 0) {
						if (myfield[i - 1][j].haveBomb)countBombNum++;
						if (myfield[i][j + 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j + 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}
					else if (j == m - 1) {
						if (myfield[i - 1][j].haveBomb)countBombNum++;
						if (myfield[i][j - 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j - 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}
					else {
						if (myfield[i - 1][j].haveBomb)countBombNum++;
						if (myfield[i][j + 1].haveBomb)countBombNum++;
						if (myfield[i][j - 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j + 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j - 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}
				}
				else {
					if (j == 0) {
						if (myfield[i - 1][j].haveBomb)countBombNum++;
						if (myfield[i + 1][j].haveBomb)countBombNum++;
						if (myfield[i][j + 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j + 1].haveBomb)countBombNum++;
						if (myfield[i + 1][j + 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}
					else if (j == m - 1) {
						if (myfield[i - 1][j].haveBomb)countBombNum++;
						if (myfield[i + 1][j].haveBomb)countBombNum++;
						if (myfield[i][j - 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j - 1].haveBomb)countBombNum++;
						if (myfield[i + 1][j - 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}
					else {
						if (myfield[i - 1][j].haveBomb)countBombNum++;
						if (myfield[i + 1][j].haveBomb)countBombNum++;
						if (myfield[i][j + 1].haveBomb)countBombNum++;
						if (myfield[i][j - 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j + 1].haveBomb)countBombNum++;
						if (myfield[i - 1][j - 1].haveBomb)countBombNum++;
						if (myfield[i + 1][j + 1].haveBomb)countBombNum++;
						if (myfield[i + 1][j - 1].haveBomb)countBombNum++;
						myfield[i][j].bombNum = countBombNum;
					}
				}
				outputLine[i].push_back('0'+countBombNum);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << outputLine[i] << endl;
	}

	

}*/