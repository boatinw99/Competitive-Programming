#include<bits/stdc++.h>
using namespace std;
int dy[2][100009][2][2];
main()
{
	int n,c,d,i,j,x,y,p,l ;
	char type;
	scanf("%d %d %d",&n,&c,&d);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %c",&x,&y,&type);
		p=type-'C';		
			if(x>dy[p][y][0][0])
			{
				dy[p][y][1][0]=dy[p][y][0][0];
				dy[p][y][1][1]=dy[p][y][0][1];
				dy[p][y][0][0]=x;
				dy[p][y][0][1]=y;
			}
			else if(x>dy[p][y][1][0])
			{
				dy[p][y][1][0]=x;
				dy[p][y][1][1]=y;
			}
	}
	for(i=2;i<=c;i++)
	{
		if(dy[0][i-1][0][0]>dy[0][i][0][0])
		{
			dy[0][i][1][0]=dy[0][i][0][0];
			dy[0][i][1][1]=dy[0][i][0][1];
			dy[0][i][0][0]=dy[0][i-1][0][0];
			dy[0][i][0][1]=dy[0][i-1][0][1];
			if(dy[0][i-1][1][0]>dy[0][i][1][0])
			{
				dy[0][i][1][0]=dy[0][i-1][1][0];
				dy[0][i][1][1]=dy[0][i-1][1][1];
			}
		}
		else if(dy[0][i-1][0][0]>dy[0][i][1][0])
		{	
			dy[0][i][1][0]=dy[0][i-1][0][0];
			dy[0][i][1][1]=dy[0][i-1][0][1];
		}
	}
	for(i=2;i<=d;i++)
	{
		if(dy[1][i-1][0][0]>dy[1][i][0][0])
		{
			dy[1][i][1][0]=dy[1][i][0][0];
			dy[1][i][1][1]=dy[1][i][0][1];
			dy[1][i][0][0]=dy[1][i-1][0][0];
			dy[1][i][0][1]=dy[1][i-1][0][1];
			if(dy[1][i-1][1][0]>dy[1][i][1][0])
			{
				dy[1][i][1][0]=dy[1][i-1][1][0];
				dy[1][i][1][1]=dy[1][i-1][1][1];
			}
		}
		else if(dy[1][i-1][0][0]>dy[1][i][1][0])
		{
			dy[1][i][1][0]=dy[1][i-1][0][0];
			dy[1][i][1][1]=dy[1][i-1][0][1];
		}
	}
	int pr=0 ;
	if(dy[0][c][0][0]!=0&&dy[1][d][0][0]!=0)
	pr=dy[0][c][0][0]+dy[1][d][0][0];
	for(i=1;i<=c/2;i++)
	{
		if(dy[0][i][0][0]!=0)
		{
			if(dy[0][i][0][1]==dy[0][c-i][0][1])
			{
				if(dy[0][c-i][1][0]!=0)
				pr=max(pr,dy[0][i][0][0]+dy[0][c-i][1][0]);
			}
			else if(dy[0][c-i][0][0]!=0)pr=max(pr,dy[0][i][0][0]+dy[0][c-i][0][0]);
		}	
	}
	for(i=1;i<=d/2;i++)
	{
		if(dy[1][i][0][0]!=0)
		{
			if(dy[1][i][0][1]==dy[1][d-i][0][1])
			{
				if(dy[1][d-i][1][0]!=0)
				pr=max(pr,dy[1][i][0][0]+dy[1][d-i][1][0]);
			}
			else if(dy[1][d-i][0][0]!=0)pr=max(pr,dy[1][i][0][0]+dy[1][d-i][0][0]);
		}
	}
	printf("%d",pr);
}