#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 201010;
ll arr[MAX], seq[MAX];


int main() {
  fastio;

  cin >> t;
  while(t--){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    for(int i = 1;i <= n;i++){
      if(arr[i] <= k) seq[i] = seq[i - 1] + 1;
      else seq[i] = 0;
    }

    ll cur = n, result = 0;
    while(cur > 0){
      if(seq[cur] >= m) {
        result += (seq[cur] - m + 1) * (seq[cur] - m + 2) / 2;
        cur -= seq[cur];
      }
      else cur--;
    }

    cout << result << "\n";
  }


  return 0;
}
