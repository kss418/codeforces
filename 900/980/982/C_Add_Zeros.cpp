#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 301010;
constexpr ll MOD = 998244353;
ll a[MAX], result;
map <ll, vector<ll>> adj;
map <ll, bool> v;

void dfs(ll cur){
    if(v[cur]) return; v[cur] = 1;
    result = max(result, cur);

    for(auto& nxt: adj[cur]) dfs(nxt);
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; adj.clear(); result = 0;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            adj[a[i] + i - 1].push_back(a[i] + 2 * i - 2);
        }
        v.clear(); dfs(n);

        cout << result << "\n";
    }

    return 0;
}
