#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 101010;
deque <char> result;


int main() {
  fastio;

  cin >> t;
  while(t--){
    cin >> n >> s;
    char top = '0';
    for(int i = n - 1;i >= 0;i--){
      if(top == '0') top = s[i];
      else{
        if(s[i] == top) {
          result.push_back(s[i]);
          top = '0';
        }
      }
    }

    while(!result.empty()){
      cout << result.back();
      result.pop_back();
    }
    cout << "\n";
  }


  return 0;
}
