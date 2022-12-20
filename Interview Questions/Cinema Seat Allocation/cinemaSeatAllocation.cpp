#include <iostream>
#include <vector>
using namespace std;
bool isInto(vector<vector<int>> vect,int row,int column){
    for(int i=0;i<vect.size();i++){        
        if(row==vect[i][0]-1 && column==vect[i][1]-1)
            return false;                    
    }
    return true;
}
vector<vector<int>> addVector(int i,int a,vector<vector<int>>vect){
    vector<int>temp;
    temp.push_back(i);
    temp.push_back(a);
    vect.push_back(temp);
    temp.clear();
    return vect;
}
int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    int c1=0;int c2=0;int c3=0;int result=0;  
    vector<int>temp;
    for(int i=0;i<n;i++){
        c1=0;c2=0;c3=0;
        for(int a=1;a<5;a++){
            if(isInto(reservedSeats,i,a)){
                cout<<"Row: "<<i+1<<"Column: "<<a+1<<endl;
                c1++;                
                reservedSeats=addVector(i+1,a+1,reservedSeats);
                temp.clear();
            }else
                cout<<"Girilmedi"<<endl;// reversedSeats 'de var mı? yoksa içeriye gir.counter saydır 4 tane ise okey burayı kullanabiliriz.            
        }
        if(c1!=4){
            for(int x=0;x<c1;x++){
                reservedSeats.pop_back();
            }
        }else
            result++;  
        cout<<"---------"<<endl;      
        for(int a=3;a<7;a++){
            if(isInto(reservedSeats,i,a)){
                cout<<"Row: "<<i+1<<"Column: "<<a+1<<endl;
                c2++; 
                reservedSeats=addVector(i+1,a+1,reservedSeats);                           
                temp.clear();
            }
            else
                cout<<"Girilmedi"<<endl;// reversedSeats' de yok ise dal ve yukarıda işaretlenmemiş ise;
        }
        if(c2!=4){
            for(int x=0;x<c2;x++){
                reservedSeats.pop_back();
            }
        }else
            result++;        
        cout<<"---------"<<endl;      
        
        for(int a=5;a<9;a++){
            if(isInto(reservedSeats,i,a)){
                cout<<"Row: "<<i+1<<"Column: "<<a+1<<endl;
                c3++;     
                reservedSeats=addVector(i+1,a+1,reservedSeats);
                temp.clear();
            }else
                cout<<"Girilmedi"<<endl;                  
        }if(c3!=4){
            for(int x=0;x<c3;x++){
                reservedSeats.pop_back();
            }
        }else            
            result++;      
        cout<<"---------"<<endl;      
          
    }
    return result;
}
int main(){
    
    vector<vector<int>>vect;
    vect=addVector(2,1,vect);
    vect=addVector(1,8,vect);  
    vect=addVector(2,6,vect);  
    cout<<maxNumberOfFamilies(2,vect);    

    
}