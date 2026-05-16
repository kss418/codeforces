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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll l[3], r[3];

class _pow {
public:
	_pow() {}

	__int128 ret(ll a, ll b){
        __int128 ret = 1;
        while(b){
            if(b & 1) ret *= a;
            a *= a; b >>= 1;
        }      
        return ret;
    }

	ll ret(ll a, ll b, ll p){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a % p, ret %= p;
            a *= a; a %= p; b >>= 1;
        }      
        return ret;
    }
};

int main() {
    fastio;

    cin >> t; _pow pow;
    while(t--){
        cin >> k; ll result = 0;
        for(int i = 1;i <= 2;i++) cin >> l[i] >> r[i];

        n = 0;
        while(1){
            __int128 now = pow.ret(k, n);
            if(now > 1e9 + 2) break;

            ll mx = r[2] / now, mn = l[2] / now; if(l[2] % now) mn++;
            result += max(min(mx, r[1]) - max(mn, l[1]) + 1, 0ll); n++;
        }

        cout << result << "\n";
    }

     
    return 0;
}
