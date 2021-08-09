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
   
  int a[4];
  bool is=true;
  int count=0;
  for(int i=0;i<4;i++)
  {
          cin>>a[i];
        if(a[i]%2)
                count++;

  }
  if(count==0 || count==1)
        cout<<"Yes\n";
  else{
          int s=0;
          if(a[3]%2)
        {
                    count--;
                    s++;
        }
        if(s)
        {
                if(count==2 || count==3)
                {
                        int numofz=0;
                        for(int i=0;i<3;i++)
                          {
                                  if(a[i]==0)
                           numofz++;
                          }
                        if(numofz)
                                cout<<"No\n";
                        else
                        cout<<"Yes\n";
                }else{
                        cout<<"No\n";
                }
        }else{
                if(count==3)
                        cout<<"Yes\n";
                else
                        cout<<"No\n";

        }
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