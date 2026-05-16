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
        ll sq = sqrt(n);
        ll flag = 1;
        if (sq * sq != n) { cout << "No\n"; continue; }
        for (int i = 0; i < sq; i++) {
            for (int j = 0; j < sq; j++) {
                char cur = s[i * sq + j];
                if (i == 0 || j == 0 || i == sq - 1 || j == sq - 1) {
                    if (cur == '0') flag = 0;
                }
                else {
                    if (cur == '1') flag = 0;
                }
            }
        }

        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }


    return 0;
}
