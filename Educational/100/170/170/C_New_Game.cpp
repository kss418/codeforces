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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX]; deque <ll> q;
map <ll, ll> cnt;


int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m; cnt.clear();
        for(int i = 1;i <= n;i++) {
            cin >> a[i]; cnt[a[i]]++;
        }

        ll result = 0, now = 0;
        for(auto& cur : cnt){
            if(!q.empty() && q.back() + 1 != cur.x) q.clear(), now = 0;
            q.push_back(cur.x); now += cur.y;

            while(!q.empty() && q.front() <= cur.x - m) {
                now -= cnt[q.front()]; q.pop_front();
            }

            result = max(result, now);
        }

        cout << result << "\n";
    }


    return 0;
}
