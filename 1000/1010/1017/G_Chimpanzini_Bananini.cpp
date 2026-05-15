#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
deque <ll> q;

void run(){
    cin >> n; 
    ll sum = 0, result = 0, cnt = 0, all = 0;
    q.clear(); bool rev = 0;

    while(n--){
        ll op; cin >> op;
        if(op == 1){
            result += sum;
            if(rev){
                ll back = q.front();
                result -= back * cnt;
                q.pop_front(); q.push_back(back);
            }
            else{
                ll back = q.back();
                result -= back * cnt;
                q.pop_back(); q.push_front(back);
            }
        }
        else if(op == 2) result = all - result + sum, rev ^= 1;
        else{
            ll x; cin >> x; cnt++;
            all += sum + cnt * x;
            sum += x;
            result += cnt * x;

            if(rev) q.push_front(x);
            else q.push_back(x);
        }

        cout << result << "\n";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}