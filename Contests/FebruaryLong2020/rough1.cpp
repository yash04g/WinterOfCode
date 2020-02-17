#include<bits/stdc++.h>
using namespace std;

int dayofweek(int y){  
	int d = 1;
	int m = 2;
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  y / 400 + t[m - 1] + d) % 7;  
}  

int main(){
	int t;
	cin>>t;
	while(t--){
		int m1,y1,m2,y2;
		cin>>m1>>y1>>m2>>y2;
		int tot=0;
		int x;
		int y;
        for(int i=y1;i<=y2;i++){
			x = 10;
			y = i;
            int leap=0;
            int xtra=y;
            y/=100;
            if(y%4==0){
                x+=6;
            }
            else if(y%4==1){
                x+=4;
            }
            else if(y%4==2){
                x+=2;
            }
            if(xtra%4==0){
                if(xtra%100!=0){
                    x--;
                    leap=1;
                }
                else if(xtra%400==0){
                    x--;
                    leap=1;
                }
            }
            xtra=xtra%100;
            xtra= (xtra +(xtra/4));
            x+=xtra;
            x=x%7;
            if(x==5){
                tot++;
            }
            else if(x==6 && leap==0){
                tot++;
            }
        }
        cout<<tot<<endl;
	}
}