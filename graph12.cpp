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
vi ad[10005];
vi res;
int in[10005];
void kahn(int n){
	// queue<int>q;
	priority_queue<int,vi,greater<int>>q;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int curr=q.top();
		q.pop();
		res.pb(curr);
		for(auto i:ad[curr]){
			in[i]--;
			if(in[i]==0){
				q.push(i);
			}
		}
	}
}
signed main()
{
    fast_io;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        ad[x].pb(y);
        in[y]++;
    }
    kahn(n);
    if(res.size()!=n){
    	cout<<"Sandro fails."<<endl;
    	return 0;
    }
    for(auto i:res){
    	cout<<i<<" ";
    }



}