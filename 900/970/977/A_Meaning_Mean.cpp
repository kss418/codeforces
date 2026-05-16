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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
multiset <ll> a;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; a.clear();
        for(int i = 1;i <= n;i++) cin >> m, a.insert(m);

        while(a.size() > 1){
            ll fi = *a.begin(); a.erase(a.begin());
            ll se = *a.begin(); a.erase(a.begin());

            ll mid = (fi + se) >> 1;
            a.insert(mid);
        }

        cout << *a.begin() << "\n";
    }


    return 0;
}
