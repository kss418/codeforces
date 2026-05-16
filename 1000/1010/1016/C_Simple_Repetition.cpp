#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
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

bool prime(ll cur){
    for(ll i = 2;i * i <= cur;i++){
        if(cur % i == 0) return 0;
    }
    return 1;
}

ll num(ll cur){
    ll ret = 1;
    for(int i = 1;i < cur;i++) ret *= 10, ret++;
    return ret;
}

void run(){
    cin >> n >> m;

    if(n > 1 && m > 1) cout << "NO\n";
    else if(n > 1) cout << (prime(n) ? "YES" : "NO") << "\n";
    else if(m > 1) cout << (prime(num(m)) ? "YES" : "NO") << "\n";
    else cout << "NO\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
