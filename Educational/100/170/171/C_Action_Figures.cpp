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
constexpr ll MAX = 401010;
constexpr ll MOD = 998244353;
ll a[MAX];
bool v[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> s;
        vector <ll> dis, buy;
        deque <ll> able;
        for(int i = 0;i < n;i++) v[i] = 0;

        for(int i = 0;i < n;i++){
            if(s[i] == '0') dis.push_back(i + 1);
            else able.push_back(i + 1);
        }

        ll result = 0;
        for(int i = n - 1;i >= 0;i--){
            if(s[i] == '0') continue;
            if(v[i]) continue;
            while(!dis.empty() && dis.back() > i + 1) {
                buy.push_back(dis.back()); dis.pop_back();
            }

            if(!dis.empty()) {
                result += dis.back();
                dis.pop_back();
            }
            else if(!able.empty()){
                result += able.front();
                v[able.front() - 1] = 1;
                able.pop_front();
            }
            else result += i + 1;
        }

        for(auto& i : buy) result += i;
        for(auto& i : dis) result += i;

        cout << result << "\n";
    }

    return 0;
}
