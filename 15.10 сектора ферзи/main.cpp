#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;


struct Qeencor{
int x=0;
int y=0;
};
int nuli(int a)
{
    int t=1;
    for (int i=0;i<a;i++)
        t*=10;
    return t;
}
int chislo(string a,int n)
{   int m[2]={0,0},k=0,c1=1,c2=1;
    n=n-1;
    if (a[0]=='-')
    {
        c1=-1;
        a.erase(0,1);
    }
    for(int i=0;i<a.size();i++)
    {
        if (a[i]!=' ') k++;
        else break;
    }

    int i=0;
    for (i;i<k;i++)
    {
        m[0]+=int(a[i]-48)*nuli(k-1-i);
    }
    if(a[k]=='-'){
        c2=-1;
        a.erase(k,1);
    }
    for (int o=i+1;o<a.size();o++)
    {
        m[1]+=int(a[o]-48)*nuli(a.size()-o-1);
    }
    return m[n];
}
int main()
{
    cout << "1- circle\n 2-chess"<<endl;
    int s;
    cin>>s;
    system("cls");
        switch(s)
    {
    case 1:
        {   int n,r;
            cout<<"num of regions:";
            cin>>n;
            cout<<"radius:";
            cin>>r;
            system("cls");
            int *areas=new int[n];
            for (int i=0;i<n;i++){
                cout<<"area #"<<i+1<<" ";
                cin>>areas[i];
            }
            double sum=0;
            for(int i=0;i<n;i++)
                sum+=areas[i];
            double S;
            S=3.14*r*r;
            for (int i=0;i<n;i++)
                cout<<i+1<<"region's area is :"<<S*areas[i]/sum<<endl;
                break;
         }
    case 2:

        {
            string desk[10]=
            { "8 0 # 0 # 0 # 0 #",
              "7 # 0 # 0 # 0 # 0",
              "6 0 # 0 # 0 # 0 #",
              "5 # 0 # 0 # 0 # 0",
              "4 0 # 0 # 0 # 0 #",
              "3 # 0 # 0 # 0 # 0",
              "2 0 # 0 # 0 # 0 #",
              "1 # 0 # 0 # 0 # 0",
              "y         ",
              " x1 2 3 4 5 6 7 8"
            };
            for (int i=0;i<10;i++){
                cout<<desk[i]<<"\n";
            }
            cout<<"num of Qeens :";
            int n;
            string strdot;
            cin>>n;

            Qeencor *dot=new Qeencor[n];
            for (int i=0;i<n;i++){
                cout<<"#"<<i+1<<" qeen's"<<" X and Y cordinates :"<<endl;

         if (i==0) cin.ignore();
         getline(cin,strdot);

         dot[i].x=chislo(strdot,1);//system("cls");
         dot[i].y=chislo(strdot,2);

            }
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(dot[i].x==dot[j].x || dot[i].y==dot[j].y){
                        cout<<"Qeen #"<<i+1<<"<->"<<"Qeen #"<<j+1<<endl;
                        break;
                    }
                }
            }
            for(int i=0;i<n-1;i++){
                    for (int j=i+1;j<n;j++){
                        if (abs(dot[i].x-dot[j].x)==abs(dot[i].y-dot[j].y))
                            cout<<"Qeen cross#"<<i+1<<"<->"<<"Qeen #"<<j+1<<endl;
                            break;
                    }

                    }

                    int maxim=dot[0].x;
                    bool isdotq;
            for(int i=0;i<n;i++){
                maxim=max(maxim,max(dot[i].x,dot[i].y));
            }
            cout<<"\n\n";
            for(int i = 1;i < maxim+1;i++)
            {
                for(int j=1;j<maxim+1;j++){
                        isdotq=false;
                    for(int k=0;k<n;k++)
                        if(dot[k].x==j && dot[k].y==maxim-i+1){
                            isdotq=true;
                        }
                        if(isdotq) cout<<"Q ";
                        else if((i-j)%2==0) cout<<"# ";
                        else cout<<"0 ";



                }
                cout<<"\n";
            }
            delete []dot;
            }
                }



                }




