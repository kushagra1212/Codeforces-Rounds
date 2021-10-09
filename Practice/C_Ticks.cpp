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
   

  int n,m,k;
    cin>>n>>m>>k;
    vector<vector<char>> arr(n,vector<char>(m));
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
 
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(arr[i][j]=='*'||arr[i][j]=='a')
            {
                int y;
 
                for(y=1;;y++)
                {
                    if(i-y<0||j-y<0||j+y>=m||arr[i-y][j-y]=='.'||arr[i-y][j+y]=='.')
                        break;
                }

                y--;
 
                if(y>=k)
                {
                    for(int y2=0;y2<=y;y2++)
                        arr[i-y2][j-y2]=arr[i-y2][j+y2]='a';
                }
            }
        }
    }
 
    bool b=1;
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            b&=(arr[i][j]!='*');
    }
 
    cout<<(b? "YES":"NO")<<endl;

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