#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define mod 1000000007LL
#define lld long long 
#define eps 1e-10
#define inf 1e6
#define fi first 
#define se second


lld dp[101][101]={0};
int width, height;
int m,a,b,c,d;

int main(){
	cin>>width>>height;	
	cin>>m;  // size of bad array 
	
	for(int i=0;i<m;i++){
		cin>>a>>b>>c>>d;
		//-1 medp down
		//-2 medp left
		if(a==c){
			if(b>d) dp[a][b]=-1;
			else dp[c][d]=-1;
		}
		else{
			if(a>c) dp[a][b]=-2;
			else dp[c][d]=-2;
		}
	}

	  for(int i=0;i<=width;i++){
		for(int j=0;j<=height;j++){
			if(i==0 && j==0) dp[i][j]=1;
			else{

				if(dp[i][j]==0){
					if(j!=0) dp[i][j]+=dp[i][j-1];
					if(i!=0) dp[i][j]+=dp[i-1][j];
				
				}
				else if(dp[i][j]==-1){

					if(i==0) dp[i][j]=0;
					else dp[i][j]=dp[i-1][j];
				}
				else if(dp[i][j]==-2){

					if(j==0) dp[i][j]=0;
					else dp[i][j]=dp[i][j-1];
				}
			}
		}
	}

	cout<<dp[width][height]<<endl;

	return 0;
}