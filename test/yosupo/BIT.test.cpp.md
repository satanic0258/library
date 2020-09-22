---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/BIT.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/BIT.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#include <bits/stdc++.h>\n#line 1 \"data-structure/BIT.hpp\"\n// @brief Binary\
    \ Indexed Tree\n// @shortcut BIT\n// @description BIT(Fenwick\u6728)\uFF0E\u5358\
    \u70B9\u66F4\u65B0\u533A\u9593\u548C\u3092O(logN)\u3067\u884C\u3046\uFF0E\n//\
    \ @docs data-structure/BIT.md\ntemplate <class T = int>\nstruct BIT {\n int N;\n\
    \ std::vector<T> bit;\n BIT() : N(0) {}\n BIT(int n) : N(n), bit(N + 1, 0) {}\n\
    \ BIT(int n, T init) : N(n), bit(N + 1, init) {}\n\n // bit[i] += w;\n void add(int\
    \ i, T w) { \n  for (int x = ++i; x <= N; x += x & -x) bit[x] += w;\n }\n // return\
    \ sum [0, i);\n T sum(int i) {\n  T res = 0;\n  for (int x = i; x > 0; x -= x\
    \ & -x) res += bit[x];\n  return res;\n }\n // return sum [i, j);\n T sum(int\
    \ i, int j) { return sum(j) - sum(i); }\n const T& operator[](const int& i) const\
    \ { return bit[i]; }\n};\n#line 4 \"test/yosupo/BIT.test.cpp\"\n\n#define REP(a,b)\
    \ for(int a=0;a<(int)(b);++a)\n\nint main(){\n int n, q;\n std::cin >> n >> q;\n\
    \n BIT<long long> bit(n);\n REP(i, n) {\n  int a;\n  std::cin >> a;\n  bit.add(i,\
    \ a);\n }\n REP(_, q) {\n  int type, l, r;\n  std::cin >> type >> l >> r;\n  if\
    \ (type == 0) bit.add(l, r);\n  else std::cout << bit.sum(l, r) << '\\n';\n }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\n#include \"../../data-structure/BIT.hpp\"\n\n#define\
    \ REP(a,b) for(int a=0;a<(int)(b);++a)\n\nint main(){\n int n, q;\n std::cin >>\
    \ n >> q;\n\n BIT<long long> bit(n);\n REP(i, n) {\n  int a;\n  std::cin >> a;\n\
    \  bit.add(i, a);\n }\n REP(_, q) {\n  int type, l, r;\n  std::cin >> type >>\
    \ l >> r;\n  if (type == 0) bit.add(l, r);\n  else std::cout << bit.sum(l, r)\
    \ << '\\n';\n }\n}"
  dependsOn:
  - data-structure/BIT.hpp
  isVerificationFile: true
  path: test/yosupo/BIT.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 00:56:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/BIT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/BIT.test.cpp
- /verify/test/yosupo/BIT.test.cpp.html
title: test/yosupo/BIT.test.cpp
---
