#include <iostream>
using namespace std;
struct node{
    int data;
    struct node* next;    
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
int num(struct node* head,int cnt){
    struct node* temp=head;
    int data;int multiple;int result=0;
    while(temp!=NULL){
        multiple=1;
        data=temp->data;        
        for(int i=0;i<cnt-1;i++){
            multiple*=10;
        }
        data=multiple*data;
        result+=data;
        cnt--;
        temp=temp->next;        
    }
    
    return result;
}


struct node* addtwolist(struct node* node1,struct node* node2){
    struct node* counter1=node1;struct node* counter2=node2;    
    int cnt1=0;int cnt2=0;
    struct node* temp1=node1;struct node* temp2=node2;
    struct node* returnnode=new node();   
    while(counter1!=NULL){
        counter1=counter1->next;   
        cnt1++;     
    } 
    while(counter2!=NULL){
        counter2=counter2->next;
        cnt2++;
    }   
    
    int result=num(node1,cnt1)+num(node2,cnt2); 
    
    if(result==0)
        insert(returnnode,result);
    else{
        while(result>0){
        insert(returnnode,result%10);
        //cout<<result%10<<" added to linked list!"<<endl;
        result/=10;
    }
    }
    
    
    returnnode=returnnode->next;
    return returnnode;
     
}

int main(){ 
    struct node* node1=newNode(2);
    insert(node1,4);
    insert(node1,9);

 
    
    struct node* node2=newNode(5);
    insert(node2,6);
    insert(node2,4);
    insert(node2,9);
    

    
    struct node* x=addtwolist(node2,node1);
    printall(x);
    
  

}