---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: UnionFind.md
    document_title: UnionFind
    links: []
  bundledCode: "#line 1 \"data-structure/UnionFind.hpp\"\n// @brief UnionFind\n//\
    \ @shortcut UnionFind\n// @description \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\
    \u9020\uFF0E union by size+path halving\u306E\u5B9F\u88C5\uFF0EO(\u03B1(N)).\n\
    // @docs UnionFind.md\nclass UnionFind {\nprivate:\n\tstd::vector<int> par;\n\t\
    std::vector<int> siz;\n\npublic:\n\tUnionFind(int sz_) : par(sz_), siz(sz_, 1)\
    \ {\n\t\tfor (int i = 0; i < sz_; ++i) par[i] = i;\n\t}\n\tvoid init(int sz_)\
    \ {\n\t\tpar.resize(sz_);\n\t\tsiz.resize(sz_, 1);\n\t\tfor (int i = 0; i < sz_;\
    \ ++i) par[i] = i;\n\t}\n\tint find(int x) {\n\t\twhile (par[x] != x) x = par[x]\
    \ = par[par[x]];\n\t\treturn x;\n\t}\n\tvoid unite(int x, int y) {\n\t\tx = find(x);\n\
    \t\ty = find(y);\n\t\tif (x == y) return;\n\t\tif (siz[x] < siz[y]) std::swap(x,\
    \ y);\n\t\tsiz[x] += siz[y];\n\t\tpar[y] = x;\n\t}\n\tbool same(int x, int y)\
    \ {\n\t\treturn find(x) == find(y);\n\t}\n\tint size(int x) {\n\t\treturn siz[find(x)];\n\
    \t}\n};\n"
  code: "// @brief UnionFind\n// @shortcut UnionFind\n// @description \u7D20\u96C6\
    \u5408\u30C7\u30FC\u30BF\u69CB\u9020\uFF0E union by size+path halving\u306E\u5B9F\
    \u88C5\uFF0EO(\u03B1(N)).\n// @docs UnionFind.md\nclass UnionFind {\nprivate:\n\
    \tstd::vector<int> par;\n\tstd::vector<int> siz;\n\npublic:\n\tUnionFind(int sz_)\
    \ : par(sz_), siz(sz_, 1) {\n\t\tfor (int i = 0; i < sz_; ++i) par[i] = i;\n\t\
    }\n\tvoid init(int sz_) {\n\t\tpar.resize(sz_);\n\t\tsiz.resize(sz_, 1);\n\t\t\
    for (int i = 0; i < sz_; ++i) par[i] = i;\n\t}\n\tint find(int x) {\n\t\twhile\
    \ (par[x] != x) x = par[x] = par[par[x]];\n\t\treturn x;\n\t}\n\tvoid unite(int\
    \ x, int y) {\n\t\tx = find(x);\n\t\ty = find(y);\n\t\tif (x == y) return;\n\t\
    \tif (siz[x] < siz[y]) std::swap(x, y);\n\t\tsiz[x] += siz[y];\n\t\tpar[y] = x;\n\
    \t}\n\tbool same(int x, int y) {\n\t\treturn find(x) == find(y);\n\t}\n\tint size(int\
    \ x) {\n\t\treturn siz[find(x)];\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/UnionFind.hpp
  requiredBy: []
  timestamp: '2020-09-23 00:10:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/unionfind.test.cpp
documentation_of: data-structure/UnionFind.hpp
layout: document
redirect_from:
- /library/data-structure/UnionFind.hpp
- /library/data-structure/UnionFind.hpp.html
title: UnionFind
---
