#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

long long getcnp();
void sex(int sex);
void an(int an);
void luna(int luna);
void zi(int zi);
void judet(int judet);

int main()

{

    long long cnp=0,x2;
    int sex=0,an=0,luna=0,zi=0,judet=0,inv=0,exit;
    int v[13];

    while(exit!=27)
    {
        cnp=0;

   while(cnp==0)
    {
        cnp=getcnp();
        if(cnp==0)  cout<<endl<<"CNP invalid";
    }

    x2=cnp;

     for(int i=12;i>=0;i--)
   {
       v[i]=x2%10;
       x2=x2/10;
   }

    sex=v[0];
    an=v[1]*10+v[2];
    luna=v[3]*10+v[4];
    zi=v[5]*10+v[6];
    judet=v[7]*10+v[8];

     switch(sex){
            case 1:
        cout<<endl<<"Sex: Masculin";
        break;
            case 2:
        cout<<endl<<"Sex: Feminin";
        break;
     }

     cout<<endl<<"Data nasterii: "<<zi<<"/";
     if(luna<10)    cout<<"0"<<luna;
        else    cout<<luna;

    if((sex==1)||(sex==2))
        cout<<"/19"<<an;
    else if((sex==3)||(sex==4))
        cout<<"/18"<<an;
    else if((sex==5)||(sex==6))
        cout<<"/20"<<an;


    cout<<endl<<"Judetul nasterii: ";

    switch(judet){

        case 1:cout<<"Alba";
    break;
        case 2:cout<<"Arad";
    break;
        case 3:cout<<"Arges";
    break;
        case 4:cout<<"Bacau";
    break;
        case 5:cout<<"Bihor";
    break;
        case 6:cout<<"Bistrita-Nasaud";
    break;
        case 7:cout<<"Botosani";
    break;
        case 8:cout<<"Brasov";
    break;
        case 9:cout<<"Braila";
    break;
        case 10:cout<<"Buzau";
    break;
        case 11:cout<<"Caras-Severin";
    break;
        case 12:cout<<"Cluj";
    break;
        case 13:cout<<"Constanta";
    break;
        case 14:cout<<"Covasna";
    break;
        case 15:cout<<"Dambovita";
    break;
        case 16:cout<<"Dolj";
    break;
        case 17:cout<<"Galati";
    break;
        case 18:cout<<"Gorj";
    break;
        case 19:cout<<"Harghita";
    break;
        case 20:cout<<"Hunedoara";
    break;
        case 21:cout<<"Ialomita";
    break;
        case 22:cout<<"Iasi";
    break;
        case 23:cout<<"Ilfov";
    break;
        case 24:cout<<"Maramures";
    break;
        case 25:cout<<"Mehedinti";
    break;
        case 26:cout<<"Mures";
    break;
        case 27:cout<<"Neamt";
    break;
        case 28:cout<<"Olt";
    break;
        case 29:cout<<"Prahova";
    break;
        case 30:cout<<"Satu Mare";
    break;
        case 31:cout<<"Salaj";
    break;
        case 32:cout<<"Sibiu";
    break;
        case 33:cout<<"Suceava";
    break;
        case 34:cout<<"Teleorman";
    break;
        case 35:cout<<"Timis";
    break;
        case 36:cout<<"Tulcea";
    break;
        case 37:cout<<"Vaslui";
    break;
        case 38:cout<<"Valcea";
    break;
        case 39:cout<<"Vrancea";
    break;
        case 40:cout<<"Bucuresti";
    break;
        case 41:cout<<"Bucuresti - Sector 1";
    break;
        case 42:cout<<"Bucuresti - Sector 2";
    break;
        case 43:cout<<"Bucuresti - Sector 3";
    break;
        case 44:cout<<"Bucuresti - Sector 4";
    break;
        case 45:cout<<"Bucuresti - Sector 5";
    break;
        case 46:cout<<"Bucuresti - Sector 6";
    break;
        case 51:cout<<"Calarasi";
    break;
        case 52:cout<<"Giurgiu";
    break;
    }

    cout<<endl<<"Pentru a introduce un alt CNP, apasati orice tasta."<<endl<<"Pentru a inchide programul, apasati tasta ESC";

    exit=getch();

}



    return 0;
}

long long getcnp()
{

    long long cnp,x,x2;
    int control=0,sex=0,an=0,luna=0,zi=0,judet=0,inv=0;
    int v[12],w[12]={2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};
    int test_control=0;

    cout<<endl<<"Introduceti CNP: ";
    cin>>cnp;

    x=cnp;
    x2=cnp/10;


    control=x%10;

   for(int i=11;i>=0;i--)
   {
       v[i]=x2%10;
       x2=x2/10;
   }


    for(int i=0;i<12;i++)
        test_control=test_control+v[i]*w[i];

    test_control=test_control%11;
    if(test_control==10)    test_control=1;

    sex=v[0];
    an=v[1]*10+v[2];
    luna=v[3]*10+v[4];
    zi=v[5]*10+v[6];
    judet=v[7]*10+v[8];

    if (test_control!=control)
        return 0;
    else if ((judet>46)&&(judet<51)&&(judet>53))
        return 0;

    else if(((luna==2)||(luna==4)||(luna==6)||(luna==9)||(luna==11))&&(zi>30))
        return 0;


    else if((luna>12)||((luna==02)&&(zi>28)))
        return 0;


    else if((an>99)||((luna==02)&&(zi>29)&&(an%4==0)))
        return 0;


    else if((sex>4)||(sex<1))
        return 0;

    else    return cnp;
}


