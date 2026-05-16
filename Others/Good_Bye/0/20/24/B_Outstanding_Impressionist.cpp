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
ll l[MAX], r[MAX], use[2 * MAX], sum[2 * MAX], cnt[2 * MAX];

void init(){
    for(int i = 1;i <= 2 * n;i++) {
        use[i] = sum[i] = cnt[i] = 0;
    }
}

void solve(){
    cin >> n; init();
    for(int i = 1;i <= n;i++) {
        cin >> l[i] >> r[i];
        if(l[i] == r[i]) {
            use[l[i]] = 1;
            cnt[l[i]]++;
        }
    }
    for(int i = 1;i <= 2 * n;i++) sum[i] = sum[i - 1] + use[i];

    for(int i = 1;i <= n;i++){
        ll now = sum[r[i]] - sum[l[i] - 1];
        if(l[i] == r[i]) cout << (cnt[l[i]] == 1);
        else if(now == r[i] - l[i] + 1) cout << 0;
        else cout << 1;
    }
    cout << '\n';
}

int main() {
    fastio;

    cin >> t;
    while(t--) solve();
    

    return 0;
}
