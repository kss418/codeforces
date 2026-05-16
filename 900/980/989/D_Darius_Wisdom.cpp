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
ll a[MAX], cnt[3];
vector <ll> arr[3][3];
vector <pll> result;

void sw(ll ai, ll an, ll bi, ll bn){
    vector <ll>& a = arr[ai][an];
    vector <ll>& b = arr[bi][bn];
    while(!a.empty() && !b.empty()){
        ll ab = a.back(), bb = b.back();
        a.pop_back(); b.pop_back();

        result.push_back({ab, bb});
        arr[bi][an].push_back(bb);
        arr[ai][bn].push_back(ab);
    }
}

void init(){
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++) arr[i][j].clear();
    }
    result.clear();
}

bool chk(){
    ll sz0 = arr[0][0].size();
    return (sz0 == cnt[0]);
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; init();
        for(int i = 1;i <= n;i++) cin >> a[i], cnt[a[i]]++;

        for(int i = 1;i <= cnt[0];i++) arr[0][a[i]].push_back(i);
        for(int i = cnt[0] + 1;i <= cnt[0] + cnt[1];i++) arr[1][a[i]].push_back(i);
        for(int i = cnt[0] + cnt[1] + 1;i <= n;i++) arr[2][a[i]].push_back(i);
        while(!chk()){
            sw(0, 2, 2, 1);
            sw(0, 2, 1, 1);
            sw(0, 1, 1, 0);
            sw(0, 1, 2, 0);
        }
        sw(1, 2, 2, 1);

        cout << result.size() << "\n";
        for(auto& i : result) cout << i.x << " " << i.y << "\n";
    }


    return 0;
}
