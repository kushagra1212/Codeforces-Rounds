#include <bits/stdc++.h>
using namespace std;

#define nline "\n"
#define FAST ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define deb(a) cerr<<#a<<" "<<a<<nline
#define all(a) a.begin(),a.end()
#define ctoi(c) (int)((int)c-'0')
#define debv(v) cerr<<#v<<" => [ "; for(auto &vv:v){cerr<<vv<<" ";}cerr<<"]"<<nline
#define deba(a,k,n) cerr<<#a<<" => [ "; for(int i=k;i<n;i++){cerr<<a[i]<<" ";}cerr<<"]"<<nline
#define loop(i,s,e) for(int i=s;i<e;i++)
#define itoc(i) (char)(i+'0')

class Solution {
private:
public:
 
void solve(){
   
   int n; cin>>n;

   int number=7+(n-1)*3;
   cout<<number<<nline;
   number-=7;
           cout<<1<<" "<<(int)2<<nline;
           cout<<2<<" "<<(int)2<<nline;
           
           cout<<0<<" "<<(int)1<<nline;
           cout<<1<<" "<<(int)1<<nline;
           cout<<2<<" "<<(int)1<<nline;

           cout<<0<<" "<<(int)0<<nline;
           cout<<1<<" "<<(int)0<<nline;
   int x1=2,y1=2;

   while(number>=3){
               x1++;
           cout<<x1<<" "<<y1<<nline;
     
           cout<<y1<<" "<<x1<<nline;
           
           y1=x1;
             
           cout<<x1<<" "<<y1<<nline;

    
           number-=3;
   }

  }
};

int main()
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