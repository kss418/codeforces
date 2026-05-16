#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, num, sum = 0;
        cin >> n;
        vector <int> arr;
        for (int i = 0; i < n; i++) {
            cin >> num;
            arr.push_back(num);
            sum += num;
        }

        int result = n;
        for (int i = n; i >= 2; i--) {
            if (sum % i != 0) {
                continue;
            }
            int cnt = 0;
            int cur = 0;
            int avg = sum / i;
            int piece = 0;
            int ret = 0;

            for (int j = 0; j < n; j++) {
                cur += arr[j];
                cnt++;

                if (cur == avg) {
                    piece++;
                    ret = max(ret, cnt);
                    cnt = 0;
                    cur = 0;
                }

                else if (cur > avg) {
                    cnt = 0;
                    break;
                }
            }

            if (piece == i) {
                piece = 0;
                result = min(result, ret);
            }
        }

         cout << result << "\n";
    }




    return 0;
}
