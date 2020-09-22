// @brief Binary Indexed Tree
// @shortcut BIT
// @description BIT(Fenwick木)．単点更新区間和をO(logN)で行う．
// @docs data-structure/BIT.md
template <class T = int>
struct BIT {
 int N;
 std::vector<T> bit;
 BIT() : N(0) {}
 BIT(int n) : N(n), bit(N + 1, 0) {}
 BIT(int n, T init) : N(n), bit(N + 1, init) {}

 // bit[i] += w;
 void add(int i, T w) { 
  for (int x = ++i; x <= N; x += x & -x) bit[x] += w;
 }
 // return sum [0, i);
 T sum(int i) {
  T res = 0;
  for (int x = i; x > 0; x -= x & -x) res += bit[x];
  return res;
 }
 // return sum [i, j);
 T sum(int i, int j) { return sum(j) - sum(i); }
 const T& operator[](const int& i) const { return bit[i]; }
};