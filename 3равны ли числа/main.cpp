#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{   /*int l=5;
    string str;
    ostringstream temp;
    temp<<l;
    str=temp.str();
    str+=str;

    cout<< str;*/
    int num;
    cin>>num;
    int p1,p2,sum1,sum2;
    p2=num%100;
    sum2=p2/10+p2%10;

    p1=num/100;
    sum1=p1/10+p1%10;

    if (sum1==sum2)
    {cout<<sum1<<"="<<sum2<<endl;
        cout<<"equal";
    }
    else {cout<<sum1<<"=!"<<sum2<<endl;
            cout << "not equal";}

    return 0;
}
