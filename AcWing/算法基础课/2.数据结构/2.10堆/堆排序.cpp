/* 
 * @Author: wxy
 * @Date: 2023-03-02 10:11:04
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-02 19:26:37
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.10堆\堆排序.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+10;

int n,m,cnt;
int h[N];

void down(int u)
{
    int t = u;
    if(u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if(u != t)
    {
        swap(h[u],h[t]);
        down(t);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    
    
    for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
    cnt = n;
    
    for (int i = n/2; i; i -- ) down(i);
    
    while (m -- )
    {
        printf("%d ",h[1]);
        h[1] = h[cnt];
        cnt--;
        down(1);
    }
    
    return 0;
}