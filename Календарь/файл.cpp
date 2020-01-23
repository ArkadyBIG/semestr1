#include <bits/stdc++.h>
#include <vector>
#include <fstream>
using namespace std;
string name;
vector<string> appoinment;
vector<string> day;
vector<int> priority;
void new_person();
void new_appoinment(string ,string ,int);
void fill_data(string );
void take_data(){
    fstream f("person1.txt");

    string s="";//,ios_base::out
    if(!f.is_open()) cout<<"pizad";    //while (getline(f,s))cout<<s<<endl;
    char c;
    while(f.get(c))  s+=c;
    f.close();
    if(s=="") {new_person();
    fstream f("person1.txt");

    if(!f.is_open()) cout<<"pizad";    //while (getline(f,s))cout<<s<<endl;
    while(f.get(c))  s+=c;
    f.close();
    }
    name="";
    while(s.size()>0){ //GET name
        if(s[0]!='|'){name+=s[0];s.erase(0,1);continue;}
        s.erase(0,1);
        break;
    }
    fill_data(s);
}
void fill_data(string s)
{   int poi=0;
    while(s.size()>0){

            appoinment.push_back("");
            day.push_back("");
            priority.push_back(0);
            while(s.size()>0){
                if(s[0]!='#')
                    {appoinment[appoinment.size()-1]+=s[0];
                s.erase(0,1);continue;}
                s.erase(0,1);
                break;
            }
            while(s.size()>0){
                if(s[0]!='#') {day[day.size()-1]+=s[0];s.erase(0,1);continue;}
                s.erase(0,1);
                break;
            }
            while(s.size()>0){
                if(s[0]!='|') {priority[priority.size()-1]=s[0]-48;s.erase(0,1);continue;}
                s.erase(0,1);
                break;
            }
        }
}
void new_person()
{
    fstream f("person1.txt");
    cout<<"Hello!What is your name?"<<endl;
    getline(cin,name);

    f<<name+'|';
    f.close();

}

void delete_num(int n){
    appoinment.erase(appoinment.begin()+n);
    day.erase(day.begin()+n);
    priority.erase(priority.begin()+n);
    string s=name+"|";
    for (int i=0;i<day.size();++i){
        s+=appoinment[i]+"#"+day[i]+"#"+to_string(priority[i])+"|";
    }

    fstream f("person1.txt",ios_base::out);
    //
    if(!f.is_open()) cout<<"pizad";    //while (getline(f,s))cout<<s<<endl;
    f<<s;
    f.close();

}
void delete_file(string d)
{
    if(d=="1"){
        fstream f("person1.txt",ios_base::out);f.close();
    exit(0);

    }
    if(d=="2"){
        fstream f("person1.txt",ios_base::out);
    //
        f<<name+"|";f.close();
        appoinment.clear();
        day.clear();
        priority.clear();
    }
}
void data_change(string a,string b,string c,int a1){
    if(a!="") appoinment[a1]=a;
    else if(b!="") day[a1]=b;
    else if(c!="") priority[a1]=int(c[0])-48;
    string s=name+"|";
    for (int i=0;i<day.size();++i){
        s+=appoinment[i]+"#"+day[i]+"#"+to_string(priority[i])+"|";
    }
    fstream f("person1.txt",ios_base::out);
    //
    if(!f.is_open()) cout<<"pizad";    //while (getline(f,s))cout<<s<<endl;
    f<<s;
    f.close();
}
void new_appoinment(string a,string d,int p)
{
    appoinment.push_back(a);
    day.push_back(d=="0"? "":d );
    priority.push_back(p);
    fstream f("person1.txt");
    string s="";//,ios_base::out
    if(!f.is_open()) cout<<"pizad";    //while (getline(f,s))cout<<s<<endl;
    char c;
    while(f.get(c))  s+=c;

    s+=a+"#"+d+"#"+to_string(p)+"|";

    f.close();
    f.open("person1.txt",ios_base::out);
    f<<s;
    f.close();
}
