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
int n,m,a[4][1000005],x[1000005],y[1000005],cnt[2][2];
class Solution {
private:
public:
 
void solve(){
    
    
    cin >> n >> m;
    if(n>3){
        cout << -1;
        return ;
    }
    if(n==1){
        cout << 0;
        return ;
    }
    char c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> c;
            a[i][j]=c-'0';
        }
    }
    for(int i=1;i<=m;i++){
        x[i]=(a[1][i]+a[2][i]+i)%2;
        if(n==3) y[i]=(a[1][i]+a[3][i])%2;
        cnt[x[i]][y[i]]++;
    }
    cout << m-max(max(cnt[0][0],cnt[1][0]),max(cnt[0][1],cnt[1][1]));
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