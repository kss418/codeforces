#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
stack <ll> st;


int main()
{
    cin >> t;

    while (t--) {
        cin >> n;
        cin >> s;

        ll cnt = 1, result = 0;
        s[0] = '('; st.push(1);
        for (int i = 1; i < n; i++) {
            if (s[i] == '_') {
                if (cnt > 0) cnt--, s[i] = ')';
                else cnt++, s[i] = '(';
            }
            else if (s[i] == '(') cnt++;
            else cnt--;
        }

        cnt = 0;
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') cnt++, st.push(i);
            else {
                result += i - st.top();
                st.pop(); cnt--;
            }
        }

        cout << result << "\n";
    }

    return 0;
}
