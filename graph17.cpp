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
vector<pii>ad[1005];
int n,m;
signed main()
{
    fast_io;
    cin>>n>>m;
    int a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        ad[a].pb({b,w});
        ad[b].pb({a,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>>q;
    vi dis(n+1,INT_MAX);
    q.push({0,1});
    dis[1]=0;
    while(!q.empty()){
        int currd=q.top().ff;
        int currn=q.top().ss;
        q.pop();
        for(auto i:ad[currn]){
            if(currd+i.ss<dis[i.ff]){
                dis[i.ff]=currd+i.ss;
                q.push({dis[i.ff],i.ff});
            }
        }
    }
        for(int i=1;i<=n;i++){
            cout<<dis[i]<<" ";
        }
    





}