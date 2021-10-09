#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int solve() {
    int n;
    cin >> n;
    vector<int> p;
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        p.push_back(e);
    }
    int x, a;
    cin >> x >> a;
    int y, b;
    cin >> y >> b;
    int k;
    cin >> k;
 
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    vector<int> pr;
    pr.push_back(0);
    for (int i = 0; i < n; ++i) {
        pr.push_back(pr[pr.size() - 1] + p[i]);
    }
 
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
 
    int ax = 0;
    int by = 0;
    int axby = 0;
 
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % a == 0 && i % b == 0) {
            axby++;
        }
        else if (i % a == 0) {
            ax++;
        }
        else if (i % b == 0) {
            by++;
        }
        cur = 0;
        cur += pr[axby]/ 100 * (x + y);
        cur += (pr[axby + ax] - pr[axby]) / 100 * x;
        cur += (pr[axby + ax + by] - pr[axby + ax]) / 100 * y;
        if (cur >= k) {
            return i;
        }
    }
    return -1;
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cout << solve() << '\n';
    }
}