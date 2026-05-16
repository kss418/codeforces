#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX];

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        ll result = 0;
        for (int i = 1; i <= m; i++) cin >> arr[i];
        sort(arr + 1, arr + m + 1);
        for (int i = 1; i < m; i++) {
            result += 2 * arr[i] - 1;
        }

        cout << result << "\n";
    }


    return 0;
}
