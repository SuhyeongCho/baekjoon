#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int T;
    cin>>T;
    for(int t=0;t<T;t++) {
        int x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        
        double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        if (d == 0) {
            if (r1 == r2) cout<<-1<<endl;
            else cout<<0<<endl;
        }
        else {
            if (d > abs(r1-r2) && d < r1 + r2) cout<<2<<endl;
            else if (d == r1 + r2 || d == abs(r1 - r2)) cout<<1<<endl;
            else if (d > r1 + r2 || d < abs(r1 - r2)) cout<<0<<endl;
        }
        
    }
}
