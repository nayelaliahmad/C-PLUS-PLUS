/*CALCULATOR*/
#include<iostream>
using namespace std;
int main(){
int a,b;
cout<<"enter the first number"<<endl;
cin>>a;
cout<<"enter the second number"<<endl;
cin>>b;
char op;
cout<<"enter the operation you want to perform"<<endl;
cin>>op;
cout<<"------"<<endl;
cout<<"answer :"<<endl;
if(op=='+'){
    cout<<a+b<<endl;

}
if(op=='-'){
    cout<<a-b<<endl;
    
}
if(op=='*'){
    cout<<a*b<<endl;
    
}
if(op=='/'){
    cout<<a/b<<endl;
    
}
return 0;




}


