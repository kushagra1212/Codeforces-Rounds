
#include <bits/stdc++.h>


using namespace std;



#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> para;
const ll inf = 1e18 + 7;
const ll maxN = 1e6 + 5;
const ll MOD = 1e9 + 7;

// sprawdz MODULO!
int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	REP(_, t) {
		int n; cin >> n;
		vi a(n + 1);
		RI(i, n) {
			cin >> a[i];
		}
		int l = 0, r = n + 1;
		RI(i, n) {
			if (a[i] != i) {
				l = i; break;
			}
		}
		FORD(i, n, 1) {
			if (a[i] != i) {
				r = i;
				break;
			}
		}
		if (l == 0) {
			cout << 0 << "\n";
		} else {
			int x = 1;
			FOR(i, l, r) {
				if (a[i] == i) {
					x = 2;
					break   ;
				}
			}
			cout << x << "\n";
		}
	}
	return 0;
}
 
