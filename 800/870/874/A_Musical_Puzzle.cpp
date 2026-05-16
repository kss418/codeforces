#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 501010;
set <ll> arr;


int main() {
	fastio;

    cin >> t;
    while(t--){
        cin >> n >> s;
        arr.clear();
        for(int i = 0; i < n - 1;i++){
            arr.insert(s[i] * 26 + s[i + 1]);
        }

        cout << arr.size() << "\n";
    }


	return 0;
}
