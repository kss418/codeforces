#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 201;
ll a[MAX], b[MAX];


int main() {
  fastio;

  cin >> t;
  while(t--){
    cin >> n;
    ll cnt = 0;
    for(int i = 1;i <= n;i++) {
      cin >> a[i] >> b[i];
      if(a[i] > b[i]) cnt++;
    }

    cout << cnt << "\n";
  }


  return 0;
}
