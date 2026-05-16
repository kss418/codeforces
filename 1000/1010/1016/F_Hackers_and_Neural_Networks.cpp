#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;

string a[MAX];
pair <vector <string>, ll> b[MAX];
ll cnt[MAX];
bool v[MAX];
vector <ll> adj[MAX], back[MAX];

void run(){
    cin >> n >> m;
    for(int i = 0;i < m;i++) adj[i].clear();
    for(int i = 0;i < n;i++) back[i].clear(), v[i] = 0;

    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++){
        b[i].y = i;
        for(int j = 0;j < n;j++){
            cin >> s, b[i].x.push_back(s);
            if(s == a[j]){
                cnt[i]++, adj[i].push_back(j);
                back[j].push_back(i);
            }
        }
    }

    ll result = n, c = 0, use = 0;
    bool flag = 0;
    while(1){
        sort(b, b + m, [](pair <vector<string>, ll>& a, pair <vector<string>, ll>& b){
            return cnt[a.y] > cnt[b.y];
        });

        ll now = b[0].y;
        if(cnt[now] <= 0) break;
        if(flag) result += 2 * cnt[now];
        c += cnt[now]; flag = 1;

        for(auto& nxt : adj[now]){
            if(v[nxt]) continue;
            v[nxt] = 1; use++;
            for(auto& nn : back[nxt]) cnt[nn]--;
            back[nxt].clear();
        }
    }

    cout << (use == n ? result : -1) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
