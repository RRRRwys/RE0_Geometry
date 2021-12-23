/* Author: rrrr_wys
 * https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_A
 **/

#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
typedef long double db;
typedef long long ll;
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

template <typename T> ostream &operator<<(ostream &out, vector<T> &_vec) {
  for (auto &v : _vec)
    out << v << " ";
  return out;
}

void de() { cout << endl; }
template <typename T, typename... Targs> void de(T value, Targs... Fargs) {
  cout << value << ' ';
  if ((sizeof...(Fargs)) > 0) {
    de(Fargs...);
  } else {
    de();
  }
}

struct P {
  db x, y;
  P() {}
  P(db _x, db _y) : x(_x), y(_y) {}
  void read() { cin >> x >> y; }
  P operator+(P o) { return P(x + o.x, y + o.y); }
  P operator-(P o) { return P(x - o.x, y - o.y); }
  P operator*(db d) { return P(x * d, y * d); }
  P operator/(db d) { return P(x / d, y / d); }
  db abs2() { return x * x + y * y; }
  db dot(P o) { return x * o.x + y * o.y; }
  db det(P o) { return x * o.y - y * o.x; }
};

P proj(P p1, P p2, P q) {
  P dir = p2 - p1;
  return dir * (q - p1).dot(dir) / (p2 - p1).abs2() + p1;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  P p1, p2;
  p1.read();
  p2.read();
  int q;
  cin >> q;
  while (q--) {
    P p;
    p.read();
    p = proj(p1, p2, p);
    cout << fixed << setprecision(12);
    cout << p.x << " " << p.y << "\n";
  }
}
