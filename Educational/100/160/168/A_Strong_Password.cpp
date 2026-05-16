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
        cin >> s;
        cout << s[0];
        ll flag = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1] && !flag) {
                flag = 1;
                if (s[i] == 'a') cout << 'b';
                else cout << 'a';
            }

            cout << s[i];
        }

        if (!flag) {
            if (s[s.size() - 1] == 'a') cout << 'b';
            else cout << 'a';
        }
        cout << "\n";
    }

    return 0;
}
