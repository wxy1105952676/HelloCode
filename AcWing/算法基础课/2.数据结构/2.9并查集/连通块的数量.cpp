/* 
 * @Author: wxy
 * @Date: 2023-03-01 19:28:10
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-01 19:30:53
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.9并查集\连通块的数量.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e5+10;

int fa[N],cnt[N];

void init(int n)
{
    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
        cnt[i] = 1;
    }
}

int find(int x)
{
    if(fa[x]!= x) fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int x,int y)
{
    int fx = find(x),fy = find(y);

    if(fx != fy)
    {
        fa[fx] = fy;
        cnt[fy] += cnt[fx];
    }
}

int main()
{
    int n,m;
    cin >> n >> m;

    init(n);
    while(m--)
    {
        string op;
        cin >> op;

        if(op == "C")
        {
            int x,y;
            cin >> x >> y;
            merge(x,y);
        }else if(op == "Q1"){
            int a,b;
            cin >> a >> b;
            if(find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl; 
        }else{
            int a;
            cin >> a;
            int res = cnt[find(a)];
            cout << res <<endl;
        }

    }

    return 0;
}