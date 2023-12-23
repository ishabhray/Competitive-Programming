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
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
int p[7600];
int get(int a){
    return p[a]=(p[a]==a)?a:get(p[a]);
}
void uni(int a,int b){
    a=get(a);
    b=get(b);
    if(a!=b)
        p[a]=b;
}
bool edge[7600][7600];
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
        for(int r=0;r<20;r++){
            for(int t=0;t<360;t++){
                int x=r*360+t,y=(r+1)*360+t;
                edge[x][y]=edge[y][x]=1;
                x=r*360+t,y=r*360+(t+1)%360;
                edge[x][y]=edge[y][x]=1;
            }
        }
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            if(c=='S'){
                int r1,r2,t;
                cin>>r1>>r2>>t;
                for(int r=r1;r<r2;r++){
                    int x=r*360+(t+359)%360,y=r*360+t;
                    edge[x][y]=edge[y][x]=0;
                    // cout<<x<<' '<<y<<'\n';
                }
            }
            else{
                int r,t1,t2;
                cin>>r>>t1>>t2;
                int t=t1;
                while(1){
                    int x=(r-1)*360+t,y=r*360+t;
                    edge[x][y]=edge[y][x]=0;
                    // cout<<x<<' '<<y<<'\n';
                    if(t==t2) break;
                    (t+=1)%=360;
                }
            }
        }
        for(int i=0;i<7560;i++) p[i]=i;
        for(int i=0;i<7560;i++){
            for(int j=i;j<7560;j++){
                if(edge[i][j])
                    uni(i,j);
            }
        }
        // for(int r=0;r<3;r++) for(int t=0;t<360;t++){
        //     int x=r*360+t
        // }
        // for(int r=0;r<=20;r++){
        //     for(int t=0;t<360;t++) cout<<(get(r*360+t)==get(0))<<" ";
        //     cout<<'\n';
        // }
        string ans="NO\n";
        for(int t=0;t<360;t++){
            int r=20,x=r*360+t;
            if(get(x)==get(0)){
                ans="YES\n";
                break;
            }
        }
        cout<<ans;
    }
}