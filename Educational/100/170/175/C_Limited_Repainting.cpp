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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
set <ll> dis, able;

void run(){
    cin >> n >> m >> s;
    dis.clear(); able.clear();
    dis.insert(MINF); dis.insert(INF);
    able.insert(MINF); able.insert(INF);
    for(int i = 0;i < n;i++) cin >> a[i].x, a[i].y = i;
    sort(a, a + n); reverse(a, a + n);

    ll result = 0, use = 0;
    for(int i = 0;i < n;i++){
        auto[num, idx] = a[i];
        auto dub = *dis.upper_bound(idx);
        auto dlb = *--dis.upper_bound(idx);
        auto aub = *able.upper_bound(idx);
        auto alb = *--able.upper_bound(idx);

        if(s[idx] == 'B'){
            able.insert(idx);
            if(aub < dub || alb > dlb) continue;
            else use++;
        }
        else{
            dis.insert(idx);
            if(dub <= aub || dlb >= alb) continue;
            else use++;
        }

        if(use <= m) continue;
        result = num; break;
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
