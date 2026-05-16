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
constexpr ll MAX = 401010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
vector <ll> adj[MAX];
ll in[MAX], out[MAX], cnt;

void init(){
    for(int i = 1;i <= n;i++) adj[i].clear();
    cnt = 0;
}

void dfs(ll cur, ll pre = -1){
    in[cur] = ++cnt;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        dfs(nxt, cur);
    }
    out[cur] = cnt;
}

class _prop {
public:
    vector<ll> seg, lazy; ll n;

    _prop(ll n) {
        this->n = n;
        seg.resize(4 * n + 1); lazy.resize(4 * n + 1);
    }

    void propagate(ll l, ll r, ll node) {
        if (!lazy[node]) return;
        if (l != r) {
            lazy[node * 2] = lazy[node];
            lazy[node * 2 + 1] = lazy[node];
        }
        seg[node] = lazy[node];
        lazy[node] = 0;
    }

    void add(ll st, ll en, ll val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node] = val; propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    ll query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return 0;
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        ll ret = query(st, en, l, mid, node * 2);
        ret = max(ret, query(st, en, mid + 1, r, node * 2 + 1));

        return ret;
    }
};

void run(){
    cin >> n; init(); _prop seg(n);
    for(int i = 1;i <= n;i++) cin >> a[i].x, a[i].y = i;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    ll result = 0; sort(a + 1, a + n + 1); dfs(1);
    for(int i = 1;i <= n;i++) seg.add(in[a[i].y], in[a[i].y], a[i].x);
    for(int i = n;i >= 1;i--){
        ll now = a[i].x, idx = a[i].y;
        ll l = (in[idx] >= 2 ? seg.query(1, in[idx] - 1) : 0);
        ll r = (out[idx] < n ? seg.query(out[idx] + 1, n) : 0);
        if(l <= now && r <= now) continue;
        result = idx; break;
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
