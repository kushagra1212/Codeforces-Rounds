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
  int n;
class Solution {
private:
public:


void solve(){
   
   
     cin>>n;

     vector<int> a(n,0);
      priority_queue<pair<int,pair<int,int>>> pq;
      pq.push({n,{0,n-1}});
      int cont=0;
      while(!pq.empty()){

         pair<int,pair<int,int>> p=pq.top();
         pq.pop();
   int l=-1*p.second.first;
         int h=p.second.second;
              int mid;
       if(l>h)continue;
      cont++;
      
                 mid=(l+h)/2;
       
     
     
                    a[mid]=cont;
                 pq.push({mid-l+1,{-1*l,mid-1}});
         pq.push({h-mid+1,{-1*(mid+1),h}});
     
    
            
      }
 for(int i=0;i<n;i++){
         cout<<a[i]<<" ";
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

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}