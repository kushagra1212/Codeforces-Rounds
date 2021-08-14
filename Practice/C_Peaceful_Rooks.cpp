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
int cycle=0;
class Solution {
private:
public:
int  dfs(int node,int parent,const vector<vector<int>> &adj,vector<bool> &visited){
       
       visited[node]=true;
       int res=0;
       for(auto &element:adj[node]){
                if(element!=parent){
               if(visited[element]==false){
                      res=res || dfs(element,node,adj,visited);
               }
                else  res=1; 

                            
                               
                       }
            
       }
       return res;
}
void solve(){
   
    int n,m; cin>>n>>m;
 
     map<pair<int,int>,int> mp;
     vector<pair<int,int>> v;
     vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
          int x,y; cin>>x>>y;
        if(x==y)
         mp[{x,y}]=1;
        else{
          mp[make_pair(x,y)]=2;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
        v.push_back({x,y});
        }
    }
    int count=0;
    for(auto &m:mp){
            if(m.second==2)
            {
                    count++;
            }
    }
        
    vector<bool> visited(n+1,false);
 
    
    for(auto &vv:v){
               if(visited[vv.first]==false){
                     count+= dfs(vv.first,-1,adj,visited);
               }
    }
        


    cout<<count;
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