#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], result[MAX];
ll pro, te, sp, st;
ll np[MAX], nt[MAX], use[MAX];

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1;i <= n + m + 1;i++) cin >> a[i];
        for(int i = 1;i <= n + m + 1;i++) cin >> b[i];

        pro = te = sp = st = 0;
        memset(np, 0, sizeof(np));
        memset(nt, 0, sizeof(nt));

        for(int i = 1;i <= n + m + 1;i++){
            if(a[i] > b[i]) pro++, np[pro] = i;
            else te++, nt[te] = i;
        }

        pro = te = 0;
        for(int i = 1;i <= n + m;i++){
            if(a[i] > b[i] && pro < n) pro++, sp += a[i], use[i] = 1;
            else if(te < m) te++, st += b[i], use[i] = -1;
            else pro++, sp += a[i], use[i] = 1;
        }
        result[n + m + 1] = st + sp;


        for(int i = 1;i <= n + m;i++){
            ll ct = st, cp = sp;
            if(use[i] == 1) {
                ct -= a[i];
                ll nxt = np[n + 1];
                if(nxt){
                    cp -= b[nxt]; ct += a[nxt];
                    cp += b[n + m + 1];
                }
                else ct += a[n + m + 1];
            }
            else {
                ct -= b[i];
                ll nxt = nt[m + 1];
                if(nxt){
                    cp -= a[nxt]; ct += b[nxt];
                    cp += a[n + m + 1];
                }
                else ct += b[n + m + 1];
            }

            result[i] = ct + cp;
        }

        for(int i = 1;i <= n + m + 1;i++) cout << result[i] << " ";
        cout << "\n";
    }

    return 0;
}
