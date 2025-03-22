#include<iostream>
using namespace std;

class bankaccount{
    private:
   int balance;
   public:
   void dep(int amount){
     balance=amount;
    cout<< "amount deposited :"<<balance<<endl;
   }
int with(int amount){
    if(balance==0){
        cout<<"you are bankrupt"<<endl;
    }
    if(amount>balance){
        cout<<"not enough balance"<<endl;
      return 0;
    }
    else{
    balance=balance-amount;
   
    }
   cout<<"amount withdrawn :"<<amount<<endl;
    return balance;
}
void print(){
    cout<<"current balance :"<<balance<<endl;
}




};
int main(){
    bankaccount obj;
    int with;
    cout<<"enter the amount you want to withdraw"<<endl;
    cin>>with;
    obj.dep(10000);
    obj.with(with);
    obj.print();

return 0;


}