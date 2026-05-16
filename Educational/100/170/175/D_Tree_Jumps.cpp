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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll p[MAX], dp[MAX], sum[MAX];
vector <ll> adj[MAX];
vector <ll> d[MAX];

void init(){
    for(int i = 1;i <= n;i++) {
        dp[i] = sum[i] = 0;
        adj[i].clear();
        d[i].clear();
    }
    dp[1] = 1;
}

void dfs(ll cur, ll dep){
    d[dep].push_back(cur);
    for(auto& nxt : adj[cur]){
        dfs(nxt, dep + 1);
    }
}

void run(){
    cin >> n; init();
    for(int i = 2;i <= n;i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }

    for(int i = 2;i <= n;i++){
        if(p[i] != 1) continue;
        dp[i] = 1; sum[2]++;
    }
    dfs(1, 1);

    for(int i = 3;i <= n;i++){
        if(d[i].empty()) break;
        for(auto& j : d[i]){
            ll pa = p[j];
            dp[j] = (sum[i - 1] - dp[pa] + MOD) % MOD;
            sum[i] += dp[j];
        }
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        result += dp[i];
        result %= MOD;
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
