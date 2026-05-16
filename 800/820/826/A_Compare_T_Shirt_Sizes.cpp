#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--) {
        string st, rd;
        cin >> st >> rd;
        if (st[st.size() - 1] == 'S') {
            if (rd[rd.size() - 1] == 'S') {
                if (st.size() > rd.size()) {
                    cout << "<" << "\n";
                }
                else if (st.size() < rd.size()) {
                    cout << ">" << "\n";
                }
                else {
                    cout << "=" << "\n";
                }
            }

            else {
                cout << "<" << "\n";
            }
        }

        else if (st[st.size() - 1] == 'L') {
            if (rd[rd.size() - 1] == 'L') {
                if (st.size() > rd.size()) {
                    cout << ">" << "\n";
                }
                else if (st.size() < rd.size()) {
                    cout << "<" << "\n";
                }
                else {
                    cout << "=" << "\n";
                }
            }

            else {
                cout << ">" << "\n";
            }
        }

        else {
            if (rd[rd.size() - 1] == 'S') {
                cout << ">" << "\n";
            }
            else if (rd[rd.size() - 1] == 'L') {
                cout << "<" << "\n";
            }
            else {
                cout << "=" << "\n";
            }
        }
    }





    return 0;
}
