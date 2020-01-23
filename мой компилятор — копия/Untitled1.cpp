#include <bits/stdc++.h>

using namespace std;
int y=0;

bool isvar;
struct Varible
{
    string name="";
    string num="";
}  ;
vector<Varible> var(0);
string letter(string &str);
string chislovstr(string &str);
int findlast(string str);
double strvdouble(string str);
string count_string(string &str);
string nozero(string str);
int printvars(){
    int num1=1;
    if(var.size()>0){
    cout<<"Variables:\n";
for(int i=0;i<var.size();++i){++num1;
        cout<<i+1<<"-name: "<<var[i].name<<"  value:"<<var[i].num<<endl;
    }}
    else cout<<"not enough variables"<<endl;
    return num1;
}


void to_assign(string str){
    int i=0;
string s=str;
 Varible var1;
 var1.name=letter(str);

 if(str[0]!='=') {cout<<"oshibka v prisvoennii : "<<s;}
 str.erase(0,1);

 var1.num=count_string(str);

 bool isname=false;
 for (i;i<var.size();++i){
    if(var[i].name == var1.name) {var[i].num=var1.num;isname=true;break;}

 }
 if(!isname){
    var.push_back(var1);
 }
}
//проверяет есть ли знак в стринге
bool hassign(string str,char c){
    bool has=false;
    for(int i=0;i<str.size();++i) if(str[i]==c) has=true;
    return has;
}
//ищет значение переменной
string num(string name)
{
    for(int i=0;i<var.size();++i){
        if(var[i].name==name) {return var[i].num;}
    }
    cout<<"not such variable "<<name;
    return "";
}
bool ifletter(char c){
    bool is=false;
    string letter="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    for(int i=0;i<letter.size();++i){
        if(letter[i]==c) is=true;
    }
    return is;
}
string letter(string &str){
    string out="";
    while(str.size()>0){
        if(ifletter(str[0])) {out+=str[0]; str.erase(0,1);}
        else break;
    }
    return out;
}
string  count_string(string &str){
    //cout<<"p: "<<str<<"\n";
    vector<string> mas(0);
    int k=0;
    while(str.size()>0){
    if (ifletter(str[0])){
        string var1="";
        var1=letter(str);
        var1=num(var1);
        //cout<<"var1 "<<var1<<endl;
        mas.push_back(var1);
    }
    else if (str[0]=='('){
            string strinbrac="";
            str.erase(0,1);
            int last=findlast(str);//cout<<str<<"last : "<<last<<endl;
            for (int i=0;i<last;i++){//  cout<<"last: "<<findlast(str)<<endl;
                strinbrac+=str[0];
                str.erase(0,1);
        }
            str.erase(0,1);//cout<<": "<<strinbrac<<endl;
            mas.push_back(count_string(strinbrac));
        }
    else if(str[0]=='-' && k!=0 && !ifletter(str[1])){
                str.erase(0,1);
                mas.push_back("-");

                if(str[0]!='(') {
                    mas.push_back(chislovstr(str));

                }
            }
            else if(str[0]=='-'  && ifletter(str[1])){
                str.erase(0,1);
                mas.push_back("-");


            }

        else if(str[0]=='+'  && !ifletter(str[1])){
                str.erase(0,1);
                mas.push_back("+");

                if(str[0]!='(') {
                    mas.push_back(chislovstr(str));

                }
            }
            else if(str[0]=='+'  && ifletter(str[1])){
                str.erase(0,1);
                mas.push_back("+");


            }
        else if(str[0]=='*'  && !ifletter(str[1])){
                str.erase(0,1);
                mas.push_back("*");

                if(str[0]!='(') {
                    mas.push_back(chislovstr(str));

                }
            }
            else if(str[0]=='*'  && ifletter(str[1])){
                str.erase(0,1);
                mas.push_back("*");


            }
        else if(str[0]=='/'  && !ifletter(str[1])){
                str.erase(0,1);
                mas.push_back("/");
                if(str[0]!='(') {
                    mas.push_back(chislovstr(str));
                }
            }
            else if(str[0]=='/'  && ifletter(str[1])){
                str.erase(0,1);
                mas.push_back("/");
            }

        else mas.push_back(chislovstr(str));
        k++;
}

//for (int i=0 ;i<mas.size();i++) cout<<""<<mas[i]<<"."; cout<<endl;////////////////////////////
for(int i=0;i<mas.size();i++){

    if(mas[i]=="*"){
                    mas[i]=to_string(strvdouble(mas[i-1])*strvdouble(mas[i+1]));
                    mas.erase(mas.begin()+i-1);

                    mas.erase(mas.begin()+i);

                    i=0;}

    else if(mas[i]=="/"){
                    if(strvdouble(mas[i+1])!=0){mas[i]=to_string(strvdouble(mas[i-1])/strvdouble(mas[i+1]));
                    mas.erase(mas.begin()+i-1);mas.erase(mas.begin()+i);
                    i=0;}
                    else{
                        mas.clear();
                        mas.push_back("not allowed to divide by 0");
                    }
                    }

}
for(int i=0;i<mas.size();i++){

    if(mas[i]=="+"){
                    mas[i]=to_string(strvdouble(mas[i-1])+strvdouble(mas[i+1]));
                    mas.erase(mas.begin()+i-1);

                    mas.erase(mas.begin()+i);i=0;

                    }
    else if(mas[i]=="-"){mas[i]=to_string(strvdouble(mas[i-1])-strvdouble(mas[i+1]));
                    mas.erase(mas.begin()+i-1);mas.erase(mas.begin()+i);i=0;

                    }


}
//for (int i=0 ;i<mas.size();i++) cout<<"\n"<<y<<mas[i]<<"\n";//////////////////////////////////////////////
string out="";
for(int i=0;i<mas.size();i++){ out+=mas[i];}
//cout<<"out: "<<out<<endl;
return nozero(out);
}
string chislovstr(string &str){

    string out="";
    do{

        out.push_back(str[0]);
        str.erase(0,1);
    }while(str[0]=='0' || str[0]=='1' || str[0]=='2'|| str[0]=='3'|| str[0]=='4'|| str[0]=='5'|| str[0]=='6'|| str[0]=='7'|| str[0]=='8'|| str[0]=='9' || str[0]=='.');
    return out;
}
double strvdouble(string str){

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
int findlast(string str){
    int out=0,l=0;
    for(int i=0;i<str.size();i++){
            if (str[i]==')' && l==0) {out=i;break;}
            else if(str[i]=='(') l++;
            else if (str[i]==')') --l;



    }

    return out;
}
bool proverka(string &str){
    if(str=="") return true;
    int smile=0,bad=0;
    bool p1=false,p2=true;
    for (int i=0;i<str.size();i++) {if (str[i]=='(') bad++; else if (str[i]==')') smile++;
    else if(!((str[i]>=40 && str[i]<=57) || str[i]==61 || (str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122) )) {str.erase(i,1);--i;}}
    if(str[str.size()-1]=='-'|| str[str.size()-1]=='+' || str[str.size()-1]=='*' ||str[str.size()-1]=='/' ||str[str.size()-1]=='(' )
    smile+=100;
    p1= bad==smile;
    if(!p1) return false;
    int s=0;

    for(char d : str){

        if (ifletter(d) || d=='/' || d=='*' || d=='-' || d=='+') s=0;
        else if(d=='.') s++;
        if(s>1) return false;
    }
    return true;
}
string nozero(string str){
    int i=0;if(hassign(str,'.')){
    for(i=str.size()-1;i>0;--i)

        if (str[i]=='.') break;
        else if(str[i]!='0'){++i;break;}
    str.erase(i,str.size()-i);}
    return str;
}
