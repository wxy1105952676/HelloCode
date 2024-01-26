/* 
 * @Author: wxy
 * @Date: 2023-04-02 21:04:54
 * @LastEditors: wxy
 * @LastEditTime: 2023-04-02 21:31:08
 * @FilePath: \AcWing\算法基础课\3.搜索与图论\3.3树与图的深度优先遍历\树的重心.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<iostream>
#include<algorithm>
#include<cstring>


using namespace std;

const int N = 1e5 + 10; //数据范围是10的5次方
const int M = 2 * N; //以有向图的格式存储无向图，所以每个节点至多对应2n-2条边

int h[N]; //邻接表存储树，有n个节点，所以需要n个队列头节点
int e[M]; //存储元素
int ne[M]; //存储列表的next值
int idx; //单链表指针
int n; //题目所给的输入，n个节点
int ans = N; //表示重心的所有的子树中，最大的子树的结点数目

bool st[N]; //记录节点是否被访问过，访问过则标记为true

//a所对应的单链表中插入b  a作为根 
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// dfs 框架
/*
void dfs(int u){
    st[u]=true; // 标记一下，记录为已经被搜索过了，下面进行搜索过程
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]) {
            dfs(j);
        }
    }
}
*/
//以u为根的子树数量
int dfs(int u)
{
    st[u] = true;

    int sum = 1,res = 0;

    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int s = dfs(j);
            res = max(res,s);
            sum += s;
        }
    }
    res = max(res,n-sum);
    
    ans = min(ans,res);

    return sum;
}



int main()
{
    cin >> n;
    
    memset(h, -1, sizeof(h));

     for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }

    dfs(1);

    cout << ans << endl;


    return 0;
}