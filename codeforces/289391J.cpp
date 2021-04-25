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
int p[300010],len[300010];
int get(int a){
    if(a==p[a])
        return p[a];
    int x=get(p[a]);
    len[a]+=len[p[a]];
    len[a]%=2;
    return p[a]=x;
}
void uni(int a,int b){
    int x=get(a),y=get(b);
    p[x]=y;
    len[x]=(1+len[a]+len[b])%2;
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
        for(int i=0;i<=n;i++)
            p[i]=i,len[i]=0;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            int a=get(x),b=get(y);
            if(a!=b)
                uni(x,y);
            else if(len[x]==len[y]){
                cout<<i+1;
                return 0;
            }
        }
        cout<<-1;
    }
}