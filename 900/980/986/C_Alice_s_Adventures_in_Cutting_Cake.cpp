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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // PLZ CHK!
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX];
deque <ll> arr;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }

        ll l = 1, r = n;
        ll cnt = 0, now = 0;

        arr.clear();
        arr.push_back(n);
        for(int i = n;i >= 1;i--){
            now += a[i]; r = i - 1;
            if(now >= k) {
                arr.push_back(i - 1);
                now = 0, cnt++;
            }
            if(cnt == m) break;
        }

        ll result = -1;
        if(cnt != m){
            cout << -1 << "\n"; continue;
        }

        if(!arr.empty()) {
            result = sum[r] - sum[l - 1];
            arr.pop_back();
        }

        while(!arr.empty()){
            ll r = arr.back(); arr.pop_back();
            ll now = 0;
            while(1){
                now += a[l++];
                if(now >= k) break;
            }

            result = max(result, sum[r] - sum[l - 1]);
        }

        cout << result << "\n";
    }


    return 0;
}
