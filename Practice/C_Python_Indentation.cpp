#include <iostream>
#include<stdint.h>
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
const int mod=1e9+7;
class Solution {
private:
public:

void solve() {

       int n;
       
       cin>>n;
       char a[n+1];
       for(int i=1;i<=n;i++) cin>>a[i];
       int dp[n+1][n+2];

       for(int l=0;l<=n+1;l++) dp[n][l]=1;
       for(int i=n-1;i>=1;i--){
            int sum=0;
            for(int l=0;l<=n;l++){
                    sum=(sum+dp[i+1][l])%mod;
                    if(a[i]=='f'){
                        dp[i][l]=dp[i+1][l+1];
                    }else{

                        dp[i][l]=(sum)%mod;
                    }

            }

       }
       cout<<dp[1][0]<<nline;

}
};

int32_t main(){
FAST; Solution sol;
int t;
t = 1;
//cin >> t;
while (t--)
    sol.solve();


return 0;
}
