/* 
 * @Author: wxy
 * @Date: 2023-03-02 19:34:37
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-02 19:34:39
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.10堆\模拟堆.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e5+10;

int h[N],hp[N],ph[N],cnt;

void heap_swap(int a,int b)
{   
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b] );
}

void down(int u)
{
    int t = u;
    if(u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t])
    {
        t = u * 2 + 1;
    }
    if(u != t){
        heap_swap(h[u],h[t]);
        down(t);
    }
}

void up(int u)
{
    while(u/2 && h[u/2] > h[u])
    {
        heap_swap(u/2,u);
        u /= 2;
    }
}

int main()
{
    int n,m = 0;
    scanf("%d",&n);
    while(n--)
    {
        char op[10];
        int k,x;


        scanf("%s",op);
        if(!strcmp(op,"I")){
            scanf("%d",&x);
            cnt++;
            m++;
            ph[m] = cnt,hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        else if(!strcmp(op,"PM")) printf("%d\n",h[1]);
        else if(!strcmp(op,"DM"))
        {
            heap_swap(1,cnt);
            cnt--;
            down(1);    
        }else if(!strcmp(op,"D"))
        {
            scanf("%d",&k);
            k = ph[k];
            heap_swap(k,cnt);
            cnt--;
            down(k),up(k);  
        }   
        else
        {
            scanf("%d%d",&k,&x);
            k = ph[k];
            h[k] = x;
            down(k),up(k);
        }
    }   

    return 0;
}