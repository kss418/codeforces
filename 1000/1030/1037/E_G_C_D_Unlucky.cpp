#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX];

class _gcd {
public:
    _gcd() {}

    tll init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
};

void run(){
    cin >> n; bool flag = 1; _gcd g;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    for(int i = 2;i <= n;i++){
        if(a[i - 1] % a[i]) flag = 0;
    }
 
    for(int i = n - 1;i >= 1;i--){
        if(b[i + 1] % b[i]) flag = 0;
    }
    ll now = a[n];
    if(now != b[1]) flag = 0;

    for(int i = 1;i < n;i++){
        ll num = g.ret(a[i], b[i + 1]);
        if(now != num) flag = 0;
    }

    cout << (flag ? "YES" : "NO") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

