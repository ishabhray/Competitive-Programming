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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        if(a>b){
            a=n-a+1;
            b=n-b+1;
        }
        int s[m];
        for(int i=0;i<m;i++)
            cin>>s[i];
        sort(s,s+m);
        int l=0,r=min(m,b-a-1),ans;
        while(l<=r){
            int mid=(l+r)/2;
            vi v;
            //cout<<mid<<' ';
            for(int i=0;i<mid;i++)
                v.pb(s[i]);
            sort(all(v),greater<int>());
            bool f=true;
            for(int i=0;i<mid;i++){
                if(v[i]+i+1>b-1){
                    f=false;
                    break;
                }
            }
            if(f){
                l=mid+1;
                ans=mid;
            }
            else
                r=mid-1;
        }
        cout<<ans<<'\n';
    }
}