// @brief ヘロンの公式
// @shortcut heron
// @description ヘロンの公式を用いて三角形の面積を計算する．O(1)．
// @docs heron.md
double Heron(double a, double b, double c) {
 double s = (a + b + c) / 2;
 return std::sqrt(s*(s - a)*(s - b)*(s - c));
}