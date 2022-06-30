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
int vis[1005][1005];
int arr[1005][1005];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool chk(int x,int y){
	if(x<1 || x>n || y<1 || y>m){
		return false;
	}
	if(vis[x][y]){
		return false;
	}
	if(arr[x][y]!=1){
		return false;
	}
	return true;
}
void dfs(int x,int y){
	vis[x][y]=1;
	// cout<<x<<" "<<y<<endl;
	for(int i=0;i<4;i++){
		if(chk(x+dx[i],y+dy[i])){
			dfs(x+dx[i],y+dy[i]);
		}
	}
	// if(chk(x-1,y)){
	// 	dfs(x-1,y);
	// }
	// if(chk(x+1,y)){
	// 	dfs(x+1,y);
	// }
	// if(chk(x,y-1)){
	// 	dfs(x,y-1);
	// }
	// if(chk(x,y+1)){
	// 	dfs(x,y+1);
	// }
}
signed main()
{
    fast_io;
    cin>>n>>m;
    // int arr[n+1][m+1];
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>arr[i][j];
    	}
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(!vis[i][j] && arr[i][j]==1){
    			cnt++;
    			dfs(i,j);
    		}
    	}
    }
    cout<<cnt;



}