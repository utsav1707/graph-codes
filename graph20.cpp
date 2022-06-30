#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define mod7 1000000007
#define test(t) int t; cin>>t; while(t--)
#define setp(x, y) fixed << setprecision(y) << x
#define fast_io std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int n,m;
int dis[1005][1005];
signed main()
{
    fast_io;
    for(int i=0;i<1005;i++){
        for(int j=0;j<1005;j++){
            if(i==j){
                dis[i][j]=0;
            }
            else{
            dis[i][j]=INT_MAX;
        }
        }
    }
    cin>>n>>m;
    int a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        dis[a][b]=w;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]==INT_MAX){
                    cout<<"I"<<" ";
                }
                else{
                    cout<<dis[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    





}