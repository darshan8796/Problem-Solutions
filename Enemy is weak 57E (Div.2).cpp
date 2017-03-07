#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXE 1000005
typedef long long ll;
using namespace std;

int n;
ll input[MAXE];
ll dummy[MAXE];
ll lt[MAXE];
ll BIT[MAXE] = {0};

long long int getsum(ll b[], int in)
{
	in++;
	long long int ans = 0;
	while(in>0)
	{
		ans += b[in];
		in = in - (in & (-in));
	}
	return ans;
}

void addsum(ll b[], int in, int val)
{
	in++;
	while(in<=n)
	{
		b[in] += val;
		in = in + (in & (-in));
	}
}


int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>input[i];
		dummy[i] = input[i];
	}
	sort(dummy, dummy+n);
	for(int i=0;i<n;i++)
	{
		input[i] = (lower_bound(dummy, dummy+n, input[i]))-dummy;
	}
	
	for(int i=0;i<n;i++)
	{
		lt[i] = getsum(BIT, n-1) - getsum(BIT, input[i]);
		//cout<<lt[i]<<" ";
		addsum(BIT, input[i], 1);
	}
	
	
	
	for(int i=0;i<MAXE;i++)
	{
		BIT[i] = 0;
	}
	for(int i=n-1;i>=0;i--)
	{
		dummy[i] = getsum(BIT, input[i]-1);
		//cout<<dummy[i]<<" ";
		addsum(BIT, input[i], 1);
	}
	
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		ans += dummy[i]*lt[i];
	}
	
	cout<<ans;
}
