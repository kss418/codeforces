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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], pos[MAX];
class _uf {
public:
    ll n; vector <ll> p, si;

    _uf(){}
    _uf(ll n) {
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
    }

    ll find(ll num) {
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
}; _uf uf;

void dfs(ll cur){
    if(uf.same(cur, pos[cur])) return;
    uf.merge(cur, pos[cur]);
    dfs(pos[cur]);
}

void run(){
    cin >> n; uf = {n};
    for(int i = 1;i <= n;i++) cin >> a[i], pos[a[i]] = i;
    for(int i = 1;i <= n;i++) cin >> b[i];

    for(int i = 1;i <= n;i++){
        uf.merge(0, b[i]);
        dfs(b[i]);
        cout << uf.size(0) - 1 << " ";
    }
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
