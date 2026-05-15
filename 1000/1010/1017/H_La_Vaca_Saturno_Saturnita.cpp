#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll sq = sqrtl(MAX);
ll a[MAX];
vector <ll> idx[MAX], idx2[400];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] < sq) idx2[a[i]].push_back(i);
        else for(int j = a[i];j < MAX;j += a[i]) idx[j].push_back(i);
    }

    while(m--){
        ll l, r; cin >> k >> l >> r;
        ll cur = l, now = 0;

        while(cur <= r){
            while(k % a[cur] == 0) k /= a[cur];

            ll mn = r + 1;
            if(k >= sq){
                auto ub = upper_bound(all(idx[k]), cur);
                ll nxt = (ub == idx[k].end() ? r + 1 : *ub);
                mn = min(mn, nxt);
            }

            for(int i = 2;i < sq;i++){
                if(k % i) continue;
                auto ub = upper_bound(all(idx2[i]), cur);
                ll nxt = (ub == idx2[i].end() ? INF : *ub);
                mn = min(mn, nxt);
            }
        
            now += k * (mn - cur);
            cur = mn;
        }

        cout << now << "\n";
    }

    for(int i = 1;i <= n;i++){
        if(a[i] < sq) idx2[a[i]].clear();
        else for(int j = a[i];j < MAX;j += a[i]) idx[j].clear();
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}