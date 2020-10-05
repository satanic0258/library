// @brief SuffixArray
// @shortcut SuffixArray
// @description SuffixArray+LCPの構築．SA-IS実装によりO(|S|)．
// @docs string/SuffixArray.md
class SuffixArray {
private:
 const int n;
 std::vector<bool> t;
 std::vector<int> p1;

 void constructSA(const std::vector<int>& s, int K) {
  std::vector<int> B(K, 0);
  std::vector<int> start(K + 1, 0);
  std::vector<int> LMS(n, -1);
  std::vector<int> tmp(n, -1);

  auto inducedSort = [&](std::vector<int> & a) {
   std::vector<int> l(K), r(K);
   for (int i = 0; i < K; ++i) l[i] = start[i], r[i] = start[i + 1] - 1;

   for (const auto& i : a) {
    if (i > 0 && !t[i - 1]) a[l[s[i - 1]]++] = i - 1;
   }

   for (int ti = n - 1; ti >= 0; --ti) {
    int i = a[ti];
    if (i > 0 && t[i - 1]) a[r[s[i - 1]]--] = i - 1;
   }
  };

  { // create t (L/S-type)
   t[n - 1] = true;
   for (int i = n - 2; i >= 0; --i) {
    if (s[i] == s[i + 1]) t[i] = t[i + 1];
    else t[i] = (s[i] < s[i + 1]);
   }
  }
  { // create p1 (position of LMS), B (bucket size) and tmp
   for (int i = 0; i < n; ++i) {
    if (i > 0 && !t[i - 1] && t[i]) LMS[i] = p1.size(), p1.emplace_back(i);
    ++B[s[i]];
   }
   for (int i = 0; i < K; ++i) start[i + 1] = start[i] + B[i];
  }
  { // induced-sort LSM-substrings
   std::vector<int> r(K);
   for (int i = 0; i < K; ++i) r[i] = start[i + 1] - 1;
   for (int i : p1) tmp[r[s[i]]--] = i;

   inducedSort(tmp);
  }
  std::vector<int> s1(p1.size());
  bool conti = false;
  int K1 = 0;
  { // create s1
   std::vector<int> t1(p1.size()), t2(p1.size(), 0);
   int p = 0;
   for (int ti = 0; ti < n; ++ti) {
    int i = tmp[ti];
    if (LMS[i] != -1) t1[p++] = i;
   }

   // compress
   for (int si = 1; si < t2.size(); ++si) {
    int i = t1[si - 1], j = t1[si];
    if (s[i] != s[j]) {
     t2[si] = t2[si - 1] + 1;
     continue;
    }
    ++i; ++j;
    while (LMS[i] == -1 && LMS[j] == -1 && s[i] == s[j]) ++i, ++j;
    if (LMS[i] != -1 && LMS[j] != -1) {
     t2[si] = t2[si - 1];
     conti = true;
    }
    else {
     t2[si] = t2[si - 1] + 1;
    }
   }
   K1 = t2.back() + 1;

   // re-order
   for (int i = 0; i < t1.size(); ++i) s1[LMS[t1[i]]] = t2[i];
  }
  std::vector<int> sa1;
  { // create sa1 (sometime recursion)
   if (conti) {
    sa1 = SuffixArray(s1, K1).sa;
   }
   else {
    sa1.resize(s1.size());
    for (int i = 0; i < s1.size(); ++i) sa1[s1[i]] = i;
   }
  }
  { // create sa
   sa.resize(n, -1);
   std::vector<int> r(K);
   for (int i = 0; i < K; ++i) r[i] = start[i + 1] - 1;
   for (int pi = static_cast<int>(p1.size()) - 1; pi >= 0; --pi) {
    int i = p1[sa1[pi]];
    sa[r[s[i]]--] = i;
   }

   inducedSort(sa);
  }
 }

 void constructLCP(const std::vector<int> & s) {
  const int n = s.size() - 1;
  lcp.resize(n + 1);
  std::vector<int> rank(n + 1);
  for (int i = 0; i <= n; ++i) rank[sa[i]] = i;

  int h = 0;
  lcp[0] = 0;
  for (int i = 0; i < n; ++i) {
   int j = sa[rank[i] - 1];
   if (h > 0) --h;
   for (; j + h < n && i + h < n; ++h) if (s[j + h] != s[i + h]) break;
   lcp[rank[i] - 1] = h;
  }
 }

 SuffixArray(std::vector<int> s, int k) : n(s.size()), t(n) {
  constructSA(s, k); constructLCP(s);
 }
public:
 std::string str;
 std::vector<int> sa;
 std::vector<int> lcp;

 SuffixArray(const std::string & s_) : str(s_), n(s_.size() + 1), t(n) {
  int k = 0;
  std::vector<int> s(n);
  { // compress s
   std::vector<int> used(256, -1);
   used[0] = 0; s[n - 1] = 0;
   for (int i = 0; i < n - 1; ++i) used[s_[i]] = 0;
   for (int i = 0; i < 256; ++i) if (used[i] != -1) used[i] = k++;
   for (int i = 0; i < n - 1; ++i) s[i] = used[s_[i]];
  }
  constructSA(s, k);
  constructLCP(s);
 }

 void debug_show() const {
  std::cerr << "idx  " << " sa  " << "LCP  " << "suffix\n";
  for (int i = 0; i < n; ++i) {
   std::cerr << std::setw(3) << std::setfill(' ') << i << "  ";
   std::cerr << std::setw(3) << std::setfill(' ') << sa[i] << "  ";
   std::cerr << std::setw(3) << std::setfill(' ') << lcp[i] << "  ";
   std::cerr << str.substr(sa[i]) << "\n";
  }
 }
};