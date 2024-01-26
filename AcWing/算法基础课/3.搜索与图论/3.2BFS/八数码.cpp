/* 
 * @Author: wxy
 * @Date: 2023-03-31 22:21:17
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-31 22:21:29
 * @FilePath: \AcWing\算法基础课\3.搜索与图论\3.2BFS\八数码.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
/*
队列可以用 queue<string> 直接存转化后的字符串
dist数组用 unordered_map<string, int>
将字符串和数字联系在一起，字符串表示状态，数字表示距离

本题重点是状态表示和转移
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

queue<string> q;
unordered_map<string, int> d;


int bfs(string state)
{
    q.push(state);
    d[state] = 0;

    string end = "12345678x";
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        if (t == end) return d[t];

        int distance = d[t];
        
        //状态转移
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[a * 3 + b], t[k]);
                if (!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[a * 3 + b], t[k]);
            }
        }
    }

    return -1;
}

int main()
{
    char s[2];

    string state;
    for (int i = 0; i < 9; i ++ )
    {
        cin >> s;
        state += *s;
    }

    cout << bfs(state) << endl;

    return 0;
}
