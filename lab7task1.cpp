#include<iostream>
#include<string>
using namespace  std ;
void bruteForcePin(string targetPin){
    cout<<"starting the audit for the 4 digit pin code"<<endl;
    cout <<"the target pin is  : "<< targetPin<<endl;
    int target = stoi (targetPin);
    int attempts =0;
    bool found = false;
    for (int i=0; i<=9999;i++)
    {
        attempts++;
        if (i == target)
{
    found =  true;
    cout<<"pin is founded : "<< i << endl;
    cout <<"number of attempts : "<< attempts <<endl;
    break;

}    }

if (!found)
{cout<<"pin is not found as combination is exceeted from 4 digits"<<endl;

}
} 
int main (){

    string targetPin = "4281";
    bruteForcePin (targetPin);
    return 0;

}


