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
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];

        if (n != 2) cout << "NO\n";
        else if (abs(arr[2] - arr[1]) == 1) cout << "NO\n";
        else cout << "YES\n";
    }




    return 0;
}
