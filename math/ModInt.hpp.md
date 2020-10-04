---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: math/ModInt.md
    document_title: ModInt
    links: []
  bundledCode: "#line 1 \"math/ModInt.hpp\"\n// @brief ModInt\n// @shortcut ModInt\n\
    // @description \u5B9A\u6570MOD\u4E0B\u306E\u6F14\u7B97\u30AF\u30E9\u30B9\uFF0E\
    \n// @docs math/ModInt.md\nclass ModInt {\n friend std::istream& operator>>(std::istream&\
    \ is, ModInt& obj);\nprivate:\n inline ModInt& setVal(int x) {\n  if (x < 0) while\
    \ (x < 0) x += MOD;\n  else while (x >= MOD) x -= MOD;\n  val = x;\n  return *this;\n\
    \ }\n inline ModInt& setVal(long long x) { return setVal((int)(x % MOD)); }\n\
    public:\n int val;\n ModInt() : val(0) {}\n ModInt(int n) { setVal(n); }\n ModInt(long\
    \ long n) { setVal(n); }\n ModInt& operator=(const ModInt & r) { return setVal(r.val);\
    \ }\n ModInt operator+() const { return *this; }\n ModInt operator-() const {\
    \ return ModInt(MOD - val); }\n ModInt& operator+=(const ModInt & r) { return\
    \ setVal(val + r.val); }\n ModInt& operator-=(const ModInt & r) { return *this\
    \ += -r; }\n ModInt& operator*=(const ModInt & r) { return setVal((long long)val\
    \ * r.val); }\n ModInt& operator/=(ModInt r) { return *this *= (r ^= MOD - 2);\
    \ }\n ModInt & operator^=(int p) {\n  ModInt t(*this); *this = 1;\n  for (; p;\
    \ p >>= 1, t *= t) if (p & 1) *this *= t;\n  return *this;\n }\n const ModInt\
    \ operator+(const ModInt & r) const { return ModInt(*this) += r; }\n const ModInt\
    \ operator-(const ModInt & r) const { return ModInt(*this) -= r; }\n const ModInt\
    \ operator*(const ModInt & r) const { return ModInt(*this) *= r; }\n const ModInt\
    \ operator/(const ModInt & r) const { return ModInt(*this) /= r; }\n const ModInt\
    \ operator^(int p) const { return ModInt(*this) ^= p; }\n};\nconst ModInt operator+(int\
    \ l, const ModInt & r) { return ModInt(l) += r; }\nconst ModInt operator-(int\
    \ l, const ModInt & r) { return ModInt(l) -= r; }\nconst ModInt operator*(int\
    \ l, const ModInt & r) { return ModInt(l) *= r; }\nconst ModInt operator/(int\
    \ l, const ModInt & r) { return ModInt(l) /= r; }\n\nstd::ostream& operator<<(std::ostream\
    \ & os, const ModInt & obj) { return os << obj.val; }\n/* friend */ std::istream&\
    \ operator>>(std::istream & is, ModInt & obj) {\n is >> obj.val;\n obj.setVal(obj.val);\n\
    \ return is;\n}\n/** ModInt **/\n"
  code: "// @brief ModInt\n// @shortcut ModInt\n// @description \u5B9A\u6570MOD\u4E0B\
    \u306E\u6F14\u7B97\u30AF\u30E9\u30B9\uFF0E\n// @docs math/ModInt.md\nclass ModInt\
    \ {\n friend std::istream& operator>>(std::istream& is, ModInt& obj);\nprivate:\n\
    \ inline ModInt& setVal(int x) {\n  if (x < 0) while (x < 0) x += MOD;\n  else\
    \ while (x >= MOD) x -= MOD;\n  val = x;\n  return *this;\n }\n inline ModInt&\
    \ setVal(long long x) { return setVal((int)(x % MOD)); }\npublic:\n int val;\n\
    \ ModInt() : val(0) {}\n ModInt(int n) { setVal(n); }\n ModInt(long long n) {\
    \ setVal(n); }\n ModInt& operator=(const ModInt & r) { return setVal(r.val); }\n\
    \ ModInt operator+() const { return *this; }\n ModInt operator-() const { return\
    \ ModInt(MOD - val); }\n ModInt& operator+=(const ModInt & r) { return setVal(val\
    \ + r.val); }\n ModInt& operator-=(const ModInt & r) { return *this += -r; }\n\
    \ ModInt& operator*=(const ModInt & r) { return setVal((long long)val * r.val);\
    \ }\n ModInt& operator/=(ModInt r) { return *this *= (r ^= MOD - 2); }\n ModInt\
    \ & operator^=(int p) {\n  ModInt t(*this); *this = 1;\n  for (; p; p >>= 1, t\
    \ *= t) if (p & 1) *this *= t;\n  return *this;\n }\n const ModInt operator+(const\
    \ ModInt & r) const { return ModInt(*this) += r; }\n const ModInt operator-(const\
    \ ModInt & r) const { return ModInt(*this) -= r; }\n const ModInt operator*(const\
    \ ModInt & r) const { return ModInt(*this) *= r; }\n const ModInt operator/(const\
    \ ModInt & r) const { return ModInt(*this) /= r; }\n const ModInt operator^(int\
    \ p) const { return ModInt(*this) ^= p; }\n};\nconst ModInt operator+(int l, const\
    \ ModInt & r) { return ModInt(l) += r; }\nconst ModInt operator-(int l, const\
    \ ModInt & r) { return ModInt(l) -= r; }\nconst ModInt operator*(int l, const\
    \ ModInt & r) { return ModInt(l) *= r; }\nconst ModInt operator/(int l, const\
    \ ModInt & r) { return ModInt(l) /= r; }\n\nstd::ostream& operator<<(std::ostream\
    \ & os, const ModInt & obj) { return os << obj.val; }\n/* friend */ std::istream&\
    \ operator>>(std::istream & is, ModInt & obj) {\n is >> obj.val;\n obj.setVal(obj.val);\n\
    \ return is;\n}\n/** ModInt **/"
  dependsOn: []
  isVerificationFile: false
  path: math/ModInt.hpp
  requiredBy: []
  timestamp: '2020-10-05 08:23:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ModInt.hpp
layout: document
redirect_from:
- /library/math/ModInt.hpp
- /library/math/ModInt.hpp.html
title: ModInt
---
## 概要
加減乗除+ベキ乗が定数MOD上で行える．\\
入出力も可．