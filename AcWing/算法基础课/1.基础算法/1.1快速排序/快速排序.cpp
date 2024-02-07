/*
 * @Author: wxy
 * @Date: 2022-11-17 13:46:31
 * @LastEditors: wxy
 * @LastEditTime: 2024-02-07 14:24:28
 * @FilePath: \HelloCode\AcWing\算法基础课\1.基础算法\1.1快速排序\快速排序.cpp
 * @Description:
 * @
 * @Copyright (c) 2022 by Author, All Rights Reserved.
 */
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int a[N];

void quick_sort(int q[], int l, int r) {
  if (l >= r)
    return;

  int i = l - 1, j = r + 1, x = q[l + r >> 1];
  while (i < j) {
    do
      i++;
    while (q[i] < x);
    do
      j--;
    while (q[j] > x);
    if (i < j)
      swap(q[i], q[j]);
  }
  quick_sort(q, l, j);
  quick_sort(q, j + 1, r);
}

int main() {
  int n;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  quick_sort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
