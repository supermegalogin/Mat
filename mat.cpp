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
    size=0;
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

    rezMas[size]=-1;
    return rezMas;}

int Mat::symbLegendre(long numb, int pole){
    try {//проверка на четность
        if((pole%2==0)||(numb==0)) throw 0;

        int mn=1,zam,newPole=pole;
        rez=1;
        if(numb<pole){
            int* rezMas=Simple(numb);
            for (int i=0;i<=size;i++) {

                int num=rezMas[i],pole=newPole;
                if(num==-1) throw 1;
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

                    mn=(num%4==1)||(pole%4==1)? 1:-1;
                    zam=pole%num;
                    pole=num;
                    num=zam;

                    rez*=mn;
                }
            }
            cout<<endl<<"Результат сравнения= "<<rez<<endl;
            return rez;

        }else{
            zam=pole%numb;
            pole=numb;
            numb=zam;
            symbLegendre(numb,pole);
        }

        symbLegendre(numb,pole);
    } catch (int x) {
        switch (x) {
        case 0: cout<<endl<<"Ошибка ввода("<<x<<")";
            break;
        case 1: cout<<endl<<"Не разложилось";
            break;
        }

        exit(0);
    }
}

void Mat::lemmaGausa(int numb, int pole){
    int a;
    bool power=true;
    try {//проверка на четность
        if((pole%2==0)||(numb==0)) throw 0;
    } catch (int x) {
        cout<<endl<<"Ошибка ввода("<<x<<")";
        exit(0);
    }
    for(int i=1;i<=(pole-1)/2;i++){
        a=(numb*i)%pole;
        if(a>(pole-1)/2) power=!power;
    }
    if(power){cout<<endl<<"Результат сравнения= "<<1<<endl;}
    else cout<<endl<<"Результат сравнения= "<<-1<<endl;
}

void Mat::symbJacobi(long numb, int pole){
    try {
        if(pole%2==0) throw 10;
        if(numb==0) {rez=0; throw 0;}

        int zam, newNumb=numb,mn=1;
        rez=1;
        if(numb<pole){
            int* rezMas=Simple(pole);

            for (int i=0;i<=size;i++) {
                numb=newNumb;
                if(rezMas[i]==-1) throw 2;

                for (;;) {
                    if(numb<rezMas[i])
                    {
                        if(numb==0){ rez=0;throw 0;}
                        if(numb==1) throw 1;
                        if(numb==2){
                            zam=(rezMas[i]*rezMas[i]-1)/8;
                            if(zam%2==1) mn=(-1);
                            rez*=mn;
                            break;
                        }
                        mn=(numb%4==1)||(rezMas[i]%4==1)? 1:-1;
                        zam=rezMas[i]%numb;
                        rezMas[i]=numb;
                        numb=zam;

                        rez*=mn;
                    }else {
                        zam=rezMas[i]%numb;
                        rezMas[i]=numb;

                        numb=zam;
                    }

                }

            }

            cout<<endl<<"Результат сравнения= "<<rez<<endl;

        }else {
            zam=pole%numb;
            pole=numb;
            numb=zam;
            symbJacobi(numb,pole);
        }

    } catch (int x) {
        switch (x) {
        case 10: cout<<endl<<"Ошибка ввода("<<x<<")"<<endl;
            break;
        case 0: cout<<endl<<"Результат сравнения= 0"<<endl;
            break;
        case 1: cout<<endl<<"Результат сравнения= "<<rez<<endl;
            break;
        case 2: cout<<endl<<"Не разложилось"<<endl;
            break;
        default: cout<<endl<<"Неизвестная Ошибка ("<<x<<")"<<endl;
            break;
        }

    }

}

void Mat::fastPower(long numb,int pow, int pole){
    try {
        if(numb==0||pole==0) throw 0;
        if(pow==0) throw 1;
        int size=0;
        long ans=numb;
        int* bitNum=new int[size];

        while (pow!=1) {
            bitNum[size]=pow%2;
            size++;
            pow=pow/2;

        }
        bitNum[size]=1;
        size--;
        for (size;size>=0;size--) {
            if(bitNum[size]==0) {ans=ans*ans%pole;
            }else {
             ans=ans*ans*numb%pole;
            }
        }
        cout<<endl<<"Результат= "<<ans<<endl;

    } catch (int q) {
        switch (q) {
        case 0: cout<<endl<<"NOT NULL"<<endl;
            break;
        case 1: cout<<endl<<"Результат= 1"<<endl;
            break;
        }
    }
}

int Mat::symbLegendre2(int numb, int pole){
    int zam,mn=1;
    try {
        if(numb==0||pole==0) throw 100;
        if(pole%2==0) throw 1;

        if(numb<pole){
            while (numb!=1) {
                if(numb==2){
                    zam=(pole*pole-1)/8;
                    if(zam%2==1) rez*=(-1);
                    break;
                }

                mn=(numb%4==1)||(pole%4==1)? 1:-1;
                zam=pole%numb;
                pole=numb;
                numb=zam;

                rez*=mn;

                for (;;) {
                    if(numb%2==0){
                        zam=(pole*pole-1)/8;
                        if(zam%2==1) rez*=(-1);
                        numb=numb/2;
                    }else break;
                }
            }
            cout<<endl<<"Результат сравнения= "<<rez<<endl;
            return rez;
        }else {
            zam=pole%numb;
            pole=numb;
            numb=zam;
            symbLegendre2(numb,pole);
        }

    } catch (int x) {
        switch (x) {
        case 100: cout<<endl<<"ENTER NOT NULL";
            break;
        case 1: cout<<endl<<"Pole= 2n+1";
            break;
        }
        exit(0);
    }
}

void Mat::ellCorPoint(int a, int b, int c, int pole){

    try {
        if(a==0||b==0||pole==0)throw 0;
        int Y[pole/2], X[pole];
        for (int i=0;i<=pole/2;i++)  Y[i]=i*i%pole;
        for (int i=0;i<pole;i++)  X[i]=(a*i*i*i+b*i+c)%pole;
        for (int i=0;i<pole;i++) {
            for (int j=0;j<=pole/2;j++) {
                if(X[i]==Y[j]) cout<<endl<<"( "<<i<<"; ±"<<j<<")";
            }
        }


    } catch (int q) {
        switch (q) {
        case 0: cout<<endl<<"NOT elliptic curve"<<endl;
            break;


        }
        exit(0);
    }
}
