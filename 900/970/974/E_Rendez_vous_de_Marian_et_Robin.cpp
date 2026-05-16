#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll horse[MAX];

template <typename T = ll>
class _dij {
public:
    ll n; vector <vector<T>> d;
    vector <ll> pre;

    class cmp {
    public:
        bool operator ()(tll& a, tll& b) {
            return get<0>(a) > get<0>(b);
        }
    };
    vector <vector<pll>> adj;
    priority_queue <tll, vector<tll>, cmp> pq;

    _dij(ll n) {
        this->n = n;
        d.resize(n + 1, vector(2, INF)); pre.resize(n + 1, -1);
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
        d[st][0] = fi;
        pq.push(tuple(d[st][0], st, 0));

        while (!pq.empty()) {
            ll cd, cur, use;
            tie(cd, cur, use) = pq.top(); pq.pop();
            if (cd > d[cur][use]) continue;
            if (horse[cur]) use = 1;

            for (auto& nn : adj[cur]) {
                auto [nd, nxt] = nn;
                if (use) {
                    if (d[nxt][use] <= nd / 2 + cd) continue;

                    d[nxt][use] = nd / 2 + cd;
                    pq.push(tuple(d[nxt][use], nxt, use));
                }
                else {
                    if (d[nxt][use] <= nd + cd) continue;

                    d[nxt][use] = nd + cd;
                    pq.push(tuple(d[nxt][use], nxt, use));
                }
            }
        }
    }

    T ret(ll n) {
        return min(d[n][0], d[n][1]);
    }
};

int main() {
    fastio;

    cin >> t;
    while (t--) {
        ll h;
        cin >> n >> m >> h;
        _dij a(n), b(n);

        memset(horse, 0, sizeof(horse));
        for (int i = 1; i <= h; i++) {
            ll node;
            cin >> node; horse[node] = 1;
        }

        while (m--) {
            ll s, e, c;
            cin >> s >> e >> c;
            a.add(s, e, c);
            b.add(s, e, c);
        }
        a.init(1);
        b.init(n);

        ll result = INF;
        for (int i = 1; i <= n; i++) {
            if (a.ret(i) == INF || b.ret(i) == INF) continue;
            result = min(result, max(a.ret(i), b.ret(i)));
        }

        if (result == INF) cout << -1 << "\n";
        else cout << result << "\n";
    }


    return 0;
}
