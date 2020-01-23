#include <bits/stdc++.h>
using namespace std;
extern string name;
extern vector<string> appoinment;
extern vector<string> day;
extern vector<int> priority;
void take_data();
void for_now();
void see();
void change(int);
void new_appoinment(string ,string,int);
void edit();
void delete_file(string );
void change_gelete();
void delete_num(int);
void sort_v();
void data_change(string,string,string,int);
int main()
{
    take_data();
    /*for(int i=0;i<day.size();++i){
        cout<<appoinment[i]<<" "<<day[i]<<priority[i]<<endl;
    }*/
    cout<<"Hello,"<<name<<endl;
    time_t raw;
    tm * timeinfo;
    time(&raw);
    timeinfo=localtime(&raw);
    cout<<asctime(timeinfo)<<endl;
    for_now();
    while(1){sort_v();

    if(day.size()>0){cout<<"Do u want to see-1  / edit-2 ur calendar"<<endl;
    string W_T_D;
    cin>>W_T_D;
    if(W_T_D=="1"){see();}
    if(W_T_D=="2") {edit();}}
    else edit();}
    return 0;
}
void for_now()
{
    cout<<"Goals:\n";
    for(int i=0;i<day.size();++i){
        if(day[i]=="0") cout<<appoinment[i]<<endl;
    }
    for(int i=0;i<day.size();++i){
        if(day[i]=="1") cout<<appoinment[i]<<" - done\n";
    }
    time_t raw;
    struct tm * timeinfo;
    time(&raw);
    timeinfo=localtime(&raw);
    string data=to_string(timeinfo->tm_mday)+"."+to_string(timeinfo->tm_mon+1);
    //cout<<data<<endl;
    for(int i=0;i<day.size();++i){
        if(day[i]==data){cout<<"Meetings today: \n";break;}
        if(i==day.size()-1){cout<<"No meetings today."<<endl;}
    }
    for(int i=0;i<day.size();++i)
        if(day[i]==data)cout<<appoinment[i]<<endl;
}
void see()
{   cout<<"Look for a appointment-1.Sort by priority-2                                 'back'-to return to menu\n";
    string a;
    cin >> a;
    if(a=="back") return;
    if(a=="1"){
    cout<<"Choose day to look for doings:          //format day:month  or 'today'.'back'-to return to menu\n";
    string data;
    cin >> data ;
    if(data=="back") return;
    if(data=="today"){for_now();return;}
    else if (data[0]>=48 && data[data.size()-1]<=57){
        for(int i=0;i<day.size();++i){
        if(day[i]==data){cout<<"On "<<data<<" you have: \n";break;}
        if(i==day.size()-1){cout<<"Any meetings on "<<data<<"."<<endl;}
    }
    for(int i=0;i<day.size();++i)
        if(day[i]==data)cout<<appoinment[i]<<endl;
        return;
    }
    see();}
    else if(a=="2"){
            system("cls");
            for(int i=0;i<day.size();++i){
            if(day[i]=="0" )cout<<appoinment[i]<<" "<<endl;}
    for(int i=0;i<day.size();++i){
            if(day[i]=="1" )cout<<appoinment[i]<<" - done"<<endl;}
        for(int i=0;i<day.size();++i){
            if(day[i]!="0" && day[i]!="1")cout<<appoinment[i]<<" "<<day[i]<<endl;

    }}
    else {cout<<"Something went wrong,try again.\n";see();}
}
void edit()
{
    cout<<"Edit mode.               //'back' to return to menu"<<endl<<"Create new-1 \nChange/delete-2 \nDelete whole calendar-3 \n";
    string a,app,day1,pry;
    cin>>a;
    if(a=="back") return;
    if(a=="3"){
        cout<<"delete all data -1 \nonly calendar-2        //'back' to return to menu\n";
        string del;
        cin>>del;
        if(del=="back") return;
        delete_file(del);
    }
    if(a=="1"){cout<<"Type new appointment:                //'back' to return to menu\n";
            cin>>app;cin.ignore();
            if(app=="back") return;
            cout<<"On which day? Enter 0 to make it dataless   /'back' to return to menu\n";
            cin>>day1;cin.ignore();
            if(day1=="back") return;
            cout<<"Priority from 1 to 3                  /'back' to return to menu\n";
            cin>>pry;cin.ignore();
            if(pry[0]<=48 && pry[0]>=52) return;
            new_appoinment(app,day1,int(pry[0])-48);


        }
    if(a=="2"){change_gelete();
    }

}
void change_gelete()
{
        string a;

        cout<<"Make a search by \ndata-1   \nname-2                   /'back' to return to menu\n";
        cin>>a;cin.ignore();
        cout<<"Type what to make a search: \n";
        string str;
        cin>>str;
        if(a=="1"){int line=0;int a1[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
            for(int i=0;i<day.size();++i){
                if(str==day[i]) {a1[line]=i;++line;}
            }

            if(line==0){cout<<"Ooops day wasn't found ,try again.";edit();}
            if(line==1){if(day[0]=="0") cout<<appoinment[0]<<" "<<" "<<priority[0]<<endl;
                else cout<<appoinment[0]<<" "<<day[0]<<" "<<priority[0]<<endl;
                change(a1[line-1]);
            }
            if(line>=2){
                cout<<"Chose from the list\n";
                for (int i=0;i<line;++i){
                    cout<<appoinment[a1[i]]<<"  "<<day[a1[i]]<< " - "<<i+1<<endl;
                }
                string v;
                cin >> v;
                change(a1[int(v[0])-49]);

            }
        }
        else if(a=="2"){int line=0;int a1[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
            for(int i=0;i<day.size();++i){
                if(str==appoinment[i]) {a1[line]=i;++line;}
            }

            if(line==0){cout<<"Ooops day wasn't found ,try again.";edit();}
            if(line==1){if(day[0]=="0") cout<<appoinment[0]<<" "<<" "<<priority[0]<<endl;
                else cout<<appoinment[0]<<" "<<day[0]<<" "<<priority[0]<<endl;
                change(a1[line-1]);
            }
            if(line>=2){
                cout<<"Chose from the list\n";
                for (int i=0;i<line;++i){
                    cout<<appoinment[a1[i]]<<"  "<<day[a1[i]]<< " - "<<i+1<<endl;
                }
                string v;
                cin >> v;
                change(a1[int(v[0])-49]);

            }
        }
}
void sort_v()
{

    if(day.size()<=1) return;
    string appoinment1,day1;
    int priority1;
    for(int i=0;i<day.size()-1;++i){
        if(priority[i+1]<priority[i]){
        day1=day[i];day[i]=day[i+1];day[i+1]=day1;
        appoinment1=appoinment[i];appoinment[i]=appoinment[i+1];appoinment[i+1]=appoinment1;
        priority1=priority[i];
        priority[i]=priority[i+1];
        priority[i+1]=priority1;i=0;
    }
    }
}
void change(int a1)
{


                cout<<"delete-1 \nchange-2                             //'back' to return to menu\n";
                string dc;
                cin>>dc;
                if(dc=="back") return ;
                if(dc=="2"){
                cout<<"\n what to change? \n1-name of appointment \n2-data\mark it done \n3-priority                  //'back' to return to menu\n";
                string str;
                cin >> str;cin.ignore();
                if(day[a1]!="0" || day[a1]!="1")cout<<"Change to:\n";
                else cout<<"Mark it done -  1\n";
                string a;
                cin >> a;
                if(str=="back") return;
                else if(str=="1") data_change(a,"","",a1);
                else if(str=="2") data_change("",a,"",a1);
                else if(str=="3" && a.size()==1 && a[0]<=52) data_change("","",a,a1);
                else  {cout<<"Something went wrong,try again.\n";edit();}
            }
                if(dc=="1") delete_num(a1);
}





















