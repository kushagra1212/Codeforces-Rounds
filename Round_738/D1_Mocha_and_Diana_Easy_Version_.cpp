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
int first[1001],second[1001];
class Solution {
private:
public:
int findFirst(int x){
        if(first[x]==-1)
           return x;
        return findFirst(first[x]);
}
int findSecond(int x){
        if(second[x]==-1)
           return x;
        return findSecond(second[x]);
}

void mergeFirst(int x,int y){
     first[findFirst(x)]=findFirst(y);
}

void mergeSecond(int x,int y){
     second[findSecond(x)]=findSecond(y);
}
void solve(){
   int n,m1,m2; cin>>n>>m1>>m2;
   memset(first,-1,sizeof(first));
   
   memset(second,-1,sizeof(second));
   for(int i=0;i<m1;i++){
       int x,y;
       cin>>x>>y;
       mergeFirst(x,y);
   }
   
   for(int i=0;i<m2;i++){
       int x,y;
       cin>>x>>y;
       mergeSecond(x,y);
   }
   vector<pair<int,int>> ans;
   for(int i=1;i<=n;i++){
           for(int j=i+1;j<=n;j++){
                   if(findFirst(i)!=findFirst(j) and findSecond(i)!=findSecond(j)){
                           mergeFirst(i,j);
                           mergeSecond(i,j);
                           ans.push_back({i,j});  

                   }
           }
   }
   cout<<ans.size()<<nline;
   for(auto &answer:ans){
           cout<<answer.first<<" "<<answer.second<<nline;

   }
   cout<<nline;



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