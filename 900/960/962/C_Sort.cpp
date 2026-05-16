#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
string st[MAX];
ll sa[MAX][30], sb[MAX][30];

int main()
{
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                sa[i][j] = sa[i - 1][j];
                sb[i][j] = sb[i - 1][j];
                if (a[i - 1] - 'a' == j) sa[i][j]++;
                if (b[i - 1] - 'a' == j) sb[i][j]++;
            }
        }

        while (m--) {
            ll st, en, result = 0;
            cin >> st >> en;
            for (int i = 0; i < 26; i++) {
                ll a = sa[en][i] - sa[st - 1][i];
                ll b = sb[en][i] - sb[st - 1][i];
                ll diff = abs(a - b);
                result += diff;
            }

            cout << (result >> 1) << "\n";

        }
    }


    return 0;
}
