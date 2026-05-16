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
constexpr ll MAX = 303; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], suf[MAX], result;
priority_queue <ll, vector<ll>, greater<ll>> pq;

void run(){
    cin >> n; result = 0;
    while(!pq.empty()) pq.pop();
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    for(int i = 1;i <= n;i++) suf[i] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = n;j >= 1;j--){
            if(a[i][j] == 1) suf[i]++;
            else break;
        }
        pq.push(suf[i]);
    }

    while(!pq.empty()){
        ll now = pq.top(); pq.pop();
        if(result <= now) result++;
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
