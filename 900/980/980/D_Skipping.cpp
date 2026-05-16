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
constexpr ll MAX = 401010;
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], result;


template <typename T = ll>
class _dij {
public:
    using ptl = pair <T, ll>;
    ll n; vector <T> d;
    vector <ll> pre;
    vector <vector<ptl>> adj;
    priority_queue <ptl, vector<ptl>, greater<ptl>> pq;

    _dij(ll n) {
        this->n = n;
        d.resize(n + 1, INF); pre.resize(n + 1, -1);
        adj.resize(n + 1);
    }

    void add(ll st, ll en, ll c = 1) { // 양방향
        adj[st].push_back({ c,en });
        adj[en].push_back({ c,st });
    }

    void addsol(ll st, ll en, ll c = 1) { // 단방향
        adj[st].push_back({ c,en });
    }

    void init(ll st, T fi = 0) {
        d[st] = fi;
        pq.push({ d[st], st });

        while (!pq.empty()) {
            auto [cd, cur] = pq.top(); pq.pop();
            if (cd > d[cur]) continue;

            for (auto& nn : adj[cur]) {
                auto [nd, nxt] = nn;
                if (d[nxt] <= nd + cd) continue;

                d[nxt] = nd + cd;
                pre[nxt] = cur;
                pq.push({ d[nxt], nxt });
            }
        }
    }

    T ret(ll n) {
        return d[n];
    }
};

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; result = 0; _dij dij(n);
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++) {
            cin >> b[i];
            dij.addsol(i, b[i], a[i]);
            if(i > 1) dij.addsol(i, i - 1, 0);
        }
        dij.init(1);

        ll sum = 0;
        for(int i = 1;i <= n;i++){
            ll d = dij.ret(i); sum += a[i];
            if(d >= INF) continue;
            result = max(result, sum - d);
        }

        cout << result << "\n";
    }



    return 0;
}
