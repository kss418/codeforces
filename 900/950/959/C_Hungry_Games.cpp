#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX], dp[MAX], sm[MAX];
map <ll, ll> num; set <ll> st;

int main()
{
    fastio;

    cin >> t;
    while (t--) {
        num.clear(); st.clear();
        cin >> n >> m;
        fill(dp + 1, dp + n + 2, 0);

        for (int i = 1; i <= n; i++) cin >> arr[i];
        for (int i = 1; i <= n; i++) {
            sm[i] = sm[i - 1] + arr[i], num[sm[i]] = i;
            st.insert(sm[i]);
        }

        for (int i = n; i >= 1; i--) {
            ll sum = 0, cur = 0;
            ll cn = sm[i - 1];
            ll nn = sm[i - 1] + m;

            if (arr[i] > m) {
                dp[i] = dp[i + 1];
                continue;
            }

            auto nxt = st.upper_bound(nn);
            if (nxt == st.end()) dp[i] = n - i + 1;
            else {
                dp[i] = num[*nxt] - i + dp[num[*nxt] + 1];
            }
        }

        ll result = 0;
        for (int i = 1; i <= n; i++) result += dp[i];
        cout << result << "\n";
    }


    return 0;
}
