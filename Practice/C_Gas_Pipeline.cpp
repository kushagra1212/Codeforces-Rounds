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


class Solution {
private:
public:
 
void solve(){
   int n,a,b; cin>>n>>a>>b;
   string s;
   cin>>s;
int dp[n+1][2];
 for(int i=0;i<=n;i++)
 {
         dp[i][0]=1e18;
         dp[i][1]=1e18;

 }
   dp[0][0]=b;

   
   for(int i=1;i<=n;i++)
   {
           if(s[i-1]=='0')
           {
             dp[i][0]=min(dp[i][0],dp[i-1][0]+a+b);
             dp[i][1]=min(dp[i][1],dp[i-1][0]+2*a+2*b);

             dp[i][1]=min(dp[i][1],dp[i-1][1]+a+2*b);
             dp[i][0]=min(dp[i][0],dp[i-1][1]+2*a+b);
           }else{
             
              dp[i][1]=min(dp[i][1],dp[i-1][1]+a+2*b);
                    
           }
   }
   cout<<dp[n][0]<<nline;
   



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
  cin >> t;
  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}