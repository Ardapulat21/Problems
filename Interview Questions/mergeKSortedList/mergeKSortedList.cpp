#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    int data;
    struct node* next;   
    node(){
        data=0;
        next=NULL;
    }
    node(int key){
        data=key;
        next=NULL;
    } 
};
struct node* newNode(int data){
    struct node* node1=new node();
    node1->data=data;
    node1->next=NULL;
    return node1;        
}
void insert(struct node* node,int data){
    struct node* temp=node;
    while(temp->next!=NULL){
        temp=temp->next;        
    }
    temp->next=newNode(data);    
}
void deleted(struct node* node,int data){
    struct node* temp=node;
    while(temp->next->data!=data){
        temp=temp->next;
    }
    struct node* deleted1=temp->next;
    temp->next=temp->next->next;
    free(deleted1);
}
void printall(struct node* node){
    struct node* temp=node;
    while(temp->next!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }    
    cout<<temp->data<<endl;
}
struct node* mergeKList(vector<node*>&list){
    struct node* mergedList=new node();
    vector<int> vect;
    int length=list.size();

    for(int i=0;i<length;i++){
        
        while(list[i]!=NULL){
            vect.push_back(list[i]->data); 
            cout<<list[i]->data<<"Eklendi."<<endl;           
            list[i]=list[i]->next;
        }
    }
    
    sort(vect.begin(),vect.end());
    for(int i=0;i<vect.size();i++){        
        insert(mergedList,vect[i]);        
    }
    mergedList=mergedList->next;
    return mergedList;
}
int main(){
    vector<struct node*>list;
    struct node* list1=new node(1);
    struct node* list2=new node(1);   
    struct node* list3=new node(2);
    insert(list1,4);
    insert(list1,5);
       
    insert(list2,3);
    insert(list2,4);
    
    insert(list3,6);

    
    list.push_back(list1);    
    list.push_back(list2);
    list.push_back(list3);


    struct node* temp=mergeKList(list);
    printall(temp);
  
}