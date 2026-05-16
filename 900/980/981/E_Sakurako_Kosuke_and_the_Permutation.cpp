#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
constexpr ll MAX = 1010101;
constexpr ll MOD = 998244353;
ll a[MAX];
bool v[MAX];

ll dfs(ll cur, ll cnt){
    if(v[cur]) return cnt - 1;
    v[cur] = 1;
    return dfs(a[cur], cnt + 1);
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        vector <ll> cycle;
        memset(v, 0, sizeof(v));

        for(int i = 1;i <= n;i++){
            if(v[i]) continue;
            cycle.push_back(dfs(i, 1)); v[i] = 1;
        }

        ll result = 0;
        for(auto& i : cycle) {
            ll now = i - 2;
            if(now <= 0) continue;
            result += now / 2 + now % 2;
        }

        cout << result << "\n";
    }


    return 0;
}
