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
   
     int n,k; cin>>n>>k;

     multiset<int> a,b,al;
     for(int i=0;i<n;i++){
             int x,a1,b1;
             cin>>x>>a1>>b1;
             if(a1 and !b1)
                a.insert(x);
             if(b1 and !a1)
                b.insert(x);
             if(a1 and b1){
                     al.insert(x);
             }
     }
 
    int sum=0,k1=0,k2=0;
    bool isPossible=true;
    while(a.size() || b.size() || al.size()){
       
       auto a1=a.begin();
       auto b1=b.begin();
       auto it=al.begin();
       if(k1<k and k2<k){
               if(it!=al.end() and a1!=a.end() and b1!=b.end() and *it<*a1+*b1){
                       sum+=*it;
                       al.erase(it);
                       k1++;
                       k2++;
               }else{
                       if(a1!=a.end() and b1!=b.end()){
                               sum+=*a1;
                               sum+=*b1;
                               a.erase(a1);
                               b.erase(b1);
                               k1++;
                               k2++;
                       }else if(it!=al.end()){
                              sum+=*it;
                       al.erase(it);
                       k1++;
                       k2++;
                       }else{
                               isPossible=false;
                               break;
                       }
               }
       }else if(k1<k){
               if(it!=al.end() and a1!=a.end() and *it<*a1){
                       sum+=*it;
                       al.erase(it);
                       k1++;
               }else if(a1!=a.end()){
                       sum+=*a1;
                       a.erase(a1);
                       k1++;
               }else if(it!=al.end()){
                       sum+=*it;
                       al.erase(it);
                       k1++;
               }else{
                       isPossible=false;
                       break;
               }
       }else if(k2<k){
               if(it!=al.end() and b1!=b.end() and *it<*b1){
                       sum+=*it;
                       al.erase(it);
                       k2++;
               }else if(b1!=b.end()){
                       sum+=*b1;
                       b.erase(b1);
                       k2++;
               }else if(it!=al.end()){
                       sum+=*it;
                       k2++;
                       al.erase(it);
               }else{
                       isPossible=false;
                       break;
               }

       }else{
               break;
       }
    }
    if(k1<k || k2<k || isPossible==false){
            cout<<-1<<nline;
    }else{
            cout<<sum<<nline;
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