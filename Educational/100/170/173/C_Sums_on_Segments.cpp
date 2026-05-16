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
ll a[MAX], idx;
map <ll, bool> cnt;
vector <ll> result;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; result.clear(); result.push_back(0); cnt.clear();
        for(int i = 1;i <= n;i++) {
            cin >> a[i]; if(abs(a[i]) != 1) idx = i;
        }

        ll mi = 0, pl = 0; cnt[0] = 1;
        for(int i = 1;i <= n;i++){
            if(a[i] == -1) mi++, pl--;
            else if(a[i] == 1) pl++, mi--;
            else mi = 0, pl = 0;
            pl = max(pl, 0ll); mi = max(mi, 0ll);

            if(!cnt.count(pl)) {
                result.push_back(pl);
                cnt[pl] = 1;
            }
            if(!cnt.count(-mi)) {
                result.push_back(-mi);
                cnt[-mi] = 1;
            }
        }

        ll mx1 = 0, mn1 = 0, mx2 = 0, mn2 = 0, now = 0;
        for(int i = idx - 1;i >= 1;i--){
            now += a[i];
            mx1 = max(mx1, now); mn1 = min(mn1, now);
        }

        now = 0;
        for(int i = idx + 1;i <= n;i++){
            now += a[i];
            mx2 = max(mx2, now); mn2 = min(mn2, now);
        }

        if(!cnt.count(a[idx])) result.push_back(a[idx]), cnt[a[idx]] = 1;
        for(int i = 1;i <= mx1 + mx2;i++){
            if(cnt.count(a[idx] + i)) continue;
            cnt[a[idx] + i] = 1;
            result.push_back(a[idx] + i);
        }

        for(int i = -1;i >= mn1 + mn2;i--){
            if(cnt.count(a[idx] + i)) continue;
            cnt[a[idx] + i] = 1;
            result.push_back(a[idx] + i);
        }

        sort(all(result));
        cout << result.size() << "\n";
        for(auto& i : result) cout << i << " ";
        cout << "\n";
    }


    return 0;
}
