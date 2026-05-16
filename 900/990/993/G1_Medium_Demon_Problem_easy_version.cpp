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
ll a[MAX], d[MAX];
vector <ll> rev[MAX];
bool v[MAX];

void init(ll idx){
    for(int i = 1;i <= idx;i++) {
        v[i] = 0; d[i] = INF;
        rev[i].clear();
    }
}

void cycle(ll cur){
    vector <ll> arr; bool use[MAX] = {};
    while(1){
        if(v[cur]) break;

        if(use[cur]){
            d[cur] = 0; v[cur] = 1;
            while(!arr.empty() && arr.back() != cur){
                d[arr.back()] = 0; v[arr.back()] = 1;
                arr.pop_back();
            }
            break;
        }
        arr.push_back(cur);
        use[cur] = 1; cur = a[cur];
    }

    while(!arr.empty()){
        v[arr.back()] = 1; arr.pop_back();
    }
}

void dfs(ll cur, ll dep){
    if(d[cur] <= dep) return;
    d[cur] = dep;

    for(auto& nxt : rev[cur]){
        dfs(nxt, dep + 1);
    }
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; init(n);
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            rev[a[i]].push_back(i);
        }

        for(int i = 1;i <= n;i++){
            if(!v[i]) cycle(i);
        }
        
        for(int i = 1;i <= n;i++){
            if(!d[i]) {
                d[i] = 1; dfs(i, 0);
            }
        }
        
        ll result = 0;
        for(int i = 1;i <= n;i++) result = max(result, d[i] + 2);

        cout << result << "\n";
    }

     
    return 0;
}
