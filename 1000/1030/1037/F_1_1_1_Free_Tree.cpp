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
ll a[MAX], p[MAX];
vector <ll> adj[MAX];
map <pll, ll> line, sum;

void init(ll cur, ll pre = -1){
    p[cur] = pre;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        init(nxt, cur);
    }
}

void run(){
    cin >> n >> m; ll now = 0; line.clear(); sum.clear();
    for(int i = 1;i <= n;i++) adj[i].clear();
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i < n;i++){
        ll s, e, c; cin >> s >> e >> c;
        ll mn = min(s, e), mx = max(s, e);
        line[{mn, mx}] = c;

        if(a[s] != a[e]) now += c;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    init(1); 

    for(auto& [l, co] : line){
        auto&[s, e] = l;
        if(p[s] == e) sum[{e, a[s]}] += co;
        else if(p[e] == s) sum[{s, a[e]}] += co;
    }

    while(m--){
        ll idx, v; cin >> idx >> v;
        ll pa = p[idx];
        if(pa != -1){ 
            ll mn = min(idx, pa), mx = max(idx, pa);
            ll co = line[{mn, mx}];
            sum[{pa, a[idx]}] -= co;
            if(a[idx] == a[pa]) now += co;
            if(v == a[pa]) now -= co;
            sum[{pa, v}] += co;
        }

        now += sum[{idx, a[idx]}];
        now -= sum[{idx, v}];

        a[idx] = v;
        cout << now << "\n";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

