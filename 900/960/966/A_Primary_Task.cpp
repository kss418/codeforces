#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX];

int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> s;

        if (s.size() < 3 || s[0] != '1' || s[1] != '0') cout << "NO\n";
        else if (s.size() >= 4 && s[2] != '0') cout << "YES\n";
        else if (s[2] == '0' || s[2] == '1') cout << "NO\n";
        else cout << "YES\n";
    }


    return 0;
}
