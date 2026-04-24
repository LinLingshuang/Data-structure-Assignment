/*3. 5.2.3HDU1559—最大子矩阵
【问题描述】
给你一个m×n的整数矩阵，在上面找一个x×y的子矩阵，使子矩阵中所有元素的和最大。
【输入形式】
 每一组测试数据的第一行为4个正整数m，n，x，y（0<m，n<1000，0<x≤m，0<y≤n），
 表示给定的矩形有m行n列。接下来这个矩阵，有m行，每行有n个不大于1000的正整数。
【输出形式】
对于每组数据，输出一个整数，表示子矩阵的最大和。
【样例输入】
  4 5 2 2
  3 361 649 676 588
  992 762 156 993 169
  662 34 638 89 543
  525 165 254 809 280
【样例输出】
    2474
【样例说明】
 测试数据的文件名为in.txt
【评分标准】
 该题目有10个测试用例，每通过一个测试用例，得10分。
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
    fstream in;
    in.open("in.txt");
    int m, n;
    cin >> m >> n;
    in >> m >> n;

    int x, y;
    cin >> x >> y;
    in >> x >> y;

    vector<vector<int>>matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            in >> matrix[i][j];
        }
    }
    int max = 0;
    for (int i = 0; i <= m - x; i++) {
        for (int j = 0; j <= n - y; j++) {
            int tempSum = 0;
            for (int ii = i; ii < i + x; ii++) {
                for (int jj = j; jj < j + y; jj++) {
                    tempSum += matrix[ii][jj];
                }
            }
            if (tempSum > max) {
                max = tempSum;
            }
        }
    }
    cout << max;

}