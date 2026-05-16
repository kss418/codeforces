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
ll p[MAX], dep[MAX], len[MAX];
ll c1[MAX], c2[MAX];


int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 2;i <= n;i++) cin >> p[i];
        for(int i = 2;i <= n;i++) dep[i] = dep[p[i]] + 1;
        for(int i = 1;i <= n;i++) len[i] = c1[i] = c2[i] = 0;

        for(int i = 1;i <= n;i++){
            ll x = i, y = i % n + 1;
            while(x != y){
                if(dep[x] < dep[y]) swap(x, y);
                if(c1[x]) c2[x] = i; else c1[x] = i;
                x = p[x]; len[i]++;
            }
        }

        ll rest = n, result = 0, now = 0;
        for(int i = 1;i < n;i++){
            ll cur, v; cin >> cur >> v;
            if(!--len[c1[cur]]) --rest;
            if(!--len[c2[cur]]) --rest;

            ll cnt = 1; if(c2[cur]) cnt = 2;

            m -= v; now += v * cnt;
            result = m * rest + now;
            cout << result << " ";
        }
        cout << "\n";
    }


    return 0;
}
