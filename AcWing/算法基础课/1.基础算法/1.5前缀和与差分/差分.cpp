/* 
 * @Author: wxy
 * @Date: 2023-02-27 20:02:20
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-27 20:03:48
 * @FilePath: \AcWing\算法基础课\1.基础算法\1.5前缀和与差分\差分.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5+10;

int a[N],b[N];

void insert(int l,int r,int c)
{
    b[l] += c;
    b[r+1] -=c;
}

int main()
{

    int n,m;
    scanf("%d%d",&n,&m);

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) insert(i,i,a[i]);

    while(m--)
    {
        int l,r,c;
        cin >> l >> r >> c;
        insert(l,r,c);
    }

    for(int i = 1; i <= n; i++) b[i] += b[i-1];

    for(int i = 1; i <= n; i++) printf("%d ",b[i]);

    return 0;
}