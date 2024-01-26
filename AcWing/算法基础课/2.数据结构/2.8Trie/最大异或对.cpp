/* 
 * @Author: wxy
 * @Date: 2023-03-01 16:22:55
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-01 19:02:43
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.8Trie\最大异或对.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5+10,M = 3e6+10;

int son[M][2],idx;

int n,a[N];


void insert(int x)
{
    int p = 0;
    for(int i = 30; ~i; i--)
    {
        int &s = son[p][x >> i & 1];
        if(!s) s = ++idx; //创建新节点
        p = s;
    } 
}

int query(int x)
{
    int res = 0, p = 0;

    for(int i = 30; ~i; i--)
    {
        int s = x >> i & 1;
        if(son[p][!s])
        {
            res += 1 << i;
            p = son[p][!s];
        }else p = son[p][s];
    }
    return res;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }   
    
    int res = 0;

    for(int i = 0; i < n; i++) res = max(res,query(a[i]));

    cout << res << endl;

    return 0;
}