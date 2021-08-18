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
int a[x];
const int mod = 1e9 + 7;
class Solution {
private:
public:


  void solve() {

   int n;
   cin>>n;
   cout<<a[n]<<nline;

  }








};

int32_t main()
{

  FAST; Solution sol;
  // #ifndef ONLINE_JUDGE
  //  freopen("input.txt","r",stdin);
  //  freopen("output.txt","w", stdout);
  // #endif

  int k=1;
  for(int i=1;i<=100000 and k<=1000;i++){
    if(i%10==3 || i%3==0)
      continue;
    else{
      a[k]=i;
      k++;
    }
  }
  int t;
  t = 1;
cin >> t;
  while (t--)
    sol.solve();

  return 0;
}
