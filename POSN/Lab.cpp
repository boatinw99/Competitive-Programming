#include<bits/stdc++.h>
using namespace std ;
main()
{
	int a,b,i,j,x,y ;
	scanf("%d",&a);
	scanf("%d",&b);
	pair<int,int> s[b+2][b+2];
	for(i=0;i<=b+1;i++)
	{
		for(j=0;j<=b+1;j++)
		{
			s[i][j].first=0;
			s[i][j].second=0;	
		}
	}
	s[1][1].second=a;
	for(i=1;i<=b;i++)
	{
		scanf(" %d",&s[0][i+1].first);
	}
	for(i=1;i<=b;i++)
	{
		scanf(" %d",&s[i+1][0].first);
	}
	for(j=2;j<=b+1;j++)
	{
		if(s[0][j].first+s[1][j-1].second>a)
		{
			s[1][j].first=s[1][j-1].first+1;
			s[1][j].second=s[0][j].first;
		}
		else 
		{
			s[1][j].first=s[1][j-1].first;
			s[1][j].second+=s[1][j-1].second+s[0][j].first;
		}
		if(s[j][0].first+s[j-1][1].second>a)
		{
			s[j][1].first=s[j-1][1].first+1;
			s[j][1].second=s[j][0].first;
		}
		else
		{
			s[j][1].first=s[j-1][1].first;
			s[j][1].second+=s[j-1][1].second+s[j][0].first;
		}
	}
	for(j=2;j<=b+1;j++)
	{
		for(i=2;i<=b+1;i++)
		{
			if(s[i][0].first+s[i-1][j].second>a)
			{
				s[i][j].first=s[i-1][j].first+1;
				s[i][j].second=s[i][0].first;
			}
			else
			{
				s[i][j].first=s[i-1][j].first;
				s[i][j].second=s[i-1][j].second+s[i][0].first;
			}
			if(s[0][j].first+s[i][j-1].second>a)
			{
				x=s[i][j-1].first+1;
				y=s[0][j].first;
			}
			else
			{
				x=s[i][j-1].first;
				y=s[i][j-1].second+s[0][j].first;
			}
			if(x<s[i][j].first)
			{
				s[i][j].first=x;
				s[i][j].second=y;
			}
			if(x==s[i][j].first&&y<s[i][j].second)
			s[i][j].second=y;
		}
	}
	//printf("\n\n");
/*	for(i=0;i<=b+1;i++)
	{
		for(j=0;j<=b+1;j++)
		printf("%d ",s[i][j].first);
		printf("\n");
	}
	//second
	printf("\n");
	for(i=0;i<=b+1;i++)
	{
		for(j=0;j<=b+1;j++)
		printf("%d ",s[i][j].second);
		printf("\n");
	}*/
	printf("%d\n%d",s[b+1][b+1].first,s[b+1][b+1].second);
}
