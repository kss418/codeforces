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
ll a[MAX], sum[MAX];

int main() {
    fastio;

    cin >> t; 
    while(t--){
        cin >> n >> m;
        for(int i = 0;i < n;i++) cin >> a[i];
        sum[0] = a[0];
        for(int i = 1;i < 2 * n;i++) sum[i] = a[i % n] + sum[i - 1];

        while(m--){
            ll result = 0;
            ll s, e; cin >> s >> e; s--; e--;
            ll sidx = s / n, eidx = e / n;
            if(sidx < eidx){
                result += (eidx - sidx - 1) * sum[n - 1];
                result += sum[n - 1 + sidx];
                if(s % n - 1 + sidx != -1) result -= sum[s % n - 1 + sidx];

                result += sum[eidx + e % n];
                if(eidx - 1 != -1) result -= sum[eidx - 1];
            }
            else{
                result += sum[e % n + eidx];
                if(s % n + sidx - 1 != -1) result -= sum[s % n - 1 + sidx];
            }

            cout << result << "\n";
        }
    }
    

    return 0;
}
