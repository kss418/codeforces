#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX], sum[MAX], cnt[MAX];
vector <ll> adj[MAX];

void init(){
    for(int i = 0;i <= n + 1;i++){
        dp[i] = INF; sum[i] = cnt[i] = 0;
        adj[i].clear();
    }
}

void run(){
    cin >> n; init();
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    deque <pll> q;
    for(int i = 1;i <= n;i++){
        if(adj[i].size() == 1) q.push_back({i, 0});
    }
    
    while(!q.empty()){
        auto [cur, cd] = q.front(); q.pop_front();
        if(dp[cur] <= cd) continue;
        dp[cur] = cd;

        for(auto& nxt : adj[cur]) q.push_back({nxt, cd + 1});
    }

    for(int i = 1;i <= n;i++) cnt[dp[i]]++;
    for(int i = n - 1;i >= 1;i--) sum[i] = sum[i + 1] + cnt[i];

    ll result = cnt[0] * sum[1];
    for(int i = 1;i <= n;i++){
        if(dp[i] != 1) continue; ll c = 0;
        for(auto& nxt : adj[i]) c += (bool)(dp[nxt]);
        result += sum[2] * (c - 1);
    }

    cout << result << "\n";
}

int main() {
    fastio;

    cin >> t;
    while(t--) run();
    

    return 0;
}
