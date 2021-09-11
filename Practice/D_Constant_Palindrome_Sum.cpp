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
     int n,k;
     cin>>n>>k;
     int a[n];
     map<int,int> mp;
     for(int i=0;i<n;i++)
     {
                     cin>>a[i];
              
     }
     vector<int> maxi(2*k+2,0);
     vector<int> mini(2*k+2,0);
     int sum[n/2];
     for(int i=0;i<n/2;i++){
        mini[min(a[i],a[n-1-i])+1]++;
        maxi[max(a[i],a[n-1-i])+k]++;
        sum[i]=a[i]+a[n-1-i];
               mp[sum[i]]++;
     }
     int prefix[2*k+2];
     memset(prefix,0,sizeof(prefix));
     for(int i=1;i<2*k+2;i++){
          prefix[i]=prefix[i-1];
          if(mini[i]){
                  prefix[i]+=mini[i];
          }
          if(maxi[i-1]){
                  prefix[i]-=maxi[i-1];
          }
     }
     
     int ans=INT64_MAX;
     
     for(int i=0;i<n/2;i++){
         int x=prefix[sum[i]]-mp[sum[i]];
         int y=n/2-prefix[sum[i]];
         y=2*y;
        
         int temp=x+y;
         ans=min(ans,temp);
     }

     cout<<min(ans,n/2)<<nline;




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