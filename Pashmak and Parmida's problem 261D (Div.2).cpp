#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int input[1000005] = {0};
int dummy[1000005] = {0};
int cnt[1000005] = {0};
int lt[1000005] = {0};
int BIT[1000005] = {0};

long long int getsum(int in)
{
	long long int ans = 0;
	while(in>0)
	{
		ans += BIT[in];
		in = in - (in & (-in));
	}
	return ans;
}

int addsum(int in, int value)
{
	while(in<=n)
	{
		BIT[in] += value;
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
		cnt[input[i]]+=1;
		lt[i] = cnt[input[i]];
		//cout<<input[i]<<"|"<<lt[i]<<" ";
	}
	//cout<<endl;
	memset(cnt, 0, sizeof(cnt)/sizeof(cnt[0]));
	for(int i=n-1;i>=0;i--)
	{
		cnt[input[i]]++;
		dummy[i] = cnt[input[i]];
		//cout<<dummy[i]<<" ";
	}
	
	long long int ans = 0;
	for(int i=n-1;i>=0;i--)
	{
		ans += getsum(lt[i]-1);
		//cout<<ans<<" ";
		addsum(dummy[i],1);
	}
	
	cout<<ans;
	return 0;
}
