#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> result;
string st = "LIT";

void cal(ll idx){
    string rest = st;
    rest.erase(find(all(rest), s[idx])); rest.erase(find(all(rest), s[idx + 1]));
    result.push_back(idx);
    s = s.substr(0, idx + 1) + rest + s.substr(idx + 1);
}

void run(){
    cin >> n >> s; result.clear();
    if(count(all(s), s[0]) == n){ cout << -1 << "\n"; return; }

    while(1){
        vector <pair<ll, char>> cnt;
        for(auto& i : st) cnt.push_back({count(all(s), i), i});
        sort(all(cnt));

        if(cnt[0].x == cnt[1].x && cnt[1].x == cnt[2].x) break;
        bool flag = 0;

        for(int i = 0;i < s.size() - 1;i++){
            if(s[i] == s[i + 1]) continue;
            if(s[i] == cnt[0].y || s[i + 1] == cnt[0].y) continue;
            cal(i); flag = 1; break;
        }

        if(flag) continue;
        for(int i = 0;i < s.size() - 1;i++){
            if(s[i] == s[i + 1]) continue;
            if(s[i] == cnt[2].y){
                cal(i); cal(i + 1); cal(i); cal(i + 2); break;
            }
            else if(s[i + 1] == cnt[2].y){
                cal(i); cal(i); cal(i + 1); cal(i + 3); break;
            }
        }
    }

    cout << result.size() << "\n";
    for(auto& i : result) cout << i + 1 << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}
