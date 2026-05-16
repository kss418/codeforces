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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[3];
ll dp[MAX][MAX];

ll solve(ll a, ll b){
    ll& ret = dp[a][b];
    if(ret != -1) return ret;
    ret = INF;

    if(a) {
        ll now = solve(a - 1, b);
        if(st[0][a - 1] != st[2][a + b - 1]) now++;
        ret = min(ret, now);
    }

    if(b) {
        ll now = solve(a, b - 1);
        if(st[1][b - 1] != st[2][a + b - 1]) now++;
        ret = min(ret, now);
    }

    return ret;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        for(int i = 0;i < 3;i++) cin >> st[i];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;

        cout << solve(st[0].size(), st[1].size()) << "\n";
    }


    return 0;
}
