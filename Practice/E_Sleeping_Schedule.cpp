#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define nline "\n"
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define deb(a) cerr << #a << " " << a << nline
#define all(a) a.begin(), a.end()
#define ctoi(c) (int)((int)c - '0')
#define debv(v)           \
  cerr << #v << " => [ "; \
  for (auto &vv : v)      \
  {                       \
    cerr << vv << " ";    \
  }                       \
  cerr << "]" << nline
#define deba(a, k, n)         \
  cerr << #a << " => [ ";     \
  for (int i = k; i < n; i++) \
  {                           \
    cerr << a[i] << " ";      \
  }                           \
  cerr << "]" << nline
#define loop(i, s, e) for (int i = s; i < e; i++)
#define itoc(i) (char)(i + '0')
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

class Solution
{
private:
public:
  void solve()
  {

    int n, h, l, r;
    cin >> n >> h >> l >> r;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    int dp[n + 2][h + 1];

    for (int t = 0; t < h; t++)
      dp[n + 1][t] = 0;

    for (int i = n; i >= 1; i--)
    {
      for (int t = 0; t < h; t++)
      {
        int t1 = (t + a[i]) % h;
        int c1 = (t1 <= r and t1 >= l) ? 1 : 0;
        dp[i][t] = dp[i + 1][t1] + c1;

        int t2 = (t + a[i] - 1) % h;
        int c2 = (t2 <= r and t2 >= l) ? 1 : 0;
        dp[i][t] = max(dp[i][t], dp[i + 1][t2] + c2);
      }
    }
    cout << dp[1][0] << nline;
  }
};

int32_t main()
{
  auto begin = std::chrono::high_resolution_clock::now();
  FAST;
  Solution sol;
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