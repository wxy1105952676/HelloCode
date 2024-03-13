/*
 * @Author: wxy
 * @Date: 2023-02-27 20:54:48
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-27 21:56:59
 * @FilePath:
 * \AcWing\算法基础课\1.基础算法\1.6双指针算法\最长连续不重复子序列.cpp
 * @Description:
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved.
 */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int s[N], q[N];
int res;
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> q[i];

    for (int i = 0, j = 0; i < n; i++)
    {
        s[q[i]]++;
        while (j < i && s[q[i]] > 1)
            s[q[j++]]--;
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}