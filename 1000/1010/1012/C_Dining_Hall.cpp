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
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

class node{
public:
    ll d, y, x;
    bool operator < (const node& ot) const{
        if(d == ot.d){
            if(x == ot.x) return y < ot.y;
            return x < ot.x;
        }
        return d < ot.d;
    }
};
set <node> num[2];

void run(){
    cin >> n; num[0].clear(); num[1].clear();
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll cnt = 0, cx = 1, cy = 1;
    while(cnt < n){
        cnt++;
        num[0].insert({cy + cx, cy, cx});
        cx += 3; cy -= 3;
        if(cy < 0){ cy = cx; cx = 1; }
    }

    cnt = 0, cx = 1, cy = 1;
    while(cnt < n){
        cnt++;
        num[1].insert({cy + cx, cy, cx});
        num[1].insert({cy + cx + 1, cy + 1, cx});
        num[1].insert({cy + cx + 1, cy, cx + 1});
        num[1].insert({cy + cx + 4, cy + 1, cx + 1});

        cx += 3; cy -= 3;
        if(cy < 0){ cy = cx; cx = 1; }
    }

    for(int i = 1;i <= n;i++){
        if(a[i]){
            auto [cd, cy, cx] = *num[1].begin();
            num[1].erase(num[1].begin());

            cout << cx << " " << cy << "\n";
            if(cy % 3 != 1 || cx % 3 != 1) continue;
            num[0].erase(num[0].find({cd, cy, cx}));
        }
        else{
            auto [cd, cy, cx] = *num[0].begin();
            num[0].erase(num[0].begin());

            cout << cx << " " << cy << "\n";
            num[1].erase(num[1].find({cd, cy, cx}));
        }
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
