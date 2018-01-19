#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node* next;
		node(int a)
		{
			data = a;
			next =NULL;
		}
		
};

class list
{
	node* head = NULL, *tail = NULL;
	public:
		void insert(int a)
		{
			node*temp = new node(a);
			if(head == NULL)
			{
				head = temp;
				tail = temp;
			}else
			{
				tail->next = temp;
				tail = temp;
			}
			temp = NULL;
		}
		
		void InsertAt(int a, int pos)
		{
			node* temp = new node(a);
			int counter,flag = 0;
			node* slider = head;
			if(pos == 1)
			{
				temp->next = slider;
				head = temp;
				flag = 1;													
			}else{	
				for(counter = 1; counter < pos||slider != NULL; counter++)
				{
					if(counter + 1 == pos)
					{
						temp -> next = slider -> next;
						slider -> next = temp;
						if(slider->next == NULL)
						{
							tail = temp;
						}
						flag = 1;
						break;
					}
					slider = slider->next;
				}
			}
			if(flag == 0)
			{
				cout<<"\nlist is not big enough \n";
			}
		}
		
		void Delete()
		{
			node* slider = head;
			if(head == tail)
			{
				head = NULL;
				tail = NULL;
				delete slider;
			}else{
				while(slider ->next != tail)
				{
					slider = slider->next;
				}
				tail = slider;
				slider = slider->next;
				tail->next = NULL;
				delete slider; 
			}
		}
		
		void deleteAt(int pos)
		{
			int counter,flag = 0;
			node* slider = head,*temp;
			if(pos == 1)
			{
				head = slider->next;
				delete slider;
				flag = 1;						
			}
			else
			{	
				for(counter = 1; counter < pos||slider != NULL; counter++)
				{
					if(counter + 1 == pos)
					{
						temp = slider -> next;
						slider -> next = temp->next;
						delete temp;
						if(slider->next == NULL)
						{
							tail = slider;
						}
						flag = 1;
						break;
					}
					slider = slider->next;
				}
			}
			if(flag == 0)
			{
				cout<<"\nlist is not big enough \n";
			}
		}
		
		int countItems()
		{
			int counter;
			node*slider = head;
			for(counter = 0; slider != NULL; counter ++)
			{
				slider = slider->next;
			}
			return counter;
		}
		
		void display()
		{
			node*slider = head;
			for(; slider != NULL;)
			{
				cout<<slider->data<<" -> ";
				slider = slider->next;
			}
			cout<<"NULL";
		}
};

int main()
{
	int data,pos,choice,flag = 0;
	list list1;
	do
	{
		system("cls");
		cout<<"welcome to your linked list suite\n";
		cout<<"\n what do you want to do??\n";
		cout<<"1. insert node at last\n";
		cout<<"2. insert a node at a position\n";
		cout<<"3. delete a node at the end\n";
		cout<<"4. delete a node at a position\n";
		cout<<"5. count nodes\n";
		cout<<"6. display list\n";
		cout<<"7. exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:{
				cout<<"\nenter data for node\n";
				cin>>data;
				list1.insert(data);
				break;
			}
			case 2:{
				cout<<"\nenter data for node\n";
				cin>>data;
				cout<<"\nenter position\n";
				cin>>pos;
				list1.InsertAt(data,pos);
				break;
			}
			case 3:{
				cout<<"\ndeleting node...";
				list1.Delete();
				cout<<"\nnode deleted";
				break;
			}
			case 4:{
				cout<<"\nenter position\n";
				cin>>pos;
				list1.deleteAt(pos);
				cout<<"\nnode deleted\n";
				break;
			}
			case 5:{
				cout<<"\nnumber of nodes is"<<list1.countItems();
				cout<<"\n";
				break;
			}
			case 6:{
				cout<<"\n";
				list1.display();
				break;
			}
			case 7:{
				flag =1;
				break;
			}
			default:{
				cout<<"wrong input\n";
				break;
			}
		}
		cout<<"\n";
		system("pause");
	}while(flag == 0);
}
