#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX];
vector <pll> num;


int main()
{
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        sort(arr + 1, arr + n + 1); ll cnt = 0, pre = 0;
        num.clear();

        for (int i = 1; i <= n; i++) {
            if (i == 1) cnt = 1, pre = arr[i];
            else if (arr[i] != arr[i - 1]) {
                num.push_back({ pre, cnt });
                pre = arr[i]; cnt = 1;
            }
            else cnt++;
        }
        num.push_back({ arr[n], cnt });

        ll result = 0;
        for (int i = 0; i < num.size(); i++) result = max(result, num[i].first * (min(num[i].second, (ll)(m / num[i].first))));
        for (int i = 1; i < num.size(); i++) {
            if (num[i].first - num[i - 1].first != 1) continue;
            ll p = num[i - 1].second, c = num[i].second;
            ll pv = num[i - 1].first, cv = num[i].first;
            ll up = min(p, (ll)(m / pv));
            ll cur = num[i - 1].first * up;
            ll uc = min(c, (ll)((m - cur) / cv));
            cur += num[i].first * uc;
            ll mn = min(up, c - uc);
            cur += min(mn, m - cur);

            result = max(result, cur);
        }

        cout << result << "\n";
    }


    return 0;
}
