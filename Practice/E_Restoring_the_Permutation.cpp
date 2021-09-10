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
   int a[n];
   for(int i=0;i<n;i++)
    cin>>a[i];
set<int> sMin,sMax;
  for(int i=1;i<=n;i++){
      sMin.insert(i);
      sMax.insert(i);
  }
  int prev=a[0];
  vector<int> laxmin,laxmax;
  laxmin.push_back(prev);
  laxmax.push_back(prev);
 sMin.erase(sMin.find(prev));

  for(int i=1;i<n;i++){
          if(a[i]==prev){
                  auto it=sMin.begin();
                  laxmin.push_back(*it);
                  sMin.erase(it);
                  auto it2=sMax.lower_bound(a[i]);
                  it2--;
                  laxmax.push_back(*it2);
                  sMax.erase(it2);
           
                  
          }else{
                
              
                  laxmin.push_back(a[i]);
                     sMin.erase(sMin.find(a[i]));
                     laxmax.push_back(a[i]);
                     sMax.erase(sMax.find(prev));
               prev=a[i];
          }
  }
  for(auto l:laxmin){
          cout<<l<<" ";
  }
  
  cout<<nline;
  for(auto m:laxmax){
          cout<<m<<" ";
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
cin >> t;
  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}