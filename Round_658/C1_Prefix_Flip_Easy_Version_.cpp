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
    
   int n; cin>>n;
   string s,t; cin>>s>>t;
   vector<int> ans;
   int p=n-1;
   for(int i=n-1;i>=0;i--)
   {
      if(s[i]==t[i])
      {
              s=s.substr(0,i);
              p--;
              continue;
      }else{

              if(s[0]!=s[i])
              {
                      s[0]=s[i];
                      ans.push_back(0);
              }
              ans.push_back(p);
              p--;
              for(int k=0;k<s.length();k++)
              {
                      s[k]=s[k]=='0'?s[k]='1':s[k]='0';
              }
              reverse(all(s));
              s=s.substr(0,i);
      }
   }
   cout<<ans.size()<<" ";
   for(auto &x:ans)
        cout<<x+1<<" ";
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