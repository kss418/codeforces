#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll arr[MAX];
stack <pll> st;

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];

        for (int i = 1; i <= n; i++) {
            ll sum = arr[i], cnt = 1;
            long double avg = sum / (long double)cnt;
            while (!st.empty() && st.top().x >= avg) {
                sum += st.top().x * st.top().y; cnt += st.top().y;
                avg = sum / (double)cnt; st.pop();
            }

            st.push({ sum / cnt, cnt - sum % cnt });
            if (sum % cnt) st.push({ sum / cnt + 1 , sum % cnt });
        }

        ll mx = 0, mn = INF;
        while (!st.empty()) {
            ll cur = st.top().x;
            mx = max(mx, cur); mn = min(mn, cur);
            st.pop();
        }

        cout << mx - mn << "\n";
    }


    return 0;
}
