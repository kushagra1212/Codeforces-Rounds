#include<iostream>
#include<vector>

using namespace std;
#define ll long long int
#define MOD 1000000007
const int N=10, M = 200010;
ll dp[N][M];

ll dfs(int n, int m){
  if(m==0){
    dp[n][m] = 1; return 1;
  }
  if(dp[n][m] != -1) return dp[n][m];
  if(n<9){
    dp[n][m] = dfs(n+1, m-1) % MOD;
    return dp[n][m];
  }
  else{
    ll val = (dfs(1, m-1) + dfs(0, m-1)) % MOD;
    dp[n][m] = val;
    return val;
  }
}
void prep(){
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++) dp[i][j] = -1;

  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      dfs(i, j);
}

vector<int> get(int n){
  if (n==0){
    vector<int> ret=  {0};
    return ret;
  }
  vector<int> ret;
  while(n){
    ret.push_back(n%10);
    n = n/10;
  }
  return ret;
}
int main(){
  prep();
  ios::sync_with_stdio(false); cin.tie(NULL);
  int t; cin>>t;
  int n,k;
  while(t--){
    cin>>n>>k;
    ll ans = 0;
    vector<int> li = get(n);
    for(auto it: li)
      ans = (ans + dp[it][k]) % MOD;
    cout << ans << "\n";
  }
}