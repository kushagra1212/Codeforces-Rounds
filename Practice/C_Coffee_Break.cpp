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

class Solution {
private:
public:

  void solve() {


    int n, m, k;
    cin >> n >> m >> k;
    set<int> seet;
    map<int, int> arr;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      arr[i] = x;
      seet.insert(x);
    }
    map<int, int> mp;
    int days = 1;
    while (!seet.empty()) {
      auto it = seet.begin();

      mp[*it] = days;
      auto it2 = seet.upper_bound(*it + k);
      seet.erase(it);

      while (it2 != seet.end() and * it2 <= m) {

        mp[*it2] = days;
        int k1 = *it2;
        seet.erase(it2);
        it2 = seet.upper_bound(k1 + k);
      }
      days++;
    }
    cout << days - 1 << nline;
    for (int i = 0; i < n; i++) {
      cout << mp[arr[i]] << " ";
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



  return 0;
}