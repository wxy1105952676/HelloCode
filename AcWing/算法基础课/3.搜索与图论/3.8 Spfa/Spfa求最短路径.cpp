/*
 * @Author: wxy
 * @Date: 2023-04-03 22:31:44
 * @LastEditors: wxy
 * @LastEditTime: 2023-04-03 22:32:15
 * @FilePath: \AcWing\算法基础课\3.搜索与图论\3.8 Spfa\Spfa求最短路径.cpp
 * @Description:
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved.
 */
//* 队列优化bellman-ford， 将每次遍历最短距离有变化的点入队
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1e5 + 5;
typedef pair<int, int> PII;
int n, m;
int idx, h[maxn], nx[maxn], e[maxn], d[maxn], st[maxn];
int dist[maxn];

void add(int u, int v, int w)
{
    e[idx] = v;
    d[idx] = w;
    nx[idx] = h[u];
    h[u] = idx++;
}

void spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> qe;
    qe.push(1);
    st[1] = 1;
    while (qe.size())
    {
        int u = qe.front();
        qe.pop();
        st[u] = 0;
        for (int i = h[u]; i != -1; i = nx[i])
        {
            int v = e[i];
            if (dist[u] + d[i] < dist[v])
            {
                dist[v] = dist[u] + d[i];
                if (!st[v])
                {
                    st[v] = 1;
                    qe.push(v);
                }
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        printf("impossible\n");
    else
        printf("%d\n", dist[n]);
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    spfa();
    return 0;
}