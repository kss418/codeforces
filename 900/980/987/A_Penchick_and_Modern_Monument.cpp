#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

template <typename T = ll>
class _lis {
public:
    ll n; vector<T> arr;
    vector<T> result, rec;
    vector<T> num;

    _lis(ll n) {
        this->n = n;
        arr.resize(n + 1); rec.resize(n + 1);
    }

    void add(ll idx, ll n) {
        arr[idx] = n;
    }

    void init() {
        for (int i = 1; i <= n; i++) {
            ll cur = arr[i];
            auto nxt = upper_bound(num.begin(), num.end(), cur) - num.begin();
            if (nxt == num.size()) num.push_back(cur);
            else num[nxt] = cur;
            rec[i] = nxt + 1;
        }

        ll cnt = num.size();
        result.resize(cnt);
        for (int i = n; i >= 1; i--) {
            if (rec[i] != cnt) continue;
            cnt--; result[cnt] = arr[i];
        }
    }

    vector <ll> ret() {
        return result;
    }
};

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; _lis lis(n);
        for(int i = 1;i <= n;i++) {
            cin >> a[i]; lis.add(i, a[i]);
        }
        lis.init();

        cout << n - lis.ret().size() << "\n";
    }


    return 0;
}
