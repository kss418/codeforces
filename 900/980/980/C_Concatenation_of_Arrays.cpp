#include <bits/stdc++.h>
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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
class node{
public:
    ll x, y;
    bool operator<(node& ot){
        return x + y < ot.x + ot.y;
    }
};

node a[MAX];
map <ll, ll> num;
set <ll> able;
ll org[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; ll seq = 1;
        num.clear(); able.clear();

        for(int i = 1;i <= n;i++){
            cin >> a[i].x >> a[i].y;
            able.insert(a[i].x);
            able.insert(a[i].y);
        }

        for(auto& i : able) {
            org[seq] = i;
            num[i] = seq++;
        }
        for(int i = 1;i <= n;i++){
            a[i].x = num[a[i].x];
            a[i].y = num[a[i].y];
        }
        sort(a + 1, a + n + 1);

        for(int i = 1;i <= n;i++){
            cout << org[a[i].x] << " " << org[a[i].y] << " ";
        }
        cout << "\n";
    }


    return 0;
}
