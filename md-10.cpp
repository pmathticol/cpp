/*************************************************************************
	> File Name: md-10.cpp
	> Author: pzz
	> Mail: 837157806@qq.com 
	> Created  Time: 2014/3/11 15:32:46

 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<iterator>

using namespace std;
 
//
struct node{
	 node *next;
	 int  data;
};

//
int  searchValue(node *head,int k){
   //assert(k>=0);
   node *p1,*p2;
   p1=head;
   p2=head;

   int pos=k;
   while(pos--){
	   if(p1==NULL){
		   cout<<"thr number of list less than k"<<endl;
	   }
	   p1=p1->next;
   }
   while(p1!=NULL){
        p1=p1->next;
		p2=p2->next;
   }
   return p2->data;
}


//
node* createList(vector<int > vi, node *head){

     if(head!=NULL){
		 node *tmp=head;
		 head=head->next;
		 delete tmp;
	 }
	 //int vecOfsize=vi.size();
     vector<int>::iterator iter=vi.begin();
     node *root=head;
	 while(iter!=vi.end())
	 {
		 node *tmp=new node;
		 tmp->data=(*iter);
		 if(head==NULL)
		 { 
			 head=tmp;
			 head->next=NULL;
             root=head;
		 }   //head=tmp;
		 else{
			 tmp->next=head->next;
			 head->next=tmp;// ”√Œ≤≤Â∑®
			 head=tmp;
		 }
		 iter++;
	 }
	 return root;
}


//
void printOf(node  *head){

	node *p=head;
	while(p!=NULL){
		cout<<p->data<<",";
		p=p->next;
	}
	cout<<"\n========================\n";
}

int main(){
  
 //test
 int arr[5]={
	 1,2,3,4,5
 };
 vector<int> vi(arr,arr+5);

 node *head=NULL;
 node *head1=createList(vi,head);
 
 //test list ,print list
 printOf(head1);

 cout<<searchValue(head1,3)<<endl;

 system("pause");
 return 0;
}

