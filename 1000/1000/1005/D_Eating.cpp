#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], pre[MAX];
vector <ll> idx[33];

void init(){
   for(int i = 0;i < 33;i++) idx[i].clear();
}

void run(){
    cin >> n >> m; init();
    for(int i = n;i >= 1;i--) cin >> a[i];
    for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] ^ a[i];
    for(int i = 1;i <= n;i++){
        for(int j = 30;j >= 0;j--){
            if(!(a[i] & (1ll << j))) continue;
            idx[j].push_back(i); break;
        }
    }

    while(m--){
        ll now, cur = 0, ret = 0; cin >> now;
        while(1){
            ll mx = -1;
            for(int i = 30;i >= 0;i--){
                if(!(now & (1ll << i))) continue;
                mx = i; break;
            }

            if(mx == -1) break; ll greater = INF;
            for(int i = 30;i > mx;i--){
                ll lb = upper_bound(all(idx[i]), cur) - idx[i].begin();
                if(lb != idx[i].size()) greater = min(greater, idx[i][lb]);
            }

            ll lb = upper_bound(all(idx[mx]), cur) - idx[mx].begin();
            if(lb == idx[mx].size()){
                if(greater == INF) ret = n;
                else ret = greater - 1; break;
            }

            ll nxt = idx[mx][lb];
            if(greater < nxt){ ret = greater - 1; break; }
            now ^= pre[nxt - 1] ^ pre[cur]; ret = nxt - 1;

            if(now < a[nxt]) break;
            now ^= a[nxt]; cur = nxt; ret++;
        }

        cout << ret << " ";
    }

    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
