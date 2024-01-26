/* 
 * @Author: wxy
 * @Date: 2023-03-02 20:06:14
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-05 16:36:48
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.11哈希表\字符串哈希.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e5+5,P = 131;//131 13331
ULL h[N],p[N];

// h[i]前i个字符的hash值
// 字符串变成一个p进制数字，体现了字符+顺序，需要确保不同的字符串对应不同的数字
// P = 131 或  13331 Q=2^64，在99%的情况下不会出现冲突
// 使用场景： 两个字符串的子串是否相同
ULL query(int l,int r){
    return h[r] - h[l-1]*p[r-l+1];
}
int main(){
    int n,m;
    cin>>n>>m;
    string x;
    cin>>x;

    //字符串从1开始编号，h[1]为前一个字符的哈希值
    p[0] = 1;
    h[0] = 0;
    for(int i=0;i<n;i++){
        p[i+1] = p[i]*P;            
        h[i+1] = h[i]*P +x[i];      //前缀和求整个字符串的哈希值
    }

    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(query(l1,r1) == query(l2,r2)) printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}
