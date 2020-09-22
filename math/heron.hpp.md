---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: heron.md
    document_title: "\u30D8\u30ED\u30F3\u306E\u516C\u5F0F"
    links: []
  bundledCode: "#line 1 \"math/heron.hpp\"\n// @brief \u30D8\u30ED\u30F3\u306E\u516C\
    \u5F0F\n// @shortcut heron\n// @description \u30D8\u30ED\u30F3\u306E\u516C\u5F0F\
    \u3092\u7528\u3044\u3066\u4E09\u89D2\u5F62\u306E\u9762\u7A4D\u3092\u8A08\u7B97\
    \u3059\u308B\uFF0EO(1)\uFF0E\n// @docs heron.md\ndouble Heron(double a, double\
    \ b, double c) {\n double s = (a + b + c) / 2;\n return std::sqrt(s*(s - a)*(s\
    \ - b)*(s - c));\n}\n"
  code: "// @brief \u30D8\u30ED\u30F3\u306E\u516C\u5F0F\n// @shortcut heron\n// @description\
    \ \u30D8\u30ED\u30F3\u306E\u516C\u5F0F\u3092\u7528\u3044\u3066\u4E09\u89D2\u5F62\
    \u306E\u9762\u7A4D\u3092\u8A08\u7B97\u3059\u308B\uFF0EO(1)\uFF0E\n// @docs heron.md\n\
    double Heron(double a, double b, double c) {\n double s = (a + b + c) / 2;\n return\
    \ std::sqrt(s*(s - a)*(s - b)*(s - c));\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/heron.hpp
  requiredBy: []
  timestamp: '2020-09-13 23:46:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/heron.hpp
layout: document
redirect_from:
- /library/math/heron.hpp
- /library/math/heron.hpp.html
title: "\u30D8\u30ED\u30F3\u306E\u516C\u5F0F"
---
