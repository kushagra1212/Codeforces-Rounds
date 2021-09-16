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
string s;
class Solution
{
private:
public:
   bool isp(int l,int r)
{
    while(l<r and s[l]==s[r])
    {
        l++;
        r--;
    }
    if(s[l]==s[r])
    {
        return true;
    }
    return false;
}
        void solve()
        {

                 cin>>s;
        int n=s.size();
        int L=0,R=n-1;
        while(s[L]==s[R] and L<R)
        {
            R--;
            L++;
        }
        if(s[L]==s[R])
        {
            cout<<s<<'\n';
            return;
        }
        int up=1,down=1;
        for(int i=L;i<=R;i++)
        {
            if(isp(L,i)==true)
                up=i;
        }
        for(int i=R;i>=L;i--)
        {
            if(isp(i,R)==true)
                down=i;
        }
        //cout<<"\n"<<up<<"\t"<<down<<" :\n";
        for(int i=0;i<L;i++)
            cout<<s[i];
        if(up-L>R-down)
        {
            for(int i=L;i<=up;i++)
                cout<<s[i];
        }
        else
        {
            for(int i=down;i<=R;i++)
                cout<<s[i];
        }
        for(int j=R+1;j<n;j++)
        {
            cout<<s[j];
        }
        cout<<"\n";
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
        cin >> t;
        while (t--)
                sol.solve();

        // auto end = std::chrono::high_resolution_clock::now();
        // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

        return 0;
}