#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX]; deque<char> q;
ll fr;

void print() {
    for (auto& i : q) cout << i;
    cout << endl;
}

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n;

        q.clear(); fr = 0;
        while (q.size() < n) {
            if (!fr) {
                q.push_back('0');
                cout << "? "; print();

                ll ret; cin >> ret;
                if (ret) continue;
                q.pop_back();

                q.push_back('1');
                cout << "? "; print();
                cin >> ret; if (ret) continue;
                q.pop_back();
            }

            fr = 1; ll ret;
            q.push_front('0');
            cout << "? "; print();
            cin >> ret; if (ret) continue;

            q.pop_front(); q.push_front('1');
        }

        cout << "! "; print();
    }


    return 0;
}
