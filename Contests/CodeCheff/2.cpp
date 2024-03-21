#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        int ans;
        if (N > 1) {
            ans = ((N / 2) * 13) + (N % 2) * 6;
        } else {
            ans = 6;
        }
        cout << ans << endl;
    }

    return 0;
}
