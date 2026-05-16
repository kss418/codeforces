#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], sum[MAX], dp[MAX];
set <ll> st;
map<ll, ll> num;

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        num.clear(); st.clear();
        for (int i = 1; i <= n; i++) {
            cin >> arr[i]; sum[i] = sum[i - 1] + arr[i];
            num[sum[i]] = i;
        }

        st.insert(0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            auto mx = st.lower_bound(-(sum[i] - m));
            st.insert(-sum[i]);
            if (mx == st.end()) continue;
            if (sum[i] - -*mx < m || sum[i] - -*mx > k) continue;

            dp[i] = max(dp[i], dp[num[-*mx]] + 1);
        }

        cout << dp[n] << "\n";
    }


    return 0;
}
