/* 
 * @Author: wxy
 * @Date: 2023-01-23 11:36:56
 * @LastEditors: wxy
 * @LastEditTime: 2023-01-23 12:10:24
 * @FilePath: \AcWing\算法基础课\1.基础算法\1.5前缀和与差分\子矩阵的和.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e3+10;

int sum[N][N],a[N][N];

int main()
{   
    int n,m,q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    while(q--){
        int x1,y1,x2,y2,ans;
        cin >> x1 >> y1 >> x2 >> y2;
        ans = sum[x2][y2] + sum[x1-1][y1-1] - sum[x2][y1-1] - sum[x1-1][y2];
        cout << ans << endl;
    }
    
    return 0;
}