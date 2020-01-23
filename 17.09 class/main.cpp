#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;


void p(int a[])
{   cout<<endl;
    for(int i=0;i<20;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
}
void p0(int a[])
{    int k=0;
     for(int i=0;i<20;i++)
    {
       if (a[i]==0)
       {
           k++;
       }
       else i=56;

    }

        for(int i=k;i<20;i++)
    {
        cout<<a[i];

    }
}
long long pow(int b)
{   long long t=1;
    for(int i=0;i<b;i++)
    {
        t=t*10;
    }
    return t;
}

int main()

{   int o=1;
    srand(time(0));
    int ost=0,b[10],a[10],ans[11];

    long long i;
    cout<<"first number:"<<endl;
    cin>>i;
    for(int t=0;t<10;t++)

    {
        a[t]=int(i/(pow(9-t)))-int((i/(pow(10-t)))*10);
    }

    cout<<"second number:"<<endl;
    cin>>i;
    for(int t=0;t<10;t++)

    {
        b[t]=int(i/(pow(9-t)))-int((i/(pow(10-t)))*10);}
    cout<<"sum:\n";
    for(int i=9;i>=0;i=i-1){
        ans[i+1]=(ost+a[i]+b[i])%10;
        ost=(ost+a[i]+b[i])/10;
    }

    ans[0]=ost;

    int k=0;

    for(int i=0;i<11;i++)
    {
       if (ans[i]==0)
       {
           k++;
       }
       else i=56;

    }

        for(int i=k;i<11;i++)
    {
        cout<<ans[i];

    }
    //minus
    int ans1[10],mass[2][10],n=2;
    for(i=0;i<10;i++)
    {
        mass[0][i]=a[i];
        mass[1][i]=b[i];
    }


    for(int i=0;i<10;i++)
    {
        if(mass[0][i]>mass[1][i])
        {
            n=0;
            i=99;
        }
        else if (mass[1][i]>mass[0][i])
        {
            i=99;
            n=1;
        }
    }

    cout<<endl<<"subtraction:"<<endl;
    int t=1;
    if (n==1)
    {cout<<"-";
     t=0;}
    if (n==2)
    {
        cout<<"0";
    }
    else
    {
        for(int i=9;i>=0;i--)
        {
            if (mass[n][i]>=mass[t][i])
            {
                ans1[i]=mass[n][i]-mass[t][i];
            }
            else
            {
                ans1[i]=mass[n][i]-mass[t][i]+10;
                mass[n][i-1]-=1;
            }
        }
        k=0;
            for(int i=0;i<10;i++)
    {
       if (ans1[i]==0)
       {
           k++;
       }
       else i=56;

    }

        for(int i=k;i<10;i++)
    {
        cout<<ans1[i];

    }


    }

    cout<<endl<<"multiplication:"<<endl;


    int mass2[2][20],o2=0,mul[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},m1[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for(i=10;i<20;i++)
    {
        mass2[0][i]=a[i-10];
        mass2[1][i]=b[i-10];
    }

    for(i=0;i<10;i++)
    {
        mass2[0][i]=0;
        mass2[1][i]=0;
    }

    for (int i=9;i>=0;i--)
    {

        ost=0;
        o2=0;
        for(int t=0;t<20;t++)
        {
            m1[t]=0;
        }

        for(int j=19;j>=0;j--)
        {
            m1[j-9+i]=(((mass2[0][j]*mass2[1][i+10])+ost)%10);
            ost=(mass2[0][j]*mass2[1][i+10]+ost)/10;

        }


        for(int t=19;t>=0;t--)
        {   o=((m1[t]+mul[t]+o2)/10);
            mul[t]=((m1[t]+mul[t]+o2)%10);

            o2=o;

        }

        }

    p0(mul);
    return 0;


}
