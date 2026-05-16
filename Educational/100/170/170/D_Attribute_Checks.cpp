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
constexpr ll MAX = 2010101;
constexpr ll MOD = 998244353;
constexpr ll MID = 5010;
ll a[MAX], dp[5010][5010];
vector <ll> mi[5010], pl[5010];


int main() {
    fastio;

    cin >> n >> m; ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(!a[i]) cnt++;
        else if(a[i] < 0) mi[cnt].push_back(-a[i]);
        else pl[cnt].push_back(a[i]);
    }

    for(int i = 0;i <= m;i++){
        sort(all(mi[i])); sort(all(pl[i]));
    }

    for(int cur = 1;cur <= m;cur++){
        for(int cnt = 0;cnt <= cur;cnt++){
            if(cnt) dp[cur][cnt] = max(dp[cur - 1][cnt], dp[cur - 1][cnt - 1]);
            else dp[cur][cnt] = dp[cur - 1][cnt];
            dp[cur][cnt] += upper_bound(all(pl[cur]), cnt) - pl[cur].begin();
            dp[cur][cnt] += upper_bound(all(mi[cur]), cur - cnt) - mi[cur].begin();
        }
    }

    ll result = 0;
    for(int cnt = 0; cnt <= m;cnt++) {
        result = max(result, dp[m][cnt]);
    }

    cout << result;


    return 0;
}
