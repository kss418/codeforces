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
ll a[MAX], sum[MAX];
bool group[MAX];
pll arr[MAX];

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        memset(group, 0, sizeof(group));
        ll cnt = 0;
        for(int i = 0;i < cur - 1;i++){
            if(i >= n - 1) break;
            if(arr[i].x < 0) break;
            group[arr[i].y] = 1;
        }

        ll ret = 0;
        for(int i = 0;i < n;i++){
            cnt += group[i];
            if(s[i] == '1') ret += cnt;
            else ret -= cnt;
        }

        return ret >= m;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m >> s;
        sum[n - 1] = (s[n - 1] == '0') ? -1 : 1;
        for(int i = n - 2;i >= 0;i--){
            sum[i] = sum[i + 1] + ((s[i] == '0') ? -1 : 1);
            arr[i] = {sum[i + 1], i + 1};
        }
        sort(arr, arr + n - 1); reverse(arr, arr + n - 1);

        _bs <ll> bs(1, n + 1);

        ll ret = bs.ret();
        if(ret == n + 1) cout << -1 << "\n";
        else cout << ret << "\n";
    }


    return 0;
}
