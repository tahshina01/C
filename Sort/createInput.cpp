#include <bits/stdc++.h>
using namespace std;
// 100000 999999
int main()
{
    srand(time(0));
    freopen("input.txt","w",stdout);

    int l = 10000;
    int h = 99999;

    int i=0;
    while(i<=7000) {
        int temp = (int)rand()%(h-l) + h ;
//        if(temp/100000>=1 && temp/100000<=9){
            cout<<temp<<" ";
            i++;
  //      }
    }
    return 0;
}
