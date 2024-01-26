/*
 * @Author: wxy
 * @Date: 2023-03-01 19:26:44
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-01 19:26:46
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.9并查集\合并集合,cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by Author, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

const int N=100010;
int p[N];//定义多个集合

int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    /*
    经上述可以发现,每个集合中只有祖宗节点的p[x]值等于他自己,即:
    p[x]=x;
    */
    return p[x];
    //找到了便返回祖宗节点的值
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) p[i]=i;
    while(m--)
    {
        char op[2];
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        if(*op=='M') p[find(a)]=find(b);//集合合并操作
        else
        if(find(a)==find(b))
        //如果祖宗节点一样,就输出yes
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}