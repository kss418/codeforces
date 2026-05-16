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
ll n, m, k, t; string s[2];

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][3];

bool chk(char& a, char& b, char& c){
    ll ret = 0;
    if(a == 'A') ret++;
    if(b == 'A') ret++;
    if(c == 'A') ret++;

    return ret >= 2;
}

ll solve(ll cur, ll h){
    if(cur < 0) return -INF;
    ll &ret = dp[cur][h];
    if(ret != -1) return ret;
    ret = 0;

    if(h == 0){
        ll cnt = chk(s[0][cur - 2], s[1][cur - 2], s[0][cur - 1]);
        ret = max(solve(cur - 2, 2) + cnt, ret);

        cnt = chk(s[0][cur - 1], s[0][cur - 2], s[0][cur - 3]);
        cnt += chk(s[1][cur - 2], s[1][cur - 3], s[1][cur - 4]);
        ret = max(solve(cur - 3, 0) + cnt, ret);
    }
    else if(h == 1){
        ll cnt = chk(s[1][cur - 1], s[1][cur - 2], s[0][cur - 2]);
        ret = max(solve(cur - 2, 2) + cnt, ret);

        cnt = chk(s[1][cur - 1], s[1][cur - 2], s[1][cur - 3]);
        cnt += chk(s[0][cur - 2], s[0][cur - 3], s[0][cur - 4]);
        ret = max(solve(cur - 3, 1) + cnt, ret);
    }
    else{
        ll cnt = chk(s[0][cur - 1], s[0][cur - 2], s[0][cur - 3]);
        cnt += chk(s[1][cur - 1], s[1][cur - 2], s[1][cur - 3]);
        ret = max(solve(cur - 3, 2) + cnt, ret);

        cnt = chk(s[0][cur - 1], s[1][cur - 1], s[1][cur - 2]);
        ret = max(solve(cur - 1, 0) + cnt, ret);

        cnt = chk(s[0][cur - 1], s[1][cur - 1], s[0][cur - 2]);
        ret = max(solve(cur - 1, 1) + cnt, ret);
    }

    return ret;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i <= 1;i++) cin >> s[i];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = dp[0][1] = -INF;
        dp[0][2] = 0;

        cout << solve(n, 2) << '\n';
    }


    return 0;
}
