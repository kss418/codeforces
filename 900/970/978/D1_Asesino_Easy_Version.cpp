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

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n;

        pll able;
        for(int i = 1;i < n; i += 2){
            ll a, b;
            cout << "? " << i << " " << i + 1 << endl;
            cin >> a;
            cout << "? " << i + 1 << " " << i << endl;
            cin >> b;

            if(a == b) continue;
            able = {i, i + 1}; break;
        }

        if(!able.x) cout << "! " << n << endl;
        else{
            for(int i = 1;i <= n;i += 2){
                if(i == able.x) continue;
                ll a, b;
                cout << "? " << i << " " << able.x << endl;
                cin >> a;
                cout << "? " << able.x << ' ' << i << endl;
                cin >> b;

                if(a == b) cout << "! " << able.y << endl;
                else cout << "! " << able.x << endl;
                break;
            }
        }
    }


    return 0;
}
