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
int N = 1e5 + 5;
int  mod = 1000000007;
vector<bool>primes;
vector<int> prime;
void seive()
{
  primes.resize(N, true);
  primes[0] = false, primes[1] = false;
  for (int i = 2; i * i < N; i++)
  {
    if (primes[i])
    {
      for (int j = i * i; j < N; j += i)
        primes[j] = false;
    }
  }
  for (int i = 2; i < N; i++)
  {
    if (primes[i])
    {
      prime.push_back(i);
    }
  }
}
class Solution {
private:
public:

void solve(){
   
   int n; cin>>n;
   string s;
   cin>>s;
 
    vector<int> ch;
   for(int i=0;i<n;i++){
    ch.push_back(ctoi(s[i]));
      if(primes[ctoi(s[i])]==false){

        cout<<1<<nline<<s[i]<<nline;
        return;
      }
   }
  
 
   for(int i=0;i<ch.size();i++){
    for(int j=i+1;j<ch.size();j++){
        int x=10*ch[i];
        x+=ch[j];
        if(primes[x]==false){
          cout<<2<<nline<<x<<nline;
          return;
        }
    }

   }
    cout<<(int)s.length()<<nline<<s<<nline;
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
  seive();
  cin >> t;
  while (t--)
    sol.solve();

  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}