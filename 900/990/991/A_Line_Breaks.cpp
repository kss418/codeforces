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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
vector <ll> num;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m; num.clear();
        for(int i = 0;i < n;i++) {
            cin >> st[i];
            num.push_back(st[i].size());
        }

        ll result = 0, sum = 0;
        for(auto& i : num){
            if(sum + i <= m) sum += i, result++;
            else break;
        }

        cout << result << "\n";
    }


    return 0;
}
