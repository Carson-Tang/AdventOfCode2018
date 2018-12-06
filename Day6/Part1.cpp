#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
int n,x,y,g[1000][1000],num,ans,d[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
bool vis[1000][1000];
string s,s2;
struct point{
    int xc,yc;
};
point coord[51];
int good(int xc, int yc){
    int a[51];
    memset(a,0,sizeof a);
    int mn = INT_MAX,mncnt,idx;
    for(int i = 0; i < 50; i++){
        a[i]=abs(xc-coord[i].xc)+abs(yc-coord[i].yc);
        if(a[i]<mn){
            mn=a[i];
            mncnt=1;
            idx=i;
        } else if (a[i]==mn) mncnt++;
    }
    if(mncnt==1) return idx+1;
    return 0;
}
int check(int x, int y){
    queue<int>q;
    while(!q.empty()) q.pop();
    q.push(x);
    q.push(y);
    int cnt = 0;
    while(!q.empty()){
        int xc = q.front(); q.pop();
        int yc = q.front(); q.pop();
        vis[xc][yc]=1;
        cnt++;
        for(int i = 0; i < 4; i++){
            int xr = xc + d[i][0];
            int yr = yc + d[i][1];
            if(xr>-1&&yr>-1&&xr<1000&&yr<1000){
                if(g[xr][yr]==g[x][y]&&!vis[xr][yr]){
                    q.push(xr);
                    q.push(yr);
                    vis[xr][yr]=1;
                }
            } else return 0;
        }
    } return cnt;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    n = 0;
    while(n<50){
        cin>>s>>s2;
        x = stoi(s.substr(0,s.length()-1));
        y = stoi(s2);
        coord[n++]={x,y};
    }
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            g[i][j]=good(i,j);
        }
    }
    for(point p : coord){
        ans=max(ans,check(p.xc,p.yc));
    }
    cout<<ans;
    return 0;
}
