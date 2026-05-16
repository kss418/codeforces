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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll v[MAX][MAX];
ll dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

void init(ll cy, ll cx){
    for(int i = 0;i <= cy;i++){
        for(int j = 0;j <= cx;j++) v[i][j] = -1;
    }
}

bool outrange(ll cy, ll cx){
    if(cy < 0 || cx < 0 || cx >= m || cy >= n) return 1;
    return 0;
}

ll dfs(ll cy, ll cx){
    if(outrange(cy, cx)) return 0;
    if(v[cy][cx] != -1) return v[cy][cx]; v[cy][cx] = 1;
    char dir = st[cy][cx];

    if(dir == '?'){
        ll cur = 0;
        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            cur = max(cur, dfs(ny, nx));
        }
        v[cy][cx] = cur;
    }
    else{
        ll ny = cy, nx = cx;
        if(dir == 'U') ny += dy[0], nx += dx[0];
        else if(dir == 'D') ny += dy[1], nx += dx[1];
        else if(dir == 'L') ny += dy[2], nx += dx[2];
        else ny += dy[3], nx += dx[3];

        v[cy][cx] = dfs(ny, nx);
    }

    return v[cy][cx];
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m; init(n, m);
        for(int i = 0;i < n;i++) cin >> st[i];

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++) {
                if(v[i][j] != -1) continue;
                dfs(i, j);
            }
        }

        ll result = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(v[i][j] == 1) result++;
            }
        }

        cout << result << "\n";
    }


    return 0;
}
