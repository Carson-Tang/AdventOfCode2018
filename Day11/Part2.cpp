#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define MAXN 100001
#define MOD 1000000007
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;
int g[1000][1000],id,n,plvl,x,y,best,temp,sz;
int check(int i, int j, int k){
    int ans = 0;
    for(int a = i; a < i+k; a++){
        for(int b = j; b < j+k; b++){
            ans+=g[a][b];
        }
    } return ans;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    n=1718;
    for(int i = 1; i <= 300; i++){
        for(int j = 1; j <= 300; j++){
            id=i+10;
            plvl=id*j;
            plvl+=n;
            plvl*=id;
            plvl/=100;
            plvl%=10;
            plvl-=5;
            g[i][j]=plvl;
        }
    }
    for(int i = 1; i <= 300; i++){
        for(int j = 1; j <= 300; j++){
            for(int k = 0; k <= min(300-i,300-j); k++){
                temp = check(i,j,k);
                if(temp>best){
                    best=temp;
                    x=i;
                    y=j;
                    sz=k;
                }
            }
        }
    }
    cout<<x<<","<<y<<","<<sz;
    return 0;
}
