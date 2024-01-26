/* 
 * @Author: wxy
 * @Date: 2022-12-14 14:20:58
 * @LastEditors: wxy
 * @LastEditTime: 2022-12-14 14:37:00
 * @FilePath: \AcWing\算法基础课\1.基础算法\1.1快速排序\第k个数.cpp
 * @Description: 
 * @
 * @Copyright (c) 2022 by Author, All Rights Reserved. 
*/

/*
1.找到分界点x,q[L],q[(L+R)/2],q[R]
2.左边所以数Left <= x, 右边数Right >= x
3.递归排序Left,递归排序Right
*/

//ACWing P786  第k个数 快速选择 O(n)
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;

int n,k;
int q[N];

int quick_sort(int l,int r,int k)
{
    if(l == r) return q[l];

    int x = q[l],i = l - 1,j = r + 1;
    while(i<j)
    {
        while(q[++i] < x);
        while(q[--j] > x);
        if(i < j) swap(q[i],q[j]);
    } 

    int sl = j - l + 1;
    if(k <= sl)return quick_sort( l, j, k);

    return quick_sort(j+1, r , k - sl);
}

int main()
{
    scanf("%d%d",&n,&k);

    for(int i = 0; i < n; i++) scanf("%d",&q[i]);

    printf("%d\n",quick_sort(0, n - 1, k));

    return 0;
}
