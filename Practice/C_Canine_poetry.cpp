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

void rec(string &s,int i,int j){
       if(i>=j || j<=0 || i>=s.length()-1)
       {
               return;
       }

        int mid2=(i+j)/2;
        
      
        if(mid2-1>=0 and mid2+1<s.length() and s[mid2-1]==s[mid2+1]){
       
                        s[mid2+1]='*';
               
         
        }
        if(mid2+1<s.length()  and s[mid2]==s[mid2+1]){
            
                        s[mid2+1]='*';
                 
          
        }
        if(mid2-1>=0  and s[mid2]==s[mid2-1]){
       
                        s[mid2-1]='*';
              
         
        }
        rec(s,mid2+1,j);
        rec(s,i,mid2-1);
} 

void solve(){
   
 
   string s; cin>>s;
   string h=s;
   int n=s.length();
   if(n==1){
           cout<<0<<nline;
           return;
   }

   for(int i=1;i<n;i++){
           if(( s[i]==s[i-1]) || (i-2>=0 and s[i]==s[i-2])){
                   s[i]='*';
           }
   }
   int ans=0;
   for(int i=0;i<n;i++){
        ans+=(s[i]=='*');
   }
   cout<<ans<<nline;



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