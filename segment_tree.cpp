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
const int N=2*1e5+10;
int a[N],seg[4*N+10];
void build(int ind,int low,int high){
	if(low==high){
		seg[ind]=a[low];
		return; 
	}
	int mid=(low+high)/2;
	build(2*ind+1,low,mid);
	build(2*ind+2,mid+1,high);
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int query(int ind,int low,int high,int l,int r){
	if(low>=l && r>=high){
		return seg[ind];
	}
	if(r<low || high<l){
		return 0;
	}
	int mid=(low+high)/2;
	int left=query(2*ind+1,low,mid,l,r);
	int right=query(2*ind+2,mid+1,high,l,r);
	return (left+right);
}
void update(int ind,int low,int high,int index,int val){
	if(low==high){
		seg[ind]=val;
		a[index]=val;
		return;
	}
	int mid=(low+high)/2;
	if(low<=index && index<=mid){
		update(2*ind+1,low,mid,index,val);
	}
	else{
		update(2*ind+2,mid+1,high,index,val);
	}
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
signed main()
{
    fast_io;
    int n;cin>>n;
    int q;cin>>q;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    build(0,0,n-1);
    // int q;cin>>q;
    while(q--){
    	int type,l,r;
    	cin>>type>>l>>r;
    	if(type==1){
    		update(0,0,n-1,l-1,r);
    	}
    	else{
    	l--;r--;	
    	cout<<query(0,0,n-1,l,r)<<endl;
    }
    }



}