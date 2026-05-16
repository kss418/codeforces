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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll able[MAX], cnt;

bool chk(ll idx){
    if(idx + 3 >= s.size()) return 0;

    if(s[idx] != '1') return 0;
    if(s[idx + 1] != '1') return 0;
    if(s[idx + 2] != '0') return 0;
    if(s[idx + 3] != '0') return 0;
    return 1;
}

int main() {
    fastio;


    cin >> t;
    while(t--){
        cin >> s >> n; cnt = 0;
        for(int i = 0;i < s.size();i++) {
            able[i] = chk(i);
            cnt += chk(i);
        }

        while(n--){
            ll idx; char num; cin >> idx >> num; idx--;
            s[idx] = num;

            for(int i = idx - 3;i <= idx;i++){
                if(i < 0) continue;
                cnt -= able[i];
                able[i] = chk(i);
                cnt += able[i];
            }

            if(cnt) cout << "YES\n";
            else cout << "NO\n";
        }
    }



    return 0;
}
