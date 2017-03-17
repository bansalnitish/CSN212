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
#define INF 2000000000LL
const int maxn=1e4+5;

vector<ll> v[30005];
ll dis[30005];
int n,m;
ll from,to,weight;

// n is number of nodes 
// m is number of edges
int main(){
    
    	
    for(int i=0;i<30005;i++)
      {
      	v[i].clear();
      	dis[i]=INF;
      }    
    
     cout<<"enter the number of nodes and edges in the graph"<<endl;
    
     cin>>n>>m; 

     cout<<"enter the source destination and weight of each edge "<<endl;

     for(int i=0;i<m;i++){

     	cin>>from>>to>>weight;
     	 v[i].pb(from);
     	 v[i].pb(to);
     	 v[i].pb(weight);
     }
     clock_t tStart = clock();
  
   dis[0] = 0;    // distance of source node is zero 
    for(int i = 0; i < n - 1; i++){
        int j = 0;
        while(v[j].size() != 0){

            if(dis[ v[j][0]  ] + v[j][2] < dis[ v[j][1] ] ){
                dis[ v[j][1] ] = dis[ v[j][0]  ] + v[j][2];
            }
            j++;
        }
    }
    
    for(int i=0;i<m;i++){
    	 if(dis[v[i][0] ]+ v[i][2]< dis[v[i][1]] && dis[v[i][0]] !=INF){
    	 	cout<<"Graph contains negative cycle "<<endl;
    	 	return 0;
    	 }
    }
      
    printf("Time taken: %.6fs\n", 1000.00*(double)(clock() - tStart)/CLOCKS_PER_SEC);
     for(int i=0;i<n;i++)
      cout<<"Distance of "<<i<<"th node from  node 0 is : "<<dis[i]<<endl;

   // printf("Time taken: %.6fs\n", 1000000.00*(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}