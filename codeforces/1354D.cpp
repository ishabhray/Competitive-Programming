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
#define MAXN 1000006
int MOD=1e9+7;

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

/*int t[4*MAXN]={0};

int sum(int v,int tl,int tr,int x)
{
	if(tl>tr)
		return 0;
    if(tl==tr){
        t[v]--;
        return tl;
    }
    else{
    	int tm=(tl+tr)/2,ans;
    	if(x<=t[2*v])
    		ans=sum(2*v,tl,tm,x);
    	else
    		ans=sum(2*v+1,tm+1,tr,x-t[2*v]);
    	t[v]=t[2*v]+t[2*v+1];
    	return ans;
    }
}
void update(int v,int tl,int tr,int pos)
{
    if(tl==tr)
        t[v]++;
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos);
        else
            update(2*v+1,tm+1,tr,pos);
        t[v]=t[2*v]+t[2*v+1];
    }
}*/
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
        /*for(int i=1;i<=n;i++){
        	int x;
        	cin>>x;
            update(1,1,n,x);
        }
        for(int i=0;i<q;i++){
            int x;
            cin>>x;
            if(x>0)
                update(1,1,n,x);
            else
                sum(1,1,n,-x);
        }
        if(t[1]==0)
        	cout<<"0";
        else
        	cout<<sum(1,1,n,1);*/
        int a[n],b[q];
        for(int i=0;i<n;i++)
        	cin>>a[i];
        for(int i=0;i<q;i++)
        	cin>>b[i];
        int l=1,r=n,ans=0;
        while(l<=r){
        	int mid=(l+r)/2;
        	int less=0,gr=0;
        	for(int i=0;i<n;i++){
        		if(a[i]<=mid)
        			less++;
        		else
        			gr++;
        	}
        	for(int i=0;i<q;i++){
        		if(b[i]>0){
        			if(b[i]>mid)
        				gr++;
        			else
        				less++;
        		}
        		else{
        			if(-b[i]<=less)
        				less--;
        			else
        				gr--;
        		}
        	}
        	if(less>0)
        		ans=mid,r=mid-1;
        	else l=mid+1;
        }
        cout<<ans<<'\n';
    }
}