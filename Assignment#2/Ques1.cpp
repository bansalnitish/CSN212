#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define mod 1000000007LL
#define ll long long 
#define eps 1e-10
#define inf 1e6
#define fi first 
#define se second

const int maxn=1e3+5;
int n;
int a[maxn];

int longestzigzag(int n ,int a[]){
   int dp[n][2];

   for(int i=0;i<n;i++)
   	dp[i][0]=dp[i][1]=1;

    int answer=1;

    for(int i=1;i<n;i++){
    	for(int j=0;j<i;j++){
    		if(a[j]<a[i] && dp[i][0]<dp[j][1]+1)
    			dp[i][0]=dp[j][1]+1;
    		else if(a[j]>a[i] && dp[i][1]<dp[j][0]+1)
    			dp[i][1]=dp[j][0]+1;

    	}
    	answer=max(answer,max(dp[i][0],dp[i][1]));
    }
    return answer;
}

int main(){
      
	 cout<<"Enter the length of the array"<<endl;
	 cin>>n;
	 cout<<"enter the array"<<endl;
	 for(int i=0;i<n;i++)
	 	cin>>a[i];
	 cout<<"Answer = "<<longestzigzag(n,a)<<endl;

	 return 0;
} 
// input array 
/*374 40 854  203 203 156 362 279 812 955 
600 947 978 46 100 953 670 862 568 188 
67 669 810 704 52 861 49 640 370 908 
477 245 413 109 659 401 483 308 609 120 
249 22 176 279 23 22 617 462 459 244 */