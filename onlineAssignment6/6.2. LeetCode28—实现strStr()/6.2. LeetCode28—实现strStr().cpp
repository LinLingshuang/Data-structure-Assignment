/*2. LeetCode28—实现strStr()
【问题描述】
给定一个s字符串和一个t字符串，在s字符串中找出t字符串出现的第一个位置（从0开始），
如果不存在则返回-1。例如，输入s="hello"，t="ll"，输出结果为2。设计如下成员函数：
class Solution {
public:
 int strStr(string s, string t)
 {  …  }
};
【输入形式】
     输入两个字符串，先输入的为s串，后输入的为t串。字符串中允许出现空格符。
【输出形式】
     t串在s串中出现的第一个位置。若t串不在s串中，则返回-1。
【样例输入】
    hello
    ll
【样例输出】
    2
【样例说明】
   s串为“hello”，t串为“ll”，t串在s串中第一次出现的位置为2（从0开始计数）。测试数据存放在in.txt文件中。
【评分标准】
  共10个测试用例，每通过一个测试得10分。*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Solution {
public:
    int strStr(string s, string t) {
        int result = -1;
        bool yes = false;
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!yes) {
                if (s[i] == t[j]) {
                    yes = true;
                    result = i;
                    j++;
                }
            }
            else {
                if (s[i] == t[j]) {                
                    j++;
                }
                else {
                    i -= j;
                    j = 0;
                    result = -1;
                    yes = false;
                }
            }
            if (j == t.length()) {
                break;
            }
        }
        if (j != t.length()) {
            return -1;
        }
        return result;
    }
};

int main() {
    string s, t;
    fstream input;
    input.open("in.txt");
    getline(input, s);
    getline(input, t);
    input.close();
    //cout << s << endl << t << endl;
    Solution wtf;
    cout << wtf.strStr(s, t);

}
