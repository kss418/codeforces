#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101;


int main()
{
    fastio;

    cin >> t;
    while (t--) {
        ll result = 0;
        cin >> n >> m;
        for (int b = 1; b < MAX; b++) {
            if (b >= m) break;
            if (b > n) break;

            for (int c = 1; c < MAX; c++) {
                if (b + c >= m) break;
                if (b * c > n) break;

                ll mi = m - b - c;
                ll mul = (n - b * c) / (b + c);
                result += min(mi, mul);
            }
        }

        cout << result << "\n";
    }


    return 0;
}
