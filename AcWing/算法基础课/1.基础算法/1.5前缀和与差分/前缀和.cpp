/* 
 * @Author: wxy
 * @Date: 2022-12-18 09:31:48
 * @LastEditors: wxy
 * @LastEditTime: 2023-01-03 21:18:28
 * @FilePath: \AcWing\算法基础课\1.基础算法\1.5前缀和与差分\前缀和.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+10;

int n, m;
int a[N], s[N];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];

    while (m -- )
    {
        int l, r;

        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}