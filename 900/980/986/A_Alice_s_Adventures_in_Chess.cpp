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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> k >> m >> s;
        ll cx = 0, cy = 0;
        bool flag = 0;
        if(cy == m && cx == k) flag = 1;

        for(int i = 0;i < 100;i++){
            for(auto& i : s){
                if(i == 'N') cy++;
                else if(i == 'S') cy--;
                else if(i == 'E') cx++;
                else cx--;

                if(cy == m && cx == k) flag = 1;
            }
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
