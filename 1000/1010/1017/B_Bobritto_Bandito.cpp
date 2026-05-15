#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

void run(){
    ll l, r; cin >> n >> m >> l >> r;
    m = n - m;
    
    ll mn = min(r, m); m -= mn; r -= mn;
    mn = min(-l, m); m -= mn; l += mn;
    cout << l << " " << r << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}