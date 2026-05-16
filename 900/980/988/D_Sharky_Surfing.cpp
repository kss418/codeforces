#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll l[MAX], r[MAX], x[MAX], v[MAX];
priority_queue <ll> pq;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i = 1;i <= n;i++) cin >> l[i] >> r[i];
        for(int i = 1;i <= m;i++) cin >> x[i] >> v[i];
        while(!pq.empty()) pq.pop();

        ll idx = 1, speed = 1, result = 0;
        for(int i = 1;i <= n;i++){
            ll cur = l[i] - 1;
            while(x[idx] <= cur && idx <= m){
                pq.push(v[idx]); idx++;
            }

            ll diff = r[i] - l[i] + 2;
            while(!pq.empty() && speed < diff){
                speed += pq.top(); pq.pop();
                result++;
            }

            if(speed < diff) {
                result = -1; break;
            }
        }

        cout << result << "\n";
    }


    return 0;
}
