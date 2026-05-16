#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;


int main()
{
    cin >> t;

    while (t--) {
        cin >> n;
        string st[2];
        for (int i = 0; i <= 1; i++) cin >> st[i];

        ll result = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 0; j <= 1; j++) {
                if (st[j][i] == 'x') continue;
                if (st[j ^ 1][i] == 'x') continue;
                if (st[j ^ 1][i - 1] == '.') continue;
                if (st[j ^ 1][i + 1] == '.') continue;
                if (st[j][i - 1] == 'x') continue;
                if (st[j][i + 1] == 'x') continue;
                result++;
            }
        }

        cout << result << '\n';
    }

    return 0;
}
