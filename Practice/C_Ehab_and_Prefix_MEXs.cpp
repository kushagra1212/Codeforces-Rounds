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
   int v[n];
   bool isPossible=true;
   for(int i=0;i<n;i++){
           cin>>v[i];
           if(v[i]>i+1){
                   isPossible=false;
           }
   }
   if(!isPossible)
   {
           cout<<-1<<nline;
        return ;
   }
   set<int> seet;
   seet.insert(0);
   int ans[n];
   for(int i=0;i<n;i++){
           seet.insert(i+1);
           auto it=seet.begin();
           if(*it==v[i]){
                   auto it2=seet.end();
                   it2--;
                  deb(*it2);
                   auto get=lower_bound(v+i,v+n,*it2);
          
                deb(*get);
                   if(get){
                            ans[i]=*it2;
                   seet.erase(it2);
                   }else{
                           ans[i]=0;
                   }
           }else{
                   ans[i]=*it;
                   seet.erase(it);
           }
   }
   for(int i=0;i<n;i++){
           cout<<ans[i]<<" ";
   }
   cout<<nline;





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
  //cin >> t;
  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}