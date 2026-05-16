#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll sum[MAX];
map <ll, ll> num;
map <ll, ll> cnt;

int main()
{
    fastio;

    cin >> t;
    while (t--) {
        cin >> s;
        num.clear();
        cnt.clear();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') sum[i + 1] = sum[i] + 1;
            else sum[i + 1] = sum[i];
        }

        ll result = 0; cnt[0]++;
        for (int i = 1; i <= s.size(); i++) {
            ll z = i - sum[i];
            ll diff = sum[i] - z;

            result += (s.size() - i + 1) * (num[diff] + cnt[diff]);
            result %= MOD;

            num[diff] += i;
            cnt[diff]++;
        }

        cout << result % MOD << "\n";
    }


    return 0;
}
