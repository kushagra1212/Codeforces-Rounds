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
     string s;
     cin>>s;
     if(n%2 || s[0]=='0' || s[n-1]=='0'){
             cout<<"NO\n";
             return;
     }
     stack<char> st1,st2;
     string s1="",s2="";
     int count_1=0,count_0=0;
     for(int i=0;i<n;i++){
             if(s[i]=='0')
               count_0++;
             else
               count_1++;
     }
     if(count_0%2 || count_1%2){
             cout<<"NO\n";
             return;
     }
     int x=count_1;
     char prev='(';
     for(int i=0;i<n;i++){
           if(s[i]=='1'){
                   if (x > count_1 / 2)
                   {
                           s1 += '(';
                           s2 += '(';
                          x--;
                   }
                   else
                   {
                           s1 += ')';
                           s2 += ')';
                   }
           }else{
                if(prev=='(')
                {
                        s1+='(';
                        s2+=')';
                }else{
                        s1+=')';
                        s2+='(';
                }
                prev==')'?prev='(':prev=')';
           }
     }
     cout<<"YES\n";
     cout<<s1<<nline<<s2<<nline;



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