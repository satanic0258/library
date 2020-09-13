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


# :warning: ヘロンの公式 <small>(math/heron.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/heron.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 20:51:18+09:00




﻿## 概要

三角形の辺の長さがそれぞれ $a$, $b$, $c$ であったとき，\\
$s=\frac{a+b+c}{2}$ とおくと，面積 $S$ は\\
$S = \sqrt{s(s-a)(s-b)(s-c)}$
である．

## Code

<a id="unbundled"></a>
{% raw %}
```cpp
﻿// @brief ヘロンの公式
// @shortcut heron
// @description ヘロンの公式を用いて三角形の面積を計算する．O(1)．
// @docs heron.md
double Heron(double a, double b, double c) {
 double s = (a + b + c) / 2;
 return std::sqrt(s*(s - a)*(s - b)*(s - c));
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/heron.cpp"
﻿// @brief ヘロンの公式
// @shortcut heron
// @description ヘロンの公式を用いて三角形の面積を計算する．O(1)．
// @docs heron.md
double Heron(double a, double b, double c) {
 double s = (a + b + c) / 2;
 return std::sqrt(s*(s - a)*(s - b)*(s - c));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

