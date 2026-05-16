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
ll a[MAX], b[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m; a[n + 1] = 0;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= m;i++) cin >> b[i];

        vector <vector <ll>> dp(n + 2, vector<ll>(m + 1, INF));
        vector <vector <ll>> nxt(n + 2, vector<ll>(m + 1));

        for(int i = 1;i <= m;i++){
            ll r = 0, sum = 0;
            for(int cur = 1;cur <= n;cur++){
                while(r <= n && sum <= b[i]) sum += a[++r];
                nxt[cur][i] = r; sum -= a[cur];
            }
        }

        dp[1][1] = 0;
        for(int cnt = 1;cnt <= m;cnt++){
            for(int cur = 1;cur <= n;cur++){
                dp[nxt[cur][cnt]][cnt] = min(dp[nxt[cur][cnt]][cnt], dp[cur][cnt] + m - cnt);
                if(cnt < m) dp[cur][cnt + 1] = min(dp[cur][cnt + 1], dp[cur][cnt]);
            }
        }

        ll result = INF;
        for(int i = 1;i <= m;i++) result = min(result, dp[n + 1][i]);

        if(result >= INF) cout << -1 << "\n";
        else cout << result << "\n";
    }

    return 0;
}
