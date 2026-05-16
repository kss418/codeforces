#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX];
vector<vector<ll>> a1, a2, num;
vector<ll> st;

int main()
{
    fastio;
    cin >> t;
    while (t--) {
        ll w;
        cin >> n >> m >> k;
        cin >> w;
        for (int i = 1; i <= w; i++) cin >> arr[i];

        a1.clear(); a2.clear(); num.clear(); st.clear();
        a1.resize(n + 1, vector<ll>(m + 1, 0));
        a2.resize(n + 1, vector<ll>(m + 1, 0));
        num.resize(n + 1, vector<ll>(m + 1, 0));


        for (int i = 1; i <= n; i++) {
            ll cnt = 1;
            for (int j = 1; j <= m; j++) a1[i][j] = cnt++;
            cnt = 1;
            for (int j = m; j >= 1; j--) a1[i][j] = min({ cnt++, a1[i][j], m - k + 1, k });
        }

        for (int i = 1; i <= m; i++) {
            ll cnt = 1;
            for (int j = 1; j <= n; j++) a2[j][i] = cnt++;
            cnt = 1;
            for (int j = n; j >= 1; j--) a2[j][i] = min({ cnt++, a2[j][i], n - k + 1, k });
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                num[i][j] = a1[i][j] * a2[i][j];
                st.push_back(num[i][j]);
            }
        }

        sort(st.begin(), st.end());
        reverse(st.begin(), st.end());
        sort(arr + 1, arr + w + 1);
        reverse(arr + 1, arr + w + 1);

        ll result = 0;
        for (int i = 1; i <= w; i++) {
            result += arr[i] * st[i - 1];
        }


        cout << result << "\n";
    }




    return 0;
}
