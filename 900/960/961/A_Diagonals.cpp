#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101;
ll arr[MAX];


int main()
{
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll cnt = 0;
        if (m >= n) m -= n, cnt++;
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= 2; j++) {
                if (m < i) continue;
                m -= i; cnt++;
            }
        }

        cout << cnt << "\n";
    }


    return 0;
}
