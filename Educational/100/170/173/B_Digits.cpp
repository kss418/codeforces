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

bool chk3(){
    return (m % 3 == 0 || n >= 3);
}

bool chk5(){
    return (m == 5);
}

bool chk7(){
    return (m == 7 || n >= 3);
}

bool chk9(){
    if(n >= 6 || m == 9) return 1;
    return (n >= 3 && m % 3 == 0);
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << 1 << " ";
        if(chk3()) cout << 3 << " ";
        if(chk5()) cout << 5 << " ";
        if(chk7()) cout << 7 << " ";
        if(chk9()) cout << 9 << " ";
        cout << "\n";
    }


    return 0;
}
