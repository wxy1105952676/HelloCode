/* 
 * @Author: wxy
 * @Date: 2023-02-28 20:34:21
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-28 20:35:01
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.7KMP算法\KMP.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include <iostream>

using namespace std;

const int N = 1e5+10, M = 1e6+10; //N为模式串长度，M匹配串长度

int n, m;
int ne[N]; //next[]数组，避免和头文件next冲突
char s[N], p[M];  //s为模式串， p为匹配串

int main()
{
    cin >> n >> p+1 >> m >> s+1;  //下标从1开始

    //求next[]数组
    for(int i = 2, j = 0; i <= n; i++)
    {
        while(j && p[i] != p[j+1]) j = ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }
    //匹配操作
    for(int i = 1, j = 0; i <= m; i++)
    {
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == n)  //满足匹配条件，打印开头下标, 从0开始
        {
            //匹配完成后的具体操作
            //如：输出以0开始的匹配子串的首字母下标
            printf("%d ", i - n); //(若从1开始，加1)
            j = ne[j];            //再次继续匹配
        }
    }

    return 0;
}