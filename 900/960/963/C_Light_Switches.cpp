#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], cnt[2 * MAX];
set <ll> mod;


int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m;

        mod.clear();
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            cnt[arr[i] % (2 * m)]++;
        }
        sort(arr + 1, arr + n + 1);

        ll result = 0;
        for (int i = 0; i < m; i++) {
            if (!cnt[i] || !cnt[i + m]) continue;
            result = -1;
        }
        if (result == -1) { cout << -1 << '\n'; continue; }

        for (int i = 0; i < 2 * m; i++) {
            if (!cnt[i]) continue;
            mod.insert(i);
        }

        ll pl = -1;
        result = -1;
        for (int i = arr[n] % (2 * m); i < 2 * m; i++) {
            if (!cnt[i]) continue;
            if (i >= m) {
                auto nxt = mod.upper_bound(i);
                if (nxt != mod.end()) continue;
                nxt = mod.upper_bound(-1);
                if (*nxt < i - m) continue;
            }
            else {
                auto nxt = mod.upper_bound(i);
                if (nxt != mod.end() && *nxt <= i + m) continue;
            }

            pl = i; break;
        }
        if (pl != -1) {
            result = arr[n] + pl - arr[n] % (2 * m);
            cout << result << '\n';
            continue;
        }

        for (int i = 0; i < arr[n] % (2 * m); i++) {
            if (!cnt[i]) continue;
            if (i >= m) {
                auto nxt = mod.upper_bound(i);
                if (nxt != mod.end()) continue;
                nxt = mod.upper_bound(-1);
                if (*nxt < i - m) continue;
            }
            else {
                auto nxt = mod.upper_bound(i);
                if (nxt != mod.end() && *nxt <= i + m) continue;
            }

            pl = i; break;
        }
        if (pl != -1) {
            result = arr[n] + pl - arr[n] % (2 * m) + 2 * m;
            cout << result << '\n';
            continue;
        }

        cout << -1 << '\n';
    }



    return 0;
}
