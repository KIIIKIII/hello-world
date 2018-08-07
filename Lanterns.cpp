#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<time.h>
#include<math.h>
#include<list>
#include<cstring>
#include<fstream>
#include<bitset>
#include<memory.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define INF 1000000007

const double EPS=1e-5;
const int MAXN=55;
int matrix[MAXN][MAXN];//保存增广矩阵
int copyMatrix[MAXN][MAXN];//增广矩阵的副本

int Gauss(int a[][MAXN],const int&m,const int&n){//m:变元个数 n:方程个数
    int res=0,r=0;//res为自由变元个数 r为增广矩阵的秩
    for(int i=0;i<m;++i){//处理第i个变元
        for(int j=r;j<n;++j)//找到第i个变元系数不为0的方程 并放到第r行
            if(a[j][i]){
                for(int k=i;k<=m;++k)
                    swap(a[j][k],a[r][k]);
                break;
            }
        if(a[r][i]==0){//第i个变元没有系数不为0的 这变元是自由变元
            ++res;
            continue;
        }
        for(int j=0;j<n;++j)//消去其他方程的i变元
            if((j!=r)&&(a[j][i]!=0))
                for(int k=i;k<=m;++k)
                    a[j][k]^=a[r][k];
        ++r;//矩阵的秩+1
    }
    //矩阵的秩下面的方程 系数都为0 0*x1+0*x2+...+0*xm恒等于0 !=0则无解
    for(int i=r;i<n;++i)
        if(a[i][m])//判断是否无解
            return -1;
    return res;
}

int main()
{
    //freopen("/home/lu/文档/r.txt","r",stdin);
    //freopen("/home/lu/文档/w.txt","w",stdout);
    int t,n,m;
    scanf("%d",&t);
    for(int Case=1;Case<=t;++Case){
        scanf("%d%d",&n,&m);
        for(int i=0;i<MAXN;++i){
            fill(matrix[i],matrix[i]+MAXN,0);
            fill(copyMatrix[i],copyMatrix[i]+MAXN,0);
        }
        for(int i=0;i<m;++i){
            int k,index;
            scanf("%d",&k);
            for(int j=0;j<k;++j){
                scanf("%d",&index);
                matrix[index-1][i]=1;
            }
        }
        cout<<"Case "<<Case<<":"<<endl;
        int q;
        scanf("%d",&q);
        while(q--){
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j)
                    copyMatrix[i][j]=matrix[i][j];
            for(int i=0;i<n;++i)
                scanf("%d",&copyMatrix[i][m]);
            ll res=Gauss(copyMatrix,m,n);
            if(res==-1)
                res=0;
            else
                res=((ll)1)<<res;
            cout<<res<<endl;
        }
    }
    return 0;
}
