/* 
 * @Author: wxy
 * @Date: 2023-03-01 15:30:01
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-01 15:30:03
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.8Trie\Trie字符串统计.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx; //下标是0的点，既是根节点，又是空节点
char str[N];


void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        char op[2];
        scanf("%s%s", op, str);
        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
}