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
ll pl[11];

bool chk(ll cur){
    string st = to_string(cur);
    for(auto& i : st){
        if(i == '7') return 1;
    }
    return 0;
}

ll solve(ll cur){
    ll ret = INF;
    if(chk(cur)) return 0;
    for(int i = 1;i <= 10;i++){
        ll now = cur;
        for(ll j = 1;j <= 10;j++){
            now += pl[i];
            if(!chk(now)) continue;
            ret = min(ret, j); break;
        }
    }

    return ret;
}

void run(){
    cin >> n;
    cout << solve(n) << "\n";
}

int main() {
    fastio; cin >> t;
    pl[1] = 9;
    for(int i = 2;i <= 10;i++) pl[i] = pl[i - 1] * 10 + 9;
    while(t--) run();

    return 0;
}
