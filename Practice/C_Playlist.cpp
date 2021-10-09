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
 
void solve(){
   
    
     int n,k;
     cin>>n>>k;
    
    vector<pair<int,int>> v;

    for(int i=0;i<n;i++){
       int x,y; cin>>x>>y;
       v.push_back({y,x});

    }

   
   sort(all(v));    

   int sum=0;
   int maxsum=0;
   set<pair<int,int>> seet;
   for(int i=n-1;i>=0;i--){

        seet.insert({v[i].second,i});
        sum+=v[i].second;
          if(seet.size()>k){
             auto it=seet.begin();
             sum-=it->first;
             seet.erase(it);
          }
   

       maxsum=max(maxsum,v[i].first*sum);


   }
   cout<<maxsum<<nline;



   

  }
};

int32_t main()
{

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