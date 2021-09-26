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
   
        string s;
        cin>>s;
        map<int,int> mp;
        stack<pair<char,int>> st;
        int dp[s.length()];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<s.length();i++){
                if(s[i]=='('){
                        st.push({s[i],i});
                }else{
                        if(!st.empty()){
                                int j=st.top().second;
                                int x=i-j+1;
                                if(j-1>=0){
                                        dp[i]=x+dp[j-1];
                                }else{
                                        dp[i]=x;
                                }
                                mp[x]++;
                                st.pop();
                        }
                }
        }
       int maxi=0;

        for(int i=0;i<s.length();i++){
                maxi=max(maxi,dp[i]);
        }

        int count=0;
        for(int i=0;i<s.length();i++){
                if(maxi==dp[i])
                count++;
        }
        if(maxi==0){
                cout<<0<<" "<<1<<nline;
        }else{
                cout<<maxi<<" "<<count<<nline;
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