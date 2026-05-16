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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

void run(){
    cin >> n >> m; ll result = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];

    if(m == 1){
        ll mx = 0;
        for(int i = 2;i < n;i++) mx = max(mx, a[i]);
        result = max({mx + a[1], mx + a[n], a[1] + a[n]});
    }
    else{
        sort(a + 1, a + n + 1, greater<ll>());
        for(int i = 1;i <= m + 1;i++) result += a[i];
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
