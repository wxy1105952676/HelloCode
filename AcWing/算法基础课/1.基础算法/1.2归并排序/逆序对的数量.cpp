/* 
 * @Author: wxy
 * @Date: 2022-12-14 15:17:51
 * @LastEditors: wxy
 * @LastEditTime: 2022-12-15 15:07:16
 * @FilePath: \AcWing\算法基础课\1.基础算法\1.2归并排序\逆序对的数量.cpp
 * @Description: 
 * @
 * @Copyright (c) 2022 by Author, All Rights Reserved. 
*/
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 1e6+10;

int p[maxn],t[maxn];
int n;
long long ans = 0;

void merge_sort(int p[], int l,int r)
{
    if(l == r) return;
    int mid = l+r >> 1;
    merge_sort(p,l,mid);
    merge_sort(p,mid+1,r);
    int i = l,j = mid + 1,k = 0;
    
    while( i <= mid && j <=r )
    {
        if(p[i] <= p[j])
        {
            t[k++] = p[i++];
        }else{
            t[k++] = p[j++];
            ans += mid-i+1;
        }
    }
    while(i <= mid) t[k++] = p[i++];
	while(j <= r) t[k++] = p[j++];
	for(int i = l, j = 0; i <= r && j <= k;i++,j++){
		p[i] = t[j];
	}
}


int main()
{
    scanf("%d",&n);

    for(int i = 0; i < n; i++)  scanf("%d",&p[i]);

    merge_sort(p, 0, n-1);

    printf("%lld\n",ans);


    return 0;
}


