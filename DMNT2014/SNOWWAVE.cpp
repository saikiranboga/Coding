#include <bits/stdc++.h>
#define msg(x) cout << #x << " = " << x << endl
using namespace std;

int n, x;
multiset<int> s;
multiset<int>::iterator it;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x - i > 0) {
            //this part is fastest way of finding
            //longest non-decreasing subsequence
            //if you simply want longest increasing, replace multiset with set
            x -= i;
            s.insert(x);
            it = upper_bound(s.begin(), s.end(), x);
            if (it != s.end()) s.erase(it);
        }
    }
    cout << n - s.size() << endl;
    return 0;
}
