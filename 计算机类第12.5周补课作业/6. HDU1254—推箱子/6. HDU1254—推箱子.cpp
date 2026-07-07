/*6. HDU1254—推箱子
【问题描述】
推箱子是一个很经典的游戏，今天我们来玩一个简单版本。
在一个n×m的房间里有一个箱子和一个搬运工，搬运工的工作就是把箱子推到指定的位置。
注意，搬运工只能推箱子而不能拉箱子，因此如果箱子被推到一个角上（如下图所示），
那么箱子就不能再被移动了，如果箱子被推到一面墙上，那么箱子只能沿着墙移动。
现在给定房间的结构，箱子的位置，搬运工的位置和箱子要被推去的位置，请你计算出搬运工至少要推动箱子多少格。
blog.png
【输入形式】
 输入数据的第一行是两个正整数n和m（2≤n，m≤7），代表房间的大小，
 然后是一个n行m列的矩阵，代表房间的布局，其中0代表空的地板，1代表墙，
 2代表箱子的起始位置，3代表箱子要被推去的位置，4代表搬运工的起始位置。
【输出形式】
对于每组测试数据，输出搬运工最少需要推动箱子多少格才能将箱子推到指定位置，如果不能推到指定位置则输出-1。
【样例输入】
5 5
0 3 0 0 0
1 0 1 4 0
0 0 1 0 0
1 0 2 0 0
0 0 0 0 0
【样例输出】
 4
【样例说明】
对于输入的房间布局和箱子、搬运工起始位置，搬运工最少需要推动箱子4格才能将箱子推到指定位置。测试数据存放在in.txt文件中。
【评分标准】
共10个测试用例，每通过一个测试得10分。
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

bool canWalkTo(pair<int, int>start, pair<int, int>end, vector<vector<int>>map, vector<vector<int>>haveWalk) {
	vector<vector<int>>nexthaveWalk = haveWalk;
	nexthaveWalk[start.second][start.first] = 1;
	if (start == end) {
		return true;
	}
	else {
		bool result = false;
		
		if (!(start.first - 1 < 0 )&&!(map[start.second][start.first - 1] == 1) && !(map[start.second][start.first - 1] == 2) && !(haveWalk[start.second][start.first - 1] == 1)) {
			pair<int, int>nextstart; nextstart.second = start.second; nextstart.first = start.first - 1;
			if (canWalkTo(nextstart, end, map, nexthaveWalk))result = true;
		}
		
		if ( !(start.first + 1 >= map[0].size()) && !(map[start.second][start.first + 1] == 1) && !(map[start.second][start.first + 1] == 2) && !(haveWalk[start.second][start.first + 1] == 1)) {
			pair<int, int>nextstart; nextstart.second = start.second; nextstart.first = start.first + 1;
			if (canWalkTo(nextstart, end, map, nexthaveWalk))result = true;
		}
	
		if ( !(start.second - 1 < 0) && !(map[start.second - 1][start.first] == 1) && !(map[start.second - 1][start.first] == 2) && !(haveWalk[start.second-1][start.first] == 1)) {
			pair<int, int>nextstart; nextstart.second = start.second-1; nextstart.first = start.first;
			if (canWalkTo(nextstart, end, map, nexthaveWalk))result = true;
		}
	
		if ( !(start.second + 1 >= map.size()) && !(map[start.second + 1][start.first] == 1) && !(map[start.second + 1][start.first] == 2) && !(haveWalk[start.second+1][start.first] == 1)) {
			pair<int, int>nextstart; nextstart.second = start.second+1; nextstart.first = start.first;
			if (canWalkTo(nextstart, end, map, nexthaveWalk))result = true;
		}
		return result;
	}
}

int boxMove(pair<int, int>start, pair<int, int>end,pair<int,int>manPosition, vector<vector<int>>map, vector<vector<int>>haveWalk) {
	vector<vector<int>>nexthaveWalk = haveWalk;
	vector<vector<int>>manhaveWalk = map;
	vector<vector<int>>newMap = map;
	nexthaveWalk[start.second][start.first] = 1;
	newMap[start.second][start.first] = 0;
	if (start == end) {
		return 0;
	}
	else {
		int result = -1;
		if (!(start.first - 1 < 0) && !(map[start.second][start.first - 1] == 1) && !(haveWalk[start.second][start.first - 1] == 1)) {
			pair<int, int>nextmanPosition; nextmanPosition.second = start.second; nextmanPosition.first = start.first + 1;		
			if (!(start.first + 1 >= map[0].size()) && canWalkTo(manPosition, nextmanPosition, map, manhaveWalk)) {
				newMap[start.second][start.first - 1] = 1;
				pair<int, int>nextstart; nextstart.second = start.second; nextstart.first = start.first - 1;
				int temp= boxMove(nextstart, end, nextmanPosition, newMap, nexthaveWalk);
				if (temp != -1 && (result==-1||temp+1 < result))result = temp+1;
				newMap[start.second][start.first - 1] = 0;
			}
		}
		if (!(start.first + 1 >= map[0].size() ) && !(map[start.second][start.first + 1] == 1 ) && !(haveWalk[start.second][start.first + 1] == 1)) {
			pair<int, int>nextmanPosition; nextmanPosition.second = start.second; nextmanPosition.first = start.first - 1;
			if (!(start.first - 1 < 0) && canWalkTo(manPosition, nextmanPosition, map, manhaveWalk)) {
				newMap[start.second][start.first + 1] = 1;
				pair<int, int>nextstart; nextstart.second = start.second; nextstart.first = start.first + 1;
				int temp = boxMove(nextstart, end, nextmanPosition, newMap, nexthaveWalk);
				if (temp != -1 && (result == -1 || temp + 1 < result))result = temp + 1;
				newMap[start.second][start.first + 1] = 0;
			}
		}
		if (!(start.second - 1 < 0 ) && !(map[start.second - 1][start.first] == 1 ) && !(haveWalk[start.second-1][start.first] == 1)) {
			pair<int, int>nextmanPosition; nextmanPosition.second = start.second+1; nextmanPosition.first = start.first;
			if (!(start.second + 1 >= map.size()) && canWalkTo(manPosition, nextmanPosition, map, manhaveWalk)) {
				newMap[start.second-1][start.first] = 1;
				pair<int, int>nextstart; nextstart.second = start.second - 1; nextstart.first = start.first;
				int temp = boxMove(nextstart, end, nextmanPosition, newMap, nexthaveWalk);
				if (temp != -1 && (result == -1 || temp + 1 < result))result = temp + 1;
				newMap[start.second - 1][start.first] = 0;
			}
		}
		if (!(start.second + 1 >= map.size() ) && !(map[start.second + 1][start.first] == 1) && !(haveWalk[start.second+1][start.first] == 1)) {
			pair<int, int>nextmanPosition; nextmanPosition.second = start.second - 1; nextmanPosition.first = start.first;
			if (!(start.second - 1 < 0) && canWalkTo(manPosition, nextmanPosition, map, manhaveWalk)) {
				newMap[start.second + 1][start.first] = 1;
				pair<int, int>nextstart; nextstart.second = start.second + 1; nextstart.first = start.first;
				int temp = boxMove(nextstart, end, nextmanPosition, newMap, nexthaveWalk);
				if (temp != -1 && (result == -1 || temp + 1 < result))result = temp + 1;
				newMap[start.second + 1][start.first] = 0;
			}
		}
		return result;
	}
}


int main() {
	int n,m;
	ifstream in;
	in.open("in.txt");
	cin >> n >> m;

	int endX, endY;
	int boxX, boxY;
	int manX, manY;

	vector<vector<int>>map(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
			if (temp == 3) {
				endX = j; endY = i;
			}
			else if (temp == 2) {
				boxX = j; boxY = i;
			}
			else if (temp == 4) {
				manX = j; manY = i;
			}
		}
	}
	cout << boxMove(pair<int, int>(boxX, boxY), pair<int, int>(endX, endY), pair<int, int>(manX, manY), map, map);
}