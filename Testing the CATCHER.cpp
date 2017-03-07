#include <iostream>
using namespace std;

int main()
{
	int a[100];
	int k=0;
	while(1)
	{
		int t;
		cin>>t;
		
		if(t==-1) break;
		a[k] = t;
		
		k++;
	}
	
	int sol[k];
	for(int i=0;i<k;i++) sol[i] = 1;
	for(int i=1;i<k;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]<=a[j])
			{
				sol[i] = max(sol[j]+1, sol[i]);
			}
		}
	}
	
	for(int i=0;i<k;i++) cout<<sol[i]<<" ";
	cout<<endl;
	return 0;
}
