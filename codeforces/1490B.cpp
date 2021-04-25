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
        int n;
        cin>>n;
        int c[3]={0};
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            c[x%3]++;
        }
        int ans=0;
        for(int i=0;i<6;i++){
            if(c[i%3]>n/3)
                ans+=c[i%3]-n/3,c[(i+1)%3]+=c[i%3]-n/3,c[i%3]=n/3;
        }
        cout<<ans<<'\n';
    }
}