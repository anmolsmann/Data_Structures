#include <iostream>
using namespace std;
struct linklist
{
  int data;
  struct linklist*next,*prev;
};
typedef struct linklist node;
node*head=NULL,*temp,*last;
void create(int);
void print();
void shuffle(int,int);
void create(int c)
{
    if(head==NULL)
    {
        head=new node;
        head->data=c;
        head->next=NULL;
        head->prev=NULL;
    }
    else{
    temp=head;
      if(c%2==0)
    {
        while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    last=temp;
        node *nd=new node;
        last->next=nd;
        nd->next=NULL;
        nd->prev=last;
        nd->data=c;
        last=nd;
    }
    if(c%2!=0)
    {
        node *nd=new node;
        nd->data=c;
        nd->next=head;
        nd->prev=NULL;
        head->prev=nd;
        head=nd;
        
    }
    }
}
    void print()
    {
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }

void shuffle(int a ,int b)
{
    int c=0;
    node*pos1,*pos2;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp=last;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
        if(c==a)
        break;
        break;
    }
    pos1=temp;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
        if(c==b)
        break;
        break;
    }
   pos2=temp;
   temp=head;
       while(temp->next!=pos1->prev)
    {
        temp=temp->next;
    }
    temp->next->next=pos2->next;
    pos2->prev=temp->next;
    pos1->prev=pos2->next;
    pos1->prev=pos2;
    pos2->next=pos1;

}
int main() {
	int n;
	char c; int k,l;
        cin>>n;
        for(int i=0;i<n;i++)
        {	    cin>>c;
        if(c=='I'){
	    cin>>k;
	    create(k);}
	    else if(c=='D')
	    print();
	   else if(c=='S'){
        cin>>k;
	    cin>>l;
	    shuffle(k,l);}
	}
	
	return 0;
}