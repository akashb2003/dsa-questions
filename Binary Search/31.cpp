

#include<bits/stdc++.h>
using namespace std;

// Minimum Difference Element in sorted array
int minDiff(vector<int> v, int n, int target) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (v[mid] == target) return target;
        else if (v[mid] < target) s = mid + 1;
        else e = mid - 1;
    }
    int val1 = abs(v[e] - target);
    int val2 = abs(v[s] - target);
    return (min(val1, val2) == val1) ? v[e] : v[s];
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << minDiff(v, n, target);
}
