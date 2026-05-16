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


int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m >> k >> s;

        ll cnt = 0, result = 0;
        deque <ll> arr;
        for(int i = 0;i < n;i++){
            arr.push_back(i);
            if(s[i] == '1') cnt++;

            if(arr.size() > m){
                ll fr = s[arr.front()];
                if(fr == '1') cnt--;
                arr.pop_front();
            }

            if(arr.size() == m){
                if(!cnt){
                    for(int j = i;j < i + k;j++) {
                        if(j >= n) break; s[j] = '1';
                    }
                    result++; cnt = 1;
                }
            }
        }

        cout << result << "\n";
    }


    return 0;
}
