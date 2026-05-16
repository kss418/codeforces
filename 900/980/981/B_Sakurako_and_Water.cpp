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
constexpr ll MAX = 501;
constexpr ll MOD = 998244353;
ll a[MAX][MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) cin >> a[i][j];
        }

        ll result = 0;
        for(int i = 1;i <= n;i++){
            ll now = 0;
            for(int j = 0;j < n;j++){
                if(i + j > n) break;
                ll cur = a[1 + j][i + j];
                if(cur >= 0) continue;
                now = max(now, -cur);
            }

            result += now;
        }

        for(int i = 2;i <= n;i++){
            ll now = 0;
            for(int j = 0;j < n;j++){
                if(i + j > n) break;
                ll cur = a[i + j][1 + j];
                if(cur >= 0) continue;
                now = max(now, -cur);
            }

            result += now;
        }

        cout << result << "\n";
    }


    return 0;
}
