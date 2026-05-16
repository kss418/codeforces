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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[26], all, result;
ll fac[MAX], dp[26][MAX];

class _inv {
public:
    _inv() {}
    ll pow_mod(ll a, ll b, ll c) {
        if (!b) return 1;
        ll ret = pow_mod(a, b / 2, c) % c;

        if (b % 2) return ((ret * ret) % c * (a % c)) % c;
        return (ret * ret) % c;
    }

    ll prime_inv(ll a, ll b) {
        return pow_mod(a, b - 2, b);
    }

    ll ret(ll a, ll b, ll m) { // (a * b^-1) % m 반환 m == prime
        return (a % m * prime_inv(b, m) % m) % m;
    }
}; _inv inv;

void init(){
    for(int i = 0;i < 26;i++){
        for(int j = 0;j <= all;j++) dp[i][j] = -1;
    }
}

ll solve(ll cur, ll sum){
    if(sum < 0) return 0;
    if(cur == -1) return sum == 0;

    ll& ret = dp[cur][sum];
    if(ret != -1) return ret; ret = 0;

    if(a[cur]) ret += solve(cur - 1, sum); ret %= MOD;
    ret += solve(cur - 1, sum - a[cur]);

    return ret %= MOD;
}

void run(){
    all = result = 0;
    for(int i = 0;i < 26;i++) cin >> a[i], all += a[i];
    init();

    ll cnt = solve(25, (all + 1) / 2);
    ll result = (fac[(all + 1) / 2] * fac[all / 2]) % MOD;
    result *= cnt; result %= MOD;

    for(int i = 0;i < 26;i++){
        result *= inv.ret(1, fac[a[i]], MOD);
        result %= MOD;
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t; fac[0] = 1;
    for(int i = 1;i < MAX;i++) fac[i] = (fac[i - 1] * i) % MOD;
    while(t--) run();

    return 0;
}
