#include <iostream>
#include <vector>
using namespace std;
int returnIndex(vector<int>& arr,int data){
    for(int i=0;i<arr.size();i++)
        if(arr[i]==data)
            return i;
    return -1;
}

int trap(vector<int>& height) {
    int h1=0;int h2=0;int n1=-2;int n2=-2;int sum=0;int area=0;// n1,n2 birdaha aynı kuleleri seçmemesi gerekiyor.It shouldn't select the same towards twice 
    vector<int> Lheight;
    vector<int> Rheight;
    int border=height.size();

    cout<<"SA"<<endl;
    
    if(returnIndex(height,-1)!=-1){
        h1=height[height.size()-1];
        for(int i=0;i<border;i++){
            if(h2<height[i] && height[i]!=h1)
                h2=height[i];
        }
        height.pop_back();
    }
    else{
        for(int i=0;i<border;i++){
            if(h1<height[i])
                h1=height[i];            
        }
        for(int i=0;i<border;i++){
            if(h2<height[i] && height[i]!=h1)
                h2=height[i];
        }
    }
    
    // en yüksek iki yapıyı buldum. I found 2 tallest height.
    if(returnIndex(height,h1)<returnIndex(height,h2)){
        for(int i=returnIndex(height,h1)+1;i<returnIndex(height,h2);i++)
            sum+=height[i];            
        
    }else{
        for(int i=returnIndex(height,h2)+1;i<returnIndex(height,h1);i++) 
            sum+=height[i];
    }

    if(h1>h2)
        area=(returnIndex(height,h2)-returnIndex(height,h1)-1)*h2 -sum;       
    else
        area=(returnIndex(height,h2)-returnIndex(height,h1)-1)*h1 -sum;
        
    if(area<0)
        area*=-1;
    
    for(int i=0;i<((returnIndex(height,h1)>returnIndex(height,h2)) ? returnIndex(height,h2) : returnIndex(height,h1)) +1;i++){ // sol tarafı alıyor
        Lheight.push_back(height[i]);
    }
    for(int i=(returnIndex(height,h1)>returnIndex(height,h2)) ? returnIndex(height,h1) : returnIndex(height,h2);i<height.size();i++){// sağ tarafı alıyor
        Rheight.push_back(height[i]);
    }
    Lheight.push_back(-1);
    Rheight.push_back(-1);
    if(area==0) // belki burada bir sıkıntı olabilir.There may be an error here.
        return 0;
    
    area+=trap(Lheight);
    area+=trap(Rheight);

    cout<<"Area: "<<area<<endl;
    return area;
}
int main(){
    vector<int> elevation={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(elevation);
   
}