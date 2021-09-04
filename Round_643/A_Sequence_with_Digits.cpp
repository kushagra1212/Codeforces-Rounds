#include <iostream>
#include<vector>
#include<algorithm>
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

class Solution {
private:
public:
struct MinMax{
        int a,b;
};
struct MinMax min_max(int x){
    vector<int> v;
      while(x>0){
          v.push_back(x%10);
          x/=10;
      }

      sort(all(v));
      struct MinMax p;
      p.a=v[0];
      p.b=v[v.size()-1];
 

      return p;

}
 
void solve(){
   
      int  n,k;
      cin>>n>>k;
      int a[100001];
      struct MinMax array=min_max(n);

      a[1]=n;
      int ans=-1;
      for(int i=2;i<=100000 and i<=k;i++){
        array=min_max(a[i-1]);
        if(array.a==0){
          ans=a[i-1];
          break;
        }
        a[i]=a[i-1]+array.a*array.b;
      }
      if(ans==-1){
        cout<<a[k]<<nline;
      }else{
        cout<<ans<<nline;
      }


  }
};

int32_t main()
{

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

  return 0;
}