/* 
 * @Author: wxy
 * @Date: 2023-04-02 21:41:27
 * @LastEditors: wxy
 * @LastEditTime: 2023-04-02 21:44:41
 * @FilePath: \AcWing\算法基础课\3.搜索与图论\3.4树与图的广度优先遍历\图中点的层次.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include <cstring>
#include <iostream>

using namespace std;

const int N=1e5+10;

int h[N], e[N], idx, ne[N];
int d[N]; //存储每个节点离起点的距离  d[1]=0
int n, m; //n个节点m条边
int q[N]; //存储层次遍历序列 0号节点是编号为1的节点

void add(int a, int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
//手写队列 维护BFS
int bfs()
{
    int hh=0,tt=0;

    q[0]=1; //0号节点是编号为1的节点

    memset(d,-1,sizeof d);

    d[1]=0; //存储每个节点离起点的距离

    //当我们的队列不为空时
    while(hh<=tt)
    {
        //取出队列头部节点
        int t=q[hh++];

        //遍历t节点的每一个邻边
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            //如果j没有被扩展过
            if(d[j]==-1)
            {
                d[j]=d[t]+1; //d[j]存储j节点离起点的距离，并标记为访问过
                q[++tt] = j; //把j结点 压入队列
            }
        }
    }

    return d[n];
}
/*
*STL队列 维护BFS
int bfs()
{
    memset(d, -1, sizeof d);

    queue<int> q;
    d[1] = 0;
    q.push(1);

    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
    return d[n];
}
*/

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }

    cout<<bfs()<<endl;
}