---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: data-structure/BIT.md
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 1 \"data-structure/BIT.hpp\"\n// @brief Binary Indexed Tree\n\
    // @shortcut BIT\n// @description BIT(Fenwick\u6728)\uFF0E\u5358\u70B9\u66F4\u65B0\
    \u533A\u9593\u548C\u3092O(logN)\u3067\u884C\u3046\uFF0E\n// @docs data-structure/BIT.md\n\
    struct BIT {\n int N;\n using TYPE = int;\n std::vector<TYPE> bit;\n BIT() : N(0)\
    \ {}\n BIT(int n) : N(n), bit(N + 1, 0) {}\n BIT(int n, TYPE init) : N(n), bit(N\
    \ + 1, init) {}\n\n // bit[i] += w;\n void add(int i, TYPE w) {\n  for (int x\
    \ = ++i; x <= N; x += x & -x) bit[x] += w;\n }\n // return sum [0, i);\n TYPE\
    \ sum(int i) {\n  TYPE res = 0;\n  for (int x = i; x > 0; x -= x & -x) res +=\
    \ bit[x];\n  return res;\n }\n // return sum [i, j);\n TYPE sum(int i, int j)\
    \ {\n  return sum(j) - sum(i);\n }\n const TYPE& operator[](const int& i) const\
    \ {\n  return bit[i];\n }\n};\n"
  code: "// @brief Binary Indexed Tree\n// @shortcut BIT\n// @description BIT(Fenwick\u6728\
    )\uFF0E\u5358\u70B9\u66F4\u65B0\u533A\u9593\u548C\u3092O(logN)\u3067\u884C\u3046\
    \uFF0E\n// @docs data-structure/BIT.md\nstruct BIT {\n int N;\n using TYPE = int;\n\
    \ std::vector<TYPE> bit;\n BIT() : N(0) {}\n BIT(int n) : N(n), bit(N + 1, 0)\
    \ {}\n BIT(int n, TYPE init) : N(n), bit(N + 1, init) {}\n\n // bit[i] += w;\n\
    \ void add(int i, TYPE w) {\n  for (int x = ++i; x <= N; x += x & -x) bit[x] +=\
    \ w;\n }\n // return sum [0, i);\n TYPE sum(int i) {\n  TYPE res = 0;\n  for (int\
    \ x = i; x > 0; x -= x & -x) res += bit[x];\n  return res;\n }\n // return sum\
    \ [i, j);\n TYPE sum(int i, int j) {\n  return sum(j) - sum(i);\n }\n const TYPE&\
    \ operator[](const int& i) const {\n  return bit[i];\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/BIT.hpp
  requiredBy: []
  timestamp: '2020-09-23 00:44:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/BIT.hpp
layout: document
redirect_from:
- /library/data-structure/BIT.hpp
- /library/data-structure/BIT.hpp.html
title: Binary Indexed Tree
---
## 概要

BIT(Fenwick木)．単点更新区間和を $O(\log N)$ で行う．\\
実装は1-indexedのものだが，区間和を $[0, i)$ と考え0-indexedと思うやつ．