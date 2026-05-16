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
constexpr ll MOD = 998244353;
deque <ll> tr;
bool p[MAX];


int main() {
    fastio;

    for(int i = 1;i < MAX;i <<= 1) p[i] = 1;

    cin >> t;
    while(t--){
        cin >> n; tr.clear();
        ll result = 0, mx = 0, mn;
        for(int i = 1;i <= n;i <<= 1) mx = i; mx--;
        for(int i = 1;i <= n;i <<= 1) {
            if(i & n) { mn = i; break; }
        }

        if(n % 2 == 0 && !p[n]){
            tr.push_back(n);
            tr.push_back(n - 1);
            tr.push_back(mx);
            for(int i = 1;i <= n - 2;i++){
                if(i == mx) continue;
                tr.push_front(i);
            }
        }
        else if(n % 2 == 0){
            tr.push_back(1);
            tr.push_back(3);
            tr.push_back(n - 2);
            tr.push_back(n - 1);
            tr.push_back(n);
            for(int i = 2;i <= n - 3;i++){
                if(i == 3) continue;
                tr.push_front(i);
            }
        }
        else{
            tr.push_back(mn);
            tr.push_back(mn + (mn == 1 ? 2 : 1));
            tr.push_back(n - mn);
            tr.push_back(n);

            for(int i = 1;i < n;i++){
                if(i == mn || i == n - mn) continue;
                if(i == mn + (mn == 1 ? 2 : 1)) continue;
                tr.push_front(i);
            }
        }

        for(int i = 0;i < n;i++){
            if(i % 2) result |= tr[i];
            else result &= tr[i];
        }

       cout << result << "\n";
       for(auto& i : tr) cout << i << " ";
       cout << "\n";
    }


    return 0;
}
