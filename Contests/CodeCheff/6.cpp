#include <iostream>
#include <string>
using namespace std;

void solve() {
    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        string ss;
        cin >> ss;

        int f = 0;
        long long cnt = n-2;

        for (int i = 0; i < n-2; i++) {
            if (ss[i] == ss[i+1] && ss[i+2] == ss[i+1]) {
                f = 1;
                cnt--;
            }
            
            else if((i+3<n) && (ss[i] == ss[i+1] && ss[i] == ss[i+3])){
                cnt--;
            }
        }

        cout << cnt + f << endl;
    }
}

int main() {
    solve();
    return 0;
}
