#include "mat.h"
#include <iostream>
using namespace std;

Mat::Mat(){
    cout<<"Welcome Mat library"<<endl;
}

void Mat::Kv(int pole){
    cout<<endl<<"x mod p | x^2 mod p "<<endl;
    int n=(pole-1)/2;
    int q;
    for(int i=1; i<=n; i++)
    {
        q=(i*i)%pole;
        cout<<i<<"  |  "<<q<<endl;
    }
}

void Mat::Simple(long numb){
    int mas[28]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,71,73,79,83,89,97,101,103,107,109};
    int a, i=0;
    long flag;
    cout<<endl<<"Результат разложения: ";
    for( ;i<=28;){
        a=numb%mas[i];
        flag=numb/mas[i];
        if(flag==1&&a==0){
            cout<<mas[i]<<endl;
            break;
        }
        if(a==0){
            numb=numb/mas[i];
            cout<<mas[i]<<"*";
            i=0;

        }else i++;

    }
}

void Mat::Kr1N1(int numb, int pole){
    bool fl=true;
    int mn=1,zam;
    if(numb<pole){
        if(numb==1){
            cout<<endl<<"Результат сравнения= "<<rez<<endl;
            exit(0);
        }
        if(numb==2){
            zam=(pole*pole-1)/8;
            if(zam%2==1) rez*=(-1);
            numb=1;
            fl=false;
        }

        if(fl){
            if((numb%4==1)||(pole%4==1)){
                mn=1;
                zam=pole%numb;
                pole=numb;
                numb=zam;

            }else {
                mn=-1;
                zam=pole%numb;
                pole=numb;
                numb=zam;
            }
        }


    }else{
        zam=pole%numb;
        pole=numb;
        numb=zam;
        Kr1N1(numb,pole);
    }
    rez*=mn;
    Kr1N1(numb,pole);
}
