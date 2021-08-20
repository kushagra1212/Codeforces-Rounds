#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define nline "\n"
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define deb(a) cerr << #a << " " << a << nline
#define all(a) a.begin(), a.end()
#define ctoi(c) (int)((int)c - '0')
#define debv(v)                    \
        cerr << #v << " => [ ";    \
        for (auto &vv : v)         \
        {                          \
                cerr << vv << " "; \
        }                          \
        cerr << "]" << nline
#define deba(a, k, n)                \
        cerr << #a << " => [ ";      \
        for (int i = k; i < n; i++)  \
        {                            \
                cerr << a[i] << " "; \
        }                            \
        cerr << "]" << nline
#define loop(i, s, e) for (int i = s; i < e; i++)
#define itoc(i) (char)(i + '0')
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 998244353;

class Solution
{
private:
public:
        int binpow(int a, int b)
        {
                int res = 1;
                while (b > 0)
                {
                        if (b & 1)
                                res = (res % mod * a % mod) % mod;
                        a = (a % mod * a % mod) % mod;
                        b >>= 1;
                }
                return res;
        }
        int modInv(int a, int mod)
        {
                return binpow(a, mod - 2);
        }
        int nCr(int n, int r)
        {
                int fac[n + 1];
                fac[1] = 1;
                for (int i = 2; i <= n; i++)
                {
                        fac[i] = (fac[i - 1] % mod * i % mod) % mod;
                }

                return ((fac[n] % mod * modInv(fac[r], mod) % mod) % mod * modInv(fac[n - r], mod) % mod) % mod;
        }

        void solve()
        {
                int n;
                cin >> n;
                int a[2 * n];
                for (int i = 0; i < 2 * n; i++)
                {
                        cin >> a[i];
                }

                int sum = 0;
                sort(a, a + 2 * n);
                for (int i = 0; i < n; i++)
                {
                        sum = (sum % mod + (a[2 * n - 1 - i] - a[i]) % mod) % mod;
                }

                int k = nCr(2 * n, n);
                sum = (sum % mod * k % mod) % mod;
                cout << sum << nline;
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