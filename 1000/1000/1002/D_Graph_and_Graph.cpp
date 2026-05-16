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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll sz[2], d[MAX][MAX];
vector <ll> adj[2][MAX];

void init(){
    for(int i = 0;i <= 1;i++){
        for(int j = 0;j < n;j++) adj[i][j].clear();
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) d[i][j] = INF;
    }
}

class node{
public:
    ll cur1, cur2;
    bool operator < (const node& ot) const{
        if(cur1 != ot.cur1) return cur1 < ot.cur1;
        return cur2 < ot.cur2;
    }
};
using ptl = pair<ll, node>;
priority_queue <ptl, vector <ptl>, greater<ptl>> pq;

bool chk(ll cur){
    set <ll> num;
    for(auto& i : adj[0][cur]) num.insert(i);
    for(auto& i : adj[1][cur]){
        if(num.count(i)) return 1;
    }
    return 0;
}

void run(){
    cin >> n >> m >> k; init();
    for(int i = 0;i <= 1;i++){
        cin >> sz[i];
        for(int j = 1;j <= sz[i];j++){
            ll s, e; cin >> s >> e; s--; e--;
            adj[i][s].push_back(e);
            adj[i][e].push_back(s);
        }
    }

    pq.push({0, {m - 1, k - 1}});
    while(!pq.empty()){
        auto[cd, cur] = pq.top(); pq.pop();
        auto[cur1, cur2] = cur;
        if(cd >= d[cur1][cur2]) continue;
        d[cur1][cur2] = cd;

        for(auto& nxt1 : adj[0][cur1]){
            for(auto& nxt2 : adj[1][cur2]){
                ll nd = cd + abs(nxt1 - nxt2);
                if(nd >= d[nxt1][nxt2]) continue;
                pq.push({nd, {nxt1, nxt2}});
            }
        }
    }

    ll result = INF;
    for(int i = 0;i < n;i++){
        if(!chk(i)) continue;
        result = min(result, d[i][i]);
    }

    cout << (result >= INF ? -1 : result) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
