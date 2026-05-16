#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll cnt[30], use;

int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        use = 0;
        for (auto& i : s) cnt[i - 'a']++;
        while (use < n) {
            for (int i = 0; i < 26; i++) {
                if (!cnt[i]) continue;
                char cur = i + 'a';
                cout << cur;
                use++;
                cnt[i]--;
            }
        }

        cout << "\n";
    }

    return 0;
}
