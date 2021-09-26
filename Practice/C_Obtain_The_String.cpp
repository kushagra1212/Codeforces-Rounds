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
   
    string s,t;
    cin>>s>>t;

    map<char,vector<int>> mp;
    map<char,int> mp2;
    for(int i=0;i<t.length();i++){
        mp2[t[i]]=1;
    }
    int k=0;
    for(int i=0;i<s.length();i++){
            if(mp2[s[i]]){
                    mp[s[i]].push_back(k);
                    k++;
            }
    }
    bool is=true;
    map<char,int> prefix;
    int ansprefix[t.length()];
    if(mp[t[0]].size()>0){
            prefix[t[0]]=mp[t[0]][0];
            ansprefix[0]=1;
    }else{
            is=false;
            cout<<-1<<nline;
            return;
    }
    for(int i=1;i<t.length();i++){
         if(mp[t[i]].size()>0){
                 bool found=false;
                //  for(int j=0;j<mp[t[i]].size();j++){
                //          if(prefix[t[i-1]]<mp[t[i]][j]){
                //                  ansprefix[i]=ansprefix[i-1]+1;
                //                  prefix[t[i]]=mp[t[i]][j];
                //                  found=true;
                //                  break;
                //          }
                //  }
                auto it=upper_bound(mp[t[i]].begin(),mp[t[i]].end(),prefix[t[i-1]]);
                if(it!=mp[t[i]].end()){
                        found=true;
                           ansprefix[i]=ansprefix[i-1]+1;
                         prefix[t[i]]=*it;
                }
                 if(!found){
                   ansprefix[i]=1;
                   prefix[t[i]]=mp[t[i]][0];
                 }
         }else{
                 is=false;
                 cout<<-1<<nline;
                 return;
         }
    }
    int count=0;
    for(int i=0;i<t.length();i++){
            if(ansprefix[i]==1)
            count++;
    }
    cout<<count<<nline;

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