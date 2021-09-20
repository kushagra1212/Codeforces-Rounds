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
int fun(int x,int y,int tx,int ty){
        return (max((int )0,(x-tx))+max((int )0,y-ty));
}
void solve(){
   
 int n;
    cin >> n;
 
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(all(a));
 
    int sum = 0;
 
    for (int x : a)
        sum += x;
 
    int m;
    cin >> m;
 
    for (int i = 0; i < m; ++i)
    {
        int x, y, ans = 0;
        cin >> x >> y;
 
        auto itr = lower_bound(a.begin(), a.end(), x);
 
        if (itr == a.end())
        {
            int remsum = sum - a.back();
 
            ans = fun(x, y, a.back(), remsum);
        }
        else
        {
            int remsum = sum - *itr;
 
            if (itr == a.begin())
                ans = fun(x, y, *itr, sum - *itr);
            else
            {
                ans = fun(x, y, *itr, sum - *itr);
 
                itr--;
 
                ans = min(ans, fun(x, y, *itr, sum - *itr));
            }
        }
 
        cout << ans << endl;
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
  //cin >> t;
  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}