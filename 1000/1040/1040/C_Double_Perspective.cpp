#include <bits/stdc++.h>
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
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class node{
public:
    ll x, y, idx;
    bool operator < (const node& ot) const{
        if(x == ot.x) return y > ot.y;
        return x < ot.x;
    }
}; node a[MAX];
vector <ll> result;

void run(){
    cin >> n; result.clear();
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        a[i].idx = i;
    }
    sort(a + 1, a + n + 1);

    ll l = -1, r = -1;
    for(int i = 1;i <= n;i++){
        if(r < a[i].x){
            result.push_back(a[i].idx);
            l = a[i].x; r = a[i].y;
        }

        if(r < a[i].y) result.push_back(a[i].idx);
        r = max(r, a[i].y);
    }

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
