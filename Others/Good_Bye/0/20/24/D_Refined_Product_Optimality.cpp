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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX];
vector <ll> av, bv;

class _gcd {
public:
    _gcd() {}

    tll init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
} g;

void run(){
    cin >> n >> m; av.clear(); bv.clear();
    for(int i = 1;i <= n;i++) cin >> a[i], av.push_back(a[i]);
    for(int i = 1;i <= n;i++) cin >> b[i], bv.push_back(b[i]);
    sort(all(av)); sort(all(bv));

    ll result = 1;
    for(int i = 0;i < n;i++){
        result *= min(av[i], bv[i]);
        result %= MOD;
    }
    result = (result + MOD) % MOD;
    cout << result << " ";

    while(m--){
        ll op, idx; cin >> op >> idx;
        if(op == 1){
            ll it = upper_bound(all(av), a[idx]) - av.begin() - 1;
            a[idx]++; av[it]++;
            result *= g.inv(min(av[it] - 1, bv[it]), MOD); result %= MOD;
            result *= min(av[it], bv[it]); result %= MOD;
        }
        else{
            ll it = upper_bound(all(bv), b[idx]) - bv.begin() - 1;
            b[idx]++; bv[it]++;
            result *= g.inv(min(av[it], bv[it] - 1), MOD); result %= MOD;
            result *= min(av[it], bv[it]); result %= MOD;
        }

        result = (result + MOD) % MOD;
        cout << result << " ";
    }
    cout << "\n";
}

int main() {
    fastio;

    cin >> t;
    while(t--) run();
    

    return 0;
}
