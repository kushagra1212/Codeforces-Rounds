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
      map<char,int> mp;
     for(int i=0;i<s.length();i++){
             mp[s[i]]++;
     }
     vector<pair<int,char>> v;
     for(auto &m:mp){
       v.push_back({m.second,m.first});
     }
     sort(all(v),[](pair<int,char> &p1,pair<int,char> &p2){return p1.first<p2.first;});
     int n=v.size();
 
     
     int maxi=0;
     for(int  i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
           int res = 0;
           int x=i,y=j;
	for (auto c : s) if (c - '0' == x) {
		++res;
		swap(x, y);
	}
          if (x != y && res % 2 == 1)
		--res;

            maxi=max(maxi,res);
        }
     }
     cout<<s.length()-maxi<<nline;
     
     





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