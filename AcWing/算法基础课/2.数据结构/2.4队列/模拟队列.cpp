/* 
 * @Author: wxy
 * @Date: 2023-02-28 19:43:13
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-28 19:48:38
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.4队列\模拟队列.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;

const int N = 1e6+10;

int qe[N],hh,tt;

void push(int x){ qe[tt++] = x;}

void pop(){hh++;}

bool empty(){return hh==tt;}

int front(){return qe[hh];}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        string ss;
        cin>>ss;
        int x;
        if(ss == "push"){
            scanf("%d", &x);
            push(x);
        }else if(ss == "pop"){
            pop();
        }else if(ss == "empty"){
            if(!empty()){
                printf("NO\n");
            }else printf("YES\n");
        }else{
            printf("%d\n", front());
        }
    }
    return 0;
}
