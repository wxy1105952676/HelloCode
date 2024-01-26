/* 
 * @Author: wxy
 * @Date: 2023-03-02 19:37:39
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-02 19:51:51
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.11哈希表\模拟散列表.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
/*
#include<cstdio>
#include<cstring>
using namespace std;

const int mod = 1e5 + 3;
const int maxn = 1e5 + 5;

int h[maxn], e[maxn], ne[maxn], idx;

void insert(int x){
    int k = ((x%mod) + mod) % mod;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

int query(int x){
    int k = ((x%mod) + mod) % mod;  
    for(int i = h[k]; i != -1; i = ne[i]){
        if(e[i] == x) return 1;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    memset(h, -1, sizeof(h));
    while(n--){
        char ch[5];
        int x;
        scanf("%s%d", ch, &x);
        if(ch[0] == 'I'){
            insert(x);
        }else{
            if(query(x)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;   
}
*/
#include <cstring>
#include <iostream>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x)
{
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x)
    {
        t ++ ;
        if (t == N) t = 0;
    }
    return t;
}

int main()
{
    memset(h, 0x3f, sizeof h);

    int n;
    scanf("%d", &n);

    while (n -- )
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'I') h[find(x)] = x;
        else
        {
            if (h[find(x)] == null) puts("No");
            else puts("Yes");
        }
    }

    return 0;
}