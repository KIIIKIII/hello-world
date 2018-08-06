#include <stdio.h>
#include <string.h>
#include <math.h>
#define Max 999999
#include <algorithm>
using namespace std;
 
struct point 
{
	int x,y;
}s[20000];
 
char map[110][110];
int turn[110][110];
int n,m,x2,y2,ok,k;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
 
void dfs(int x,int y,int dir)
{
	int i,xx,yy;
	if(x==x2 && y==y2 && turn[x][y]<=k)		//成功的时候返回
	{
		ok=1;
		return ;
	}
	if(turn[x][y]>k)			//大于k时已晕，不行
		return ;
 
	if(x!=x2 && y!=y2 && turn[x][y]==k)			//如果(x,y)和终点(x2,y2),既不在同一行也不在同一列，那么要想到终点至少需要转一次，但现在已经转够k次了，故不行
		return ;
	for(i=0;i<4;i++)	
	{
		xx=x+dx[i];
		yy=y+dy[i];
		if(xx<=0 || yy<=0 || xx>m || yy>n || map[xx][yy]=='*')
				continue;
//注意！！！下面这行中的turn[xx][yy]是表示(xx,yy)已经由别的路线走过了，并记录了turn[xx][yy]，现在需要比较这次走到(xx,yy)和由别的路线走到
//(xx,yy)时，两个的turn值，如果上次的比这次的小，说明这次不行，故要continue；
		if(turn[xx][yy]<turn[x][y])		//这里相等的情况不能剪掉，原因开头已解释	
			continue;
//下面这条if和上面的差不多，目的是：如果从(x,y)走一步到(xx,yy)需要转一次话，并且转过之后turn[x][y]+1依然比turn[xx][yy]大的话，也不符合
		if(dir!=-1 && i!=dir && turn[xx][yy]<turn[x][y]+1)
			continue;			//这两个if语句剪枝很重要，没有的话就超时
		if(dir!=-1 && i!=dir)
			turn[xx][yy]=turn[x][y]+1;
		else
			turn[xx][yy]=turn[x][y];
		map[xx][yy]='*';		//如果这里能走，就把这里变成不能走，然后再从这里开始递归，其实就是起到vis[][] 的作用，会用vis的话就不用追究了
		dfs(xx,yy,i);
		map[xx][yy]='.';		//这里再变成'.',是为了不影响其他的递归过程，因为其他路线可能还要从这里过
		if(ok)
			return ;
	}
 
}
 
 
 
int main()
{
	int i,j,t,x1,y1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				scanf(" %c",&map[i][j]);
		scanf("%d%d%d%d%d",&k,&y1,&x1,&y2,&x2);		//注意，这里是先接y，再接x，我被坑了好长时间
		memset(turn,Max,sizeof(turn));			//因为在dfs()中剪枝要去最小的转弯次数，所以turn要初始化成最大
		ok=0;
		turn[x1][y1]=0;
		dfs(x1,y1,-1);
		if(ok)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
 
 
 
 
