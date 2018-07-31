#include<iostream>
#include<cstring>
#include<algorithm>
 
using namespace std;
 
class Block
{
public:
    int x,y,z;
    void fun(int a,int b,int c)
        {
            x=a;
            y=b;
            z=c;
        }
}node[200];
 
bool cmp(Block r,Block t)
    {
        return r.x*r.y<t.x*t.y;
    }
 
int dp[200];
 
int main()
    {
        int num,cnt=0;
        while(cin>>num&&num)
            {
                int a,b,c;
                int m=0;
                for(int i=0;i<num;i++)
                    {
                        cin>>a>>b>>c;
                        node[m++].fun(a, b, c);
                        node[m++].fun(a, c, b);
                        node[m++].fun(b, a, c);
                        node[m++].fun(b, c, a);
                        node[m++].fun(c, a, b);
                        node[m++].fun(c, b, a);
                    }
                sort(node,node+m,cmp);
                int maxlen=0;
                memset(dp,0,sizeof(dp));
                for(int i=0;i<m;i++)
                    {
                        dp[i]=node[i].z;
                        for(int j=0;j<i;j++)
                            {
                                if(node[i].x>node[j].x&&node[i].y>node[j].y)
                                    {
                                        dp[i]=max(dp[i],dp[j]+node[i].z);
                                    }
                            }
                        if(dp[i]>maxlen) maxlen=dp[i];
                    }
                cout<<"Case "<<++cnt<<": maximum height = "<<maxlen<<endl;
            }
        return 0;
    }
