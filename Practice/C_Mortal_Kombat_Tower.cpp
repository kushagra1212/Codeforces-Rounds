#include <bits/stdc++.h>
using namespace std;
#define int long long int 
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
int n;
class Solution {
private:
public:

int rec(vector<int> &a,int i,vector<int> &dp){
   
  if(i>=n)
    return 0;
if(dp[i]!=-1)
  return dp[i];
   
int one=INT_MAX;
int two=INT_MAX;
   if(i<n){

      one=min(rec(a,i+3,dp),rec(a,i+2,dp))+a[i];
   }
   if(i+1<n){
      two=min(rec(a,i+4,dp),rec(a,i+3,dp))+a[i]+a[i+1];
   }
   return dp[i]=min(one,two);
    
}
void solve(){
     
      cin>>n;
    vector<int> a(n);
     for(int i=0;i<n;i++)
        cin>>a[i];
vector<int> dp(n+1,-1);
     cout<<rec(a,0,dp)<<nline;


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