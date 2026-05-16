#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll dp[MAX][2], a[MAX];
vector <ll> adj[MAX];

void dfs(ll cur, ll pre) {
    for (auto& nxt : adj[cur]) {
        if (nxt == pre) continue;
        dfs(nxt, cur);
    }

    for (auto& nxt : adj[cur]) {
        if (nxt == pre) continue;
        dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[cur][1] += max(dp[nxt][0], dp[nxt][1] - 2 * m);
    }
    dp[cur][1] += a[cur];

    return;
}

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m;

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            cin >> a[i]; adj[i].clear();
        }

        for (int i = 1; i < n; i++) {
            ll st, en;
            cin >> st >> en;
            adj[st].push_back(en);
            adj[en].push_back(st);
        }
        dfs(1, -1);

        cout << max(dp[1][0], dp[1][1]) << "\n";
    }




    return 0;
}
