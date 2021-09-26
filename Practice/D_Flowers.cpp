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
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int dp[100001];
int pre[100001];
const int mod=1000000007;
class Solution {
private:
public:
 
void solve(){
   
   int a,b;
   cin>>a>>b;
   
   int ans=(pre[b]%mod-pre[a-1]%mod+mod)%mod;
   cout<<ans<<nline;


  }
};

int32_t main()
{
  auto begin = std::chrono::high_resolution_clock::now();
  FAST; Solution sol;
  // #ifndef ONLINE_JUDGE
  //  freopen("input.txt","r",stdin);
  //  freopen("output.txt","w", stdout);
  // #endif
  int t;
  t = 1;
  int k;
   
cin >> t;
  cin>>k;
  for(int i=1;i<k;i++) dp[i]=1;
  dp[k]=2;

  for(int i=k+1;i<=100000;i++)
    dp[i]=(dp[i-1]%mod+dp[i-k]%mod)%mod;
 
  for(int i=1;i<=100000;i++)
    pre[i]=(pre[i-1]%mod+dp[i]%mod)%mod;

  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}