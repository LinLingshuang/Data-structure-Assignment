//3. 用栈实现队列
//用栈实现队列
//一、问题描述
//仅使用两个栈实现队列的功能，支持以下操作：
//ENQUEUE x：将元素x加入队尾
//DEQUEUE：移除队头元素，队空时输出"EMPTY"
//PEEK：查看队头元素，队空时输出"EMPTY"
//要求：所有操作的均摊时间复杂度为O(1)。
//二、输入形式
//第一行输入一个正整数m（1 ≤ m ≤ 100000），表示操作数量。
//接下来m行，每行一个操作，格式如上所述。
//三、输出形式
//对于DEQUEUE、PEEK操作，输出对应的值或错误信息，每行一个。
//四、样例输入
//6
//ENQUEUE 1
//ENQUEUE 2
//PEEK
//DEQUEUE
//ENQUEUE 3
//DEQUEUE
//五、样例输出
//1
//1
//2
//六、样例说明
//使用两个栈：stackIn（入队栈）和stackOut（出队栈）
//ENQUEUE：直接压入stackIn
//DEQUEUE / PEEK：如果stackOut为空，将stackIn所有元素倒入stackOut，然后从stackOut弹出 / 查看
//操作过程：
//ENQUEUE 1：stackIn = [1]
//ENQUEUE 2：stackIn = [1, 2]
//PEEK：stackOut为空，倒入后stackOut = [2, 1]，查看栈顶1
//DEQUEUE：弹出stackOut栈顶1，输出1
//ENQUEUE 3：stackIn = [3]
//DEQUEUE：stackOut = [2]，弹出2
//七、评分标准
//共8个测试用例。
//八、类库使用要求
//只能使用两个栈（可以手动实现或使用STL stack），禁止使用队列。
#include<iostream>
using namespace std;

int main() {


}