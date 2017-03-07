#include <cstdio>
#include <iostream>

using namespace std;

int tree[700000] = {0};
int ans[400000] = {0};

void build(int node, int i, int j, int l, int r, int x)
{
	if(tree[node]!=0) return;
	
	if(i>j || j<l || i>r) return;
	
	if(i==j)
	{
		if(i!=x)
		{
			tree[node] = x;
			ans[i] = x;
		}
		return; 
	}
	
	int m = (i+j)/2;
	build(2*node, i, m, l, r, x);
	build(2*node+1, m+1, j, l, r, x);
	
	tree[node] = tree[2*node] & tree[2*node+1];

}
int main()
{
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int l, r, x;
		cin>>l>>r>>x;
		build(1, 1, n, l, r, x);
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

