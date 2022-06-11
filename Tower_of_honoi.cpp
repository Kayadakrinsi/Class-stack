#include<iostream>
using namespace std;
 void toh(int n,int source,int destination,int auxiliary){
     if(n>0){
         toh(n-1,source,auxiliary,destination);
            cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
        toh(n-1,auxiliary,destination,source);
     }
 }
int main()
{
     toh(3,1,3,2); //toh(number of disk,source,destination,auxiliary)
     return 0;
}
