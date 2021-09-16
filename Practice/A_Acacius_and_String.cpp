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
string check="abacaba";
int m=7;
class Solution {
private:
public:
 
void solve(){
   
    int n; cin>>n;
    string s;
    cin>>s;
    for(int t=0;t<n;t++){
            string temp=s;  
        int j=0;
       for(int i=t;i<n and j<m;i++,j++){
            if(temp[i]=='?'){
                    temp[i]=check[j];
            }else if(temp[i]==check[j]) {
                    continue;
            }else{
                    break;
            }
       }
       if(j==m){
        bool isPossible=true;
           for(int p=0;p<n;p++){
                   if(p==t)
                     continue;
                   j=0;
                   for (int i = p; i < n and j < m; i++, j++)
                   {
                           if (temp[i] == '?')
                           {
                                   break;
                           }
                           else if (temp[i] == check[j])
                           {
                                   continue;
                           }
                           else
                           {
                                   break;
                           }
                   }
                   if(j==m){
                           isPossible=false;
                           break;
                   }
           }
           if(isPossible){
                   cout<<"Yes\n";
                   for(int l=0;l<n;l++){
                           if(temp[l]=='?')
                             temp[l]='e';
                   }
                   cout<<temp<<nline;
                   return;
               
           }
       }
    }
    cout<<"No\n";



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