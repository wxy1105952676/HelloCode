/* 
 * @Author: wxy
 * @Date: 2024-01-26 15:51:35
 * @LastEditors: wxy
 * @LastEditTime: 2024-01-26 15:53:59
 * @FilePath: \HelloCode\晴问\第 2 章 C&C++快速入门\2.3选择结构\选择结构.cpp
 * @Description: 
 * @
 * @Copyright (c) 2024 by Author, All Rights Reserved. 
*/

//* if else
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    if (n % 2) {
        printf("Odd Number");
    } else {
        printf("Even Number");
    }
    return 0;
}
//* if 嵌套
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    if (n < 0) {
        printf("Negative Number");
    } else {
        if (n % 2) {
            printf("Odd Number");
        } else {
            printf("Even Number");
        }
    }
    return 0;
}
//* switch
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    switch (n) {
        case 0:
            printf("Zero");
            break;
        case 1:
            printf("One");
            break;
        case 2:
            printf("Two");
            break;
        case 3:
            printf("Three");
            break;
        case 4:
            printf("Four");
            break;
        case 5:
            printf("Five");
            break;
        default:
            printf("Greater than 5");
    }
    return 0;
}