#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 2010;
ll cnt[MAX];


int main() {
  fastio;

  cin >> t;
  while(t--){
    cin >> n >> m;
    memset(cnt, 0, sizeof(cnt));

    for(int i = 1;i <= n;i++){
      ll num;
      cin >> num;
      cnt[num] = 1;
    }

    if(cnt[m]) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
