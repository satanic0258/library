#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0079&lang=ja"
#include <bits/stdc++.h>
#include "../../math/heron.hpp"

#define ERROR 1e-6

#define FOR(w, a, n) for(int w=(a);w<(n);++w)

int main() {
 std::vector<double> x, y;
 double xi, yi; char tmp;
 while (std::cin >> xi >> tmp >> yi) x.emplace_back(xi), y.emplace_back(yi);
 int n = x.size();
 double ans = 0;
 FOR(i, 1, n - 1) ans += Heron(std::hypot(x[0] - x[i], y[0] - y[i]), std::hypot(x[0] - x[i + 1], y[0] - y[i + 1]), std::hypot(x[i + 1] - x[i], y[i + 1] - y[i]));
 std::cout << ans << std::endl;

 return 0;
}