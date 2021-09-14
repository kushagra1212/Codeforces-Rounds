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
 
void shorest_path(int node,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &dist){
      
      visited[node]=true;
      queue<int> q;
      q.push(node);
      while(!q.empty()){
              int par=q.front();
              q.pop();
              for(auto &child:adj[par]){
                    if(visited[child]==false){
                            if (dist[par] + 1 < dist[child])
                            {
                                    dist[child] = dist[par] + 1;
                            }
                            visited[child]=true;
                            q.push(child);
                    }
              }
      }
     
}
void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited2,vector<int> &leaf){
        visited2[node]=true;
        int count=0;
        for(auto &child:adj[node]){
                count++;
                if(visited2[child]==false){
                        dfs(child,adj,visited2,leaf);
                }
        }
        if(count==1)
         leaf.push_back(node);
}
void solve(){
   
     int  n,e; cin>>n>>e;
     vector<vector<int>> adj(n+1);
     if(n==1){
             cout<<"Ayush\n";
             return;
     }
     for(int i=1;i<n;i++){
             int x,y;
             cin>>x>>y;
             adj[x].push_back(y);
             adj[y].push_back(x);
     }
      vector<bool> visited(n+1,false);
      vector<int> dist(n+1,INT64_MAX);
      dist[e]=0;
     shorest_path(e,adj,visited,dist);
     int mini=INT64_MAX;
     vector<bool> visited2(n+1,false);
     vector<int> leaf;
     dfs(1,adj,visited2,leaf);
     int sum=0;
     for(auto &l:leaf){
         if(l==e){
                cout<<"Ayush\n";
                return;
         }
     
     }
           
                if(n%2==1)
                   cout<<"Ashish\n";
                else
                    cout<<"Ayush\n";
     
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