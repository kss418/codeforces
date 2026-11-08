#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long; using u64 = uint64_t;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

void run(){
    cin >> n >> m; 
    for(int i = 1;i <= n;i++) cin >> a[i];

    if(n == 1){
        cout << abs(m - a[1]) << "\n";
        return;
    }

    ll result = INF, now = 0;
    now = abs(m - a[1]);
    if(a[n] > m) now += a[n] - a[1];
    result = min(result, now);

    now = abs(a[n] - m);
    if(a[1] < m) now += a[n] - a[1];
    result = min(result, now);

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}