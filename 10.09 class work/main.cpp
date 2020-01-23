#include <iostream>
//#include <clocale>
#include <stdlib.h>
using namespace std;

int main()
{   setlocale(LC_ALL,"");
    while(true){
    int num=1;
    //cin>>num;
    switch(num){
case 1:
    {  int i=0,k=0,j;
    string n;
       cout<<"4-значное число:"<<endl;
       cin>>n;
       cout<<"все ли цифры разные?"<<endl;
       while(i<4 && k==0) {
            j=i+1;
        while (j<4)
        {
            if(n[i]==n[j]) k=1;
            j++;
        }
        i++;
       }
       if (k==1)
        {cout<<"нет"<<endl;}
       else
       {cout<<"да"<<endl;}
       i=2;
       cout<<"сумма всех цифр простое число?"<<endl;
       int sum;
       sum=(int)n[0]+(int)n[1]+(int)n[2]+(int)n[3]-48*4;
       while(i<=sum/2)
       {
           if(sum%i==0){
            cout<<"нет"<<endl;
            k=3;
            i+=sum;

           }
           i++;
       }
       if (k!=3) cout<<"да"<<endl;
       cout<<"на не парных местах парные и наоборот?"<<endl;
       i=0;
       k=0;

       int number []={(int)n[0]-48,(int)n[1]-48,(int)n[2]-48,(int)n[3]-48};
       while(i<4){
        if(number[i]%2==0) k=1;
        i+=2;
       }
       i=1;
       while(i<4){
        if(number[i]%2!=0) k=1;
        i+=2;
       }
       if(k==1){cout<<"нет";}
    else cout<<"да";
    cout<<"\n\n\n";

    }



    }
    }
}
