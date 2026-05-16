#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], dp[MAX];

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cin >> s;

        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            char cur = s[i - 1];
            if (cur == 'C') continue;

            if (cur == 'L') {
                dp[i] = dp[i - 1];
                for (int j = 2; j <= m; j++) {
                    if (i - j > 0 && s[i - j - 1] == 'W') continue;
                    dp[i] = min(dp[i], dp[i - j]);
                }
            }

            else {
                dp[i] = dp[i - 1] + 1;
                for (int j = 2; j <= m; j++) {
                    if (i - j > 0 && s[i - j - 1] == 'W') continue;
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        }

        dp[n + 1] = dp[n];
        for (int i = 2; i <= m; i++) {
            if (n + 1 - i > 0 && s[n - i] == 'W') continue;
            dp[n + 1] = min(dp[n + 1], dp[n + 1 - i]);
        }

        if (dp[n + 1] > k) cout << "NO\n";
        else cout << "YES\n";
    }


    return 0;
}
