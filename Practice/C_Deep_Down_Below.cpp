#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef pair<int,int> PII;
int T,n;
PII cave[N];
bool check(long long num)
{
	for(int i=1;i<=n;i++)
	{
		if(num>=cave[i].first) num+=cave[i].second;
		else return false;
	}
	return true;
}
int main()
{
	int x,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&cave[i].second);cnt=0;
			for(int j=1;j<=cave[i].second;j++)
			{
				scanf("%d",&x);
				cnt=max(cnt,x-j+2);
			}
			cave[i].first=cnt;
		}
		sort(cave+1,cave+n+1);
		long long l=0,r=2e9,mid,ans;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid)) ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}