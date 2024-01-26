/*
 * @Author: wxy
 * @Date: 2023-03-05 20:57:37
 * @LastEditors: wxy
 * @LastEditTime: 2023-03-05 20:57:39
 * @FilePath: \AcWing\算法基础课\3.搜索与图论\3.1DFS\n-皇后问题.cpp
 * @Description:
 * @
 * @Copyright (c) 2023 by Author, All Rights Reserved.
 */

//（DFS按行枚举）
#include <iostream>
using namespace std;
const int N = 20;
/*
*bool数组用来判断搜索的下一个位置是否可行
*col列，dg对角线，udg反对角线
*g[N][N]用来存路径
*/

/*
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
    * u == n 表示已经搜了n行，故输出这条路径
    if (u == n) {
        for (int i = 0; i < n; i ++ ) puts(g[i]);   // 等价于cout << g[i] << endl;
        puts("");  // 换行
        return;
    }

* 对n个位置按行搜索

    for (int i = 0; i < n; i ++ )
    {
        * 剪枝(对于不满足要求的点，不再继续往下搜索)
         * udg[n - u + i]，+n是为了保证下标非负
        
        if (!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false; // 恢复现场 这步很关键
            g[u][i] = '.';
        }
    }      
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    dfs(0);

    return 0;
}
*/
// （DFS按每个元素枚举）
#include <iostream>
    using namespace std;
const int N = 20;

int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N]; // 因为是一个个搜索，所以加了row

// s表示已经放上去的皇后个数
void dfs(int x, int y, int s)
{
    // 处理超出边界的情况
    if (y == n)
        y = 0, x++;

    if (x == n)
    { // x==n说明已经枚举完n^2个位置了
        if (s == n)
        { // s==n说明成功放上去了n个皇后
            for (int i = 0; i < n; i++)
                puts(g[i]);
            puts("");
        }
        return;
    }

    // 分支1：放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }

    // 分支2：不放皇后
    dfs(x, y + 1, s);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    dfs(0, 0, 0);

    return 0;
}