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
ll a[MAX], b[MAX];
map <ll, pll> num;
vector <tll> q;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m; ll result = 0, now = 0;
        q.clear(); num.clear();

        for(int i = 1;i <= n;i++) {
            cin >> a[i]; num[a[i]].x += 0;
            num[a[i] + 1].x += 1;
        }

        for(int i = 1;i <= n;i++) {
            cin >> b[i]; num[b[i]].x += 0;
            num[b[i] + 1].x -= 1; num[b[i] + 1].y -= 1;
        }

        for(auto& i : num) q.push_back({i.x, i.y.x, i.y.y});
        sort(all(q));

        ll cnt = n, neg = 0;
        for(auto& i : q){
            auto[num, f, c] = i;
            cnt += c; neg += f;

            if(neg > m) continue;
            result = max(result, cnt * num);
        }

        cout << result << "\n";
    }


    return 0;
}
