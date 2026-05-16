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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll arr[MAX][2];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; memset(arr, 0, sizeof(arr));
        for(int i = 1;i <= n;i++) {
            ll a, b; cin >> a >> b;
            arr[a][b] = 1;
        }

        ll result = 0;
        for(int i = 0;i <= n;i++){
            if(arr[i][0] && arr[i][1]) result += n - 2;
            
            if(i && arr[i][1] && arr[i - 1][0] && arr[i + 1][0]) result++;
            if(i && arr[i][0] && arr[i - 1][1] && arr[i + 1][1]) result++;
        }

        cout << result << "\n";
    }
    

    return 0;
}
