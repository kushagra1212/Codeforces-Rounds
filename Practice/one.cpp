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

bool is_composite(int n){

    for(int i=2;i<=n;i++){
        if(n%i==0){
            return true;
        }
    }
    return false;
}
 
void solve(){
   
    int n; cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int prefix[n+1];
    prefix[0]=0;
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    int length=-1;
     int s,e;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int num=prefix[j]-prefix[i-1];
            if(is_composite(num))
            {
                if(j-i+1>length){
                    s=i,e=j;
                    length=j-i+1;
                }
                
            }
        }
    }
    cout<<length<<nline;
    while(s<=e){
        cout<<s++<<" ";
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

  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}