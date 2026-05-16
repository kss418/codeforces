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
ll dp[MAX];
vector <ll> adj[MAX];

void init(){
    for(int i = 1;i <= n;i++) adj[i].clear();
}

void fill(){
    for(int i = 1;i <= n;i++) dp[i] = -1;
}

void bulid(){
    for(int i = 2;i < n;i++){
        adj[i].push_back(i - 1);
        adj[i].push_back(i + 1);
    }
    adj[1].push_back(n); adj[1].push_back(2);
    adj[n].push_back(n - 1); adj[n].push_back(1);
    adj[m].push_back(k); adj[k].push_back(m);
}

ll solve(ll cur, ll pre = -1){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;

    vector <ll> vec;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        vec.push_back(solve(nxt, cur));
    }

    sort(all(vec));
    for(auto& i : vec){
        if(ret == i) ret++;
    }

    return ret;
}

bool chk(){
    for(int i = 1;i <= n;i++){
        ll now = 0; vector <ll> vec;
        for(auto& nxt : adj[i]) vec.push_back(solve(nxt));
        sort(all(vec));

        for(auto& i : vec){
            if(i == -1) return 0;
            if(i == now) now++;
        }

        if(dp[i] != now) return 0;
    }

    return 1;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m >> k; init();
        ll st; if(m != 1 && k != 1) st = 1;
        else if(m != 2 && k != 2) st = 2;
        else st = 3; bulid(); ll flag = 0;

        for(int i = 0;i <= 3;i++){
            fill(); dp[m] = i; solve(st);
            if(!chk()) continue;
            for(int j = 1;j <= n;j++) cout << dp[j] << " ";
            cout << "\n"; flag = 1; break;
        }

        if(flag) continue;
        for(int i = 0;i <= 3;i++){
            fill(); dp[k] = i; solve(st);
            if(!chk()) continue;
            for(int j = 1;j <= n;j++) cout << dp[j] << " ";
            cout << "\n"; flag = 1; break;
        }
    }


    return 0;
}
