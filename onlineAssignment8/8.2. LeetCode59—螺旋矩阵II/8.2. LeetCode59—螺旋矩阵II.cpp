/*2. LeetCode59—螺旋矩阵II
【问题描述】
给定一个正整数n，生成一个包含1到n^2所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
要求设计如下函数：
class Solution{
public:
 vector<vector<int>> generateMatrix(int n)
 {  …   }
};
【输入形式】
输入一个正整数n。
【输出形式】 
输出一个正方形矩阵，其中元素按顺时针顺序螺旋排列，元素的值为1~n^2之间的正整数。
【样例输入】
     3
【样例输出】[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
【样例说明】 
输入一个正整数3，输出元素值为1~9的3×3方阵，其元素按顺时针顺序螺旋排列。测试数据存放在in.txt文件中。
【评分标准】
共10个测试用例，每通过一个测试得10分。*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>>result(n, vector<int>(n));
        int data = 1;
        int i = n;
        int j = n;
        int state = 1;
        while (!(i == 0 && j == 0)) {
            if (state == 1) {
                for (int k = 0 + (n - j) / 2; k < 0 + (n - j) / 2 + j; k++) {
                    result[0 + (n - i) / 2][k] = data;
                    data++;
                }
                i--;
                state = 2;
            }
            else if (state == 2) {
                for (int k = 0 + (n - i + 1) / 2; k < 0 + (n - i + 1) / 2 + i; k++) {
                    result[k][n - 1 - (n - j) / 2] = data;
                    data++;
                }
                j--;
                state = 3;
            }
            else if (state == 3) {
                for (int k = n - 1 - (n - j + 1) / 2; k > n - 1 - (n - j + 1) / 2 - j; k--) {
                    result[n - 1 - (n - i - 1) / 2][k] = data;
                    data++;
                }
                i--;
                state = 4;
            }
            else if (state == 4) {
                for (int k = n - 1 - (n - i) / 2; k > n - 1 - (n - i) / 2 - i; k--) {
                    result[k][0 + (n - j - 1) / 2] = data;
                    data++;
                }
                j--;
                state = 1;
            }
        }
        return result;
    }
};

int main() {
    Solution mySolution;
    fstream in;
    in.open("in.txt");
    int n;
    cin >> n;
    in >> n;
    vector<vector<int>>matrix = mySolution.generateMatrix(n);
    cout << '[' << endl;
    for (int i = 0; i < n; i++) {
        cout << '[';
        for (int j = 0; j < n; j++) {
            cout << ' ' << matrix[i][j];
            if (j != n - 1) {
                cout << ',';
            }
        }
        cout << ' ' << ']';
        if (i != n - 1) {
            cout << ',';
        }
        cout << endl;
    }
    cout << ']';
}