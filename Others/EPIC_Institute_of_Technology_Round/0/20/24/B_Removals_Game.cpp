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
constexpr ll MAX = 301010;
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++) cin >> b[i];

        ll flag = 1;
        ll al = 1, bl = 1, ar = n, br = n;
        for(int i = 1;i < n;i++){
            if(a[al] != b[bl] && a[al] != b[br]) { flag = 0; break; } 
            if(a[ar] != b[bl] && a[ar] != b[br]) { flag = 0; break; } 

            if(a[al] == b[bl]) al++, bl++;
            else if(a[al] == b[br]) al++, br--;
            else if(a[ar] == b[bl]) ar--, bl++;
            else if(a[ar] == b[br]) ar--, br--;
        }

        if(flag) cout << "Bob\n";
        else cout << "Alice\n";
     }

    return 0;
}

