#include <iostream>
#include<vector>
#include<string.h>

#include <stdio.h>
#include <string.h>
using namespace std;

class LeerNumero{
private:
    vector<string>palabras;
    string p1,p2,p3;
    long long num;

    void decenas(int decena, int temp,bool val=true){//usado para dar nombre a los dos primeros numeros
        p2=palabras[decena];
        if(temp!=0&&(!val||num%10!=1)){//val se usa como validador para evitar el uno mil
            p2+="y ";
            p2+=palabras[temp];
        }
        else{
            p2+="y ";
            p2+=palabras[22];
        }
    }

    void unid_y_dec(int num1,bool val=true){//da nombre a los dos primeros numeros
        if(num1<=20)
            p2=palabras[num1];
        else if(num1<30){
            if(val||num%10!=1){
                p2=palabras[21];
                p2+=palabras[22];
            }
            else{
                p2=palabras[21];
                p2+=palabras[num1%10];
            }
        }
        else if(num1<40)decenas(23, num1%10,val);
        else if(num1<50)decenas(24, num1%10,val);
        else if(num1<60)decenas(25, num1%10,val);
        else if(num1<70)decenas(26, num1%10,val);
        else if(num1<80)decenas(27, num1%10,val);
        else if(num1<90)decenas(28, num1%10,val);
        else if(num1<100)decenas(29, num1%10,val);
    }

    void centenas(int num1,bool val=true){
        if(num1==100)
            p2=palabras[30];
        else{
            unid_y_dec(num1%100,val);
            if(num1/100==1)p2.insert(0,palabras[31]);
            else if(num1/100==2)p2.insert(0,palabras[32]);
            else if(num1/100==3)p2.insert(0,palabras[33]);
            else if(num1/100==4)p2.insert(0,palabras[34]);
            else if(num1/100==5)p2.insert(0,palabras[35]);
            else if(num1/100==6)p2.insert(0,palabras[36]);
            else if(num1/100==7)p2.insert(0,palabras[37]);
            else if(num1/100==8)p2.insert(0,palabras[38]);
            else if(num1/100==9)p2.insert(0,palabras[39]);
        }
    }

    void millar(long long num1){
        centenas(num1%1000);
        p3=p2;
        if(num1<2000&&num1>=1000)
            p3.insert(0,palabras[40]);//Evitar el un mil, sino poner solo mil
        else if(num1>=2000){
            centenas(num1/1000,false);
            p3.insert(0,p2);//Estas son las tres cifras que estan antes del mil: 999 000
            p3.insert(p2.size(),palabras[40]);//"mil"
        }
    }

    void millon(){
        if (num==0){
            p1=palabras[43];
            return;
        }
        millar(num%1000000);
        p1=p3;
        if(num<2000000 && num>=1000000){
            p1.insert(0,palabras[41]);//"un millon"
        }
        else if (num>=2000000) {
            millar(num/1000000);
            p1.insert(0,p3);//Estas son las seis cifras que estan antes del millon 999 999 000 000
            p1.insert(p3.size(),palabras[42]);//"millones"
        }
    }

public:

    LeerNumero(long long num_){
        palabras.push_back("");
        palabras.push_back("uno ");
        palabras.push_back("dos ");
        palabras.push_back("tres ");
        palabras.push_back("cuatro ");
        palabras.push_back("cinco ");
        palabras.push_back("seis ");
        palabras.push_back("siete ");
        palabras.push_back("ocho ");
        palabras.push_back("nueve ");
        palabras.push_back("diez ");//10
        palabras.push_back("once ");
        palabras.push_back("doce ");
        palabras.push_back("trece ");
        palabras.push_back("catorce ");
        palabras.push_back("quince ");
        palabras.push_back("dieciseis ");
        palabras.push_back("diecisiete ");
        palabras.push_back("dieciocho ");
        palabras.push_back("diecinueve ");
        palabras.push_back("veinte ");//20
        palabras.push_back("veinti");
        palabras.push_back("un ");//22
        palabras.push_back("treinta ");
        palabras.push_back("cuarenta ");
        palabras.push_back("cincuenta ");
        palabras.push_back("sesenta ");
        palabras.push_back("setenta ");
        palabras.push_back("ochenta ");
        palabras.push_back("noventa ");
        palabras.push_back("cien ");//30
        palabras.push_back("ciento ");
        palabras.push_back("doscientos ");
        palabras.push_back("trescientos ");
        palabras.push_back("cuatroscientos ");
        palabras.push_back("quinientos ");
        palabras.push_back("seiscientos ");
        palabras.push_back("setecientos ");
        palabras.push_back("ochocientos ");
        palabras.push_back("novecientos ");
        palabras.push_back("mil ");//40
        palabras.push_back("un millon ");
        palabras.push_back("millones ");
        palabras.push_back("cero");

        num=num_;
        if(num>0 && num<=999999999999)
            millon();
        else
            cout<<"ingrese un numero mayor a 0 y menor a 999 999 999 999"<< endl;
    }

    void imprimir(){
        cout<< p1;
    }
};

int main()
{
    int a;
    cout<< "Ingrese un numero: "<<endl;
    cin>> a;
    LeerNumero num(a);//999 999 999 999
    num.imprimir();
    return 0;
}
