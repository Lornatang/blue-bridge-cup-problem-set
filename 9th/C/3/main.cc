#include <iostream>
using namespace std;

using namespace std;
int main()
{
  int n;
  int num1 = 0;
  int num2 = 0;
  while(cin>>n){
    while(1){
      if(n % 2 == 0){
        n /= 2;
        num1++;
      }
       else if(n % 5 == 0){
        n /= 5;
        num2++;
      }
      else {
        break;
      }
    }
  }
  printf("%d\n",num1>num2?num2:num1);
  return 0;
}