/* 
 * @Author: wxy
 * @Date: 2023-02-28 16:56:10
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-28 17:09:53
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.2双链表\双链表.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e5+10;

int m,idx;
int l[N],r[N],e[N];

//在节点a的右边插入节点x
void insert(int a,int x)
{
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx,r[a] = idx++;
}

//删除节点a
void remove(int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

int main()
{
    cin >> m;

    r[0] = 1,l[1] = 0;

    idx = 2;

    while(m--)
    {
        string op;
        cin >> op;
        int k,x;
         if (op == "L")
        {
            cin >> x;
            insert(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            insert(l[1], x);
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            insert(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            insert(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' '; 
    cout << endl;

    return 0;
}