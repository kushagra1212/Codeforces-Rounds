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
   
     int n; cin>>n;
      n=2*n;
     int a[n];
       
     for(int i=0;i<n;i++)
        cin>>a[i];
  
     vector<int> v;
     int prev=a[0];
     int count=1;
     for(int i=1;i<n;i++)
     {
             if(a[i]>prev)
             {
                     
                     v.push_back(count);
                     count=0;
                     prev=a[i];

             }
                     count++;
           
             
     }
     if(count!=0)
        v.push_back(count);
   
    vector<int> values(v.size(),1);
 
  
    int dp[(int)v.size()+1][n+1];
    

   int sum=0;
   
   for(int i=0;i<=v.size();i++)
   {
           for(int j=0;j<=n/2;j++)
           {
                   if(i==0 || j==0)
                        dp[i][j]=0;
                   else{
                     if(j-v[i-1]>=0)
                     {
                             dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i-1]]+v[i-1]);
                     }else{
                             dp[i][j]=dp[i-1][j];
                     }
                   }

          }
   }
  for(int i=0;i<=v.size();i++)
  {
          if(dp[i][n/2]==n/2)
          {
                  cout<<"YES\n";
                  return;
          }
  }
 
                  cout<<"NO\n";
                  return;

 





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