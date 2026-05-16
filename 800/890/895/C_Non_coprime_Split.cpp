#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 10101010;
ll p[MAX];

void is_prime(ll n){
  for(int i = 2;i * i<= n;i++){
    if(p[i] == -1) p[i] = 1;
    for(int j = 2 * i;j <= n;j += i) p[j] = i;
  }
}


int main() {
  fastio;

  cin >> t;
  memset(p, -1, sizeof(p));
  p[1] = 0;
  is_prime(MAX - 100);
  while(t--){
    cin >> n >> m;
    if(m <= 3) cout << -1 << "\n";
    else if(n == m && p[n] <= 1) cout << -1 << "\n";
    else if(n == m && p[n] > 1) cout << p[n] << " " << n - p[n] << "\n";
    else cout << 2 << " " << m - 2 - (m % 2) << "\n";
  }


  return 0;
}

 
