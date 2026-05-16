#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX], sum[MAX];


int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        cin >> s;
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];

        ll result = 0;
        ll st = 0, en = n - 1;
        while (en > st) {
            if (s[st] == 'R') st++;
            else if (s[en] == 'L') en--;
            else {
                result += sum[en + 1] - sum[st];
                st++, en--;
            }
        }

        cout << result << "\n";
    }


    return 0;
}
