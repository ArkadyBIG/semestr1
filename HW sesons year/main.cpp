#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int getnum(string &);
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
struct contry{
    string name;
    int seson[4];
};
int powof10(int n)
{
    int out=1;
    for(int i=0;i<n;++i) out*=10;
    return out;
}
double M(double n1,double n2,int n)
{
    return n==1 ? max(n1,n2) : min(n1,n2);
}
vector<contry> con(0);
void fill_countries(string str);
int main()
{
    fstream f("Year.txt");
    string s="";
    //,ios_base::out
    if(!f.is_open()) return 2;    //while (getline(f,s))cout<<s<<endl;
    char c;
    while(f.get(c))  s+=c;

    fill_countries(s);
    if(0)
    for(contry c : con){
        cout<<c.name;
        for(int i=0;i<4;++i){
            cout<<ends<<c.seson[i];
        }
        cout<<endl;
    }
    int task;while(true){
        cout<<endl<<"Number of task 1-6: ";
    cin>>task;
    switch (task){
        case 1:{task1();break;}
        case 2:{task2();break;}
        case 3:{task3();break;}
        case 4:{task4();break;}
        case 5:{task5();break;}
        case 6 :{task6();break;}
        default: return 0;
    }}

    return 0;
}
void task1()
{
    int temp[4]={INT_MIN,INT_MIN,INT_MIN,INT_MIN};
    cout<<"Max temperature in\n";
    for(int i=0;i<con.size();i++){
        temp[0]=max(con[i].seson[0],temp[0]);
        temp[1]=max(con[i].seson[1],temp[1]);
        temp[2]=max(con[i].seson[2],temp[2]);
        temp[3]=max(con[i].seson[3],temp[3]);
    }
    cout<<"Summer= "<<temp[0]<<endl;
    for(int i=0;i<con.size();++i){
        if(temp[0]==con[i].seson[0]) cout<<"   "<<con[i].name<<endl;
    }
    cout<<"Autumn= "<<temp[1]<<endl;
    for(int i=0;i<con.size();++i){
        if(temp[1]==con[i].seson[1]) cout<<"   "<<con[i].name<<endl;
    }
    cout<<"Winter= "<<temp[2]<<endl;
    for(int i=0;i<con.size();++i){

        if(temp[2]==con[i].seson[2]) cout<<i<<"   "<<con[i].name<<endl;
    }
    cout<<"Spring= "<<temp[3]<<endl;
    for(int i=0;i<con.size();++i){
        if(temp[3]==con[i].seson[3]) cout<<"   "<<con[i].name<<endl;
    }
    //min
    temp[4]=(INT_MAX,INT_MAX,INT_MAX,INT_MAX);
    cout<<"\n\nMin temperature in\n";
    for(int i=0;i<con.size();i++){
        temp[0]=min(con[i].seson[0],temp[0]);
        temp[1]=min(con[i].seson[1],temp[1]);
        temp[2]=min(con[i].seson[2],temp[2]);
        temp[3]=min(con[i].seson[3],temp[3]);
    }
    cout<<"Summer= "<<temp[0]<<endl;
    for(int i=0;i<con.size();++i){
        if(temp[0]==con[i].seson[0]) cout<<"   "<<con[i].name<<endl;
    }
    cout<<"Autumn= "<<temp[1]<<endl;
    for(int i=0;i<con.size();++i){
        if(temp[1]==con[i].seson[1]) cout<<"   "<<con[i].name<<endl;
    }
    cout<<"Winter= "<<temp[2]<<endl;
    for(int i=0;i<con.size();++i){
        if(temp[2]==con[i].seson[2]) cout<<"   "<<con[i].name<<endl;
    }
    cout<<"Spring= "<<temp[3]<<endl;
    for(int i=0;i<con.size();++i){
        if(temp[3]==con[i].seson[3]) cout<<"   "<<con[i].name<<endl;
    }
    vector<double> t(con.size());
    for(int i=0;i<con.size();++i){
        for(int j=0;j<4;++j){
            t[i]+=con[i].seson[j];
        }
        t[i]/=4;
    }
    double tn=10000,tx=-100000;
    for(int i=0;i<t.size();++i){
        tn=min(t[i],tn);
        tx=max(t[i],tx);
    }
    cout<<"\n\nMin average temperature= "<<tn<<endl;
    for(int i=0;i<t.size();++i){
        if(tn==t[i]) cout<<"   "<<con[i].name<<endl;
    }
    cout<<"Max average temperature= "<<tx<<endl;
    for(int i=0;i<t.size();++i){
        if(tx==t[i]) cout<<"   "<<con[i].name<<endl;
    }
}
void task2()
{
    int tn=100000,tx=-100000,sesone;
    for(int i=0;i<con.size();++i)
    for(int j=0;j<4;++j){
        tn=min(con[i].seson[j],tn);
        tx=max(con[i].seson[j],tx);
    }
    for(int i=0;i<con.size();++i)
    for(int j=0;j<4;++j){
        if(tn==con[i].seson[j]){cout<<"The coldest time was in "<<con[i].name<<" in ";
        if(j==0) cout<<"summer.";
        else if(j==1) cout<<"autumn.";
        else if(j==2) cout<<"winter.";
        else cout<<"spring.";
        cout<<"With temperature= "<<tn<<'.'<<endl;}
    }
    for(int i=0;i<con.size();++i)
    for(int j=0;j<4;++j){
        if(tx==con[i].seson[j]){cout<<"The hottest time was in "<<con[i].name<<" in ";
        if(j==0) cout<<"summer.";
        else if(j==1) cout<<"autumn.";
        else if(j==2) cout<<"winter.";
        else cout<<"spring.";
        cout<<"With temperature= "<<tx<<'.'<<endl;}
    }
}
void task3()
{
    cout<<"Sort by temperature in: 0-summer 1-autumn 2-winter 3-spring 4-average.\n";
    int s,h;
    cin>>s;
    cout<<"By 1-descending 2-growth"<<endl;
    cin>>h;
    if(s==4){
        vector<double> avr(con.size());
        vector<contry> sor(con.size());
        for(int i=0;i<con.size();++i)
            sor[i]=con[i];
        for(int i=0;i<con.size();++i){
        for(int j=0;j<4;++j){
            avr[i]+=con[i].seson[j];
        }
        avr[i]/=4;
        }
        while(avr.size()>0){
            double m;
            h==1 ? m=-19999999:m=1999999999;
            for(int i=0;i<avr.size();++i){
                m=M(m,avr[i],h);
            }
            for(int i=0;i<avr.size();++i){
                if(avr[i]==m){
                    cout<<sor[i].name<< " - "<<m<<endl;
                    avr.erase(avr.begin()+i);
                    sor.erase(sor.begin()+i);
                }
            }
        }

    }
    vector<contry> sor(con.size());
        for(int i=0;i<con.size();++i)
            sor[i]=con[i];

        while(sor.size()>0){
            double m;
            h==1 ? m=-19999999:m=1999999999;
            for(int i=0;i<sor.size();++i){
                m=M(m,sor[i].seson[s],h);
            }
            for(int i=0;i<sor.size();++i){
                if(sor[i].seson[s]==m){
                    cout<<sor[i].name<<" - "<<m<<endl;

                    sor.erase(sor.begin()+i);
                }
            }
        }

}
void task4()
{
    cout<<"Countries with temperature in summer more than 30^"<<endl;
    for(int i=0,n=con.size();i<n;++i){
        if(con[i].seson[0]>30) cout<<con[i].name<<endl;
    }
}
void task5()
{
    cout<<"Countries with temperature in winter less than 0^"<<endl;
    for(int i=0,n=con.size();i<n;++i){
        if(con[i].seson[2]<0) cout<<con[i].name<<endl;
    }
}
void task6()
{
    cout<<"Enter the country: ";
    string c;
    cin >>c;
    int ind,tn=10000,tx=-100000;
    double avr=0;
    for (int i=0;i<con.size();++i){
        if(c==con[i].name) {ind=i;break;}
        if(i==con.size()-1){cout<<"Your county not in the list"<<endl;exit(0);}
    }
    for(int i=0;i<4;++i){
        tn=min(tn,con[ind].seson[i]);
        tx=max(tx,con[ind].seson[i]);
        avr+=con[ind].seson[i];
    }
    avr/=4;
    cout<<"Min= "<<tn<<"\nMax= "<<tx<<"\n Avr= "<<avr<<"\nDifference in Max and Min is "<<tx-tn<<endl;
    cout<<"Enter the temperature: "<<endl;
    cin>>avr;
    if(avr<tx) cout<<c<<" has temp above "<<avr<<endl;
    else cout<<c<<" doesn't have temp above "<<avr<<endl;
    if(avr>tn) cout<<c<<" has temp bellow "<<avr<<endl;
    else cout<<c<<" doesn't have temp bellow "<<avr<<endl;

}
int getnum(string &str)
{
    int out=0,z=1;
    if(str[0]=='-'){z=-1;str.erase(0,1);}
    string c="";
    while(str.size()>0){

        if(str[0]!=' ' && str[0]!=9 && str[0]!=11 && str[0]!=10){
                //cout<<str[0]<<"   "<<int(str[0])<<endl;
            c+=str[0];str.erase(0,1);
        }
        else break;
    }
    str.erase(0,1);

    for(int i=0,n=c.size();i<n;++i){
        out+=int(c[i]-'0')*powof10(n-i-1);
    }

    return out*z;
}
void fill_countries(string str)
{   int ses=0;
        while(str.size()>0){
        //cout<<"str: "<<str<<endl;
            if((str[0]>64 && str[0]<91) || (str[0]>96 && str[0]<123)){
                    //cout<<str[0]-0<<"   +\n";
                    if(con.size()>0 && con[con.size()-1].name=="") {cout<<"Mistake in names ";exit(0);}

                if(con.size()==0 || con[con.size()-1].seson[3]!=228) con.push_back({"",{228,228,228,228}});
                else if(con.size()!=0) con[con.size()-1].name+=" ";
                while((str[0]>40 && str[0]<91) || (str[0]>60 && str[0]<123)){
                    con[con.size()-1].name+=str[0];
                    str.erase(0,1);
                }
                continue;
            }
            if(str[0]>47 && str[0]<58 || str[0]=='-'){
                    string s="";if(ses==4) ses=0;
                if(str[0]=='-'){
                    s='-';
                    str.erase(0,1);
                }
                if(con[con.size()-1].name=="") {cout<<"Mistake in num ";exit(0);}
                while(str.size()>0 && str[0]>47 && str[0]<58){
                    s+=str[0];
                    str.erase(0,1);
                }
                if(s.size()==0) exit(1);
                con[con.size()-1].seson[ses]=getnum(s);
                ++ses;
                continue;
            }
            str.erase(0,1);

        }
}



