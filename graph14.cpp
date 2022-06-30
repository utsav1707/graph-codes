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
int dis[1005][1005];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool chk(int x,int y){
	if(x<1 || x>n || y<1 || y>m){
		return false;
	}
	if(vis[x][y]){
		return false;
	}
	
	return true;
}
void bfs(int x,int y){
	queue<pii>q;
	q.push({x,y});
	dis[x][y]=0;
	vis[x][y]=1;
	while(!q.empty()){
	int currx=q.front().ff;
	int curry=q.front().ss;
	q.pop();
	for(int i=0;i<4;i++){
		if(chk(currx+dx[i],curry+dy[i])){
			int newx=currx+dx[i];
			int newy=curry+dy[i];
			dis[newx][newy]=dis[currx][curry]+1;
			vis[newx][newy]=1;
			q.push({newx,newy});
		}
	}
	
}
}
signed main()
{
    fast_io;
    cin>>n>>m;
    bfs(1,1);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cout<<dis[i][j]<<" ";
    	}
    	cout<<endl;
    }
    



}