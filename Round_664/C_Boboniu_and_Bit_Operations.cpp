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
int n,m,p[210],d[210],ans;
class Solution {
private:
public:
 bool Check(int x){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)if(((p[i]&d[j])|x)==x)goto Next;
		return 0;
		Next:;
	}
	return 1;
}
void solve(){
 cin>>n>>m;

   set<int> s;
   for(int i=1;i<=n;i++)
   {
              cin>>p[i];
       
   }


   for(int i=1;i<=m;i++)
   {
           cin>>d[i];
    
   }


  int  ans=(1<<9)-1;
	for(int i=8;i>=0;--i)Check(ans^(1<<i))?ans^=(1<<i):0;
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
  //cin >> t;
  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}