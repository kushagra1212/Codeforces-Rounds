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

const int N=10000007;
int spf[N];
class Solution {
private:
public:

void make(){
  spf[0]=-1,spf[1]=-1;
  for(int i=2;i<=N;i++){
   if(spf[i]==0){
      for(int j=i;j<=N;j+=i){
        spf[j]=i;
    }
   }
  }
}

void solve(){
   int n;
   int k; cin>>n>>k;
   int a[n];
  
   for(int i=0;i<n;i++){
     cin>>a[i];
   }
  vector<int> v;
  map<int,int> mp;
  for(int i=0;i<n;i++){
    int temp=a[i];
   int res=1;
  
   while(spf[temp]!=-1){
     int ors=0;
      int pr=spf[temp];
     while(temp%pr==0){
       temp/=pr;
        ors^=1;
     }
     if(ors) res*=pr;
   }
   v.push_back(res);
  }
  int ans=0;
  for(auto &vv:v){
    if(mp.find(vv)!=mp.end()){
      ans++;
      mp.clear();
    }
    mp[vv]=1;
  }
  cout<<ans+1<<nline;
  
 




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
    sol.make();
  cin >> t;
  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}