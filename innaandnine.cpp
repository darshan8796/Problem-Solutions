#include <string>
#include <iostream>


using namespace std;

int main()
{
	string s;
	cin>>s;
	long long int ans = 1;
	long long int count = 1;

	for(int i=0;i<s.length()-1;i++)
	{
		if((s[i]-'0') + (s[i+1]-'0') == 9) count++;
		else
		{
			if(count%2==1 && count>1) ans *= (count+1)/2; 
			count = 1;
		}
	}
	//cout<<count<<endl;
	if(count%2==1 && count>1) ans *= (count+1)/2;
	
	
	if(ans == 0) cout<<1;
	else cout<<ans;
	return 0;
}
