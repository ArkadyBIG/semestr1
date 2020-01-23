#include <iostream>

using namespace std;
int men(int m,int n)
{
    int i=max(m,n);
    while(true)
    {
        if(i%n==0&& i%m==0)
        {
            return i;
        }
        i++;
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    cout<<men(m,n);
    return 0;
}
