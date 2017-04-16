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
#define INF 2000000

const int maxn=1e5+5;
pair<int ,int > answer[maxn],points[maxn];

int check(pair<int,int > p, pair<int,int> q, pair<int,int> r)
{
    int val = (q.se - p.se) * (r.fi - q.fi)-
              (q.fi - p.fi) * (r.se - q.se);
 
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; // clock or counterclock wise
}

void find_convex_hull(pair<int,int > points[],int n){
	 if(n<3)
	 	return ;
         
       int cnt=0,l; 
	   int leftmost=points[0].fi;
 
	   for(int i=1;i<n;i++){
	   	 if(leftmost>points[i].fi){
	   	 	leftmost=points[i].fi;
            l=i;
	   	 }
	   }

	   int a=l,b;

	   do{
         
         answer[cnt++]=points[a];

         b=(a+1)%n;   // find the next point such that move in a counter clock wise direction 

         for(int i=0;i<n;i++){

         	   if(check(points[a],points[i],points[b])==2)   // if we get counterclockwise point b 
         	   	b=i;
         }
         
         a=b;

	   }while(a!=l);

        cout<<"The required points are "<<endl;
	   for(int i=0;i<cnt;i++){
           cout<<answer[i].fi<<" , "<<answer[i].se<<endl;
	   }

    return ;
}

int main(){
      
     //ios::sync_with_stdio(false);
	  //cin.tie(0) ;
    
    int n,x,y;
	cout<<"No. of points= ";
	cin>>n;
   
    
        cout<<"Enter the n points "<<endl;
         for(int i=0;i<n;i++){
         	  
         	  cin>>x>>y;                // x coordinate of the point  // y coordinate of the point
              points[i]=(mp(x,y));    // pushing x and y as a pair in point

         }

         // finding the leftmost point from the given points 
         clock_t t;
         t = clock();
          find_convex_hull(points , n);

          t = clock() - t;
     printf ("It took %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);

	return 0;
}