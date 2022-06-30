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
vi ad[1005];
vi tr[1005];
int vis[1005];
int n,m;
vi order;
void dfs(int u){
	vis[u]=1;
	for(auto i:ad[u]){
		if(!vis[i]){
			dfs(i);
		}
	}
	order.pb(u);
}
void dfs1(int u){
	vis[u]=1;
	for(auto i:tr[u]){
		if(!vis[i]){
			dfs1(i);
		}
	}
}
signed main()
{
    fast_io;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int x,y;
    	cin>>x>>y;
    	ad[x].pb(y);
    	tr[y].pb(x);
    }
    for(int i=1;i<=n;i++){
    	if(!vis[i]){
    		dfs(i);
    	}
    }
    for(int i=1;i<=n;i++){
    	vis[i]=0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
    	if(!vis[order[n-i]]){
    		cnt++;
    		dfs1(order[n-i]);
    	}
    }
    cout<<cnt<<endl;



}