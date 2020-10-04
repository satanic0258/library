// @brief ModInt
// @shortcut ModInt
// @description 定数MOD下の演算クラス．
// @docs math/ModInt.md
class ModInt {
 friend std::istream& operator>>(std::istream& is, ModInt& obj);
private:
 inline ModInt& setVal(int x) {
  if (x < 0) while (x < 0) x += MOD;
  else while (x >= MOD) x -= MOD;
  val = x;
  return *this;
 }
 inline ModInt& setVal(long long x) { return setVal((int)(x % MOD)); }
public:
 int val;
 ModInt() : val(0) {}
 ModInt(int n) { setVal(n); }
 ModInt(long long n) { setVal(n); }
 ModInt& operator=(const ModInt & r) { return setVal(r.val); }
 ModInt operator+() const { return *this; }
 ModInt operator-() const { return ModInt(MOD - val); }
 ModInt& operator+=(const ModInt & r) { return setVal(val + r.val); }
 ModInt& operator-=(const ModInt & r) { return *this += -r; }
 ModInt& operator*=(const ModInt & r) { return setVal((long long)val * r.val); }
 ModInt& operator/=(ModInt r) { return *this *= (r ^= MOD - 2); }
 ModInt & operator^=(int p) {
  ModInt t(*this); *this = 1;
  for (; p; p >>= 1, t *= t) if (p & 1) *this *= t;
  return *this;
 }
 const ModInt operator+(const ModInt & r) const { return ModInt(*this) += r; }
 const ModInt operator-(const ModInt & r) const { return ModInt(*this) -= r; }
 const ModInt operator*(const ModInt & r) const { return ModInt(*this) *= r; }
 const ModInt operator/(const ModInt & r) const { return ModInt(*this) /= r; }
 const ModInt operator^(int p) const { return ModInt(*this) ^= p; }
};
const ModInt operator+(int l, const ModInt & r) { return ModInt(l) += r; }
const ModInt operator-(int l, const ModInt & r) { return ModInt(l) -= r; }
const ModInt operator*(int l, const ModInt & r) { return ModInt(l) *= r; }
const ModInt operator/(int l, const ModInt & r) { return ModInt(l) /= r; }

std::ostream& operator<<(std::ostream & os, const ModInt & obj) { return os << obj.val; }
/* friend */ std::istream& operator>>(std::istream & is, ModInt & obj) {
 is >> obj.val;
 obj.setVal(obj.val);
 return is;
}
/** ModInt **/