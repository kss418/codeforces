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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll dp[MAX][3];

void init(ll idx){
    for(int i = 1;i <= n;i++) adj[i].clear();
    for(int i = 1;i <= idx;i++) {
        for(int j = 0;j < 3;j++) dp[i][j] = -1;
    }
}

ll solve(ll cur, ll cnt, ll pre = -1){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret;
    ret = 0;

    vector <ll> num; ll c = 0;
    for(auto& nxt : adj[cur]){
        if(pre == nxt) continue; c++;
        if(!cnt){
            ret = max(ret, solve(nxt, 0, cur));
            for(int i = 1;i < 3;i++) {
                ret = max(ret, solve(nxt, i, cur) + 1);
            }
        }
        else num.push_back(solve(nxt, 1, cur));
    }
    sort(all(num)); reverse(all(num));
    if(cnt == 1) ret = max(ret, c);
    if(num.size() < cnt) return ret;

    if(cnt == 1) ret = max(ret, num[0] + c - 1);
    else if(cnt == 2) ret = max(ret, num[0] + num[1] + c - 2);

    return ret;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; init(n);
        for(int i = 1;i < n;i++){
            ll l, r; cin >> l >> r;
            adj[l].push_back(r);
            adj[r].push_back(l);
        }

        cout << max({solve(1, 0), solve(1, 1), solve(1, 2)}) << "\n";
    }


    return 0;
}
