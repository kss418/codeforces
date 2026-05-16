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
vector <ll> a;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; a.clear();
        for(int i = 1;i <= n;i++) cin >> m, a.push_back(m);
        sort(all(a));

        ll result = INF;
        for(int i = 0;i < n - 1;i++){
            ll cur = i;
            ll now = a[i] + a[i + 1];
            cur += n - (lower_bound(all(a), now) - a.begin());

            result = min(result, cur);
        }

        cout << result << "\n";
    }


    return 0;
}
