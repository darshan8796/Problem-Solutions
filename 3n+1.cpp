#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	int i = 1;
	int j = 10;
	
	
	for(int an=i;an<=j;an++)
	{
		//cout<<n;
		int c = 0;
		int n = an;
		while(1)
		{
			//cout<<n<<" ";
			c++;
			if(n==1) break;
		
			if(n%2 == 0) 
			{
				n = n/2;
			}				
			else
			{
				n = 3*n + 1;		
			}
		}
		cout<<endl<<c;
	}
	
	
	return 0;
}
