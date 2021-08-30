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
   
    int n;
        cin >> n;
        int a[n];
        map<int,int> cnt;
        cnt[0] = cnt[1] = 0;
        for (int i = 1; i <= n; ++ i)
        {
            cin >> a[i];
            a[i] %= 2;
            cnt[a[i]]++;
        }
 
        if (abs(cnt[0] - cnt[1]) > 1) cout << -1 << endl;
        else
        {
            if (cnt[0] == cnt[1])
            {
                long long ans1 = 0;
                int j = 1;
                for (int i = 1; i <= n; ++ i)
                {
                    if (a[i] == 0)
                    {
                        ans1 += abs(i - j);
                        j += 2; 
                    }
                }
 
                long long ans2 = 0;
                j = 1;
                for (int i = 1; i <= n; ++ i)
                {
                    if (a[i] == 1)
                    {
                        ans2 += abs(i - j);
                        j += 2;
                    }
                }
 
                cout << min(ans1, ans2) << endl;
            }
            else
            {
                int x = (cnt[0] > cnt[1] ? 0 : 1);
                long long ans = 0;
                int j = 1;
                for (int i = 1; i <= n; ++ i)
                {
                    if (a[i] == x)
                    {
                        ans += abs(i - j);
                        j += 2;
                    }
                }
 
                cout << ans << endl;
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