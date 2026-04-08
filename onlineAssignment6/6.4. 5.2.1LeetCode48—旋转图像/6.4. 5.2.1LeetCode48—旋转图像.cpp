/*4. 5.2.1LeetCode48—旋转图像
【问题描述】
   给定一个n×n的二维矩阵表示一个图像。将图像顺时针旋转90度。你必须在原地旋转图像，
   这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。例如，
   给定matrix={{1，2，3}，{4，5，6}，{7，8，9}}，原地旋转输入矩阵，使其变为{{7，4，1}，{8，5，2}，{9，6，3}}。
【输入形式】
    每个测试用例的第一行为n（1≤n≤800），接下来n行每行n个整数，表示矩阵a，第i行的第j个整数为aij（-10^8≤aij≤10^8）
【输出形式】对于每个测试用例，输出n行每行n个整数表示矩阵旋转之后的结果。
【样例输入】
4
5 1 9 11
2 4 8 10
13 3 6 7
15 14 12 16
【样例输出】
15 13 2 5
14 3 4 1
12 6 8 9
16 7 10 11
【样例说明】
     测试数据的文件名为in.txt
【评分标准】
    该题目有10个测试用例，每通过一个测试用例，得10分。*/
#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream input;
    input.open("in.txt");
    int n;
    input >> n;
   // cin >> n;
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> matrix[i][j];
          //  cin >> matrix[i][j];
        }
    }
    input.close();
    for (int j = 0; j < n; j++) {
        for (int i = n-1; i >= 0; i--) {
            cout << matrix[i][j]<<' ';
        }
        cout << endl;
    }
}