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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], num[MAX];

void init(){
    for(int i = 1;i <= n;i++) num[i] = 0;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m >> k; init();
        for(int i = 1;i <= m;i++) cin >> a[i];
        for(int i = 1;i <= k;i++){
            ll now; cin >> now;
            num[now] = 1;
        }

        for(int i = 1;i <= m;i++){
            if(k < n - 1 || (k == n - 1 && num[a[i]])) cout << 0;
            else cout << 1;
        }
        cout << "\n";
    }


    return 0;
}
