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
int p[200005];
int get(int a){
    return p[a]=(p[a]==a)?a:get(p[a]);
}
void uni(int a,int b){
    a=get(a),b=get(b);
    if(a==b)
        return;
    p[a]=b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n,m;
        cin>>n>>m;
        vv<pair<int,ii > >v(m);
        for(int i=0;i<m;i++)
            cin>>v[i].ss.ff>>v[i].ss.ss>>v[i].ff;
        sort(all(v));
        for(int i=1;i<=n;i++)
            p[i]=i;
        int ans=0;
        for(auto i:v){
            int x=i.ss.ff,y=i.ss.ss;
            x=get(x),y=get(y);
            if(x==y)
                continue;
            else{
                ans=max(ans,i.ff);
                uni(x,y);
            }
        }
        cout<<ans;
    }
}