/* 
 * @Author: wxy
 * @Date: 2023-03-01 19:54:48
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-01 19:55:13
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.9并查集\食物链.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/

//维护路径的并查集

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 5e4 + 5;

int fa[maxn];
int d[maxn];//每个点到根节点的距离 利用路径压缩  距离%3得关系;


int find(int x){
    if(fa[x] != x){
        int root = find(fa[x]);
        d[x] = ((d[x] + d[fa[x]])%3 + 3) % 3;
        fa[x] = root;
    }
    return fa[x];
}

int main(){
    int n, k, res = 0;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= k; i++){
        int e, x, y;
        scanf("%d%d%d", &e, &x, &y);
        if(x > n || y > n) res++;
        else if(e == 1){
            int fx = find(x);
            int fy = find(y);
            if(fx != fy){
                fa[fx] = fy;
                d[fx] = ((d[y] - d[x]) % 3 + 3) % 3; //dfx + dx = dy;
            }else{
                if((d[x] - d[y]) % 3) res++;
            } 
        }else{
            int fx = find(x);
            int fy = find(y);
            if(fx != fy){
                fa[fx] = fy;
                d[fx] = ((d[y] - d[x] + 1) % 3 + 3) % 3;//dfx + dx = dy + 1
            }else{
                if(((d[x] - d[y])%3 + 3) % 3 != 1) res++;
            } 
        }
    } 
    printf("%d\n", res);
    return 0;
}
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int N = 50005;

int fa[N], ra[N];

void initial(int n){
    for(int i = 0; i <= n; i++){
        fa[i] = i;
    }
}

int find(int x)
{
    if(fa[x] == x){
        return x;
    }

    int fx = find(fa[x]);

    ra[x] += ra[fa[x]];

    return fa[x] = fx;
}

void merge(int x,int y,int rel){
    int fx,fy;

    fx = find(x);
    fy = find(y);

    fa[fx] = fy;
    ra[fx] = ra[y] - (ra[x] - rel);
}

int main(){
    int n,k,ans,fx,fy;

    scanf("%d%d",&n,&k);

    initial(n);

    ans = 0;
    for(int i = 1; i <= k; i++){

        int t, x, y;

        scanf("%d%d%d", &t, &x, &y);

        if(x > n || y > n){
            ans ++;
            continue;
        }
        else if(t == 2 && x == y){
            ans++;
            continue;
        }
        else{
            int rel;

            if(t == 2){
                rel = 1;
            }
            else{
                rel = 0;
            }
            fx = find(x),
            fy = find(y);

            if(fx == fy){
                if((((ra[x] - ra[y]) % 3) + 3) % 3 != rel){
                    ans++;
                }
            }else{
                merge(x,y,rel);
            }
        }
    }
    printf("%d",ans);
}
