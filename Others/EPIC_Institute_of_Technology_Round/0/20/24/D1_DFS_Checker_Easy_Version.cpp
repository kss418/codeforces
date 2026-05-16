#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
ll a[MAX], p[MAX], cnt, org[MAX], pre[MAX];
ll in[MAX], out[MAX], dep[MAX], sum[MAX], mx;
vector <ll> adj[MAX];
set <ll> dis;

class _sseg {
public:
    ll n; vector <ll> arr, seg;
    _sseg(){}
    _sseg(ll n) {
        this->n = n;
        arr.assign(n + 1, 0); seg.assign(4 * n + 1, 0);
    }

    void con(ll idx, ll val) { arr[idx] = val; }

    void init() { init(1, n); }
    ll init(ll l, ll r, ll node = 1) {
        if (l == r) return seg[node] = arr[l];
        ll mid = (l + r) >> 1;
        seg[node] = init(l, mid, node * 2) + init(mid + 1, r, node * 2 + 1);
        return seg[node];
    }

    ll query(ll st, ll en) { return query(st, en, 1, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return 0;
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return query(st, en, l, mid, node * 2) + query(st, en, mid + 1, r, node * 2 + 1);
    }

    void add(ll idx, ll val) { add(idx, val, 1, n); }
    void add(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return;
        seg[node] += val;
        if (l == r) return;
        ll mid = (l + r) >> 1;
        add(idx, val, l, mid, node * 2);
        add(idx, val, mid + 1, r, node * 2 + 1);
    }

    ll update(ll idx, ll val) { return update(idx, val, 1, n); }
    ll update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = update(idx, val, l, mid, node * 2);
        seg[node] += update(idx, val, mid + 1, r, node * 2 + 1);
        return seg[node];
    }

    ll cnt(ll val) { return cnt(val, 1, n); }
    ll cnt(ll val, ll l, ll r, ll node = 1){
        if(l == r) return r;
        ll mid = (l + r) >> 1;

        if(seg[node * 2] < val) return cnt(val - seg[node * 2], mid + 1, r, node * 2 + 1);
        else return cnt(val, l, mid, node * 2);
    }
};

void dfs(ll cur,ll p, ll d) {
	in[cur] = ++cnt;
    dep[cur] = d;
    pre[cnt] = in[p];
	for (auto& nxt : adj[cur]) {
		if (nxt == p) continue;
		dfs(nxt, cur, d + 1);
	}
	out[cur] = cnt;
}

_sseg seg;
bool chk(ll idx){
    if(org[idx] != dep[a[idx]]) return 0;
    ll la = idx + (1ll << (mx - dep[a[idx]] + 1)) - 2;
    if(sum[out[a[idx]]] - sum[in[a[idx]] - 1] != seg.query(idx, la)) return 0;
    return 1;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m; dis.clear(); seg = {n};
        for(int i = 1;i <= n;i++) adj[i].clear();
        for(int i = 2;i <= n;i++) {
            cin >> p[i]; adj[p[i]].push_back(i);
        }
        for(int i = 1;i <= n;i++) cin >> a[i];
        cnt = 0; dfs(1, -1, 1);
        mx = 0; for(int i = 0;n >= (1 << i);i++){
            if(n & i) mx = i + 1;
        }
        
        for(int i = 1;i <= n;i++) sum[in[i]] = i, org[in[i]] = dep[i];
        for(int i = 1;i <= n;i++) sum[i] += sum[i - 1];
        for(int i = 1;i <= n;i++) seg.con(i, a[i]); seg.init();

        for(int i = 1;i <= n;i++){
            if(!chk(i)) dis.insert(i);
        }

        while(m--){
            ll s, e; cin >> s >> e;
            swap(a[s], a[e]);
            seg.update(s, a[s]);
            seg.update(e, a[e]);

            ll cur = s;
            while(cur){
                if(!chk(cur)) dis.insert(cur);
                else dis.erase(cur);
                cur = pre[cur];
            }

            cur = e;
            while(cur){
                if(!chk(cur)) dis.insert(cur);
                else dis.erase(cur);
                cur = pre[cur];
            }

            if(dis.empty()) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}

