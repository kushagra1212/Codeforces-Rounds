#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		 cin>>a[i];
		set<int> pos;
		set<int> neg;
		for(int i=1;i<n;i++)
		{
			if(a[i]-a[i-1]<0)
			 neg.insert(a[i]-a[i-1]);
			else pos.insert(a[i]-a[i-1]); 
		}
		if(pos.size()>1 || neg.size()>1)
		 cout<<-1<<endl;
		else if(pos.size()==0 || neg.size()==0)
		 cout<<0<<endl;
		else
		{
		   int c=*pos.begin();
		   int m=c-*neg.begin();
		   sort(a,a+n,greater<int>());
		   if(m>a[0]) cout<<m<<" "<<c<<endl;
		   else cout<<-1<<endl;	
		}   
	}
	return 0;
}