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
   string s;
   cin>>s;
   bool start=false;
   int index=-1;
   int count=0;
   for(int i=0;i<n;i++){
           if(start){
                   if(s[i]=='?'){
                           (i-1>=0 and s[i-1]=='R')?s[i]='B':s[i]='R';
                           count++;
                   }
           }
           if((s[i]=='R' or s[i]=='B') and start==false){
                   start=true;
                   index=i;
           }
           
   }
   if(index!=-1){
           for(int i=index-1;i>=0;i--){
                   if(s[i]=='?' and i+1<n){
                           s[i+1]=='R'?s[i]='B':s[i]='R';
                   }
           }
   }
   if(count==0){
           if(s[0]=='?')s[0]='R';
           for(int i=1;i<n;i++){
                 if(s[i]=='?'){
                           s[i-1]=='R'?s[i]='B':s[i]='R';
                 }
           }
   }
   cout<<s<<nline;



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

 auto end = std::chrono::high_resolution_clock::now();
 auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}