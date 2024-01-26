/* 
 * @Author: wxy
 * @Date: 2023-04-03 22:21:12
 * @LastEditors: wxy
 * @LastEditTime: 2023-04-03 22:21:25
 * @FilePath: \AcWing\算法基础课\3.搜索与图论\3.7Bellman-ford\有边数限制的最短路.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/

// * bellman-ford算法，遍历n次所有边
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int maxn = 1e4 + 5;
int n, m, k;

struct Node{
    int u, v, w;
}edge[maxn];

int dist[maxn], backup[maxn];

int bell(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 1; i <= k; i++){
        memcpy(backup, dist, sizeof dist);
        for(int j = 1; j <= m; j++){
            int u, v, w;
            u = edge[j].u;
            v = edge[j].v;
            w = edge[j].w;
            dist[v] = min(dist[v], backup[u] + w);
        }
    }
    return dist[n];
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge[i] = {u, v, w};
    }
    int t = bell();
    if(t > 0x3f3f3f3f/2) printf("impossible\n");
    else printf("%d\n", t);
    return 0;
}
