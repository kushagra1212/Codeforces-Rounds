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
   
    int n,W; cin>>n>>W;
    int a[n];
    vector<int> b;
    map<int,stack<int>> mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        
    
          b.push_back(a[i]);
            mp[a[i]].push(i);
  
    }

    stack<int> ans;
    sort(all(b));
    int sum=0;

    for(int i=b.size()-1;i>=0;i--)
    {
    

      while(!mp[b[i]].empty() and sum+a[mp[b[i]].top()]<=W)
      {
           
          sum+=a[mp[b[i]].top()];
          ans.push(mp[b[i]].top());
          mp[b[i]].pop();
     

      }
      if(sum>=(int)ceil((double)W/2))
            break;
        
  }

  if(sum>=(int)ceil((double)W/2))
  {
      cout<<ans.size()<<nline;
     while(!ans.empty())
     {
         cout<<ans.top()+1<<" ";
         ans.pop();
     }
      cout<<nline;
  }else{
      sum=0;
      int temp;
      bool is=false;
      for(int i=0;i<n;i++)
      {
          if(a[i]<=W and a[i]>=(int)ceil((double)W/2))
          {
              is=true;
              temp=i;
              break;
          }
      }
      if(is)
      {  
          cout<<1<<nline;
          cout<<temp<<nline;

      }else
      cout<<-1<<nline;
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