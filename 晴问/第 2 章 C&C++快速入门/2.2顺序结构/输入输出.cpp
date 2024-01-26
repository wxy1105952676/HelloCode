/* 
 * @Author: wxy
 * @Date: 2024-01-26 15:34:31
 * @LastEditors: wxy
 * @LastEditTime: 2024-01-26 15:47:50
 * @FilePath: \HelloCode\晴问\第 2 章 C&C++快速入门\2.2顺序结构\输入输出.cpp
 * @Description: 
 * @
 * @Copyright (c) 2024 by Author, All Rights Reserved. 
*/

//* 整型输入输出
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", n);
    return 0;
}
//* 长整型输入输出
#include <cstdio>

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld", n);
    return 0;
}
//* 浮点型输入输出
#include <cstdio>

int main() {
    double d;
    scanf("%lf", &d);
    printf("%.2f", d);
    return 0;
}
//* 字符型输入输出 换行符\n
#include <cstdio>

int main() {
    char c;
    scanf("%c", &c);
    printf("%c", c);
    return 0;
}
//* 强制类型转换
#include <cstdio>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n%.2f", a / b, (double)a / b);
    return 0;
}
//* 定义常量
#include <cstdio>

const double PI = 3.14;

int main() {
    double r;
    scanf("%lf", &r);
    printf("%.2f", 2 * PI * r);
    return 0;
}
//* 自增运算符
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    n++;
    printf("%d", n);
    return 0;
}
//* 条件运算符
#include <cstdio>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf(a >= b ? "A >= B" : "A < B");
    return 0;
}
//* 日期时间输入输出I
#include <cstdio>

int main() {
    int yyyy, mm, dd, hh, mi, ss;
    scanf("%d-%d-%d %d:%d:%d", &yyyy, &mm, &dd, &hh, &mi, &ss);
    printf("%d\n%d\n%d\n%d\n%d\n%d", yyyy, mm, dd, hh, mi, ss);
    return 0;
}
//* 日期时间输入输出II
#include <cstdio>
#include <string>
using namespace std;

string fillPrefixZero(int n) {
    if (n > 10) {
        return to_string(n);
    } else {
        return "0" + to_string(n);
    }
}

int main() {
    int yyyy, mm, dd, hh, mi, ss;
    scanf("%d-%d-%d %d:%d:%d", &yyyy, &mm, &dd, &hh, &mi, &ss);
    printf("%s\n", to_string(yyyy).c_str());
    printf("%s\n", fillPrefixZero(mm).c_str());
    printf("%s\n", fillPrefixZero(dd).c_str());
    printf("%s\n", fillPrefixZero(hh).c_str());
    printf("%s\n", fillPrefixZero(mi).c_str());
    printf("%s", fillPrefixZero(ss).c_str());
    return 0;
}
//* getchar函数
#include <cstdio>

int main() {
    int n;
    char c;
    scanf("%d", &n);
    getchar();
    c = getchar();
    printf("%d\n%c", n + 1, c);
    return 0;
}
/*
//* 数学函数系列I
  * 数学函数都在cmath头文件下，以下是本题涉及的常见数学函数，它们都接收浮点型，返回的也是浮点型。
  
  * fabs(a)：a的绝对值
  * floor(a)：a的向下取整
  * ceil(a)：a的向上取整
  * round(a)：a的四舍五入（实际是四舍六入五成双）
  * pow(a, b)：a的b次方，其中b也可以是浮点型
  * 最后输出时按题目要求用%.2f或者%.0f格式输出即可。
*/
#include <cstdio>
#include <cmath>

int main() {
    double d;
    scanf("%lf", &d);
    printf("%.2f %.0f %.0f %.0f %.2f", fabs(d), floor(d), ceil(d), round(d), pow(d, 5));
    return 0;
}
/*
//* 数学函数系列II
* 数学函数都在cmath头文件下，以下是本题涉及的常见数学函数，它们都接收浮点型，返回的也是浮点型。
*  sqrt(a)：a的算术平方根（即开根号）
*  log(a)： a的以自然对数e为底的对数
*  最后输出时按题目要求用%.2f格式输出即可。
*/

#include <cstdio>
#include <cmath>

int main() {
    double d;
    scanf("%lf", &d);
    printf("%.2f %.2f", sqrt(d), log(d));
    return 0;
}


