//THIS IS THE FINAL VERSION
#include<iostream>
using namespace std;
int main(){
int e=0;
int n=0;
cout<<"Enter the atomic no:";
cin>>e;
while(e!=0)
{

n++;
for(int i=0;i<n;i++){
   if(e==0)
    break;
   else if(i==0) {
      if(e<=2){
         cout<<n<<"s"<<e;
         e=0;
      }
      else{
         cout<<n<<"s2";
         e=e-2;
      }
   }
   else if(i==1){
      if(e<=6){
         cout<<n<<"p"<<e;
         e=0;
      }
      else{
         cout<<n<<"p6";
         e=e-6;
      }
   }
   else if(i==2){
      int s=e-2;
      if(s<=10 && s>0){
         if(s+1==5 || s-1==5 && e>5 && e<8){
            cout<<n<<"d5";
            e=e-5;
         }
         else if(s+1==10 && e>10){
            cout<<n<<"d10";
            e=e-10;
         }
         else{
            cout<<n<<"d"<<s;
            e=e-s;
         }
      }
      else if(s>10)
      {
          cout<<n<<"d10";
          e=e-10;
      }
      else{
         continue;
      }
   }
   else if(i==3){
      int s=e-10;
      if(s<=14 && s>0){
         if(s+1==7 || s-1==7 &&  e>13 && e<<16){
            cout<<n<<"f7";
            e=e-7;
         }
         else if(s+1==14 && e>20){
            cout<<n<<"f14";
            e=e-14;
         }
         else{
            cout<<n<<"f"<<s;
            e=e-s;
         }
         
      }
      else if(s>14)
      {
          cout<<n<<"f14";
          e=e-14;
      }
      else {
         continue;
      }
   }
   else{
      continue;
   }
   cout<<" ";
}
}

return 0;

}