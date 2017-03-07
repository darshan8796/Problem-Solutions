
#include <cstdio>

	

int x1[4];
int y1[4];
int x2[4];
int y2[4];

long xx1[4] = {0};
long yy1[4] = {0};
long xx2[4] = {0};
long yy2[4] = {0};

int a[4] = {0};
int check[4] = {0};
int main()
{
	for(int i=0;i<4;i++) scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
	
	int c=0;
	for(int i=0;i<4;i++)
	{
		if(y1[i]==y2[i]) 
		{
			check[i] = 1, a[c] = i, c++;
			if(x1[i]>x2[i])
			{
				int temp = x2[i];
				x2[i] = x1[i];
				x1[i] = temp;
			}
			else if(x1[i]==x2[i])
			{
				printf("NO");
				return 0;
			}
		}
	}
	
	c--;
	if(c!=1)
	{
		printf("NO");
		return 0;
	}
	else
	{	
		int q = a[0];
		xx1[0] = x1[q];
		yy1[0] = y1[q];	
		xx1[1] = x2[q];
		yy1[1] = y2[q];
		
		q = a[1];
		xx2[0] = x1[q];
		yy2[0] = y1[q];
		xx2[1] = x2[q];
		yy2[1] = y2[q];		
		
	}
	
	for(int i=0;i<4;i++)
	{
		if(check[i]==0)
		{
			for(int j=0;j<2;j++)
			{
				if((x1[i]==xx1[j] && y1[i]==yy1[j] && x2[i]==xx2[j] && y2[i]==yy2[j]) || (x1[i]==xx2[j] && y1[i]==yy2[j] && x2[i]==xx1[j] && y2[i]==yy1[j]))
				{
					check[i] = 1;
					xx1[j] = 10e9 + 1;
					xx2[j] = 10e9 + 1;
					yy1[j] = 10e9 + 1;
					yy2[j] = 10e9 + 1;
					break;
				}
			}
		}
	}
	
	if(check[0] == 1 && check[1] == 1 && check[2] == 1 && check[3] == 1) printf("YES");
	else printf("NO");
	return 0;
}
