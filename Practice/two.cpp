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
 
void dfs(int node,const vector<vector<int>> &adj,vector<bool> &visited)
{
    visited[node]=true;
    for(auto &child:adj[node]){
        if(visited[child]==false){
            dfs(child,adj,visited);
        }
    }
}
void solve(){
   
   int n,m; cin>>n>>m;
   vector<vector<int>> adj(n+1);
   for(int i=0;i<m;i++){
       int a,b,c; cin>>a>>b>>c;
       adj[a].push_back(c);
       adj[c].push_back(a);
   }

   vector<bool> visited(n+1,false);
   vector<int> v;
   int count=0;
   for(int i=1;i<=n;i++){
     if(visited[i]==false){
        v.push_back(i);
        count++;
        dfs(i,adj,visited);
     }
   }

   if(v.size()!=0){
      for(int i=0;i<v.size()-1;i++){
            adj[v[i]].push_back(v[i+1]);
            adj[v[i+1]].push_back(v[i]);
      }
   }
    set<pair<int,int>> seet;


   for(int i=1;i<=n;i++){
      for(auto  &j:adj[i]){
             if(seet.find({j,i})==seet.end()){
                 seet.insert({i,j});
             }

      }
   }

   for(pair<int,int> s:seet){
     cout<<s.first<<" "<<s.second<<nline;
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
  cin >> t;
  while (t--)
    sol.solve();

  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}