#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
vector <vector<ll>> a;


int main() {
    fastio;

    cin >> n >> m >> k;
    a.resize(m + 1, vector<ll>(n + 1));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) {
            cin >> a[j][i];
            a[j][i] |= a[j][i - 1];
        }
    }

    while(k--){
        ll num; cin >> num;
        ll l = 1, r = n;
        for(int i = 1;i <= num;i++){
            ll s, e; char c; cin >> s >> c >> e;
            if(c == '>'){
                ll ub = upper_bound(all(a[s]), e) - a[s].begin();
                l = max(l, ub);
            }
            else{
                auto it = lower_bound(all(a[s]), e);
                ll lb;
                if(it == a[s].begin()) lb = 0;
                else lb = --it - a[s].begin();

                r = min(r, lb);
            }
        }

        if(l <= r) cout << l << "\n";
        else cout << -1 << "\n";
    }


    return 0;
}
