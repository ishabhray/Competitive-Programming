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
#define eps 1e-9
ld solve(ld c,ld m,ld p,ld v,int d){
    // cout<<c<<' '<<m<<' '<<p<<' '<<v<<' '<<d<<'\n';
    ld ans=0;
    ans+=p*d;
    if(c>eps){
        ld red=min(v,c);
        ld m1,p1;
        if(m>eps)
            m1=m+red/2,p1=p+red/2;
        else m1=0.0,p1=p+red;
        ans+=c*solve(c-red,m1,p1,v,d+1);
    }
    if(m>eps){
        ld red=min(v,m);
        ld c1,p1;
        if(c>eps)
            c1=c+red/2,p1=p+red/2;
        else c1=0.0,p1=p+red;
        ans+=m*solve(c1,m-red,p1,v,d+1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ld c,m,p,v;
        cin>>c>>m>>p>>v;
        cout<<setprecision(9)<<solve(c,m,p,v,1)<<'\n';
    }
}