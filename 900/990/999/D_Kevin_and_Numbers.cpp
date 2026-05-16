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
multiset <ll> a, b;
map <ll, bool> dis;

bool dfs(ll cur){
    if(a.count(cur)) {
        a.erase(a.find(cur));
        return 1;
    }

    if(cur <= 1) return 0;
    ll l = (cur >> 1ll), r = (cur >> 1ll) + (cur & 1);

    if(dis.count(l) || dis.count(r)) return 0;
    ll rl = dfs(l), rr = dfs(r);
    if(!rl) dis[l] = 1; if(!rr) dis[r] = 1;

    return rl & rr;
}

bool solve(){
    for(auto& i : b){
        if(!dfs(i)) return 0;
    }
    return a.empty();
}

void run(){
    cin >> n >> m; a.clear(); b.clear(); dis.clear();
    for(int i = 1;i <= n;i++) cin >> k, a.insert(k);
    for(int i = 1;i <= m;i++) cin >> k, b.insert(k);

    cout << (solve() ? "Yes" : "No") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
