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
constexpr ld eps = 1e-9;
ll a[MAX];
ld la[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        ll idx = INF, flag = 1;
        for(int i = 1;i <= n;i++){
            if(a[i] != 1) idx = min<ll>(i, idx);
            if(a[i] == 1 && i > idx) flag = 0;
        }

        if(!flag) {
            cout << -1 << "\n";
            continue;
        }

        ll result = 0;
        for(int i = idx;i <= n;i++) la[i] = log(log(a[i]));
        for(int i = idx + 1;i <= n;i++){
            ld diff = la[i - 1] - la[i];
            if(diff <= eps) continue;
            ll cnt = (diff - eps) / log(2) + 1;
            result += cnt; la[i] += cnt * log(2);
        }

        cout << result << "\n";
    }


    return 0;
}
