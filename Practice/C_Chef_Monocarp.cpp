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
        int dp[200][405];
        int a[200];
        int n;
        class Solution {
        private:
        public:
        
        int recur(int index,int t){
                if(index==n){
                        return 0;
                }

                if(dp[index][t]!=-1)
                   return dp[index][t];
                int mini=INT64_MAX;
                for(int i=t;i<=max(t,a[index]);i++){
                    mini=min(mini,abs(a[index]-i)+recur(index+1,i+1));
                }
                return dp[index][t]=mini;

        }
        void solve(){

   
         cin>>n;
      
         for(int i=0;i<n;i++){
                 cin>>a[i];
         }  
         memset(dp,-1,sizeof(dp));

         sort(a,a+n);
         cout<<recur(0,1)<<nline;
         
           

        

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