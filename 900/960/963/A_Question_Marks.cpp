#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;


int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> s;
        ll cnt[4] = {}, result = 0;
        for (auto& i : s) if(i != '?')cnt[i - 'A']++;
        for (int i = 0; i < 4; i++) result += min(n, cnt[i]);

        cout << result << "\n";
    }



    return 0;
}
