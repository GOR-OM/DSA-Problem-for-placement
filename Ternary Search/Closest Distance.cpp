// #include<bits/stdc++.h>
// using namespace std;


// double distance(int ax,int ay, int bx,int by){
//     return sqrt(pow(ax-bx,2)+pow(ay-by,2));
// }



// int main(){
//     int t;
//     cin>>t;
//     for(int I=1;I<=t;I++){
//         int ax,ay,bx,by,cx,cy,dx,dy;
//         cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;

//         while(distance(ax,ay,bx,by)>1e-6){
//             int mx1 = (2*ax+bx)/3;
//             int my1 = (2*ay+by)/3;
//             int mx2 = (ax+2*bx)/3;
//             int my2 = (ay+2*by)/3;

//             int mx3 = (2*cx+dx)/3;
//             int my3 = (2*cy+dy)/3;
//             int mx4 = (cx+2*dx)/3;
//             int my4 = (cy+2*dy)/3;

//             if(distance(mx1,my1,mx3,my3)<distance(mx2,my2,mx4,my4)){
//                 bx=mx2;
//                 by=my2;
//                 dx=mx4;
//                 dy=my4;
//             }
//             else if(distance(mx1,my1,mx3,my3)>distance(mx2,my2,mx4,my4)){
//                 ax=mx1;
//                 ay=my1;
//                 cx=mx3;
//                 cy=my3;
//             }
//             else{
//                 ax=mx1;
//                 ay=my1;
//                 bx=mx2;
//                 by=my2;
//                 cx=mx3;
//                 cy=my3;
//                 dx=mx4;
//                 dy=my4;
            
//             }
//         }

//         cout<<fixed<<setprecision(6)<<"case "<<I<<": "<<distance(ax,ay,cx,cy)<<endl;
        
//     }
// }

#include <bits/stdc++.h>
using namespace std;

double distance(double ax, double ay, double bx, double by) {
    return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

int main() {
    int t;
    cin >> t;
    for (int I = 1; I <= t; I++) {
        double ax, ay, bx, by, cx, cy, dx, dy;
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

        while (distance(ax, ay, bx, by) > 1e-7 || distance(cx, cy, dx, dy) > 1e-7) {
            double mx1 = (2 * ax + bx) / 3;
            double my1 = (2 * ay + by) / 3;
            double mx2 = (ax + 2 * bx) / 3;
            double my2 = (ay + 2 * by) / 3;

            double mx3 = (2 * cx + dx) / 3;
            double my3 = (2 * cy + dy) / 3;
            double mx4 = (cx + 2 * dx) / 3;
            double my4 = (cy + 2 * dy) / 3;

            double dist1 = distance(mx1, my1, mx3, my3);
            double dist2 = distance(mx2, my2, mx4, my4);

            if (dist1 < dist2) {
                bx = mx2;
                by = my2;
                dx = mx4;
                dy = my4;
            } else if(dist1 > dist2) {
                ax = mx1;
                ay = my1;
                cx = mx3;
                cy = my3;
            }
            else {
                ax = mx1;
                ay = my1;
                bx = mx2;
                by = my2;
                cx = mx3;
                cy = my3;
                dx = mx4;
                dy = my4;
            
            }
        }

        cout <<fixed<<setprecision(7) << "Case " << I << ": " << distance(ax, ay, cx, cy) << endl;
    }
    return 0;
}
