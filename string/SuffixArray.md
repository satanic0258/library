## 概要
文字列 $S$ に対して次の配列を $O(|S|)$ で構築する．
  - $\mathtt{sa}_i := $ $S$ のsuffixで辞書順 $i$ 番目のsuffixの開始位置
  - $\mathtt{lcp}_i := $ 辞書順 $i$ 番目のsuffixと辞書順 $i+1$ 番目のsuffixの最長共通接頭辞の長さ

なお，実装はSA-ISで行っている．

## 応用
### 任意のsuffixどうしの最長共通接頭辞の長さ
$S$ のsuffix $X:=S[i,|S|), Y:=S[j,|S|)$ について， $\mathtt{LCP}(X, Y)$ が知りたいとき．\\
$i', j'$ をそれぞれ $i = \mathtt{sa}[i']$, $j := \mathtt{sa}[j']$ となる数とすると，\\
$\mathtt{LCP}(X, Y) = \min_{k\in[i',j')}{\mathtt{lcp}_k}$ となる．\\
( $i'>j'$ のときは逆)\\
\\
$\mathtt{lcp}_i$ をSparseTableに入れれば，前計算 $O(|S|\log |S|)$, クエリ $O(1)$ となる．