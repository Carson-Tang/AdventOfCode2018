#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
string s;
int n,wood,lumber, d[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
char grid[50][50],change[50][50];
void update(){
    for(int i = 0; i < 50; i++){
        for(int j= 0; j < 50; j++){
            grid[i][j]=change[i][j];
        }
    }
}
void check(int x, int y){
    char cur = grid[x][y];
    int adjtree=0,adjlumber=0;
    for(int i = 0; i < 8; i++){
        int xr = x + d[i][0];
        int yr = y + d[i][1];
        if(xr>-1&&yr>-1&&xr<50&&yr<50){
            if(grid[xr][yr]=='|') adjtree++;
            else if (grid[xr][yr]=='#') adjlumber++;
        }
    }
    if(cur=='.'){
        if(adjtree>2) change[x][y]='|';
        else change[x][y]='.';
    } else if (cur=='|'){
        if(adjlumber>2) change[x][y]='#';
        else change[x][y]='|';
    } else if (cur=='#'){
        if(adjtree&&adjlumber) change[x][y]='#';
        else change[x][y]='.';
    }
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    n=10;
    for(int i = 0; i < 50; i++){
        cin>>s;
        for(int j = 0; j < 50; j++){
            grid[i][j]=s.at(j);
        }
    }
    while(n--){
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
                check(i,j);
            }
        }
        update();
    }
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            if(grid[i][j]=='#')lumber++;
            else if (grid[i][j]=='|')wood++;
        }
    }
    cout<<wood*lumber;
    return 0;
}
