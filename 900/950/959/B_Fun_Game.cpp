#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
string arr[2];


int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> arr[0] >> arr[1];
        ll st = n, en = n;
        for (int i = 0; i < n; i++) {
            if (arr[0][i] == '0') continue;
            st = i; break;
        }

        for (int i = 0; i < n; i++) {
            if (arr[1][i] == '0') continue;
            en = i; break;
        }

        if (en >= st) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}
