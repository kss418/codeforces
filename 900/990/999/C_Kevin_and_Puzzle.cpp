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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][2];

void init(){
    for(int i = 0;i <= n;i++) dp[i][0] = dp[i][1] = -1;
}

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;

    if(!cnt){
        if(a[cur - 1] == a[cur]) ret += solve(cur - 1, 0);
        if(cur < 2 || a[cur - 2] + 1 == a[cur]) ret += solve(cur - 1, 1);
    }
    else ret = solve(cur - 1, 0);

    return ret %= MOD;
}

void run(){
    cin >> n; init(); dp[0][0] = 1;
    for(int i = 1;i <= n;i++) cin >> a[i];

    cout << (solve(n, 1) + solve(n, 0)) % MOD << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
