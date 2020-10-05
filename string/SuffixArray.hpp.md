---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: string/SuffixArray.md
    document_title: SuffixArray
    links: []
  bundledCode: "#line 1 \"string/SuffixArray.hpp\"\n// @brief SuffixArray\n// @shortcut\
    \ SuffixArray\n// @description SuffixArray+LCP\u306E\u69CB\u7BC9\uFF0ESA-IS\u5B9F\
    \u88C5\u306B\u3088\u308AO(|S|)\uFF0E\n// @docs string/SuffixArray.md\nclass SuffixArray\
    \ {\nprivate:\n const int n;\n std::vector<bool> t;\n std::vector<int> p1;\n\n\
    \ void constructSA(const std::vector<int>& s, int K) {\n  std::vector<int> B(K,\
    \ 0);\n  std::vector<int> start(K + 1, 0);\n  std::vector<int> LMS(n, -1);\n \
    \ std::vector<int> tmp(n, -1);\n\n  auto inducedSort = [&](std::vector<int> &\
    \ a) {\n   std::vector<int> l(K), r(K);\n   for (int i = 0; i < K; ++i) l[i] =\
    \ start[i], r[i] = start[i + 1] - 1;\n\n   for (const auto& i : a) {\n    if (i\
    \ > 0 && !t[i - 1]) a[l[s[i - 1]]++] = i - 1;\n   }\n\n   for (int ti = n - 1;\
    \ ti >= 0; --ti) {\n    int i = a[ti];\n    if (i > 0 && t[i - 1]) a[r[s[i - 1]]--]\
    \ = i - 1;\n   }\n  };\n\n  { // create t (L/S-type)\n   t[n - 1] = true;\n  \
    \ for (int i = n - 2; i >= 0; --i) {\n    if (s[i] == s[i + 1]) t[i] = t[i + 1];\n\
    \    else t[i] = (s[i] < s[i + 1]);\n   }\n  }\n  { // create p1 (position of\
    \ LMS), B (bucket size) and tmp\n   for (int i = 0; i < n; ++i) {\n    if (i >\
    \ 0 && !t[i - 1] && t[i]) LMS[i] = p1.size(), p1.emplace_back(i);\n    ++B[s[i]];\n\
    \   }\n   for (int i = 0; i < K; ++i) start[i + 1] = start[i] + B[i];\n  }\n \
    \ { // induced-sort LSM-substrings\n   std::vector<int> r(K);\n   for (int i =\
    \ 0; i < K; ++i) r[i] = start[i + 1] - 1;\n   for (int i : p1) tmp[r[s[i]]--]\
    \ = i;\n\n   inducedSort(tmp);\n  }\n  std::vector<int> s1(p1.size());\n  bool\
    \ conti = false;\n  int K1 = 0;\n  { // create s1\n   std::vector<int> t1(p1.size()),\
    \ t2(p1.size(), 0);\n   int p = 0;\n   for (int ti = 0; ti < n; ++ti) {\n    int\
    \ i = tmp[ti];\n    if (LMS[i] != -1) t1[p++] = i;\n   }\n\n   // compress\n \
    \  for (int si = 1; si < t2.size(); ++si) {\n    int i = t1[si - 1], j = t1[si];\n\
    \    if (s[i] != s[j]) {\n     t2[si] = t2[si - 1] + 1;\n     continue;\n    }\n\
    \    ++i; ++j;\n    while (LMS[i] == -1 && LMS[j] == -1 && s[i] == s[j]) ++i,\
    \ ++j;\n    if (LMS[i] != -1 && LMS[j] != -1) {\n     t2[si] = t2[si - 1];\n \
    \    conti = true;\n    }\n    else {\n     t2[si] = t2[si - 1] + 1;\n    }\n\
    \   }\n   K1 = t2.back() + 1;\n\n   // re-order\n   for (int i = 0; i < t1.size();\
    \ ++i) s1[LMS[t1[i]]] = t2[i];\n  }\n  std::vector<int> sa1;\n  { // create sa1\
    \ (sometime recursion)\n   if (conti) {\n    sa1 = SuffixArray(s1, K1).sa;\n \
    \  }\n   else {\n    sa1.resize(s1.size());\n    for (int i = 0; i < s1.size();\
    \ ++i) sa1[s1[i]] = i;\n   }\n  }\n  { // create sa\n   sa.resize(n, -1);\n  \
    \ std::vector<int> r(K);\n   for (int i = 0; i < K; ++i) r[i] = start[i + 1] -\
    \ 1;\n   for (int pi = static_cast<int>(p1.size()) - 1; pi >= 0; --pi) {\n   \
    \ int i = p1[sa1[pi]];\n    sa[r[s[i]]--] = i;\n   }\n\n   inducedSort(sa);\n\
    \  }\n }\n\n void constructLCP(const std::vector<int> & s) {\n  const int n =\
    \ s.size() - 1;\n  lcp.resize(n + 1);\n  std::vector<int> rank(n + 1);\n  for\
    \ (int i = 0; i <= n; ++i) rank[sa[i]] = i;\n\n  int h = 0;\n  lcp[0] = 0;\n \
    \ for (int i = 0; i < n; ++i) {\n   int j = sa[rank[i] - 1];\n   if (h > 0) --h;\n\
    \   for (; j + h < n && i + h < n; ++h) if (s[j + h] != s[i + h]) break;\n   lcp[rank[i]\
    \ - 1] = h;\n  }\n }\n\n SuffixArray(std::vector<int> s, int k) : n(s.size()),\
    \ t(n) {\n  constructSA(s, k); constructLCP(s);\n }\npublic:\n std::string str;\n\
    \ std::vector<int> sa;\n std::vector<int> lcp;\n\n SuffixArray(const std::string\
    \ & s_) : str(s_), n(s_.size() + 1), t(n) {\n  int k = 0;\n  std::vector<int>\
    \ s(n);\n  { // compress s\n   std::vector<int> used(256, -1);\n   used[0] = 0;\
    \ s[n - 1] = 0;\n   for (int i = 0; i < n - 1; ++i) used[s_[i]] = 0;\n   for (int\
    \ i = 0; i < 256; ++i) if (used[i] != -1) used[i] = k++;\n   for (int i = 0; i\
    \ < n - 1; ++i) s[i] = used[s_[i]];\n  }\n  constructSA(s, k);\n  constructLCP(s);\n\
    \ }\n\n void debug_show() const {\n  std::cerr << \"idx  \" << \" sa  \" << \"\
    LCP  \" << \"suffix\\n\";\n  for (int i = 0; i < n; ++i) {\n   std::cerr << std::setw(3)\
    \ << std::setfill(' ') << i << \"  \";\n   std::cerr << std::setw(3) << std::setfill('\
    \ ') << sa[i] << \"  \";\n   std::cerr << std::setw(3) << std::setfill(' ') <<\
    \ lcp[i] << \"  \";\n   std::cerr << str.substr(sa[i]) << \"\\n\";\n  }\n }\n\
    };\n"
  code: "// @brief SuffixArray\n// @shortcut SuffixArray\n// @description SuffixArray+LCP\u306E\
    \u69CB\u7BC9\uFF0ESA-IS\u5B9F\u88C5\u306B\u3088\u308AO(|S|)\uFF0E\n// @docs string/SuffixArray.md\n\
    class SuffixArray {\nprivate:\n const int n;\n std::vector<bool> t;\n std::vector<int>\
    \ p1;\n\n void constructSA(const std::vector<int>& s, int K) {\n  std::vector<int>\
    \ B(K, 0);\n  std::vector<int> start(K + 1, 0);\n  std::vector<int> LMS(n, -1);\n\
    \  std::vector<int> tmp(n, -1);\n\n  auto inducedSort = [&](std::vector<int> &\
    \ a) {\n   std::vector<int> l(K), r(K);\n   for (int i = 0; i < K; ++i) l[i] =\
    \ start[i], r[i] = start[i + 1] - 1;\n\n   for (const auto& i : a) {\n    if (i\
    \ > 0 && !t[i - 1]) a[l[s[i - 1]]++] = i - 1;\n   }\n\n   for (int ti = n - 1;\
    \ ti >= 0; --ti) {\n    int i = a[ti];\n    if (i > 0 && t[i - 1]) a[r[s[i - 1]]--]\
    \ = i - 1;\n   }\n  };\n\n  { // create t (L/S-type)\n   t[n - 1] = true;\n  \
    \ for (int i = n - 2; i >= 0; --i) {\n    if (s[i] == s[i + 1]) t[i] = t[i + 1];\n\
    \    else t[i] = (s[i] < s[i + 1]);\n   }\n  }\n  { // create p1 (position of\
    \ LMS), B (bucket size) and tmp\n   for (int i = 0; i < n; ++i) {\n    if (i >\
    \ 0 && !t[i - 1] && t[i]) LMS[i] = p1.size(), p1.emplace_back(i);\n    ++B[s[i]];\n\
    \   }\n   for (int i = 0; i < K; ++i) start[i + 1] = start[i] + B[i];\n  }\n \
    \ { // induced-sort LSM-substrings\n   std::vector<int> r(K);\n   for (int i =\
    \ 0; i < K; ++i) r[i] = start[i + 1] - 1;\n   for (int i : p1) tmp[r[s[i]]--]\
    \ = i;\n\n   inducedSort(tmp);\n  }\n  std::vector<int> s1(p1.size());\n  bool\
    \ conti = false;\n  int K1 = 0;\n  { // create s1\n   std::vector<int> t1(p1.size()),\
    \ t2(p1.size(), 0);\n   int p = 0;\n   for (int ti = 0; ti < n; ++ti) {\n    int\
    \ i = tmp[ti];\n    if (LMS[i] != -1) t1[p++] = i;\n   }\n\n   // compress\n \
    \  for (int si = 1; si < t2.size(); ++si) {\n    int i = t1[si - 1], j = t1[si];\n\
    \    if (s[i] != s[j]) {\n     t2[si] = t2[si - 1] + 1;\n     continue;\n    }\n\
    \    ++i; ++j;\n    while (LMS[i] == -1 && LMS[j] == -1 && s[i] == s[j]) ++i,\
    \ ++j;\n    if (LMS[i] != -1 && LMS[j] != -1) {\n     t2[si] = t2[si - 1];\n \
    \    conti = true;\n    }\n    else {\n     t2[si] = t2[si - 1] + 1;\n    }\n\
    \   }\n   K1 = t2.back() + 1;\n\n   // re-order\n   for (int i = 0; i < t1.size();\
    \ ++i) s1[LMS[t1[i]]] = t2[i];\n  }\n  std::vector<int> sa1;\n  { // create sa1\
    \ (sometime recursion)\n   if (conti) {\n    sa1 = SuffixArray(s1, K1).sa;\n \
    \  }\n   else {\n    sa1.resize(s1.size());\n    for (int i = 0; i < s1.size();\
    \ ++i) sa1[s1[i]] = i;\n   }\n  }\n  { // create sa\n   sa.resize(n, -1);\n  \
    \ std::vector<int> r(K);\n   for (int i = 0; i < K; ++i) r[i] = start[i + 1] -\
    \ 1;\n   for (int pi = static_cast<int>(p1.size()) - 1; pi >= 0; --pi) {\n   \
    \ int i = p1[sa1[pi]];\n    sa[r[s[i]]--] = i;\n   }\n\n   inducedSort(sa);\n\
    \  }\n }\n\n void constructLCP(const std::vector<int> & s) {\n  const int n =\
    \ s.size() - 1;\n  lcp.resize(n + 1);\n  std::vector<int> rank(n + 1);\n  for\
    \ (int i = 0; i <= n; ++i) rank[sa[i]] = i;\n\n  int h = 0;\n  lcp[0] = 0;\n \
    \ for (int i = 0; i < n; ++i) {\n   int j = sa[rank[i] - 1];\n   if (h > 0) --h;\n\
    \   for (; j + h < n && i + h < n; ++h) if (s[j + h] != s[i + h]) break;\n   lcp[rank[i]\
    \ - 1] = h;\n  }\n }\n\n SuffixArray(std::vector<int> s, int k) : n(s.size()),\
    \ t(n) {\n  constructSA(s, k); constructLCP(s);\n }\npublic:\n std::string str;\n\
    \ std::vector<int> sa;\n std::vector<int> lcp;\n\n SuffixArray(const std::string\
    \ & s_) : str(s_), n(s_.size() + 1), t(n) {\n  int k = 0;\n  std::vector<int>\
    \ s(n);\n  { // compress s\n   std::vector<int> used(256, -1);\n   used[0] = 0;\
    \ s[n - 1] = 0;\n   for (int i = 0; i < n - 1; ++i) used[s_[i]] = 0;\n   for (int\
    \ i = 0; i < 256; ++i) if (used[i] != -1) used[i] = k++;\n   for (int i = 0; i\
    \ < n - 1; ++i) s[i] = used[s_[i]];\n  }\n  constructSA(s, k);\n  constructLCP(s);\n\
    \ }\n\n void debug_show() const {\n  std::cerr << \"idx  \" << \" sa  \" << \"\
    LCP  \" << \"suffix\\n\";\n  for (int i = 0; i < n; ++i) {\n   std::cerr << std::setw(3)\
    \ << std::setfill(' ') << i << \"  \";\n   std::cerr << std::setw(3) << std::setfill('\
    \ ') << sa[i] << \"  \";\n   std::cerr << std::setw(3) << std::setfill(' ') <<\
    \ lcp[i] << \"  \";\n   std::cerr << str.substr(sa[i]) << \"\\n\";\n  }\n }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: string/SuffixArray.hpp
  requiredBy: []
  timestamp: '2020-10-05 09:34:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/SuffixArray.hpp
layout: document
redirect_from:
- /library/string/SuffixArray.hpp
- /library/string/SuffixArray.hpp.html
title: SuffixArray
---
## 概要
文字列 $S$ に対して次の配列を $O(|S|)$ で構築する．
  - $\mathtt{sa}_i := $ $S$ のsuffixで辞書順 $i$ 番目のsuffixの開始位置
  - $\mathtt{lcp}_i := $ 辞書順 $i$ 番目のsuffixと辞書順 $i+1$ 番目のsuffixの最長共通接頭辞の長さ

なお，実装はSA-ISで行っている．

## 応用
### 任意のsuffixどうしの最長共通接頭辞の長さ
$S$ のsuffix $X:=S[i,|S|), Y:=S[j,|S|)$ について， $\mathtt{LCP}(X, Y)$ が知りたいとき．\\
$i', j'$ をそれぞれ $i = \mathtt{sa}[i']$, $j := \mathtt{sa}[j']$ となる数とすると，\\
$\mathtt{LCP}(X, Y) = \min_{k\in[i',j')}{\mathtt{lcp}_k}$ となる．\\
( $i'>j'$ のときは逆)\\
\\
$\mathtt{lcp}_i$ をSparseTableに入れれば，前計算 $O(|S|\log |S|)$, クエリ $O(1)$ となる．