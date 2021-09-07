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
        int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
        int n,m;
        class Solution {
        private:
        public:
        bool isvalid(int x,int y){
        if(x<0 ||y<0 || x>=n || y>=m)
        return false;
        return true;
        }
        bool dfs(const string *s, vector<vector<bool>> &visited, int x, int y)
        {
                if (x == n - 1 and y == m - 1 and s[x][y]!='#')
                {
                        return true;
                }
                bool is=false;
                visited[x][y] = true;
                for (int i = 0; i < 4; i++)
                {
                        int nx = dx[i] + x, ny = dy[i] + y;
                        if (isvalid(nx, ny) and visited[nx][ny] == false and s[nx][ny]!='#')
                        {
                                is= dfs(s, visited, nx, ny);
                                if(is){
                                       return is;
                                }
                        }
                 
                }
                return is;
        }
        void solve(){
        

        cin>>n>>m;
        string s[n];
        for(int i=0;i<n;i++){
                cin>>s[i];
        }
         
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){

                        if(s[i][j]=='B'){
                        for(int k=0;k<4;k++){
                                
                                int x=dx[k]+i,y=dy[k]+j;
                             
                                if(isvalid(x,y) and s[x][y]=='.'){
                                        s[x][y]='#';
                                }
                                   if(isvalid(x,y) and s[x][y]=='G'){
                                        cout<<"No\n";
                                        return;
                                }
                        }
                        }
                }
        }
        
       bool isPossible=true;
      
       vector<pair<int,int>> p;
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                if(s[i][j]=='G'){
                    p.push_back({i,j});        
                }
                }
        }
        for(auto P:p){
                int i=P.first,j=P.second;
                    vector<vector<bool>> visited(n,vector<bool>(m,false));
                        if(!dfs(s,visited,i,j)){
                                isPossible=false;
                                break;
                        }
        }
        if(isPossible)
        cout<<"Yes\n";
        else
        cout<<"No\n";
        


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