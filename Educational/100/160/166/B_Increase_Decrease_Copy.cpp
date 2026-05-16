#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n + 1;i++) cin >> b[i];

        ll mn = INF, result = 0;
        for(int i = 1;i <= n;i++) {
            result += abs(a[i] - b[i]);
            ll cmx = max(a[i], b[i]);
            ll cmn = min(a[i], b[i]);

            if(b[n + 1] <= cmx && b[n + 1] >= cmn) mn = min(mn, 0ll);
            else if(b[n + 1] > cmx) mn = min(mn, b[n + 1] - cmx);
            else mn = min(mn, cmn - b[n + 1]);
        }

        cout << result + mn + 1 << "\n";
    }

    return 0;
}
