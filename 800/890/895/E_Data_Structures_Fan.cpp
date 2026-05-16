#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 101010;
ll q, arr[MAX], x[MAX], one;


int main() {
  fastio;

  cin >> t;
  while(t--){
    one = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    for(int i = 1;i <= n;i++) x[i] = arr[i] ^ x[i - 1];

    cin >> s;
    for(int i = 0;i < n;i++) if(s[i] == '1') one ^= arr[i + 1];

    cin >> q;
    while(q--){
      ll com, a, b;
      cin >> com;
      if(com == 2){
        cin >> a;
        ll zero = x[n] ^ one;
        if(a) cout << one << " ";
        else cout << zero << " ";
      }
      else{
        cin >> a >> b;
        one ^= (x[b] ^ x[a - 1]);
      }
    }

    cout << "\n";
  }


  return 0;
}

 
