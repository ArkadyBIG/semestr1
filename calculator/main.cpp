#include <iostream>

#include <cmath>

using namespace std;
bool numinthe(char a);
void minusi(int m[4],int );
string s(string t);
void f();
int main()
{   f();
    cout<<"\n" ;

   return 0;}
bool numinthe(char a)
{
    string m="1234567890";
    for (int u =0;u<10;u++)
    {
        if (m[u]==a)
        {
            return true;
        }
    }
    return false;
}
string s(string t)
{
    string t2="";
    for (int i=0;i<t.size();i++)
    {
        if(t[i]!=' ')
            t2+=t[i];
}
    return t2;
}
int nuli(int a)
{
    int t=1;
    for (int i=0;i<a;i++)
        t*=10;
    return t;
}
int stoint(string a)
{   int t=0;
    for (int i=0;i<a.size();i++)
    {
        t+=int(a[i]-48)*nuli(a.size()-1-i);
    }
    return t;
}
int chislo(int a,int b)
{
     int k=1,i=2;
     while (i<=min(a,b))
     {
         if (a%i==0&&b%i==0)
         {
             k*=i;
             a=a/i;
             b=b/i;
         }
         else i++;
     }
    return k;

}
void plusi(string zn[2],int num[4])
{    int a,b;
    if(zn[0]==zn[1])
    {


        a=(num[0]*num[3]+num[2]*num[1])/chislo(num[0]*num[3]+num[2]*num[1],num[1]*num[3]);
        b=(num[1]*num[3])/chislo(num[0]*num[3]+num[2]*num[1],num[1]*num[3]);
        num[0]=a;
        num[1]=b;
    }
    else
    {
        a=num[0]*num[3]-num[2]*num[1];
        b=num[1]*num[3];
        if(zn[0]=="-") a*=-1;
        if (a>=0) zn[0]="";
        else a*=-1;
        num[0]=a/chislo(a,b);
        num[1]=b/chislo(a,b);
    }
}
void minusi(string zn[2],int num[4])
{
    if (zn[0]=="-")
    {
        zn[1]="-";
        plusi(zn,num);
    }
    else
    {
        zn[0]="-";
        int a,b;
        a=num[0];
        b=num[1];
        num[0]=num[2];
        num[1]=num[3];
        num[2]=a;
        num[3]=b;
        plusi(zn,num);

    }
}
void multiply(string zn[],int num[])
{
     if (zn[0]==zn[1]) zn[0]="";
     else zn[0]="-";
     num[0]=num[0]*num[2]/chislo(num[0]*num[2],num[1]*num[3]);
     num[1]=num[1]*num[3]/chislo(num[0]*num[2],num[1]*num[3]);
}
void delit6(string zn[],int num[])
{
    int a=num[2];
    num[2]=num[3];
    num[2]=a;
    multiply(zn,num);
}
void f()
{
    cout<<" + - / *\n -1/1*-1/1\n";
      int o=0,num[4];
      string the="-45/321/7",zn[2]={"",""},z[3]={"","",""},snum[4]={"","","",""};

      getline(cin,the);
      //cout<<the<<"\n";
      the=s(the);
      if (the[0]=='-')
      {
          zn[0]="-";
          the.erase(0,1);
      }

      int i=0;
      for (int u=0;u<4;u++)
      {   if (u==2 && the[i]=='-')
      {   zn[1]="-";
          the.erase(i,1);

      }
          while(numinthe(the[i]))
      {
          snum[u]+=the[i];
          i++;
      }
      if (u!=3) z[u]=the[i];
      i++;
      }                                              //"-"+87/7676*-87/98
       for (int g=0;g<4;g++) num[g]=stoint(snum[g]);//zn[0]+num[0]+z[0]+num[1]+z[1]+zn[1]+num[2]+z[2]+num[3]
      // cout<<zn[0]<<"\n"<<num[0]<<"\n"0<<z[0]<<"\n"<<num[1]<<"\n"<<z[1]<<"\n"<<zn[1]<<"\n"<<num[2]<<"\n"<<z[2]<<"\n"<<num[3];
      if (z[1]=="-"&&zn[1]=="-") {zn[1]="";z[1]="+";}
      if(z[1]=="+") plusi(zn,num);
      else if (z[1]=="-") minusi(zn,num);
      else if (z[1]=="*") multiply(zn,num);
      else if  (z[1]=="/") delit6(zn,num);
      else if (z[0]!="/"||z[2]!="/") f();
      cout<<"answer is:";
      if(num[1]==1) cout<<zn[0]<<num[0];
      else if (num[0]==0) cout<<0;
      else cout<<zn[0]<<num[0]<<"/"<<num[1];
}
