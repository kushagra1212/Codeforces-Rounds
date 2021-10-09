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
 
void bfs(const vector<vector<int>> &adj,vector<bool> &visited,vector<vector<int>> &level_nodes,int &maxi_level){

    queue<int> q;

    q.push(1);
    q.push(-1);

    int level=1;
    int conti=0;

    while(!q.empty()){
      int par=q.front();
      q.pop();
  
      if(par!=-1){
         
         for(int child:adj[par]){
             if(!visited[child]) q.push(child);
         }
         visited[par]=true;
         conti=0;
       
          level_nodes[level].push_back(par);
        
          maxi_level=level;
      }else{
    
            conti++;
        if(conti>=2)
            break;
     
        level++;
           q.push(-1);
       
           
      }
    }

}

void solve(){
    
    int n; cin>>n;
    vector<vector<int>> adj(n+1);

    for(int i=2;i<=n;i++){
      int x; cin>>x;
      adj[i].push_back(x);
      adj[x].push_back(i);
    }

    int data[n+1];
  for(int i=1;i<=n;i++)
    cin>>data[i];
    vector<bool> visited(n+1,false);
    vector<vector<int>> level_nodes(n+1);
  int maxi_level=1;
  bfs(adj,visited,level_nodes,maxi_level);
   int ans=0;

vector<bool> visited2(n+1,false);
  for(int i=1;i<=maxi_level;i++){
    if(i%2==1){ 
   
              
        for(int j=0;j<level_nodes[i].size();j++){
            int node=level_nodes[i][j];
               
       
            
             

              for(int element:adj[node]){
                     visited2[node]=true;
                       int mini=INT64_MAX;
                     for(int child:adj[element]){
                         if(!visited2[child]){

                          
                             mini=min(mini,data[child]);
         
                         }


                    }int x;
               if(mini!=INT64_MAX){

                  x=mini-data[node];
                     ans+=x;
                 }else
                   continue;

                 for(int child:adj[element]){
                    if(!visited2[child] )
                    {

              
           
                   visited2[child]=true;
                   if(data[child]<data[node]){
                      cout<<-1<<nline;
                      return;
                   }

                    ans+=(data[child]-(data[node]+x));
                    }
                 }
              }
        }

    }   
  }
 cout<<ans+data[1]<<nline;





  


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



  return 0;
}