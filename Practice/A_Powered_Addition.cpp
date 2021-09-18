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
    int binpow(int a, int b) {
      int res = 1;
      while (b > 0) {
        if (b & 1)
          res = res * a;
        a = a * a;
        b >>= 1;
      }
      return res;
    }
void solve(){
     
     int n;
     cin>>n;
     int sum=0;
    int a[n];
    int maxi=0;
    for(int i=0;i<n;i++)
    cin>>a[i];
   
     for(int i=1;i<n;i++){
                if(a[i]<a[i-1]){
                            int temp=a[i-1]-a[i];
                            a[i]=a[i-1];
             int x=0;
             while(temp>0){
                     temp>>=1;
                     x++;
             }  
             maxi=max(maxi,x);
         }
             }
  

     cout<<maxi<<nline;

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