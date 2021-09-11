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
    
    int k;
    string s;
    cin>>s>>k;
 
    int n=s.length();
    int w[n];
    for(int i=0;i<n;i++)
     w[i]=1;
  
    for(int i=0;i<n;i++){
            if(i-k>=0 and s[i]=='0'){
                w[i-k]=0;
            }
            if(i+k<n and s[i]=='0'){
                    w[i+k]=0;
            }
    }

    bool isPossible=true;
    for(int i=0;i<n;i++){
           if(s[i]=='1'){
                  int flag=0;
                  if(i-k>=0 and w[i-k]==1) flag++;
                  if(i+k<n and w[i+k]==1) flag++;
                  if(!flag){
                          isPossible=false;
                          break;
                  }
           }
    }

    if(isPossible)
     {
             for(int i=0;i<n;i++){
                     cout<<w[i];
             }
             cout<<nline;
     }else{
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