---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/UnionFind.cpp
    title: data-structure/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include <bits/stdc++.h>\n\n#line 1 \"data-structure/UnionFind.cpp\"\nclass\
    \ UnionFind {\nprivate:\n\tstd::vector<int> par;\n\tstd::vector<int> siz;\n\n\
    public:\n\tUnionFind(int sz_) : par(sz_), siz(sz_, 1) {\n\t\tfor (int i = 0; i\
    \ < sz_; ++i) par[i] = i;\n\t}\n\tvoid init(int sz_) {\n\t\tpar.resize(sz_);\n\
    \t\tsiz.resize(sz_, 1);\n\t\tfor (int i = 0; i < sz_; ++i) par[i] = i;\n\t}\n\t\
    int find(int x) {\n\t\twhile (par[x] != x) x = par[x] = par[par[x]];\n\t\treturn\
    \ x;\n\t}\n\tvoid unite(int x, int y) {\n\t\tx = find(x);\n\t\ty = find(y);\n\t\
    \tif (x == y) return;\n\t\tif (siz[x] < siz[y]) std::swap(x, y);\n\t\tsiz[x] +=\
    \ siz[y];\n\t\tpar[y] = x;\n\t}\n\tbool same(int x, int y) {\n\t\treturn find(x)\
    \ == find(y);\n\t}\n\tint size(int x) {\n\t\treturn siz[find(x)];\n\t}\n};\n#line\
    \ 6 \"test/yosupo/unionfind.test.cpp\"\n\n#define REP(a,b) for(int a=0;a<(int)(b);++a)\n\
    \nsigned main(){\n  int n, q;\n  std::cin >> n >> q;\n\n  UnionFind uf(n);\n \
    \ REP(i, q) {\n    int t, u, v;\n    std::cin >> t >> u >> v;\n    /* */if (t\
    \ == 0) uf.unite(u, v);\n    else if (t == 1) std::cout << uf.same(u, v) << \"\
    \\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../data-structure/UnionFind.cpp\"\n\n#define\
    \ REP(a,b) for(int a=0;a<(int)(b);++a)\n\nsigned main(){\n  int n, q;\n  std::cin\
    \ >> n >> q;\n\n  UnionFind uf(n);\n  REP(i, q) {\n    int t, u, v;\n    std::cin\
    \ >> t >> u >> v;\n    /* */if (t == 0) uf.unite(u, v);\n    else if (t == 1)\
    \ std::cout << uf.same(u, v) << \"\\n\";\n  }\n\n  return 0;\n}"
  dependsOn:
  - data-structure/UnionFind.cpp
  isVerificationFile: true
  path: test/yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2020-01-06 22:20:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/unionfind.test.cpp
- /verify/test/yosupo/unionfind.test.cpp.html
title: test/yosupo/unionfind.test.cpp
---
