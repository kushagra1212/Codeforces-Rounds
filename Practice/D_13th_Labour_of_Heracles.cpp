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
   vector<pair<int,int>> v(n+1,{0,0});
   int sum=0;
   for(int i=1;i<=n;i++)
   {
           int x;
           cin>>x;
           sum+=x;
           v[i].first=x;
           v[i].second=i;
   }

    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n-1;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
    }
    sort(v.begin()+1,v.end(),[](pair<int,int> &p1,pair<int,int> &p2){return p1.first>p2.first;});

    int ans[n];
    ans[0]=0;
    int k=1;
    ans[k]=sum;
    k++;

    for(int i=1;i<=n and k<n;i++){
        for(int j=0;j<adj[v[i].second].size()-1 and k<n;j++){
                sum+=v[i].first;
             //   cerr<<v[i].first<<' '<<v[i].second<<" ";
                ans[k]=sum;
                k++;
        }
    }

    for(int i=1;i<n;i++)
        cout<<ans[i]<<" ";
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