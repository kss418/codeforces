#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
set <pll> arr;
vector <ll> mn, mx;

class _uf {
public:
    ll n; vector <ll> p, si;

    _uf(){}
    _uf(ll n) {
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, -1);
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

    ll size(ll num){
        return si[find(num)];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }
};

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; _uf uf(n); arr.clear();
        mn.resize(n + 1), mx.resize(n + 1);
        for(int i = 1;i <= n;i++) cin >> a[i], mn[i] = mx[i] = a[i];

        for(int i = 1;i <= n;i++){
            ll cur = mn[uf.find(i)];


            while(!arr.empty() && (--arr.end())->x > cur){
                auto now = --arr.end();
                ll mnn = min(mn[uf.find(now->y)], mn[uf.find(i)]);
                ll mxn = max(mx[uf.find(now->y)], mx[uf.find(i)]);


                uf.merge(now->y, i);
                mn[uf.find(i)] = min(mn[uf.find(i)], mnn);
                mx[uf.find(i)] = max(mx[uf.find(i)], mxn);
                arr.erase(*--arr.end());
            }

            arr.insert({mx[uf.find(i)], i});
        }

        for(int i = 1;i <= n;i++) cout << mx[uf.find(i)] << " ";
        cout << "\n";
    }


    return 0;
}
