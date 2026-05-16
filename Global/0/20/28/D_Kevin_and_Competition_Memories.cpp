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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> a, b;

ll lb(ll s, ll e, ll k){
    s = *lower_bound(all(b), s);

    if(s > e) return 1;
    ll ret = a.size() - (lower_bound(all(a), s) - a.begin()) + 1;
    return ret;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m; a.clear(); b.clear();
        for(int i = 1;i <= n;i++) {
            cin >> k; if(a.empty() || k > a[0]) a.push_back(k);
        }
        for(int i = 1;i <= m;i++) {
            cin >> k;
            b.push_back(((k > a[0]) ? k : INF));
        }
        ll num = a[0];
        sort(all(a)); sort(all(b));

        for(int i = 1;i <= m;i++){
            ll result = 0;
            for(int j = m;j >= 1;j -= i){
                if(j < i) break;
                ll e = b[j - 1], s = b[j - i];
                result += lb(s, e, num);
            }

            cout << result << " ";
        }
        cout << "\n";
    }


    return 0;
}
