#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
#include "../../data-structure/BIT.hpp"

#define REP(a,b) for(int a=0;a<(int)(b);++a)

int main(){
 int n, q;
 std::cin >> n >> q;

 BIT<long long> bit(n);
 REP(i, n) {
  int a;
  std::cin >> a;
  bit.add(i, a);
 }
 REP(_, q) {
  int type, l, r;
  std::cin >> type >> l >> r;
  if (type == 0) bit.add(l, r);
  else std::cout << bit.sum(l, r) << '\n';
 }
}