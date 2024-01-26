/* 
 * @Author: wxy
 * @Date: 2023-03-31 22:04:37
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-31 22:19:34
 * @FilePath: \AcWing\算法基础课\3.搜索与图论\3.2BFS\走迷宫.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 110;

int n,m;
int g[N][N],d[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef pair<int, int> PII;

int bfs()
{
    queue<PII> q;
    q.push({0,0});
    
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i],y = t.second + dy[i];
            if(x >= 0 & x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x,y});
            }
        }
    }
    return d[n-1][m-1];
    
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0;  j < m; j++){
            cin >> g[i][j];
        }
    }
    
    cout << bfs() << endl;
    
    return 0;
}