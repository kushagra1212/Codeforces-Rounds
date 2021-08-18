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

      int k;
    cin >> k;
    int num = sqrt(k - 1);
    int val = k - num * num - 1;
    if (val <= num) cout << val + 1 << " " << num + 1 << endl;
    else {
        cout << num + 1 << " " << num - (val - num) + 1 << endl;
    }
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
