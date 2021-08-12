#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool findPartiion(ll arr[], ll n) {
	ll sum = 0;
	ll i, j;
	for (i = 0; i < n; i++)
		sum += arr[i];
	if (sum % 2 != 0)
		return false;
	bool part[sum / 2 + 1];
	for (i = 0; i <= sum / 2; i++) {
		part[i] = 0;
	}
	for (i = 0; i < n; i++) {
		for (j = sum / 2; j >= arr[i]; j--) {
			if (part[j - arr[i]] == 1 || j == arr[i])
				part[j] = 1;
		}
	}
	return part[sum / 2];
}
void solve() {
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (findPartiion(a, n) == 0) {
		cout << "0\n";
	}
	else {
		ll mn = LONG_MAX, res=0;
		for (ll i = 0; i < n; i++) {
			ll zero = __builtin_ctz(a[i]);
			if(mn>zero) {
				res=i+1;
				mn=zero;
			}
		}
		cout<<1<<"\n"<<res<<"\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
