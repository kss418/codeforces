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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

class _uf {
public:
    ll n; vector <ll> p, size;
    _uf(ll n) {
        this->n = n;
        p.resize(n + 1); size.resize(n + 1);
        fill(p.begin(), p.end(), -1);
        fill(size.begin(), size.end(), 1);
    }

    ll find(ll num) {
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (a < b) swap(a, b);
        p[b] = a, size[a] += size[b];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }
};
vector <tll> query;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        ll result = 0; _uf uf(n);
        map <ll, ll> num[11][11];

        while(m--){
            ll a, d, k; cin >> a >> d >> k;
            ll l = a, r = a + d * k;
            query.push_back({a, d, k});
        }
        sort(all(query));

        for(auto& i : query){
            auto[a, d, k] = i;
            ll l = a, r = a + d * k;

            auto lb = num[a % d][d].lower_bound(l);
            if(lb != num[a % d][d].end()){
                if(lb->y > r || lb->x < l) num[a % d][d][r] = l;
                else {
                    num[a % d][d].erase(lb);
                    ll mn = min(lb->y, l), mx = max(lb->x, r);
                    num[a % d][d][mx] = mn;
                }
            }
            else num[a % d][d][r] = l;
        }
        query.clear();

        for(int i = 1;i <= 10;i++){
            for(int j = 0;j < i;j++){
                for(auto& cur : num[j][i]){
                    auto[en, st] = cur;
                    for(int idx = st + i;idx <= en;idx += i){
                        uf.merge(st, idx);
                    }
                }
            }
        }

        for(int i = 1;i <= n;i++){
            if(uf.find(i) == i) result++;
        }

        cout << result << "\n";
    }


    return 0;
}
