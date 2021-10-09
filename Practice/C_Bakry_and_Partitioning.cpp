#include <bits/stdc++.h>
#define intt long long
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<intt,intt>
#define ld long double
#define y1 yyyyy1
using namespace std;
const int sz = 2e5+5;
int a[sz], res[sz];
vector<int>g[sz];
int cnt;
void dfs(int node, int val, int par){
    res[node] = a[node];
    for ( int i : g[node] ){
        if ( i == par ) continue;
        dfs(i, val, node);
        res[node] ^= res[i];
    }
    if ( res[node] == val and node != 1 ){ 
        cnt++;
        res[node]=false;
    }
}
int i,j;
int main(){
    int t;
    cin >> t;
    while ( t-- ){
        int n, k;
        cin >> n >> k;
        int val = 0;
        cnt = 0;
        for ( i = 1; i <= n; i++ ){
            g[i].clear();
            res[i]=false;
            cin >> a[i];
            val ^= a[i];
        }
        for ( i = 1; i < n; i++ ){
            int x, y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        if ( !val ){
            cout << "YES" << endl;
            continue;
        }
        if ( k <= 2 ){
            cout << "NO" << endl;
            continue;
        }
        dfs(1, val, 0);
        if ( cnt > 1 ){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}