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
int n,e;
int vis[1005];
vi ad[1005];
bool dfs(int u,int p){
	vis[u]=1;
    for(auto i:ad[u]){
        if(!vis[i]){
            if(dfs(i,u)){
                return true;
            }
        }
        else{
            if(i!=p){
                return true;
            }
        }
    }
    return false;
	
}
signed main()
{
    fast_io;
    cin>>n>>e;
    for(int i=0;i<e;i++){
    	int x,y;
    	cin>>x>>y;
    	ad[x].pb(y);
    	ad[y].pb(x);
    }
    if(dfs(1,0)){
        cout<<"Cycle";
    }
    else{
        cout<<"No Cycle";
    }
    



}