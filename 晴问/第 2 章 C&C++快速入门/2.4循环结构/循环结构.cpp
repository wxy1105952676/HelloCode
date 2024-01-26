/* 
 * @Author: wxy
 * @Date: 2024-01-26 15:57:11
 * @LastEditors: wxy
 * @LastEditTime: 2024-01-26 15:57:33
 * @FilePath: \HelloCode\晴问\第 2 章 C&C++快速入门\2.4循环结构\循环结构.cpp
 * @Description: 太基础啦 过过过
 * @
 * @Copyright (c) 2024 by Author, All Rights Reserved. 
*/
#include <cstdio>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    printf("%d", sum);
    return 0;
}

#include <cstdio>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum += i;
        if (sum > 2000) {
            break;
        }
    }
    printf("%d", sum);
    return 0;
}

#include <cstdio>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) {
            continue;
        }
        sum += i;
    }
    printf("%d", sum);
    return 0;
}
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", j);
            printf(j < n ? " " : "\n");
        }
    }
    return 0;
}
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
            printf(j < i ? " " : "\n");
        }
    }
    return 0;
}
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            printf("%d", j);
            printf(j < n - i + 1 ? " " : "\n");
        }
    }
    return 0;
}