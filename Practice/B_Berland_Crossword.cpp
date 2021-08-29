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
  
   int N , T , R , B , L;
   		cin>>N>>T>>R>>B>>L;
 
   		int NeedTop = 0 , NeedRight = 0 , NeedBottom = 0 , NeedLeft = 0;
 
 		if(T == N)
 		{
 			NeedRight++;
 			NeedLeft++;
 
 		}
 
 		if(B == N)
 		{
 			NeedRight++;
 			NeedLeft++;
 		}
 		
 
 		if(R == N)
 		{
 			NeedTop++;
 			NeedBottom++;
 		}
 		if(L == N)
 		{
 			NeedTop++;
 			NeedBottom++;
 		}
 		if(T == N - 1)
 		{
 			if(L - NeedLeft < R - NeedRight)NeedRight++;
 			else NeedLeft++;
 		}
 		if(B == N - 1)
 		{
 			if(L - NeedLeft < R - NeedRight)NeedRight++;
 			else NeedLeft++;
 		}
 		if(R == N - 1)
 		{
 			if(T - NeedTop < B - NeedBottom)NeedBottom++;
 			else NeedTop++; 
 		}
 		if(L == N - 1)
 		{
 			if(T - NeedTop < B - NeedBottom)NeedBottom++;
 			else NeedTop++;
 		}
 
 
 		if(NeedTop > T || NeedRight > R || NeedLeft > L || NeedBottom > B)cout<<"NO\n";
 		else cout<<"YES\n";
 		
  

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