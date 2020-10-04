#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include <bits/stdc++.h>

constexpr int MOD = 1000000007;
#include "../../math/ModInt.hpp"

int main(){
	ModInt m;
	int n;
	std::cin >> m >> n;
	std::cout << (m ^ n) << std::endl;
}