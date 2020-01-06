---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: data-structure/UnionFind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/UnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-06 22:08:24+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
class UnionFind {
private:
	std::vector<int> par;
	std::vector<int> siz;

public:
	UnionFind(int sz_) : par(sz_), siz(sz_, 1) {
		for (int i = 0; i < sz_; ++i) par[i] = i;
	}
	void init(int sz_) {
		par.resize(sz_);
		siz.resize(sz_, 1);
		for (int i = 0; i < sz_; ++i) par[i] = i;
	}
	int find(int x) {
		while (par[x] != x) x = par[x] = par[par[x]];
		return x;
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (siz[x] < siz[y]) std::swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return siz[find(x)];
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/UnionFind.cpp"
class UnionFind {
private:
	std::vector<int> par;
	std::vector<int> siz;

public:
	UnionFind(int sz_) : par(sz_), siz(sz_, 1) {
		for (int i = 0; i < sz_; ++i) par[i] = i;
	}
	void init(int sz_) {
		par.resize(sz_);
		siz.resize(sz_, 1);
		for (int i = 0; i < sz_; ++i) par[i] = i;
	}
	int find(int x) {
		while (par[x] != x) x = par[x] = par[par[x]];
		return x;
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (siz[x] < siz[y]) std::swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return siz[find(x)];
	}
};
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

