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
     
     int n;
     cin>>n;
     char c;
     cin>>c;
     string s; cin>>s;
     int v=0;
     for(int i=0;i<n;i++){
             if(s[i]!=c){
                   v++;
             }
     }
     if(v==0){
             cout<<0<<nline;
             return;
     }
     unordered_map<int,int> mp1;
     for(int i=0;i<n;i++)
     {
             if(s[i]==c)
               mp1[i+1]=1;
     }

     unordered_map<int,unordered_map<int,int>> mp2;

     for(int i=1;i<=n;i++){
             int x=i;
             int count=2;
             mp2[i][x]=1;
   
             while(x*count<=n){
                     x=i*count;
                     mp2[i][x]=1;
                     count++;
             }
     }
      bool is=false;
      int number=n;
     for(int i=n;i>n/2;i--){
          bool check=true;
          for(auto m:mp2[i]){
                  if(mp1[m.first]!=1){
                          check=false;
                          break;
                  }
          }

          if(check){
                  is=true;
                  number=i;
                  break;
          }

     }
   
     if(is)
     {
             cout<<1<<nline;
             cout<<number<<nline;

     }else{
             cout<<2<<nline;
             cout<<number<<" "<<number-1<<nline;
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