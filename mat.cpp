#include "mat.h"
#include <iostream>
#include <cmath>
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

int* Mat::Simple(long numb){
    int mas[28]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,71,73,79,83,89,97,101,103,107,109};
    int* rezMas=new int[size];
    int a, i=0;
    long flag;
    //cout<<endl<<"Результат разложения: ";
    for( ;i<=28;){
        a=numb%mas[i];
        flag=numb/mas[i];
        if(flag==1&&a==0){
            // cout<<mas[i]<<endl;
            rezMas[size]=mas[i];
            return rezMas;
        }
        if(a==0){
            numb=numb/mas[i];
            // cout<<mas[i]<<"*";
            rezMas[size]=mas[i];
            size++;
            i=0;

        }else i++;

    }
}

void Mat::symbLegendre(long numb, int pole){
    try {//проверка на четность
        if(pole%2==0) throw 0;
    } catch (int x) {
        cout<<endl<<"pole должно быть нечетным("<<x<<")";
        exit(0);
    }
    int mn=1,zam,newPole=pole;

    if(numb<pole){
        int* rezMas=Simple(numb);
        for (int i=0;i<=size;i++) {

            int num=rezMas[i],pole=newPole;

            for (;;) {
                if(num==1){
                    break;
                }
                if(num==2){
                    zam=(pole*pole-1)/8;
                    if(zam%2==1) mn=(-1);
                    rez*=mn;
                    break;
                }

                if((num%4==1)||(pole%4==1)){
                    mn=1;
                    zam=pole%num;
                    pole=num;
                    num=zam;

                }else {
                    mn=-1;
                    zam=pole%num;
                    pole=num;
                    num=zam;
                }
                rez*=mn;
            }
        }
        cout<<endl<<"Результат сравнения= "<<rez<<endl;
        exit(0);

    }else{
        zam=pole%numb;
        pole=numb;
        numb=zam;
        symbLegendre(numb,pole);
    }

    symbLegendre(numb,pole);
}

void Mat::lemmaGausa(int numb, int pole){
    int a;
    bool power=true;
    try {//проверка на четность
        if(pole%2==0) throw 0;
    } catch (int x) {
        cout<<endl<<"pole должно быть нечетным("<<x<<")";
        exit(0);
    }
    for(int i=1;i<=(pole-1)/2;i++){
        a=(numb*i)%pole;
        if(a>(pole-1)/2) power=!power;
    }
    if(power){cout<<endl<<"Результат сравнения= "<<1<<endl;}
    else cout<<endl<<"Результат сравнения= "<<-1<<endl;
}
