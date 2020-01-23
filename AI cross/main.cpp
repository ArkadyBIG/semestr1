#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <ctime>
#include <fstream>
#include <math.h>
#include <cmath>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;
int Desk_size=4,change=0;
double AI_size=Desk_size*Desk_size,dchange=1;

int move_AI1,move_AI2;
bool game_over=0,player=0;
char c(int i)
{
    if (i==0) return ' ';
    if(i==1) return 'x';
    if(i==-1) return 'o';
}
void print_game();
void analis();
void player_move();
void print_desk();
void get_AI1();
void get_AI2();
void AI_move();
void AI_analiz1();
void AI_analiz2();
void reset_game();
void index();
void winner();
double get_num(string &s);
double sigmoid(double x);
int win1,win2;
bool W[2]={0,0};
vector<int> data(Desk_size*Desk_size);
vector<double> data_copy(Desk_size*Desk_size);
vector<double[16]> AI_data1(AI_size);
vector<double[16]> AI_data2(AI_size);
//vector<double[9]> AI_data2(AI_size);
void wait()
{
    while (true){
    if(_kbhit) {
            _getch();break;}}

}
void NAX()
{
    fstream f("AI_data1.txt",ios_base::out);
    fstream f1("AI_data2.txt",ios_base::out);
    if(!f.is_open()) cout<<"pizad";    //while (getline(f,s))cout<<s<<endl;
    srand(time(0));

    for(int i=0;i<AI_size;++i){
        for(int j=0;j<16;++j){
            double d=0;
        f<<d <<" ";
        f1<<d<<" ";}
        f<<'\n';
        f1<<'\n';}
    f.close();
    f1.close();
}
int gen=0;
int main()
{



    get_AI1();
    get_AI2();

    //print_desk();


    cout<<"Generation# "<<"\nChange# ";

    while(true){++gen;


    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{20,0});
    cout<<gen;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{20,1});
    cout<<change<<"    "<<(double)change/gen;
    win1=0;W[0]=0;W[1]=0;
    win2=0;

    game_over=false;

    while(win1<2 && win2 <2){
    //player_move();
    if(game_over){

        reset_game();

    }
    if((win1+win2)%2==0){
    if(!game_over){
    AI_analiz1();
    //print_game();
    analis();}
    if(!game_over){
    AI_analiz2();
    //AI_move();
    //print_game();
    analis();}
    //cout<<move_AI1<<" "<<move_AI2;
    }
    else if((win1+win2)%2==1){
    if(!game_over){
    AI_analiz2();
    //AI_move();
    //print_game();
    analis();}
    if(!game_over){
    AI_analiz1();
    //print_game();
    analis();}

    //cout<<move_AI1<<" "<<move_AI2;
    }


    }
    win1>=win2? W[0]=1:W[1]=1;
    winner();
    }
    print_desk();
    while(!game_over){
        player_move();
        print_game();
        analis();
        AI_analiz2();
        print_game();
        analis();
    }
    return 0;
}
void winner()
{string s="";
    if(W[1]){
            fstream f("AI_data1.txt",ios_base::out);
        for(int i=0;i<AI_size;++i){
        for(int j=0;j<16;++j)
        {s+=to_string(int(AI_data2[i][j]))+" ";
        AI_data1[i][j]=AI_data2[i][j];}
        s+='\n';}
        f<<s;
        f.close();
        change+=1;
    }
    if(gen%2000==0)
    for(int i=0;i<AI_size;++i){
        for(int j=0;j<16;++j)
        {
        AI_data2[i][j]=AI_data1[i][j];}
        }
    srand(time(0));
    for(int t=0;t<10;++t){int s=rand()%int(AI_size),d=rand()%16;
    if(rand()%2==0) AI_data2[s][d]+=dchange;
    else AI_data2[s][d]-=dchange;
    abs(AI_data2[s][d])>100 ? AI_data2[s][d]=100: s=s;
    }
    s="";
    fstream f("AI_data2.txt",ios_base::out);
        for(int i=0;i<AI_size;++i){
        for(int j=0;j<16;++j)
        {s+=to_string(int(AI_data2[i][j]))+" ";
        }
        s+='\n';}
        f<<s;
        f.close();
    }


void player_move()
{
    int mov;

    cin>>mov;
        if(data[mov-1]!=0 || mov>Desk_size*Desk_size) {}
        else data[mov-1]=1;


}
void AI_move()
{
    if(data[move_AI1]==0) data[move_AI1]=-1;
    if(data[move_AI2]==0) data[move_AI2]=1;
}
void analis()
{
    for(int i=0,n=Desk_size*Desk_size;i<n;++i){
        if(data[i]!=0 && i<=n-2*Desk_size && data[i]==data[i+Desk_size] && data[i]==data[i+2*Desk_size]) {if(data[i]==1) win1++;else if (data[i]==-1) win2++;game_over=true;break;}
        else if(data[i]!=0 &&i<=n-2*Desk_size && i%Desk_size<Desk_size-1 && data[i]==data[1+i+Desk_size] && data[i]==data[2+i+2*Desk_size]) {if(data[i]==1) win1++;else if (data[i]==-1) win2++;game_over=true;break;}
        else if(data[i]!=0 &&i>2*Desk_size-1 &&i%Desk_size<Desk_size-1&& data[i]==data[1+i-Desk_size] && data[i]==data[2+i-2*Desk_size]) {if(data[i]==1) win1++;else if (data[i]==-1) win2++;game_over=true;break;}
        else if(data[i]!=0 &&i%Desk_size<Desk_size-2 && data[i]==data[i+1] && data[i]==data[i+2]) {if(data[i]==1) win1++;else if (data[i]==-1) win2++;game_over=true;break;}
    }
}
void print_game()
{



   // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});

for(int i=0;i<Desk_size*Desk_size;++i){
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{i*2%(Desk_size*2),(i/Desk_size)*2});
        //int k=X[i];
        if(Desk_size<4) c(data[i])!=' ' ? cout<<c(data[i]): cout<<i+1;
        else  cout<<c(data[i]);
}
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{25,0});
cout<<"win1= "<<win1;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{25,2});
cout<<"win2= "<<win2;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,Desk_size*2+2});
cout<<"\r   \r";
}
void AI_analiz1()
{

    for(int i=0;i<Desk_size*Desk_size;++i)
        data_copy[i]=0;
        //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,Desk_size*2+10});
    for(int i=0,n=Desk_size*Desk_size;i<n;++i){
        for(int j=0;j<n;++j){

            data_copy[i]+=data[j]*AI_data1[j][i];

        }
        //cout<<"data: "<<data_copy[i]<<endl;
        data_copy[i]=abs(data_copy[i]);
        data_copy[i]=sigmoid(data_copy[i]);

    }
    double r;
    while(true){r=-10;
    for (int i=0;i<Desk_size*Desk_size;++i){
        r=max(r,data_copy[i]);
    }
    for (int i=0;i<Desk_size*Desk_size;++i)
        if(r==data_copy[i]) move_AI1=i;
        if(data[move_AI1]!=0) data_copy[move_AI1]=-1;
        else break;
        }
    data[move_AI1]=1;
    /*fstream T("AI1.txt",ios_base::out);
    for(int i=0;i<Desk_size*Desk_size;++i){if(i%Desk_size==0 && i!=0) T<<char(13);
        T<<data_copy[i]<<" ";
    }
    T.close();*/

}
void AI_analiz2()
{

    for(int i=0;i<Desk_size*Desk_size;++i)
        data_copy[i]=0;
        //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,Desk_size*2+10});
    for(int i=0,n=Desk_size*Desk_size;i<n;++i){
        for(int j=0;j<n;++j){

            data_copy[i]+=data[j]*AI_data2[j][i];

        }
        //cout<<"data: "<<data_copy[i]<<endl;
        //data_copy[i]=abs(data_copy[i]);
        data_copy[i]=sigmoid(data_copy[i]);

    }
    double r;
    while(true){r=-10;
    for (int i=0;i<Desk_size*Desk_size;++i){
        r=max(r,data_copy[i]);
    }
    for (int i=0;i<Desk_size*Desk_size;++i)
        if(r==data_copy[i]) move_AI2=i;
        if(data[move_AI2]!=0) data_copy[move_AI2]=-1;
        else break;
        }
        //cout<<move_AI;
    /*fstream T("AI1.txt",ios_base::out);
    for(int i=0;i<Desk_size*Desk_size;++i){if(i%Desk_size==0 && i!=0) T<<char(13);
        T<<data_copy[i]<<" ";


    }
    T.close();*/
    data[move_AI2]=-1;

}
void reset_game()
{
    for(int i=0;i<Desk_size*Desk_size;++i){
        data[i]=0;
    }
    //print_game();
    game_over-=1;
}
void get_AI1()
{
    fstream f("AI_data1.txt");
    string s="";//,ios_base::out
    if(!f.is_open()) cout<<"pizad";    //while (getline(f,s))cout<<s<<endl;
    char c;
    while(f.get(c))  s+=c;

    for(int i=0;i<AI_size;++i){
        for(int j=0;j<16;++j)
        AI_data1[i][j]=get_num(s);
        s.erase(0,1);}
    f.close();
}
void get_AI2()
{
    fstream f("AI_data1.txt");
    string s="";//,ios_base::out
    if(!f.is_open()) cout<<"pizad";    //while (getline(f,s))cout<<s<<endl;
    char c;

    while(f.get(c))  s+=c;

    for(int i=0;i<AI_size;++i){
        for(int j=0;j<16;++j)
        AI_data2[i][j]=get_num(s);
        s.erase(0,1);}
    f.close();
}
void print_desk()
{
    for (int y=0;y<Desk_size*2-1;++y){
        for(int x=0;x<Desk_size*2-1;++x)
            if(x%2==1) cout<<'|';
            else if(y%2==1) cout<<'-';
            else cout<<" ";
        cout<<endl;
    }
}
string continue_to_next(string &str)
{
    string out;
    while(str.size()>0){
        if((str[0]>47 && str[0]<58)||str[0]=='.'||str[0]=='-') {out+=str[0];str.erase(0,1);}
        else break;
    }
    str.erase(0,1);
    return out;
}
double sigmoid(double x)
{
    return 1/(1+pow(2.718281828459,-x));
}
double get_num(string &s){
    string str=continue_to_next(s);
    double out=0;

    int znack=1,numbeordot=0;

    if(str[0]=='-'){ str.erase(0,1);znack=-1;}
    for(int i=0;i<str.size();i++){
        if(str[i]=='.') break;

        else numbeordot++;

    }

    for(int i=0;i<numbeordot;i++){
        out+=int(str[i]-48)*pow(10,numbeordot-i-1);

    }
    for(int i=numbeordot+1;i<str.size();i++){
        out+=int(str[i]-48)*pow(10,-(i-numbeordot));
    }

    return out*znack;
}
