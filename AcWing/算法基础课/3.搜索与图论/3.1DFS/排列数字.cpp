/* 
 * @Author: wxy
 * @Date: 2023-03-05 20:53:19
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-05 20:53:20
 * @FilePath: \AcWing\算法基础课\3.搜索与图论\3.1DFS\排列数字.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 15;

int n,p[N];
bool vis[N];

void out()
{
    for(int i = 0; i < n; i++) cout << p[i] << " ";
    cout << endl;
}

void dfs(int u)
{
    if(u == n) out();

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            p[u] = i;
            vis[i] = true;
            dfs(u+1);
            vis[i] = false;
        }
    }
}
int main()
{
    cin >> n;

    dfs(0);
    
    return 0;
}