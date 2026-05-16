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
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
ll arr[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        ll mx = 0, mxd = 0;
        for(int i = 1;i <= n;i++) {
            cin >> arr[i];
            mx = max(arr[i], mx);
        }

        ll result = 0;
        for(int i = 1;i <= n;i++){
            if(arr[i] != mx) continue;
            ll cnt = (i + 1) / 2;
            cnt += (n - i) / 2;

            result = max(result, mx + cnt);
        }

        cout << result << "\n";
    }

    return 0;
}
