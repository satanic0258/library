#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <bits/stdc++.h>
#include "../../string/SuffixArray.hpp"

#define REP(w, n) for(int w=0; w<int(n); ++w)

int main(){
 std::string s;
 std::cin >> s;

 SuffixArray sa(s);
 REP(i, s.size()) {
  std::cout << sa.sa[i + 1] << (i + 1 == s.size() ? '\n' : ' ');
 }
}