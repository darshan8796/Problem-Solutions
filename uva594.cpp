#include <bitset>
#include <string>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long n;

	while(scanf("%ld", &n)==1)
	{
		string b = bitset<32>(n).to_string();
		string a = b.substr(24,8);
		a += b.substr(16,8);
		a += b.substr(8,8);
		a += b.substr(0,8);
	
		long ans = bitset<32>(a).to_ulong();
	
		if(a[0] == '1')
		{
			ans = ans - (long)pow(2,32);
		}

		printf("%ld converts to %ld\n", n, ans);
	}
}




