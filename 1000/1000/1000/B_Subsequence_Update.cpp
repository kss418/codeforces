#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll all = accumulate(a + m, a + k + 1, 0ll), result = all;

    sort(a + 1, a + m, greater<ll>()); sort(a + m, a + k + 1, greater<ll>());
    ll diff = 0;
    for(int i = m;i <= k;i++){
        ll idx = m - (i - m) - 1;
        if(idx <= 0) break;
        diff += a[idx] - a[i];
        result = min(result, all + diff);
    }

    diff = 0;
    sort(a + m, a + k + 1); sort(a + k + 1, a + n + 1);
    for(int i = k;i >= m;i--){
        ll idx = k + (k - i) + 1;
        if(idx > n) break;
        diff += a[idx] - a[i];
        result = min(result, all + diff);
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
