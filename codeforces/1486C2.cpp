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
        int smax=f(1,n),ans;
        if(smax!=1&&f(1,smax)==smax){
            int l=1,r=smax-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(f(mid,smax)==smax)
                    ans=mid,l=mid+1;
                else
                    r=mid-1;
            }
        }
        else{
            int l=smax+1,r=n;
            while(l<=r){
                int mid=(l+r)/2;
                if(f(smax,mid)==smax)
                    ans=mid,r=mid-1;
                else
                    l=mid+1;
            }
        }
        cout<<"! "<<ans<<endl;
    }
}