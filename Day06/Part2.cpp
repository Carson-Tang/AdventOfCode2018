#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
int n,x,y,g[1000][1000],num,ans,d[4][2]={{1,0},{-1,0},{0,-1},{0,1}},cnt;
bool vis[1000][1000];
string s,s2;
struct point{
    int xc,yc;
};
point coord[51];
bool good(int xc, int yc){
    int sum=0;
    for(int i = 0; i < 50; i++){
        sum+=abs(xc-coord[i].xc)+abs(yc-coord[i].yc);
    } return sum<10000;
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
            if(good(i,j))cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
