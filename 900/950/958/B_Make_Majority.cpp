#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;


int main()
{
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> s;
        ll c0, c1;
        c0 = c1 = 0;
        for (int i = 0;i < s.size();i++) {
            if (s[i] == '1') c1++;
            else if (i > 0 && s[i] == '0' && s[i - 1] == '1') c0++;
            else if (i == 0 && s[i] == '0') c0++;
        }

        if (c1 > c0) cout << "Yes\n";
        else cout << "No\n";
    }


    return 0;
}
