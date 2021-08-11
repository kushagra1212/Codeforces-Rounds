#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[500][500][11];
int a[500][500];
int b[500][500];
int n,m;
int solve(int i,int j,int k)
{
    if(k==0)
    {
        return 0;
    }
    if(dp[i][j][k])
    {
        return dp[i][j][k];
    }
    int ans=1e18;
    if(i-1>=0)
    {
        int te=b[i-1][j];
        ans=min(ans,te+solve(i-1,j,k-1));
    }
    if(i+1<n)
    {
        int te=b[i][j];
        ans=min(ans,te+solve(i+1,j,k-1));
    }
    if(j-1>=0)
    {
        int te=a[i][j-1];
        ans=min(ans,te+solve(i,j-1,k-1));
    }
    if(j+1<m)
    {
        int te=a[i][j];
        ans=min(ans,te+solve(i,j+1,k-1));
    }
    return dp[i][j][k]=ans;
}
signed main()
{
    int k;
    cin>>n>>m>>k;
    if(k%2)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<-1<<' ';
            }
            cout<<'\n';
        }
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int ans=2*solve(i,j,k/2);
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
    return 0;
}