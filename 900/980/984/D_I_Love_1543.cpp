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
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
string st[MAX];
vector <ll> num[MAX];

bool chk(ll cnt, ll idx){
    ll si = num[cnt].size();
    if(num[cnt][idx] != 1) return 0;
    if(num[cnt][(idx + 1) % si] != 5) return 0;
    if(num[cnt][(idx + 2) % si] != 4) return 0;
    if(num[cnt][(idx + 3) % si] != 3) return 0;
    return 1;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0;i < n;i++) cin >> st[i];
        for(int i = 0;i < max(n, m);i++) num[i].clear();

        for(int cnt = 0;cnt < (min(n, m) + 1) / 2;cnt++){
            for(int cx = cnt; cx < m - cnt;cx++){
                num[cnt].push_back(st[cnt][cx] - '0');
            }

            for(int cy = cnt + 1;cy < n - cnt - 1;cy++){
                num[cnt].push_back(st[cy][m - cnt - 1] - '0');
            }

            for(int cx = m - cnt - 1; cx >= cnt;cx--){
                num[cnt].push_back(st[n - cnt - 1][cx] - '0');
            }

            for(int cy = n - cnt - 2;cy >= cnt + 1;cy--){
                num[cnt].push_back(st[cy][cnt] - '0');
            }
        }

        ll result = 0;
        for(int cnt = 0;cnt < (min(n, m) + 1) / 2;cnt++){
            ll si = num[cnt].size();
            for(int i = 0;i < si;i++){
                result += chk(cnt, i);
            }
        }

        cout << result << "\n";
    }



    return 0;
}
