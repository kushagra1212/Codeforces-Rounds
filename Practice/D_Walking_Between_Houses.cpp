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
   
     int n,k,t;
     cin>>n>>k>>t;

     int x=t/k;
     
     int y=t-x*k;
  
     vector<int> v;

     for(int i=0;i<k;i++){
             v.push_back(x);
     }
     int p=1;
     for(int i=0;i<k;i++){
             int x=n-1-v[i];
             if(x<=y){
                 v[i]+=x;
                     y-=x;
             }else{
                     v[i]+=y;
                     y=0;
             }
             if(y==0)
             break;

     }
     if(y!=0 || t<k){
             cout<<"NO\n";
             return;
     }
     y=n-1;
     cout<<"YES\n";
     int temp=y-v[0];

     for(int i=1;i<k;i++){
             if(temp<v[i]){
                     v[i]-=temp;
                     v[i-1]+=temp;
             }else
                     break;
             
     }
     temp=1;

     for(int i=0;i<k;i++){
             if(i%2==0){
                     temp=v[i]+temp;
                     cout<<temp<<" ";
             }else{
                     temp=temp-v[i];
                     cout<<temp<<" ";
             }
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
  //cin >> t;
  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}