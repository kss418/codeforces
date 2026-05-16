#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
pll arr[MAX];


int main()
{
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> arr[i].first;
        for (int i = 1; i <= n; i++) cin >> arr[i].second;
        sort(arr + 1, arr + n + 1);

        ll result = 0;
        for (int i = 1; i <= n; i++) result = max(result, arr[i].first * (min(arr[i].second, (ll)(m / arr[i].first))));
        for (int i = 2; i <= n; i++) {
            if (arr[i].first - arr[i - 1].first != 1) continue;
            ll p = arr[i - 1].second, c = arr[i].second;
            ll pv = arr[i - 1].first, cv = arr[i].first;
            ll up = min(p, (ll)(m / pv));
            ll cur = arr[i - 1].first * up;
            ll uc = min(c, (ll)((m - cur) / cv));
            cur += arr[i].first * uc;
            ll mn = min(up, c - uc);
            cur += min(mn, m - cur);

            result = max(result, cur);
        }

        cout << result << "\n";
    }


    return 0;
}
