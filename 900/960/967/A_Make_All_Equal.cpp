#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], cnt[MAX];


int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) cnt[arr[i]]++;

        ll mx = 0;
        for (int i = 1; i <= n; i++) mx = max(mx, cnt[i]);

        cout << n - mx << "\n";
    }


    return 0;
}
