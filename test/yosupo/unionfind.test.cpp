#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
#include "../../data-structure/UnionFind.hpp"

#define REP(a,b) for(int a=0;a<(int)(b);++a)

signed main(){
  int n, q;
  std::cin >> n >> q;

  UnionFind uf(n);
  REP(i, q) {
    int t, u, v;
    std::cin >> t >> u >> v;
    /* */if (t == 0) uf.unite(u, v);
    else if (t == 1) std::cout << uf.same(u, v) << "\n";
  }

  return 0;
}