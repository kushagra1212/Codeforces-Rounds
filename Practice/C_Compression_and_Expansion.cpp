#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX =1000000000000000000;
ll mod= 1000000000;
long double pi=3.141592653589793238;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}

const ll N=3e5+2;
ll n;
void solve()
{  
      int t; cin>>t;
      while(t--){
        cin>>n;
        stack<string> st;
        st.push("1");
        n--;
        cout<<"1"<<endl;
        int x; cin>>x;
        while(n--){
            cin>>x;
            while(1){
                string cur=st.top();
                int k=cur.size();
                int temp=0;
                int cnt=1;
                // cout<<cur<<endl;
                int i=k-1;
                for(;i>=0 && cur[i]!='.';i--){
                    temp=(cur[i]-'0')*cnt+temp;
                    cnt*=10;
                }
                // cout<<x<<" "<<temp<<endl;
                if(temp+1==x){
                    st.pop();
                    temp++;
                    string nn=cur.substr(0,i+1);
                    nn+=to_string(temp);
                    st.push(nn);
                    cout<<nn<<endl;
                    break;
                }
                else if(x==1){
                    cur =cur+"."+"1";
                    st.push(cur);
                    cout<<cur<<endl;
                    break;
                }
                else{
                    st.pop();
                }
            }

        }
      }
      



       
}
int main(){pls(); solve(); return 0;}