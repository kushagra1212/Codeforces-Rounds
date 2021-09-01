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
int fact[200001];
class Solution {
private:
public:

void fac(){
fact[1]=1;
 for(int i=2;i<=200001;i++){
     fact[i]=i*fact[i-1];
 }
}


void solve(){
   int n; cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++)
        cin>>v[i];
  int ans=0;
  sort(all(v));
   for(int i=0;i<n;i++){
      auto it=upper_bound(all(v),v[i]+2);
      it--;
      int index=it-v.begin();
     
      int temp_ans=index-i;
 
      temp_ans--;
      if(temp_ans>0)
        ans+=temp_ans*(temp_ans+1)/2;
   }
   cout<<ans<<nline;


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
  sol.fac();
  cin >> t;
  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}