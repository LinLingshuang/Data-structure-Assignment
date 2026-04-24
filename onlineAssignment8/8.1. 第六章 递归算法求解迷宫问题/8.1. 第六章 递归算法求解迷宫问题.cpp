/*1. 第六章 递归算法求解迷宫问题
【问题描述】
给定一个二维迷宫矩阵，其中：
0 表示可以通过的路径。
1 表示障碍物，无法通过。
起点为左上角 (0, 0)，终点为右下角 (n-1, m-1)。
请设计一个递归算法，判断是否存在一条从起点到终点的路径。如果存在，输出路径上节点数量；如果不存在，输出 -1。
使用递归深度优先搜索（DFS）来探索迷宫：
1.从起点开始，依次尝试四个方向（上、右、下、左）移动。
2.每次移动时，检查当前位置是否越界或是否为障碍物。
3.如果到达终点，则返回成功，并记录路径。
4.如果所有方向都无法继续前进，则回溯。
【输入形式】
第一行为迷宫的n行m列值，接下来是n*m行的迷宫。
【输出形式】
如果找到迷宫路径，输出路径长度；
如果没有找到路径，输出-1。
【样例输入】
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
0 1 1 1 0
0 0 0 0 0
【样例输出】
13
【样例说明】
5行5列的矩阵，用递归算法按（上、右、下、左）顺时针方向找到路径上节点数量为9。
【评分标准】
【样例说明】
可以使用STL库函数。*/
#include<iostream>
#include<vector>
using namespace std;

struct block {
	int x;
	int y;
	bool canWalk;
	bool haveWalked = false;
};

int solveMaze(vector<vector<block>>maze,int i,int j,int n,int m) {
	if (i == n - 1 && j == m - 1) {
		return 1;
	}
	else {	
		maze[i][j].haveWalked = true;
		if (i - 1 >= 0 && maze[i - 1][j].canWalk && !maze[i - 1][j].haveWalked) {
			maze[i][j].haveWalked = true;
			if (solveMaze(maze, i - 1, j, n, m) != -1) {
				return solveMaze(maze, i - 1, j, n, m) + 1;
			}
		}
		if (j + 1 < m && maze[i][j + 1].canWalk && !maze[i][j + 1].haveWalked) {
			maze[i][j].haveWalked = true;
			if (solveMaze(maze, i, j + 1, n, m) != -1) {
				return solveMaze(maze, i, j + 1, n, m) + 1;
			}
		}
		if (i + 1 < n && maze[i + 1][j].canWalk && !maze[i + 1][j].haveWalked) {
			maze[i][j].haveWalked = true;
			if (solveMaze(maze, i + 1, j, n, m) != -1) {
				return solveMaze(maze, i + 1, j, n, m) + 1;
			}
		}
		if (j - 1 >= 0 && maze[i][j - 1].canWalk && !maze[i][j - 1].haveWalked) {
			maze[i][j].haveWalked = true;
			if (solveMaze(maze, i, j - 1, n, m) != -1) {
				return solveMaze(maze, i, j - 1, n, m) + 1;
			}
		}
		else {
			return -1;
		}
	}
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<block>>maze(n, vector<block>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int blockState;
			cin >> blockState;
			if (blockState == 1) {
				maze[i][j].canWalk = false;
			}
			else {
				maze[i][j].canWalk = true;
			}
		}
	}

	cout << solveMaze(maze, 0, 0, n, m);

}