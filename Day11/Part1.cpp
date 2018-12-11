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
int g[310][310],id,n,plvl,x,y,a,temp;
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
            temp = 0;
            for(int i2 = i; i2<i+3; i2++){
                for(int j2 = j; j2<j+3; j2++){
                    temp+=g[i2][j2];
                }
            }
            if(temp>a){
                a=temp;
                x=i;
                y=j;
            }
        }
    }
    cout<<x<<","<<y;
    return 0;
}
