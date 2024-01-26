/* 
 * @Author: wxy
 * @Date: 2023-02-28 20:01:33
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-28 20:02:25
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.6单调队列\滑动窗口.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
/*
1.ST表
2.单调队列
*/
//ST 表
// #include<cmath>
// #include<cstdio>
// #include<cstring>
// #include<iostream>
// #include<algorithm>
// using namespace std;

// const int N = 1e6 + 5;

// int n,k;
// int a[N],ans1[N],ans[N];

// void st_init(const int &n) {
	
// 	for(int j = 1; (1<<j) <= k; j++) {
// 		int t = 1<<j;
// 		for(int i = 1; (i+t-1) <= n; i++) {
// 			ans1[i]=min(ans1[i],ans1[i+(t>>1)]);
// 			ans[i]=max(ans[i],ans[i+(t>>1)]);
// 		}
// 	}
// }


// int main() {

// 	scanf("%d%d",&n,&k);
// 	for(int i=1; i<=n; i++) {
// 		scanf("%d",&ans[i]);
// 		ans1[i] = ans[i];
// 	}
// 	st_init(n);
// 	int cnt = (int)((log(k*1.0))/(log(2.0)));
	
// 	for(int i=1; i+k-1<=n; i++) {
// 		printf("%d ",min(ans1[i],ans1[i+k-(1<<cnt)]));
// 	}
// 	printf("\n");
// 	for(int i=1; i+k-1<=n; i++) {
// 		printf("%d ",max(ans[i],ans[i+k-(1<<cnt)]));
// 	}

// 	return 0;
// }

//单调队列

#include<cstdio>
#include<iostream>

const int maxn = 1e6 + 5;
//qe[i]数组记下标
int qe[maxn], hh, tt=-1, a[maxn];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	int hh = 1,tt = 0;
	for(int i = 1; i <= n; i++) {
        //维护队头是否滑出
		while(hh <= tt && qe[hh] < i-k+1) {
			hh++;
		}
        //维护单调性 
		while(hh <= tt && a[qe[tt]] >= a[i]) {
			tt--;
		}
		qe[++tt] = i;
		if(i >= k ) printf("%d ",a[qe[hh]]);
	}
	
    
	printf("\n");
	hh = 1,tt = 0;
	for(int i = 1; i <= n; i++) {
		while(hh <= tt && qe[hh] < i-k+1) {
			hh++;
		}
		
		while(hh <= tt && a[qe[tt]] <= a[i]) {
			tt--;
		}
		qe[++tt] = i;
		/*
		维护单调性  tt-- ++tt 更新qe[tt]数值 
		*/
		if(i >= k ) printf("%d ",a[qe[hh]]);
	}
	
	return 0;
}
