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
ll a[MAX], dp[MAX];


int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];

        bool use1 = 0, use2 = 0;
        for(int i = 1;i <= n;i++){
            if(!a[i]) {
                dp[i] = dp[i - 1];
                use1 = use2 = 0;
            }
            else if(a[i] <= 2){
                if(use1) {
                    dp[i] = dp[i - 1];
                    use1 = use2 = 0;
                }
                else {
                    dp[i] = dp[i - 1] + 1;
                    use1 = 1; use2 = 0;
                }
            }
            else if(a[i] <= 4){
                if(use1 && use2){
                    dp[i] = dp[i - 1];
                    use1 = use2 = 0;
                }
                else if(use1){
                    dp[i] = dp[i - 1] + 1;
                    use1 = 0; use2 = 1;
                }
                else if(use2){
                    dp[i] = dp[i - 1] + 1;
                    use1 = 1; use2 = 0;
                }
                else{
                    dp[i] = dp[i - 1] + 1;
                    use1 = use2 = 0;
                }
            }
            else{
                dp[i] = dp[i - 1] + 1;
                use1 = use2 = 0;
            }
        }

        cout << dp[n] << "\n";
    }


    return 0;
}
