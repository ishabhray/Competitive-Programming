#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=10000000;
    long double cnt=0;
    int n;
    cin>>n;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while(t--){
        int pre=-1;
        int curr=0;
        for(int i=0;i<n;i++){
            int x=rng()%2;
            if(x==pre&&x) curr++;
            pre=x;
        }
        cnt+=curr;
    }
    cnt/=10000000;
    cout<<cnt<<'\n';
}