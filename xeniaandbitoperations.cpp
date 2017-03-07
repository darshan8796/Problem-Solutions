#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;
int seg_tree[500000] = {0};
int a[200000] = {0};
int leaf[200000] = {0};

int max_depth = 0;
void build_seg_tree(int node, int i, int j, int depth)
{
	if(i==j)
	{
		seg_tree[node] = a[i];
		leaf[i] = node;
		return;
	}
	
	int m = (i+j)/2;
	build_seg_tree(2*node+1, i, m, depth+1);
	build_seg_tree(2*node+2, m+1, j, depth+1);	
	
	if((max_depth - depth)%2 == 0)
	{
		seg_tree[node] = seg_tree[2*node+1] | seg_tree[2*node+2]; 
	}
	else
	{
		seg_tree[node] = seg_tree[2*node+1] ^ seg_tree[2*node+2];
	}
}
/*
void update(int node, int i, int j, int depth, int l, int r, int value)
{
	if(i>j || j<l || i>r )
	{
		return;
	}
	
	if(i==j)
	{
		seg_tree[node] = value;
		a[i] = value;
		return;
	}
	
	int m = (i+j)/2;
	update(2*node+1, i, m, depth+1, l, r, value);
	update(2*node+2, m+1, j, depth+1, l, r, value);	
	
	if((max_depth - depth)%2 == 0)
	{
		seg_tree[node] = seg_tree[2*node+1] | seg_tree[2*node+2]; 
	}
	else
	{
		seg_tree[node] = seg_tree[2*node+1] ^ seg_tree[2*node+2];
	}
}
*/
void update(int pos, int value)
{
	seg_tree[pos] = value;
	
	int depth = 1;
	for(int node = (pos-1)/2;node>0;node=(node-1)/2,depth++)
	{
		if((depth)%2 == 1)
		{
			seg_tree[node] = seg_tree[2*node+1] | seg_tree[2*node+2]; 
		}
		else
		{
			seg_tree[node] = seg_tree[2*node+1] ^ seg_tree[2*node+2];
		}
	}
	if((depth)%2 == 1)
		{
			seg_tree[0] = seg_tree[1] | seg_tree[2]; 
		}
		else
		{
			seg_tree[0] = seg_tree[1] ^ seg_tree[2];
		}
}

void display(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<seg_tree[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n, m;
	cin>>n>>m;
	for(int i=0;i<(1<<n);i++)
	{
		cin>>a[i];
	}	
	max_depth = n;
	build_seg_tree(0, 0, (1<<n)-1, 1);
	
	for(int i=0;i<m;i++)
	{
		int p, b;
		cin>>p>>b;
		//update(0, 0, (1<<n)-1, 1, p-1, p-1, b);
		
		
		update(leaf[p-1], b);
		//display((1<<(n+1))-1);
		cout<<seg_tree[0]<<endl;
	}
	
	return 0;
}

