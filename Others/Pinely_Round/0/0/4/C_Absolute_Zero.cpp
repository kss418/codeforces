#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX], result[MAX];

ll chk() {
    ll flag = 1;
    for (int i = 1; i <= n; i++) if (arr[i]) flag = 0;

    return flag;
}


int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        ll z = 0, o = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] % 2) o = 1;
            else z = 1;
        }

        if (o & z) {
            cout << -1 << '\n';
            continue;
        }

        if (chk()) {
            cout << 0 << "\n";
            cout << "\n";
            continue;
        }

        for (int i = 1; i <= 40; i++) {
            ll M = 0, m = INF;
            for (int j = 1; j <= n; j++) {
                M = max(M, arr[j]);
                m = min(m, arr[j]);
            }

            ll mid = (M + m) >> 1;
            result[i] = mid;
            for (int j = 1; j <= n; j++) arr[j] = abs(arr[j] - mid);

            if (chk()) {
                cout << i << "\n";
                for (int j = 1; j <= i; j++) cout << result[j] << " ";
                cout << "\n";
                break;
            }
        }

        if (chk()) continue;
        cout << -1 << "\n";
    }


    return 0;
}
