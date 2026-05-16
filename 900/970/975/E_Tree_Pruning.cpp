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
constexpr ll MAX = 501010;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll mx, cnt[MAX], leap[MAX];

ll dfs(ll cur, ll pre, ll dep){
    mx = max(mx, dep);
    cnt[dep]++;

    ll mx = dep;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        mx = max(dfs(nxt, cur, dep + 1), mx);
    }

    leap[mx]++;
    if(adj[cur].size() == 1 && dep != 1) return dep;
    return mx;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) {
            adj[i].clear();
            leap[i] = 0; cnt[i] = 0;
        }

        for(int i = 1;i < n;i++){
            ll s, e;
            cin >> s >> e;
            adj[s].push_back(e);
            adj[e].push_back(s);
        }

        mx = 0;
        dfs(1, -1, 1);
        ll result = INF;
        for(int i = 1;i <= mx;i++){
            cnt[i] += cnt[i - 1];
            leap[i] += leap[i - 1];
        }

        for(int i = 1;i <= mx;i++){
            ll cur = cnt[mx] - cnt[i];
            cur += leap[i - 1];
            result = min(result, cur);
        }

        cout << result << "\n";
    }

    return 0;
}
