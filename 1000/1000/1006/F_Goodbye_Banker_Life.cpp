#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long; using u64 = uint64_t;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;

class _mint{
public:
    ll mod, v;
    _mint(ll v = 0, ll mod = 1) : mod(mod), v(norm(v, mod)) {}
    static ll norm(ll x, ll m){ x %= m; return x < 0 ? x + m : x; }
    static tll gcd(ll a, ll b){
        if (b == 0) return {a, 1, 0};
        auto [g, x, y] = gcd(b, a % b);
        return {g, y, x - (a / b) * y};
    }

    _mint inv() const{
        assert(v);
        auto [g, x, y] = gcd(v, mod);
        assert(g == 1 || g == -1);
        if(g == -1) x *= -1;
        return _mint(x, mod);
    }

    _mint pow(ll e) const{
        assert(e >= 0);
        _mint base = *this, ret(1, mod);
        while(e){
            if(e & 1) ret *= base;
            base *= base; e >>= 1ll;
        }
        return ret;
    }

    _mint& operator+=(const _mint& ot){
        assert(mod == ot.mod);
        v += ot.v;
        if (v >= mod) v -= mod;
        return *this;
    }

    _mint& operator-=(const _mint& ot){
        assert(mod == ot.mod);
        v -= ot.v;
        if (v < 0) v += mod;
        return *this;
    }

    _mint& operator*=(const _mint& ot){
        assert(mod == ot.mod);
        v = (ll)((i128)v * ot.v % mod);
        return *this;
    }
    _mint& operator/=(const _mint& ot){ return (*this) *= ot.inv(); }

    friend _mint operator+(_mint a, const _mint& b){ return a += b; }
    friend _mint operator-(_mint a, const _mint& b){ return a -= b; }
    friend _mint operator*(_mint a, const _mint& b){ return a *= b; }
    friend _mint operator/(_mint a, const _mint& b){ return a /= b; }
    _mint& operator+=(ll b){ return (*this) += _mint(b, mod); }
    _mint& operator-=(ll b){ return (*this) -= _mint(b, mod); }
    _mint& operator*=(ll b){ return (*this) *= _mint(b, mod); }
    _mint& operator/=(ll b){ return (*this) /= _mint(b, mod); }
    friend _mint operator+(_mint a, ll b){ return a += b; }
    friend _mint operator-(_mint a, ll b){ return a -= b; }
    friend _mint operator*(_mint a, ll b){ return a *= b; }
    friend _mint operator/(_mint a, ll b){ return a /= b; }
    friend ostream& operator<<(ostream& os, const _mint& a){ return os << a.v; }
};

class _lucas{ // mod == prime
public:
    int mod; vector <_mint> fac, inv;
    _lucas(int mod) : mod(mod), fac(mod), inv(mod){ // O(mod)
        fac[0] = _mint(1, mod);
        for(int i = 1;i < mod;i++) fac[i] = fac[i - 1] * i;
        inv[mod - 1] = fac[mod - 1].pow(mod - 2);
        for(int i = mod - 2;i >= 0;i--) inv[i] = inv[i + 1] * (i + 1);
    }

    _mint cal(ll n, ll r){ // O(1)
        if(n < r) return _mint(0, mod);
        return fac[n] * inv[r] * inv[n - r];
    }

    int ret(ll n, ll r){ // O(log n)
        if(n < r || n < 0 || r < 0) return 0;
        if(!n || !r || n == r) return 1;
        return (cal(n % mod, r % mod) * ret(n / mod, r / mod)).v;
    }
}; _lucas luc(2);

void run(){
    cin >> n >> m; 
    for(int i = 0;i < n;i++){
        cout << luc.ret(n - 1, i) * m << " ";
    }
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}