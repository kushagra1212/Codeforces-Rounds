#include <iostream>
#include<algorithm>
#include<math.h>
#define intl long long int
using namespace std;
int main(){
    int q; cin>>q;
    while(q--){
        int n; cin>>n; 
        int ar[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
        intl max_till=0,max=0;
        for(int i=0;i<n-1;i+=2){
            max_till+=(ar[i+1]-ar[i]);
            if(max<max_till){
                max=max_till;
            }
            if(max_till<0)
                max_till=0;
        }
        max_till=0;
        for(int i=1;i<n-1;i+=2){
                max_till+=(ar[i]-ar[i+1]);
                if(max<max_till){
                    max=max_till;
                }
                if(max_till<0)
                    max_till=0;
        }
        intl even=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                even+=ar[i];
            }
        }
        max=even+max;
        cout<<max<<endl;
    }
}