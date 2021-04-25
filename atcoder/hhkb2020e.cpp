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
int MOD=1e9+7;


ll power[2000*2000+10];
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
        power[0]=1;
        for(int i=1;i<=4000005;i++)
            power[i]=2*power[i-1]%MOD;
        int h,w;
        cin>>h>>w;
        string a[h];
        for(int i=0;i<h;i++)
            cin>>a[i];
        ll ans=0,tidy=0;
        int preh[h][w],prev[h][w],sufh[h][w],sufv[h][w];
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(a[i][j]=='.')
                    tidy++;
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(a[i][j]=='#')
                    preh[i][j]=0;
                else{
                    preh[i][j]=1;
                    if(j)
                        preh[i][j]+=preh[i][j-1];
                }
            }
        }
        for(int i=0;i<h;i++){
            for(int j=w-1;j>=0;j--){
                if(a[i][j]=='#')
                    sufh[i][j]=0;
                else{
                    sufh[i][j]=1;
                    if(j!=w-1)
                        sufh[i][j]+=sufh[i][j+1];
                }
            }
        }
        for(int j=0;j<w;j++){
            for(int i=0;i<h;i++){
                if(a[i][j]=='#')
                    prev[i][j]=0;
                else{
                    prev[i][j]=1;
                    if(i)
                        prev[i][j]+=prev[i-1][j];
                }
            }
        }
        for(int j=0;j<w;j++){
            for(int i=h-1;i>=0;i--){
                if(a[i][j]=='#')
                    sufv[i][j]=0;
                else{
                    sufv[i][j]=1;
                    if(i!=h-1)
                        sufv[i][j]+=sufv[i+1][j];
                }
            }
        }
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(a[i][j]=='#')
                    continue;
                int cnt=prev[i][j]+preh[i][j]+sufv[i][j]+sufh[i][j]-3;
                ans+=(power[cnt]-1)*power[tidy-cnt]%MOD;
                ans%=MOD;
            }
        }
        cout<<ans;
    }
}