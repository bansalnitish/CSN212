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
#define INF 200000

const int maxn=1e5+5;

class Point {

public:
    int x, y;

    // comparison is done first on y coordinate and then on x coordinate
    bool operator < (Point b) {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};

Point points[maxn];

Point pivot;

// returns -1 if a -> b -> c forms a counter-clockwise turn,


int counter_clockwise(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

// returns square of Euclidean distance between two points
int Dist(Point a, Point b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// used for sorting points according to polar order w.r.t the pivot
bool POLAR_ORDER(Point a, Point b)  {
    int order = counter_clockwise(pivot, a, b);
    if (order == 0)
        return Dist(pivot, a) < Dist(pivot, b);
    return (order == -1);
}

stack<Point> find_convex_hull(Point *points, int N)    {
    stack<Point> ans;

    if (N < 3)
        return ans;

    
    int minY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[minY])
            minY = i;

    // swap the pivot with the first point
    Point temp = points[0];
    points[0] = points[minY];
    points[minY] = temp;

    // sort the remaining point according to polar order about the pivot
    pivot = points[0];
    sort(points + 1, points + N, POLAR_ORDER);

    ans.push(points[0]);
    ans.push(points[1]);
    ans.push(points[2]);

    for (int i = 3; i < N; i++) {
        Point top = ans.top();
        ans.pop();
        while (counter_clockwise(ans.top(), top, points[i]) != -1)   {
            top = ans.top();
            ans.pop();
        }
        ans.push(top);
        ans.push(points[i]);
    }
    
    return ans;

}

int main()  {

    //ios::sync_with_stdio(false);
   // cin.tie(0);

    int n,x,y;
    cout<<"No. of points= ";
    cin>>n;
   
    
        cout<<"Enter the n points "<<endl;
         for(int i=0;i<n;i++){
              
              cin>>x>>y;                // x coordinate of the point  // y coordinate of the point
              points[i]={x,y};    // pushing x and y as a pair in point

         }
     
         clock_t t;
         t = clock();
    
     stack<Point> ans = find_convex_hull(points, n);

     cout<<"The required points are "<<endl;

    while (!ans.empty())   {
        Point p = ans.top();
        ans.pop();
  
        printf("(%d, %d)\n", p.x, p.y);
    }

     t = clock() - t;

     printf ("It took %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);

    return 0;
}