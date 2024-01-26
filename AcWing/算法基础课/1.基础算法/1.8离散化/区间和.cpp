/* 
 * @Author: wxy
 * @Date: 2023-02-28 08:56:05
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-28 09:46:56
 * @FilePath: \AcWing\算法基础课\1.基础算法\1.8离散化\区间和.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 3e5+10;

vector<int> alls;
vector<PII> add,query;

int n,m;
int a[N],s[N];

int find(int x)//返回的是输入的坐标的离散化下标
{
    return lower_bound(alls.begin(),alls.end(),x) - alls.begin() + 1;
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int x,c;
        cin >> x >> c;
        add.push_back({x,c});
        alls.push_back(x);
    }

    for(int i = 0; i < m; i++)
    {
        int l,r;
        cin >> l >> r;

        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    //去重操作
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    //处理插入操作  a[]数组储存的是对应坐标插入的值
    for(auto item: add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }
    //预处理前缀和
    for(int i = 1; i <= alls.size(); i++) s[i] = s[i-1] + a[i];

    //处理查询操作
    for(auto item: query)
    {
        int l = find(item.first),r = find(item.second);
        //ans = s[r] - s[l-1]
        cout << s[r] - s[l-1] << endl;
    }

    return 0;
}