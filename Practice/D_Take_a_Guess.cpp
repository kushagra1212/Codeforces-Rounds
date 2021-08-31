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
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

class Solution {
private:
public:
 
void solve(){
    int n,k; cin>>n>>k;
    int x,y,z;
     int temp1,temp2;
     cout<<"and "<<1<<" "<<2<<endl;
     cin>>temp1;
     cout<<"or "<<1<<" "<<2<<endl;
     cin>>temp2;
     x=temp1+temp2;
     cout<<"and "<<2<<" "<<3<<endl;
     cin>>temp1;
     cout<<"or "<<2<<" "<<3<<endl;
     cin>>temp2;
     y=temp1+temp2;
     cout<<"and "<<1<<" "<<3<<endl;
     cin>>temp1;
     cout<<"or "<<1<<" "<<3<<endl;
     cin>>temp2;
     z=temp1+temp2;
     int a[n];
     a[0]=(x-y+z)/2;
     a[1]=x-a[0];
     a[2]=y-a[1];
     

    for(int i=2;i<n-1;i++){
                 cout<<"and "<<i+1<<" "<<i+2<<endl;
                cin>>temp1;
                cout<<"or "<<i+1<<" "<<i+2<<endl;
                cin>>temp2;
                a[i+1]=temp1+temp2-a[i];
    }
    sort(a,a+n);
    k--;
    cout<<"finish "<<a[k]<<endl;



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
//   cin >> t;
  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}