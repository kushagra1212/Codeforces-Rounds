#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef APURBA
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 500 +5;
const ll mod = 1e9+7;
typedef pair<int,int> pii;

int n;
int a[N];
int ans[N][N];

bool safe(int i, int j)
{
    return (i<n && j>=0);
}

void go(int idx, int i, int j, int cnt)
{
    if(cnt==idx)
        return;
    if(safe(i,j-1) && ans[i][j-1]==-1)
    {
        ans[i][j-1] = idx;
        go(idx, i,j-1 , cnt+1);
    }
    else if(safe(i+1,j) && ans[i+1][j]==-1)
    {
        ans[i+1][j] = idx;
        go(idx, i+1,j , cnt+1);
    }
    else{
        assert(false);
    }
}

void TEST_CASES(int cas)
{
    memset(ans,-1,sizeof ans);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        ans[i][i] = a[i];
        go(a[i] , i,i,1);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

}




/*
*/

int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    //freopen("input.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
    int t=1,cas=0;
    //cin>>t;
    while(t--)
    {
        TEST_CASES(++cas);
    }
    return 0;
}

