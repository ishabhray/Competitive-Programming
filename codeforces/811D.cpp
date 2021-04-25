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

int vis[1005][1005];
char back[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n,m;
        cin>>n>>m;
        int fx,fy;
        char ch[n][m];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char x;
                cin>>x;
                ch[i][j]=x;
                if(x=='F')
                    fx=i,fy=j;
                else if(x=='*')
                    vis[i][j]=1;
            }
        }
        ii mov[4]={{1,0},{-1,0},{0,1},{0,-1}};
        queue<ii>q;
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            if(a.ff==fx&&a.ss==fy)
                break;
            for(ii i:mov){
                int x=a.ff+i.ff,y=a.ss+i.ss;
                if(x<0||x>=n||y<0||y>=m||vis[x][y])
                    continue;
                vis[x][y]=1;
                q.push({x,y});
                if(i.ff==1)
                    back[x][y]='D';
                if(i.ff==-1)
                    back[x][y]='U';
                if(i.ss==1)
                    back[x][y]='R';
                if(i.ss==-1)
                    back[x][y]='L';
            }
        }
        int x=fx,y=fy;
        string ans="";
        while(x!=0||y!=0){
            ans=back[x][y]+ans;
            if(back[x][y]=='D')
                x--;
            else if(back[x][y]=='U')
                x++;
            else if(back[x][y]=='L')
                y++;
            else if(back[x][y]=='R')
                y--;
        }
        int swapUD=-1,swapLR=-1;
        x=1,y=1;
        for(char i:ans){
            if(i=='U'||i=='D'){
                if(swapUD==-1){
                    cout<<i<<endl;
                    int _x,_y;
                    cin>>_x>>_y;
                    if(_x==x&&_y==y)
                        swapUD=1;
                    else{
                        swapUD=0;
                        cout<<((i=='U')?'D':'U')<<endl;
                        cin>>_x>>_y;
                    }
                }
                if(swapUD==1)
                    cout<<((i=='U')?'D':'U')<<endl;
                else
                    cout<<i<<endl;
                int _x,_y;
                cin>>_x>>_y;
            }
            if(i=='L'||i=='R'){
                if(swapLR==-1){
                    cout<<i<<endl;
                    int _x,_y;
                    cin>>_x>>_y;
                    if(_x==x&&_y==y)
                        swapLR=1;
                    else{
                        swapLR=0;
                        cout<<((i=='R')?'L':'R')<<endl;
                        cin>>_x>>_y;
                    }
                }
                if(swapLR==1)
                    cout<<((i=='R')?'L':'R')<<endl;
                else
                    cout<<i<<endl;
                int _x,_y;
                cin>>_x>>_y;
            }
            if(i=='D')
                x++;
            else if(i=='U')
                x--;
            else if(i=='L')
                y--;
            else if(i=='R')
                y++;
        }
    }
}