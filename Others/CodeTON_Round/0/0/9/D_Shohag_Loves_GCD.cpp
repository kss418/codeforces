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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result[MAX];


void init(ll idx){
    for(int i = 1;i <= idx;i++) result[i] = m;
}

int main() {
    fastio;
    
    cin >> t; 
    while(t--){
        cin >> n >> m; init(n);
        for(int i = 1;i <= m;i++) cin >> a[i];

        ll flag = 1;
        for(int i = 1;i <= n;i++){
            ll now = result[i];
            if(now <= 0){ flag = 0; break; }

            for(int j = 2 * i;j <= n;j += i){
                result[j] = min(result[j], now - 1);    
                if(result[j] <= 0){ flag = 0; break; }  
            }
        }

        if(!flag) cout << -1;
        else for(int i = 1;i <= n;i++) cout << a[result[i]] << " ";
        cout << "\n";
    }
    
     
    return 0;
}
