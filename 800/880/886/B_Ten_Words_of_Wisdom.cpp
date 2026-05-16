#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll; 
typedef pair<int, int> pi; typedef pair<ll, ll> pll; 
typedef unsigned long long ull; ll n, m, k, t; string s;
        
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 1010101;
ll arr[4];

int main() { 
    fastio;
    
    cin >> t;
    while(t--){
        cin >> n;
        ll m = 0, result = 0;
        for(int i = 1;i <= n;i++){
            ll a, b;
            cin >> a >> b;
            if(a > 10) continue;
            if(b <= m) continue;
            m = b;
            result = i;
        }
        
        cout << result << "\n";
    }
        
        
    return 0;
}

     
  
  
