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
int n;
class Solution {
private:
public:

void solve(){
   
   int l,r,s;
   cin>>n>>l>>r>>s;

   int x=r-l+1;
  

   int a[n];
   a[0]=0;
   for(int i=1;i<=n;i++){
           a[i]=i;
   }
   int arr[r-l+2];
   arr[0]=0;
   int sum=0;
   for(int i=1;i<=r-l+1;i++){
        arr[i]=i;
        sum+=i;
   }

   if(sum==s){
        queue<int> q1,q2;
        for(int i=1;i<=n;i++)
        {
           if(i<=r-l+1){
                   q2.push(i);
           }else{
                   q1.push(i);
           }

        }
        for(int i=1;i<=n;i++){
                if(i>=l and i<=r){
                     cout<<q2.front()<<" ";
                   q2.pop();
                }else{
                             cout<<q1.front()<<" ";
                   q1.pop();
                }
        }
        cout<<nline;
        return;
   }else if(sum>s){
           cout<<-1<<" "<<nline;
           return;
   }

   int i=r-l+1;
 
   int upto=n;
   bool isPossible=true;
   while(i>=1 ){
        int temp=arr[i];
        while(sum<s and temp<=upto){
                sum-=temp;
                temp++;
                if(temp>upto){
                        temp--;
                        sum+=temp;
                        break;
                }else{
                        sum+=temp;
                }
        }
    
                arr[i]=temp;
 
        if(sum>s){
                isPossible=false;
                break;
        }
        if(sum==s){
                break;
        }
        upto--;
        i--;
   }
    
   if(sum<s || sum>s){
           cout<<-1<<nline;
           return;
   }
   map<int,int> mp;
   for(int i=1;i<=r-l+1;i++)
   {
          mp[arr[i]]++;
   }
    queue<int> q1,q2;
   for(int i=1;i<=n;i++){
      if(mp[i]==0){
              q1.push(i);
      }else{
              q2.push(i);
      }
   }
   for(int i=1;i<=n;i++){
           if(i>=l and i<=r){
                   cout<<q2.front()<<" ";
                   q2.pop();
           }else{
                   
                   cout<<q1.front()<<" ";
                   q1.pop();
           }
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
  cin >> t;
  while (t--)
    sol.solve();

 // auto end = std::chrono::high_resolution_clock::now();
 // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
 // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

  return 0;
}