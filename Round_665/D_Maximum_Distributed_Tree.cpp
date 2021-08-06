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
const int mod=1e9+7;
class Solution {
private:
public:

int cal_subtree_size(int node,const vector<vector<pair<int,int>>> &adj,int *visited,vector<int> &subtree_size)
{
    visited[node]=1;
    subtree_size[node]=1;

    for(auto f:adj[node])
    {
        int child=f.first;
        if(!visited[child])
        {
           subtree_size[node]=(subtree_size[node]+cal_subtree_size(child,adj,visited,subtree_size));
        }
    }
    return subtree_size[node];

}
void cal_val(int node, const vector<vector<pair<int,int>>> &adj,vector<int> &values,const vector<int> &subtree_size,int *visited)
{
    visited[node]=1;
 
    int x=subtree_size[node];
            int y=(adj.size()-1-x);

     values.push_back((x%mod*y%mod)%mod);
    for(auto f:adj[node])
    {
        int child=f.first;
        if(!visited[child])
        {
     
            cal_val(child,adj,values,subtree_size,visited);
        }
    }

}
void dofun(const vector<vector<pair<int,int>>> &adj,vector<int> &k,int n)
{
    vector<int> subtree_size(n+1,0);
  
   int visited[n+1];
   memset(visited,0,sizeof(visited));
    int temp=cal_subtree_size(1,adj,visited,subtree_size);
    vector<int> values;
 
   memset(visited,0,sizeof(visited));
    cal_val(1,adj,values,subtree_size,visited);
   
    sort(all(values));
    reverse(all(values));
    int sum=0;
    for(int i=0;i<values.size();i++)
    {
        sum=(sum+(values[i]%mod*k[i]%mod)%mod)%mod;
    }
    cout<<sum<<nline;
}


 
void solve(){
   
  int n; cin>>n;
  vector<vector<pair<int,int>>> adj(n+1);

  for(int i=0;i<n-1;i++)
  {
      int x,y; cin>>x>>y;
      adj[x].push_back({y,0});  
      adj[y].push_back({x,0});

  }
    int q; cin>>q; 
    vector<int> k1(q);
    for(int i=0;i<q;i++)
      {
          cin>>k1[i];
        

      }
    while(q<n-1)
    {
        k1.push_back(1);
        q++;
    }
    vector<int> k2;
            
    sort(all(k1));
    reverse(all(k1));
    if(q>n-1)
    {
        int x=q-n+1;
        int temp=1;
        for(int i=0;i<=x;i++)
        {
            temp=(temp%mod*k1[i]%mod)%mod;
        }
        k2.push_back(temp);
        for(int i=x+1;i<k1.size();i++)
            k2.push_back(k1[i]);

    
       dofun(adj,k2,n);





    }else{
      
        dofun(adj,k1,n);
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

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}