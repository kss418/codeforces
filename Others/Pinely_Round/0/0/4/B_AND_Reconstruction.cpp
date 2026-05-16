#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX], result[MAX];


int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < n; i++) cin >> arr[i];

        result[1] = arr[1];
        result[n] = arr[n - 1];
        for (int i = 2; i < n; i++) {
            result[i] = arr[i] | arr[i - 1];
        }

        ll flag = 1;
        for (int i = 1; i < n; i++) {
            if ((result[i] & result[i + 1]) != arr[i]) flag = 0;
        }

        if (!flag) cout << -1;
        else for (int i = 1; i <= n; i++) cout << result[i] << " ";
        cout << '\n';
    }


    return 0;
}
