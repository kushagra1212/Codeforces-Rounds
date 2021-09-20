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
     
    void recur(string s,int c,int  d,int &k) {
        if(k==n){
            return;
        }
        if(s.length()==2*n and c==0 and d==0){
            stack<char> st;
            

            for(int i=0;i<s.length();i++){
                if(s[i]=='('){
                    st.push('(');
                }else{
                    if(!st.empty() and st.top()=='('){
                            st.pop();
                    }else{
                        return;
                    }
                }
            }

            k++;
            cout<<s<<nline;
            
            return;
        }else if(c<0 ||d<0){
            return; 
        }

        recur(s+"(",c-1,d,k);
        recur(s+")",c,d-1,k);

    }
    void solve(){
       
   
         cin>>n;

         string s="(";
         int k=0;
         recur(s,n-1,n,k);
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

      auto end = std::chrono::high_resolution_clock::now();
      auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
      cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

      return 0;
    }