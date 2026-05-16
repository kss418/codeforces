#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 501;
constexpr ll MOD = 1e9 + 7;
string a[MAX], b[MAX];
ll diff[MAX][MAX];
ll sd[MAX], sr[MAX];


int main() {
    fastio;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diff[i][j] = ((b[i][j] - '0') - (a[i][j] - '0') + 3) % 3;
            }
        }

        ll result = 1;
        for (int i = 0; i < n; i++) {
            sr[i] = diff[i][0];
            for (int j = 1; j < m; j++) sr[i] += diff[i][j];
            if (sr[i] % 3) result = 0;
        }

        for (int i = 0; i < m; i++) {
            sd[i] = diff[0][i];
            for (int j = 1; j < n; j++) sd[i] += diff[j][i];
            if (sd[i] % 3) result = 0;
        }

        if (result) cout << "YES\n";
        else cout << "NO\n";
    }



    return 0;
}
