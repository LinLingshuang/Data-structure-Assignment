/*16. BST的插入删除查找
BST的插入删除查找
一、问题描述
实现一个二叉搜索树（BST），支持以下操作：

INSERT x：插入元素x，若已存在则忽略

DELETE x：删除元素x，若不存在输出"NOT FOUND"

FIND x：查找元素x，存在输出"YES"，不存在输出"NO"

MIN：输出最小值，树空输出"EMPTY"

MAX：输出最大值，树空输出"EMPTY"

二、输入形式
第一行输入一个正整数m（1 ≤ m ≤ 100000），表示操作数量。
接下来m行，每行一个操作，格式如上所述。

三、输出形式
对于需要输出的操作，输出对应的结果，每行一个。

四、样例输入

10
INSERT 5
INSERT 3
INSERT 7
FIND 3
FIND 4
MIN
MAX
DELETE 3
FIND 3
MIN
五、样例输出

YES
NO
3
7
NO
5
六、样例说明
操作过程：

插入5,3,7，树结构：

  5
 / \
3   7
FIND 3：存在，输出YES

FIND 4：不存在，输出NO

MIN：最小值3

MAX：最大值7

DELETE 3：删除3

FIND 3：不存在，输出NO

MIN：最小值变为5

七、评分标准
共8个测试用例。

八、类库使用要求
必须手动实现BST结构。*/