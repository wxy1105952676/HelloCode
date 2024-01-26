/* 
 * @Author: wxy
 * @Date: 2023-02-27 20:53:42
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-27 20:54:08
 * @FilePath: \AcWing\算法基础课\1.基础算法\1.5前缀和与差分\差分矩阵.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<cstdio>

const int maxn = 1e3 + 5;

int d[maxn][maxn];

void insert(int x1, int y1, int x2, int y2, int c){
    d[x1][y1] += c;
    d[x1][y2+1] -= c;
    d[x2+1][y1] -= c;
    d[x2+1][y2+1] += c; 
}

int main(){
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x;
            scanf("%d", &x);
            insert(i,j,i,j,x);
        }
    }
    while(q--){
        int x1,x2,y1,y2,x;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &x);
        insert(x1, y1, x2, y2, x);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            d[i][j] += d[i-1][j]+d[i][j-1]-d[i-1][j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}