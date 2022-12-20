#include <iostream>
#include <vector>
using namespace std;
int main(){
    string result="";
    int sayi=54;
    vector<int> arr;
    vector<int> arr2;
    while(sayi!=0){
        arr.push_back(sayi%10);
        sayi/=10;
    }
    int temp=1;
   /* for(int i=0;i<arr.size();i++){
        result+=arr[i]*temp;
        temp*=10;
    }*/
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
    int num=0;
    for(int i=arr.size()-1;i>=0;i--){
        num=arr[i];
        for(int x=0;x<i;x++){
            temp*=num*10;
            num=1;
            cout<<"Temp: "<<temp<<endl;
        }
        if(i==0){
            temp=arr[i];
        }

        arr2.push_back(temp);

        temp=1;
    }
    for(int i=0;i<arr2.size();i++){
        cout<<i<<". index: "<<arr2[i]<<endl;
    }


    for(int i=0;i<arr2.size();i++){// arr2{2000,600,40,3} //
        cout<<"index: "<<arr2[i]<<endl;
        if(arr2[i]>=1000){
            cout<<"kademe1"<<endl;
            for(int a=0;a<arr2[i]/1000;a++){
                result+="M";
            }
        }
        else if(arr2[i]>=500){
            cout<<"kademe2"<<endl;
            if(arr2[i]==900){
                result+="CM";
            }else{
                for(int a=0;a<arr2[i]/500;a++){
                    result+="D";
            }
            }
        }
        else if(arr2[i]>=100){
            cout<<"kademe3"<<endl;
            if(arr2[i]==400){
                result+="CD";
            }
            else{
                for(int a=0;a<arr2[i]/100;a++){
                result+="C";
            }
            }
        }
        else if(arr2[i]>=50){
            cout<<"kademe4"<<endl;
            if(arr2[i]==90){
                result+="XC";
            }
            else{
                for(int a=0;a<arr2[i]/50;a++){
                    result+="L";

            }
            }
        }
        else if(arr2[i]>=10){
            if(arr2[i]==40){
                result+="XL";
            }
            else{
                for(int a=0;a<arr2[i]/10;a++){
                    result+="X";

                }
            }
        }
        else if(arr2[i]>=5){
            cout<<"kademe6"<<endl;
            if(arr2[i]==9){
                result+="IX";
                arr2[i]-=9;
            }else{
                for(int a=0;a<arr2[i]/5;a++){
                    result+="V";
                    arr2[i]-=5;
                }
                if(arr2[i]>0){
                    for(int a=0;a<arr2[i];a++){
                    result+="I";

                }
                }
            }
        }
        else if(arr2[i]>=1){
            cout<<"kademe7"<<endl;
            if(arr2[i]==4){
                result+="IV";
                arr2[i]-=4;
            }

            else{
                for(int a=0;a<arr2[i];a++){
                    result+="I";
                    arr2[i]-=1;
                }
            }
        }
    }
    cout<<"Result:"<<result;


}
