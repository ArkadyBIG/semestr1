#include <iostream>

using namespace std;

int main()
{
    int i=2,j=2,n,p;
    while (i<1000)
    { n=0;
      j=2;
      while (j<i/2)
      {
          p=i%j;
          if(p==0)
          {
              n=1;
              j+=i;
          }
          j+=1;
      }
      if(n==0)
      {
          cout<<i<<endl;
      }
      i+=1;
    }

    return 0;
}
