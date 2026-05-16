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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][9];

void init(ll num){
    for(int i = 0;i <= num;i++){
        for(int j = 0;j < 9;j++) dp[i][j];
    }
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> s; init(s.size());
        dp[0][0] = 1;
        for(int i = 1;i <= s.size();i++){
            ll cur = s[i - 1] - '0';
            ll sq = cur * cur;
            for(int j = 0;j < 9;j++){
                dp[i][j] = max(dp[i][j], dp[i - 1][(j - cur + 9) % 9]);
                if(sq < 10) dp[i][j] = max(dp[i][j], dp[i - 1][(j - sq + 9) % 9]);
            }
        }

        if(dp[s.size()][0]) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}
