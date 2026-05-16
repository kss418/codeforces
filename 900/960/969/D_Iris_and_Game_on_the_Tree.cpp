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
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
ll a[MAX], ind[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; memset(ind, 0, sizeof(ind));
        for(int i = 1;i < n;i++){
            ll s, e; cin >> s >> e;
            ind[s]++; ind[e]++;
        }
        cin >> s;

        ll one = 0, zero = 0, q = 0, ot = 0;
        for(int i = 2;i <= n;i++){
            if(ind[i] == 1){
                if(s[i - 1] == '?') q++;
                else if(s[i - 1] == '0') zero++;
                else one++;
            }
            else if(s[i - 1] == '?') ot++;
        }

        ll result;
        if(s[0] == '0') result = one + (q + 1) / 2;
        else if(s[0] == '1') result = zero + (q + 1) / 2;
        else{
            if(one != zero || ot % 2 == 0) result = max(zero, one) + q / 2;
            else result = max(zero, one) + (q + 1) / 2;
        }

        cout << result << "\n";
    }


    return 0;
}
