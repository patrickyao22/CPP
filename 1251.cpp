#include<bits/stdc++.h>

#define N 26

using namespace std;
int r,c;
char a[N][N];
bool vis[N][N];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct node
{
    int x;
    int y;
    int step;
}q[N*100];
void bfs(int sx,int sy,int ex,int ey)
{
    int head=1,tail=1;
    bool flag=true;
    memset(vis,0,sizeof(vis));

    vis[sx][sy]=1;
    q[tail].x=sx;
    q[tail].y=sy;
    q[tail].step=0;
    tail++;

    while(head<tail)
    {
        int x=q[head].x;
        int y=q[head].y;
        int step=q[head].step;
        if(x==ex&&y==ey)
        {
            flag=false;
            printf("%d\n",step);
            break;
        }
        for(int i=0;i<4;i++)
        {
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(nx>=0&&nx<r&&ny>=0&&ny<c&&vis[nx][ny]==0&&a[nx][ny]=='.')
            {
                vis[nx][ny]=1;
                q[tail].x=nx;
                q[tail].y=ny;
                q[tail].step=step+1;
                tail++;
            }
        }
        head++;
    }
    if(flag)
        printf("-1\n");
}
int main()
{
    int sx,sy,ex,ey;
    while(scanf("%d%d",&r,&c)!=EOF&&(r||c))
    {

        for(int i=0;i<r;i++)
            scanf("%s",a[i]);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(a[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }
                if(a[i][j]=='*')
                {
                    ex=i;
                    ey=j;
                    a[i][j]='.';
                }
            }
        bfs(sx,sy,ex,ey);
    }
    return 0;
}
