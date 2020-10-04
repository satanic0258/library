---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n#include <bits/stdc++.h>\n#line 1 \"math/ModInt.hpp\"\n// @brief ModInt\n//\
    \ @shortcut ModInt\n// @description \u5B9A\u6570MOD\u4E0B\u306E\u6F14\u7B97\u30AF\
    \u30E9\u30B9\uFF0E\n// @docs math/ModInt.md\nclass ModInt {\n friend std::istream&\
    \ operator>>(std::istream& is, ModInt& obj);\nprivate:\n inline ModInt& setVal(int\
    \ x) {\n  if (x < 0) while (x < 0) x += MOD;\n  else while (x >= MOD) x -= MOD;\n\
    \  val = x;\n  return *this;\n }\n inline ModInt& setVal(long long x) { return\
    \ setVal((int)(x % MOD)); }\npublic:\n int val;\n ModInt() : val(0) {}\n ModInt(int\
    \ n) { setVal(n); }\n ModInt(long long n) { setVal(n); }\n ModInt& operator=(const\
    \ ModInt & r) { return setVal(r.val); }\n ModInt operator+() const { return *this;\
    \ }\n ModInt operator-() const { return ModInt(MOD - val); }\n ModInt& operator+=(const\
    \ ModInt & r) { return setVal(val + r.val); }\n ModInt& operator-=(const ModInt\
    \ & r) { return *this += -r; }\n ModInt& operator*=(const ModInt & r) { return\
    \ setVal((long long)val * r.val); }\n ModInt& operator/=(ModInt r) { return *this\
    \ *= (r ^= MOD - 2); }\n ModInt & operator^=(int p) {\n  ModInt t(*this); *this\
    \ = 1;\n  for (; p; p >>= 1, t *= t) if (p & 1) *this *= t;\n  return *this;\n\
    \ }\n const ModInt operator+(const ModInt & r) const { return ModInt(*this) +=\
    \ r; }\n const ModInt operator-(const ModInt & r) const { return ModInt(*this)\
    \ -= r; }\n const ModInt operator*(const ModInt & r) const { return ModInt(*this)\
    \ *= r; }\n const ModInt operator/(const ModInt & r) const { return ModInt(*this)\
    \ /= r; }\n const ModInt operator^(int p) const { return ModInt(*this) ^= p; }\n\
    };\nconst ModInt operator+(int l, const ModInt & r) { return ModInt(l) += r; }\n\
    const ModInt operator-(int l, const ModInt & r) { return ModInt(l) -= r; }\nconst\
    \ ModInt operator*(int l, const ModInt & r) { return ModInt(l) *= r; }\nconst\
    \ ModInt operator/(int l, const ModInt & r) { return ModInt(l) /= r; }\n\nstd::ostream&\
    \ operator<<(std::ostream & os, const ModInt & obj) { return os << obj.val; }\n\
    /* friend */ std::istream& operator>>(std::istream & is, ModInt & obj) {\n is\
    \ >> obj.val;\n obj.setVal(obj.val);\n return is;\n}\n/** ModInt **/\n#line 4\
    \ \"test/aoj/NTL_1_B.test.cpp\"\n\nint main(){\n ModInt m;\n int n;\n std::cin\
    \ >> m >> n;\n std::cout << (m ^ n) << std::endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n#include <bits/stdc++.h>\n#include \"../../math/ModInt.hpp\"\n\nint main(){\n\
    \ ModInt m;\n int n;\n std::cin >> m >> n;\n std::cout << (m ^ n) << std::endl;\n\
    }"
  dependsOn:
  - math/ModInt.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-10-05 08:31:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
