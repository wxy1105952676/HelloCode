/* 
 * @Author: wxy
 * @Date: 2023-02-27 22:05:52
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-27 22:05:53
 * @FilePath: \AcWing\算法基础课\1.基础算法\1.6双指针算法\数组元素的目标和.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+10;

int a[N],b[N];

int main()
{
    int n,m,x;
    cin >> n >> m >> x;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0,j = m - 1; i < n; i ++ ){
        while( j >= 0 && a[i] + b[j] > x) j--;
        if(j >= 0 && a[i] + b[j] == x) cout << i <<' '<< j <<endl;
    }

    return 0;
}