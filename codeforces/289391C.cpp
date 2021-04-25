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

int p[200005],r[200005];
int get(int x){
    return p[x]=(p[x]==x)?x:get(p[x]);
}
int get1(int x){
    return r[x]=(r[x]==x)?x:get1(r[x]);
}
void uni(int a,int b){
    a=get(a),b=get(b);
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
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n+1;i++)
            p[i]=i,r[i]=i;
        for(int i=0;i<q;i++){
            int x,y,z;
            cin>>x>>y>>z;
            if(x==1)
                uni(y,z);
            else if(x==2){
                y=get1(y);
                while(y+1<=z){
                    uni(y,y+1);
                    r[y]=r[y+1];
                    y=get1(y);
                }
            }
            else{
                y=get(y),z=get(z);
                if(y==z)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
        }
    }
}