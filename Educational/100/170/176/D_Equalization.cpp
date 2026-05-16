#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[65][65][65];

ll solve(ll ns, ll ms, ll cur){
    ll& ret = dp[ns][ms][cur];
    if(ret != -1) return ret; ret = INF;
    if(!cur){ return ret = (ns || ms ? INF : 0); }

    if(ns >= cur) ret = min(ret, solve(max(ns - cur, 0ll), ms, cur - 1) + (1ll << cur));
    if(ms >= cur) ret = min(ret, solve(ns, max(ms - cur, 0ll), cur - 1) + (1ll << cur));
    ret = min(ret, solve(ns, ms, cur - 1));

    return ret;
}

void run(){
    cin >> n >> m;

    ll result = INF;
    for(ll i = 0;i <= 62;i++){
        for(ll j = 0;j <= 62;j++){
            if((n >> i) != (m >> j)) continue;
            result = min(result, solve(i, j, 62));
        }
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    memset(dp, -1, sizeof(dp));
    while(t--) run();

    return 0;
}
