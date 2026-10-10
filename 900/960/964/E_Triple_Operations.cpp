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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll pre[MAX];

ll cal(ll cur){
    ll ret = 0;
    while(cur){
        cur /= 3;
        ret++;
    }
    return ret;
}

void run(){
    cin >> n >> m; 
    cout << pre[m] - pre[n - 1] + cal(n) << "\n";
}

int main() {
    fastio; cin >> t;
    for(int i = 1;i < MAX;i++) pre[i] = pre[i - 1] + cal(i);
    while(t--) run(); 

    return 0;
}