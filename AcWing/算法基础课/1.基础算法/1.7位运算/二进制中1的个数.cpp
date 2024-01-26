/* 
 * @Author: wxy
 * @Date: 2023-02-27 22:13:12
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-27 22:16:37
 * @FilePath: \AcWing\算法基础课\1.基础算法\1.7位运算\二进制中1的个数.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<iostream>

using namespace std;

int lowbit(int x)
{
    return x & -x;
}

int main(){
    int n;
    cin >> n;

    while(n--)
    {
        int x;
        cin >> x;

        int res = 0;
        while(x) x-= lowbit(x),res++;
        cout << res <<' ';
    }
    return 0;
}