/* 
 * @Author: wxy
 * @Date: 2023-02-28 17:14:09
 * @LastEditors: wxy
 * @LastEditTime: 2023-02-28 19:39:43
 * @FilePath: \AcWing\算法基础课\2.数据结构\2.3栈\模拟栈.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved. 
*/
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

const int maxn = 1e6 + 5;

int tt, stk[maxn];

void push(int x){
    stk[tt++] = x;
}

bool empty(){
    return tt;
}

void pop(){
    tt--;
}

int top(){
    return stk[tt-1];
}

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
        }else if(ss == "empty"){
            if(!empty()) printf("YES\n");
            else printf("NO\n");
        }else if(ss == "pop"){
            pop();
        }else{
            printf("%d\n", top());
        }
        //printf("\n");
    }
    return 0;
}
//STL栈

#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> stack;
    int m,x;
    string op;
    cin >> m;
    while (m--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            stack.push_back(x);
        }
        else if (op == "pop") {
            stack.pop_back();
        }
        else if (op == "empty") {
            if (stack.size() == 0) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else if (op == "query") {
            cout << stack.back() << endl;
        }
    }
    return 0;
}