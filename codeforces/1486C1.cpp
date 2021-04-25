#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
#define all(v) (v).begin(),(v).end()
#define MAXN 300005
int MOD=1e9+7;

int f(int l,int r){
    cout<<"? "<<l<<' '<<r<<endl;
    int x;
    cin>>x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int l=1,r=n,pre=f(1,n);
        while(r-l>1){
            int mid=(l+r)/2;
            int x;
            if(pre<=mid){
                x=f(l,mid);
                if(x==pre)
                    r=mid;
                else{
                    pre=f(mid,r);
                    l=mid;
                }
            }
            else{
                x=f(mid,r);
                if(x==pre)
                    l=mid;
                else{
                    pre=f(l,mid);
                    r=mid;
                }
            }
        }
        cout<<"! "<<l+r-pre<<endl;
    }
}