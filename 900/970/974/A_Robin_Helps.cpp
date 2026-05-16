#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll arr[MAX];

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m; ll gold = 0, result = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (arr[i] >= m) gold += arr[i];
            else if (!arr[i] && gold > 0) gold--, result++;
        }

        cout << result << "\n";
    }


    return 0;
}
