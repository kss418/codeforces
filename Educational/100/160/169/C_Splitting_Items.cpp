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
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        sort(arr + 1, arr + n + 1);
        reverse(arr + 1, arr + n + 1);

        ll result = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) result += arr[i];
            else {
                ll use = min(arr[i - 1] - arr[i], m);
                m -= use;
                result -= arr[i] + use;
            }
        }

        cout << result << '\n';
    }




    return 0;
}
