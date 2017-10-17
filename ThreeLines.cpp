//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int n, xx[50050], yy[50050], ok[3][2], s=0, ok2[3][2], more=0;

int main()
{
    int i, j;
    int boolf=1;
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> xx[i] >> yy[i];
        bool inc=false;
        for(j=0;j<s;j++){
            if(xx[i]==ok[j][0] || yy[i]==ok[j][1]){
                inc=true;
            }
        }
        if(!inc){
            if(s<3)
                ok[s][0]=xx[i], ok[s++][1]=yy[i];
            else{
                boolf=0;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<s;j++){
            if(xx[i]==ok[j][0]&&yy[i]==ok[j][1])
                continue;
        }
        int howm=0;
        for(j=0;j<s;j++){
            if(xx[i]==ok[j][0]){
                howm++;
            }
            if(yy[i]==ok[j][1]){
                howm++;
            }
        }
        if(howm==1){
            for(j=0;j<s;j++){
                if(xx[i]==ok[j][0]){
                    ok2[j][0]++;
                }
                if(yy[i]==ok[j][1]){
                    ok2[j][1]++;
                }
            }
        }
    }
    
    for(i=0;i<s;i++){
        if(ok2[i][0]!=0 && ok2[i][1]!=0){
            more+=min(ok2[i][0], ok2[i][1]);
        }
    }
    if(3-s<more)
        boolf=0;
    
    if(boolf){
        cout << "1" << endl;
    }
    else{
        cout << "0" << endl;
    }
    
    return 0;
}
