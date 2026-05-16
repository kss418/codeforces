#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], cnt[MAX];

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;

        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            cnt[arr[i]]++;
        }

        ll flag = 0;;
        for (int i = n; i >= 1; i--) {
            if (!cnt[i]) continue;
            if (cnt[i] % 2) {
                flag = 1; break;
            }
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}
