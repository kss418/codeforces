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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX], p[MAX];
vector <ll> adj[MAX];

bool dfs(ll cur, ll v){
    bool ret = 1;
    ll now = a[cur] - v;
    if(now < 0) v -= now;
    if(v > INF) return 0;

    for(auto& nxt : adj[cur]){
        ret &= min(dfs(nxt, v), ret);
    }

    if(adj[cur].empty() && now < 0) ret = 0;
    return ret;
}

class _bs { // 0-based index
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll ret = 1;
        for(auto& i : adj[1]) ret &= dfs(i, cur - a[1]);
        return ret;
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) >> 1ll;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i], adj[i].clear();
        for(int i = 2;i <= n;i++) {
            cin >> p[i]; adj[p[i]].push_back(i);
        }

        _bs bs(a[1], 3e14);
        cout << bs.ret() << "\n";
    }


    return 0;
}
