#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
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
     ll n;
    cin >> n;
    vector<ll> v(n);
    ll cnt1 = 0;
    ll res = 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    if (sum % 3)
    {
        cout << 0 << endl;
    }
    else
    {
        vector<ll> suff(n + 1, 0);
        // ll sum = 0;
        sum = sum / 3;
        ll sum1 = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum1 += v[i];
            if (sum1 == sum)
            {
                suff[i] = 1;
                suff[i] = suff[i] + suff[i + 1];
            }
            else
            {
                suff[i] = suff[i + 1];
            }
        }
        sum1 = 0;
        ll res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum1 = sum1 + v[i];
            if (sum1 == sum)
            {
                res = res + suff[i + 2];
            }
        }
        cout << res << endl;
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
  //cin >> t;
  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}