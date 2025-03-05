/*QUESTION NO 5*/
#include<iostream>
using namespace std;

struct election{
    string name[5];
    int votes[5];
    float percentage[5];
};
int main(){
election s;
float sum;
int highest=0;
cout<<"enter the name of candidates"<<endl;
for(int i=0;i<5;i++){
    cin>>s.name[i];

}
cout<<"enter the votes of candidates"<<endl;
for(int i=0;i<5;i++){
    cin>>s.votes[i];

}
for(int i=0;i<5;i++){
    sum += s.votes[i];
}
for(int i=0;i<5;i++){
   s.percentage[i]=(s.votes[i]/sum)*100;
}
for(int i=0;i<5;i++){
  if(s.votes[i]>highest){
    highest=s.votes[i];
 }
}                       
    cout<<"candidates"<<" "<<" votes"<<" "<<"percentage"<<endl;
for(int i=0;i<5;i++){
    cout<<s.name[i]<<"     "<<s.votes[i]<<"     "<<s.percentage[i]<<endl;
}
cout<<"total"<<" "<<sum<<endl;
for(int i=0;i<5;i++){
    if(s.votes[i]==highest){
        cout<<s.name[i]<<" "<<"has the highest votes"<<endl;
    }
}

return 0;

}
