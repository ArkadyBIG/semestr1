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
       cout<<"4-������� �����:"<<endl;
       cin>>n;
       cout<<"��� �� ����� ������?"<<endl;
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
        {cout<<"���"<<endl;}
       else
       {cout<<"��"<<endl;}
       i=2;
       cout<<"����� ���� ���� ������� �����?"<<endl;
       int sum;
       sum=(int)n[0]+(int)n[1]+(int)n[2]+(int)n[3]-48*4;
       while(i<=sum/2)
       {
           if(sum%i==0){
            cout<<"���"<<endl;
            k=3;
            i+=sum;

           }
           i++;
       }
       if (k!=3) cout<<"��"<<endl;
       cout<<"�� �� ������ ������ ������ � ��������?"<<endl;
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
       if(k==1){cout<<"���";}
    else cout<<"��";
    cout<<"\n\n\n";

    }



    }
    }
}
