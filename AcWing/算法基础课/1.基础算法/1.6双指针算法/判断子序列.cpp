/* 
 * @Author: wxy
 * @Date: 2023-02-27 22:03:06
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-27 22:03:15
 * @FilePath: \AcWing\算法基础课\1.基础算法\1.6双指针算法\判断子序列.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+10;

int n,m;
int a[N],b[N]; 

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int i = 0,j = 0;

    while( i < n && j < m){
        if(a[i] == b[j]) i++;
        j++;
    }

    if(i == n) cout<<"Yes"<<endl;
    else cout << "No" << endl;


    return 0;
}