/* 
 * @Author: wxy
 * @Date: 2023-04-02 22:12:59
 * @LastEditors: wxy
 * @LastEditTime: 2023-04-02 22:31:55
 * @FilePath: \AcWing\算法基础课\3.搜索与图论\3.5拓扑排序\有向图的拓扑序列.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010;
int e[N], ne[N], idx;//邻接表存储图
int h[N];
int q[N], hh = 0, tt = -1;//队列保存入度为0的点，也就是能够输出的点，
int n, m;//保存图的点数和边数
int d[N];//保存各个点的入度

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    for(int i = 1; i <= n; i++){//遍历一遍顶点的入度。
        if(d[i] == 0)//如果入度为 0, 则可以入队列
            q[++tt] = i;
    }
    while(tt >= hh){//循环处理队列中点的
        int a = q[hh++];
        for(int i = h[a]; i != -1; i = ne[i]){//循环删除 a 发出的边
            int b = e[i];//a 有一条边指向b
            d[b]--;//删除边后，b的入度减1
            if(d[b] == 0)//如果b的入度减为 0,则 b 可以输出，入队列
                q[++tt] = b;
        }
    }
    if(tt == n - 1){//如果队列中的点的个数与图中点的个数相同，则可以进行拓扑排序
        for(int i = 0; i < n; i++){//队列中保存了所有入度为0的点，依次输出
            cout << q[i] << " ";
        }
    }
    else//如果队列中的点的个数与图中点的个数不相同，则可以进行拓扑排序
        cout << -1;//输出-1，代表错误
}

int main(){
    cin >> n >> m;//保存点的个数和边的个数
    memset(h, -1, sizeof h);//初始化邻接矩阵
    while (m -- ){//依次读入边
        int a, b;
        cin >> a >> b;
        d[b]++;//顶点b的入度+1
        add(a, b);//添加到邻接矩阵
    }
    topsort();//进行拓扑排序
    return 0;
}