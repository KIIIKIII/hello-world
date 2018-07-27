#include <stdio.h>
#define MAX_N 100
 
int A[MAX_N][10], n;
 
bool dfs(int i, int ia, int b, int c)
{
	if(10 == ia)
		return true;
 
	if(A[i][ia] > b)
		if( dfs(i, ia + 1, A[i][ia], c) )
			return true;
	
	if(A[i][ia] > c)
		if( dfs(i, ia + 1, b, A[i][ia]) )
			return true;
 
	return false;
}
 
void solve()
{
	int ans[MAX_N];
	for(int i = 0; i < n; i ++)
		ans[i] = dfs(i, 0, 0, 0);
	for(int i = 0; i < n; i ++)
		puts(ans[i] ? "YES" : "NO");
}
 
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < 10; j ++)
			scanf("%d", &A[i][j]);
	solve();
	return 0;
}
