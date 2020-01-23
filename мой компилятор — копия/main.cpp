#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;
string str="",str1;
bool reset=false;
int yc=5;
bool ifletter(char c);
string chislovstr(string &str);
bool hassign(string str,char c);
void to_assign(string str);
string count_string(string &str);
int  printvars();
void wait();
bool proverka(string &str);
COORD c={5,yc};
bool chitat=true;
int main()
{ cout<<"Type in expression and it will calculate the answer.\nTo assign value to variable do like this: \nVAR=11 ,now VAR is equal 11 and you can call it.\nTo see list of variables type 'all' and press ENTER.\nTo stop the program type 'finish' and press ENTER."<<endl;
    cout<<"-->"<<ends;
setprecision(15);
 while(true){
    if(reset){
            c={5,yc};
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,yc});
        cout<<"-->"<<ends;
        str="";
        c.X=5;
        reset=false;
    }

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    wait();
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,yc+1});
    cout<<"\r                                                                       \r";
    if(proverka(str)){
    if (str=="all"&& reset ) {yc+=printvars();reset=true;yc+=1;}
    else if(str=="finish" && reset) break;
    else if(ifletter(str[0]) && hassign(str,'=')&& reset) {

            to_assign(str);yc++;

    }
    //printvars();

    else if(   !hassign(str,'=')  ) {str1=str;cout<<count_string(str1)<<endl;if(reset) yc+=2;}
    }

    }return 0;
}
void wait()
{
    int i;
    while (true)
    {
        if(_kbhit)
        {
            i=_getch();
            if(i!=13 && i!=8){
            str+=i;
            c.X++;
            printf("%c\n",i);
            break;}
            else if(i==8){
                    c.X--;
                str.erase(str.size()-1,1);
                cout<<"\r                                  \r-->  "<<str;break;
            }
            else {reset=true;
                break;

            }

        }
    }
}
