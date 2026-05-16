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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX][MAX];
ll rx[MAX], ry[MAX];
pll sx[MAX], sy[MAX];
bool use[MAX][MAX];
deque <pll> q;

void run(){
    cin >> n >> m >> s; ll cy = 1, cx = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin >> a[i][j].y, a[i][j].x = 0;
    }

    memset(use, 0, sizeof(use));
    use[cy][cx] = 1;
    for(auto& i : s){
        if(i == 'D') cy++;
        else cx++;
        use[cy][cx] = 1;
    }

    memset(ry, 0, sizeof(ry)); memset(ry, 0, sizeof(rx));
    for(int i = 1;i <= n;i++) sy[i] = {0, 0};
    for(int i = 1;i <= m;i++) sx[i] = {0, 0};
    q.clear();

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ry[i] += use[i][j];
            sy[i].y += a[i][j].y;
        }
        if(ry[i] == 1) q.push_back({i, -1});
    }

    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            rx[i] += use[j][i];
            sx[i].y += a[j][i].y;
        }
        if(rx[i] == 1) q.push_back({i, 1});
    }

    while(!q.empty()){
        auto[now, f] = q.front(); q.pop_front();
        if(f == -1){
            for(int i = 1;i <= m;i++){
                if(!use[now][i]) continue;
                use[now][i] = 0;
                ry[now]--; rx[i]--;
                a[now][i].x = -sy[now].x + 1;
                a[now][i].y = -sy[now].y;
                sx[i].x += a[now][i].x;
                sx[i].y += a[now][i].y;

                if(rx[i] == 1) q.push_back({i, 1});
                break;
            }
        }
        else{
            for(int i = 1;i <= n;i++){
                if(!use[i][now]) continue;
                use[i][now] = 0;
                rx[now]--; ry[i]--;

                a[i][now].x = -sx[now].x + 1;
                a[i][now].y = -sx[now].y;

                sy[i].x += a[i][now].x;
                sy[i].y += a[i][now].y;


                if(ry[i] == 1) q.push_back({i, -1});
                break;
            }
        }
    }

    pll num = {0, 0};
    for(int i = 1;i <= n;i++){
        num.x += a[i][1].x; num.y += a[i][1].y;
    }

    ll now = 0;
    if(num.x != 1) now = -num.y / (num.x - 1);

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cout << a[i][j].x * now + a[i][j].y << " ";
        cout << "\n";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
