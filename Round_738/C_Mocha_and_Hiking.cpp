#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=2e9;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
//#define int ll

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int _; cin>>_;
    while (_--) {
        int n; cin>>n;
        vector<int> v(n);
        for (int &i:v) cin>>i;

        int pos;
        if (v[0]==1) pos=0;
        else if (v[n-1]==0) pos=n;
        else {
            for (int i=0;i<n-1;i++) {
                if (v[i]==0 && v[i+1]==1) pos=i+1;
            }
        }

        for (int i=0;i<pos;i++) cout<<i+1<<' ';
        cout<<n+1<<' ';
        for (int i=pos;i<n;i++) cout<<i+1<<' ';
        cout<<'\n';
    }
}
