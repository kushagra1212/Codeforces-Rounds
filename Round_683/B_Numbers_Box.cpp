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
   
    int n,m; cin>>n>>m;
    int a[n][m];
   int count=0;
   int sum=0;
   int x,y,mini=INT64_MAX;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
        {
                cin>>a[i][j];
                if(a[i][j]<0)
                    count++;
                sum+=abs(a[i][j]);
                if(abs(a[i][j])<mini)
                {
                    mini=abs(a[i][j]);
                    x=i,y=j;
                }
        }
   }
   if(count%2==0)
    cout<<sum<<nline;
   else{
      sum=0;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(x==i and y==j)
              {
                sum-=abs(a[i][j]);
              }else{
                  
              sum+=abs(a[i][j]);
              }
          }
      }
      cout<<sum<<nline;
   }
   


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