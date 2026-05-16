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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll a[MAX];

class _pow {
public:
	_pow() {}

	ll ret(ll a, ll b){
        ll ret = 1;
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
vector <pll> st;

int main() {
    fastio;

    cin >> t; _pow pow;
    while(t--){
        cin >> n; st.clear();
        for(int i = 1;i <= n;i++) cin >> a[i];

        ll sum = 0;
        for(int i = 1;i <= n;i++){
            ll tmp = a[i], cnt = 0;
            while(tmp % 2 == 0) tmp /= 2, cnt++;
            while(!st.empty()){
                if(cnt >= 30 || st.back().x <= (tmp << cnt)){
                    cnt += st.back().y;
                    sum += st.back().x;
                    st.pop_back();
                }
                else break;
            }

            if(cnt) st.push_back({tmp, cnt});
            else sum += tmp;

            ll result = sum % MOD;
            for(auto& i : st) {
                result += pow.ret(2, i.y, MOD) * i.x % MOD;
                result %= MOD;
            }
            cout << result % MOD << " ";
        }
        cout << "\n";
    }


    return 0;
}
