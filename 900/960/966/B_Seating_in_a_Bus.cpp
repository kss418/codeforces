#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX], cnt[MAX];

int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        fill(cnt + 1, cnt + n + 2, 0);

        cnt[arr[1]] = 1;
        ll result = 1;
        for (int i = 2; i <= n; i++) {
            cnt[arr[i]] = 1;
            if (cnt[arr[i] - 1] || cnt[arr[i] + 1]) continue;
            result = 0; break;
        }

        if (result) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}
