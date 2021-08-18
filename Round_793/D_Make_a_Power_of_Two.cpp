#include <bits/stdc++.h>
using namespace std;
#define int  long long int
#define nline "\n"
#define FAST ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define deb(a) cerr<<#a<<" "<<a<<nline
#define all(a) a.begin(),a.end()
#define ctoi(c) (int)((int)c-'0')
#define debv(v) cerr<<#v<<" => [ "; for(auto &vv:v){cerr<<vv<<" ";}cerr<<"]"<<nline
#define deba(a,k,n) cerr<<#a<<" => [ "; for(int i=k;i<n;i++){cerr<<a[i]<<" ";}cerr<<"]"<<nline
#define loop(i,s,e) for(int i=s;i<e;i++)
#define itoc(i) (char)(i+'0')
const int x = 100001;

const int mod = 1e9 + 7;
class Solution {
private:
public:


  void solve() {


        int n;
        cin>>n;
        vector<int> dn;
        while(n) {
          dn.push_back(n % 10);
          n /= 10;
    }
    reverse(dn.begin(), dn.end());
    int zk = (int) dn.size();
    int ans = zk + 1;
        for(int i = 0; i <= 62; ++i) {
          int t = (int)1 << i;
          vector<int> vt;
          while(t) {
            vt.push_back(t % 10);
            t /= 10;
      }
      reverse(vt.begin(), vt.end());
      int up = (int) vt.size();
      int now = 0;
      for(int v : dn) {
        if(v == vt[now])  ++now;
        if(now == up)  break;
      }
      if(now == up)  ans = min(ans, zk - now);
      else  ans = min(ans, up - now + zk - now);

    }
    cout<<ans<<nline;

  }








};

int32_t main()
{

  FAST; Solution sol;
  // #ifndef ONLINE_JUDGE
  //  freopen("input.txt","r",stdin);
  //  freopen("output.txt","w", stdout);
  // #endif

  int t;
  t = 1;
cin >> t;
  while (t--)
    sol.solve();

  return 0;
}
