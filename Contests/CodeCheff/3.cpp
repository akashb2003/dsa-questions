#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void asquare() {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    long long ans = 0;
    long long mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, ans + 2 * v[i]);
        ans += v[i];
    }
    cout << mx << "\n";
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        asquare();
    }
    return 0;
}
