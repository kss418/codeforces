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
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (l2 < l1) swap(l1, l2), swap(r1, r2);

        if (l2 > r1) cout << 1 << "\n";
        else if (l2 > l1 && r2 < r1) cout << min(r2 - l2, r1 - l1) + 2 << "\n";
        else if (l2 == l1 && r2 == r1) cout << min(r2 - l2, r1 - l1) << "\n";
        else if (l2 == l1 || r2 == r1) cout << min(r2 - l2, r1 - l1) + 1 << "\n";
        else cout << r1 - l2 + 2 << "\n";
    }




    return 0;
}
