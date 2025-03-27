#include<iostream>

using namespace std;

class bankaccount{
protected:
int ban;
double balance;
public:
bankaccount(){
ban=0;
balance=0;
}
void set(int a,double b){
ban =a;
balance= b;

}
int getban(){
    return ban;
    }
double getbal(){

    return balance;
}
void dep(double d){
balance+=d;
cout<<"amount after depositing :"<<balance<<endl;
}
void with(double w){
balance=balance-w;
cout<<"amount withdrawn:"<<w<<endl;
}
 void print(){
cout<<"ban:"<<ban<<endl;
cout<<"current balance:"<<balance<<endl;
}
};
class saving:public bankaccount {
    private:
    double interest;
    float rate;
    public:
    saving(){
        interest=0;
        rate=0;
    }
void  setint(float r){
    rate=r;
}
double calint(){
interest=balance*rate/100;
return interest;
}
double getint(){
    return interest;
}
double postint(){
    interest=calint();
balance=balance+interest;
return balance;
}
void print()  {
       
        cout << "Interest Rate: " << rate << "%" << endl;
        cout << "Interest Amount: $" << interest << endl;
        cout << "Balance after interest: $" << balance << endl;
    }

};
int main(){
bankaccount obj;
saving yes;
obj.set(1122,5000);
obj.dep(100);
obj.with(200);
yes.set(1122,4900);
yes.setint(5);
yes.calint();
yes.postint();
obj.print();
yes.print();



}