/* 
 * @Author: wxy
 * @Date: 2023-04-03 21:26:35
 * @LastEditors: wxy
 * @LastEditTime: 2023-04-03 22:19:57
 * @FilePath: \AcWing\算法基础课\3.搜索与图论\3.6Dijkstra\Dijkstra求最短路.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
/*
*邻接矩阵存图  Dijkstra最短路算法
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=510;

int g[N][N];    //为稠密阵所以用邻接矩阵存储
int dist[N];    //用于记录每一个点距离第一个点的距离
bool st[N];     //用于记录该点的最短距离是否已经确定

int n,m;

int Dijkstra()
{
    memset(dist, 0x3f,sizeof dist);     //初始化距离  0x3f代表无限大

    dist[1]=0;  //第一个点到自身的距离为0

    for(int i=0;i<n;i++)      //有n个点所以要进行n次 迭代
    {
        int t=-1;       //t存储当前访问的点

        for(int j=1;j<=n;j++)   //这里的j代表的是从1号点开始
            if(!st[j]&&(t==-1||dist[t]>dist[j]))     
                t=j;

        st[t]=true;   

        for(int j=1;j<=n;j++)           //依次更新每个点所到相邻的点路径值
            dist[j]=min(dist[j],dist[t]+g[t][j]);
    }

    if(dist[n]==0x3f3f3f3f) return -1;  //如果第n个点路径为无穷大即不存在最低路径
    return dist[n];
}
int main()
{
    cin>>n>>m;

    memset(g,0x3f,sizeof g);    //初始化图 因为是求最短路径
                                //所以每个点初始为无限大

    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=min(g[x][y],z);     //如果发生重边的情况则保留最短的一条边
    }

    cout<<Dijkstra()<<endl;
    return 0;
}
*/

/*
* 堆优化 优先队列  
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>


using namespace std;

typedef pair<int, int> PII;

const int N = 1e5+10,M = N << 1;

int n,m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)  // 添加一条边a->b，边权为c
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);//距离初始化为无穷大
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;//小根堆
    // 这里heap中为什么要存pair呢，首先小根堆是根据距离来排的，所以有一个变量要是距离，
    // 其次在从堆中拿出来的时候要知道知道这个点是哪个点，不然怎么更新邻接点呢？所以第二个变量要存点
    q.push({0, 1});//插入距离和节点编号

    while (q.size())
    {
        PII t = q.top();//取距离源点最近的点
        q.pop();

        int ver = t.second, distance = t.first;//ver:节点编号，distance:源点距离ver 的距离

        if (st[ver]) continue;//如果距离已经确定，则跳过该点
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])//更新ver所指向的节点距离
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                q.push({dist[j], j});//距离变小，则入堆
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);

    while (m--)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        add(x, y, c);
    }

    cout << dijkstra() << endl;

    return 0;
}




