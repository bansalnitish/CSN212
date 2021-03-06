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

int binary_search(int list[],int r,int num){
	int l=0;
	while(r-l>1){
		int m=(l+r)/2;
		if(list[m]>num)
		r=m;
		else
		l=m;
	}
	return r;
}
 
int LongestIncreasingSubsequence(long long int a[],int s,int n){
	int *list=new int[n];
	memset(list,0,sizeof(list[0])*n);
 
	list[0]=a[s];
	int len=1;
	for(int i=s+1;i<n+s;i++){
		if(a[i]<list[0])
		list[0]=a[i];
		
		else if (a[i]>list[len-1])
		list[len++]=a[i];
		
		else
		list[binary_search(list,len-1,a[i])]=a[i];
	}
	return len;
}
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
	
	int n;
	cin>>n;
	long long int a[2*n];
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	a[n+i]=a[i];       //copying same array two times in an array so that each elemnt has access to next n-1 numbers
    }
    int max=0;
    int answer;
	for(int i=0;i<n;i++){	
    answer=LongestIncreasingSubsequence(a,i,n);
    if(answer>max)
    max=answer;	
   }
	cout<<max<<endl;
 
}
	return 0;
} 

