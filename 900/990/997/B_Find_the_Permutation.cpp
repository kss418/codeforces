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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX]; ll ind[MAX];
deque <ll> q;

void run(){
    cin >> n; memset(ind, 0, sizeof(ind)); q.clear();
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++) {
            if(st[i][j] == '1') ind[j]++;
        }
        for(int j = 0;j < i;j++){
            if(st[i][j] == '0') ind[j]++;
        }
    }

    for(int i = 0;i < n;i++) if(!ind[i]) q.push_back(i);
    while(!q.empty()){
        ll cur = q.front(); q.pop_front();
        cout << cur + 1 << " ";

        for(int j = cur + 1;j < n;j++) {
            if(st[cur][j] == '0') continue;
            if(!--ind[j]) q.push_back(j);
        }
        for(int j = 0;j < cur;j++){
            if(st[cur][j] == '1') continue;
            if(!--ind[j]) q.push_back(j);
        }
    }
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
