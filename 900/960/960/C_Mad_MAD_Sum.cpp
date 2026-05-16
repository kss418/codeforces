#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], fi[MAX], cnt[MAX], se[MAX];
vector <ll> num;


int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;

        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) cin >> arr[i];

        ll mx = 0, result = 0;
        for (int i = 1; i <= n; i++) {
            cnt[arr[i]]++; result += arr[i];
            if (cnt[arr[i]] >= 2) mx = max(mx, arr[i]);
            fi[i] = mx;
        }

        memset(cnt, 0, sizeof(cnt));
        ll cur = 0; mx = 0;
        for (int i = 1; i <= n; i++) {
            cnt[fi[i]]++; result += fi[i];
            if (cnt[fi[i]] >= 2) mx = max(mx, fi[i]);
            se[i] = mx;
        }

        for (int i = 1; i <= n; i++) {
            if (!se[i]) continue;
            num.push_back(se[i]);
            cur += se[i];
        }
        result += cur;

        while (!num.empty()) {
            cur -= num.back();
            num.pop_back();
            result += cur;
        }

        cout << result << "\n";
    }


    return 0;
}
