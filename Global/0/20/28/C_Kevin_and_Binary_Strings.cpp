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
ll a[MAX]; string result;

string chk(const string& now){
    string ret = s;
    for(int i = 0;i < min(now.size(), s.size());i++){
        if(ret[ret.size() - i - 1] == now[now.size() - i - 1]) ret[ret.size() - i - 1] = '0';
        else ret[ret.size() - i - 1] = '1';
    }

    return ret;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> s; cout << 1 << " " << s.size() << " ";
        ll sz = 1; for(int i = 1;i < s.size();i++){
            if(s[i] == '1') continue;
            sz = s.size() - i; break;
        }

        result = s; ll rs = 1, re = sz;
        for(int i = s.size() - 2;i >= 0;i--){
            if(sz + i >= s.size()) continue;
            string st = s.substr(i, sz);
            string now = chk(st);

            if(result >= now) continue;
            result = now;
            rs = i + 1; re = i + sz;
        }

        cout << rs << " " << re << "\n";
    }


    return 0;
}
