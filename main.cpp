#include <iostream>
#include <conio.h>
using namespace std;
/* Node of a doubly linked list */
struct Node {
	int data;
	Node* next; // Pointer to next node in DLL
	Node* prev; // Pointer to previous node in DLL
};

class Doubly_Linked_List
{
	Node *head;  	// points to first node of list
	Node *tail;   	// points to last node of list
	public:
		Doubly_Linked_List()
		{
			head = NULL;
			tail = NULL;
		}
		void add_node(int );
		void display();
		void del_Mid_odd();
		void del_Mid_two_even();
		void Update_Second(int);
		void Insert_At_Second(int);
};
void Doubly_Linked_List::add_node(int d)
{
	// Creating new node
	Node *temp;
	temp = new Node();
	temp->data = d;
	temp->prev = NULL;
	temp->next = NULL;

	// List is empty
	if(head == NULL){
		head = temp;
		tail = temp;
	}
	else{
		//List is not empty
		tail->next = temp;
		temp->prev = tail;
		temp->next = NULL;
		tail = temp;
	}
}
void Doubly_Linked_List::display(){
	Node *trav;
	trav = head;
	int count = 0;
	cout<<"List Data: ";
	while(trav != NULL)
	{
		count++;
		cout<<trav->data<<"  ";
		trav = trav->next;
	}
	cout<<"\nList has "<<count<<" Nodes."<<endl;
}
void Doubly_Linked_List::del_Mid_odd(){
	int length = 0;
	Node *temp = head;
	while(temp!=NULL){
		length++;
		temp = temp->next;
	}
	if(length%2!=0){
		temp = head;
		Node *middle;
		int counter = 0;
		int mid = int(length/2);
		mid+=1;
		while(temp!=NULL){
			counter++;
			if(counter == mid){
				if(temp->prev == NULL){
					head = NULL;
					tail = NULL;
					delete temp;
					cout<<"Process Done!"<<endl;
					break;
				}
				else{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					delete temp;
					cout<<"Process Done!"<<endl;
					break;
				}
			}
			temp = temp->next;
		}
	}
	else
	cout<<"List length is not odd."<<endl;
}
void Doubly_Linked_List::del_Mid_two_even(){
	int length = 0;
	Node *temp = head;
	while(temp!=NULL){
		length++;
		temp = temp->next;
	}
	if(length%2==0){
		temp = head;
		int counter = 0;
		int first_mid = length/2;
		while(temp!=NULL){
			counter++;
			if(counter == first_mid){
				Node *temp1, *temp2;
				if(temp->prev == NULL){
					temp1 = temp->next;
					delete temp;
					delete temp1;
					head = NULL;
					tail = NULL;
					cout<<"Process Done!"<<endl;
					break;
				}
				else{
					temp1 = temp->prev;
					temp2 = temp->next;
					temp1->next = temp->next->next;
					temp->next->next->prev = temp1;
					delete temp2;
					delete temp;
					cout<<"Process Done!"<<endl;
					break;
				}
			}
			temp = temp->next;
		}
	}
	else
	cout<<"List length is not Even."<<endl;
}
void Doubly_Linked_List::Update_Second(int v){
	if(head == NULL || head->next == NULL){
		cout<<"Second Node Does Not Exist!"<<endl;
	}
	else
		head->next->data = v;
}
void Doubly_Linked_List::Insert_At_Second(int d){
	if(head == NULL){
		cout<<"First Node does not Exist!"<<endl;
	}
	else if(head->next == NULL){
		Node *temp = new Node;
		temp->data = d;
		temp->prev = head;
		temp->next = NULL;
		head->next = temp;
		tail = temp;
	}
	else{
		Node *temp = new Node;
		temp->data = d;
		temp->prev = head;
		temp->next = head->next;
		head->next->prev = temp;
		head->next = temp;
	}
}

int main() {
	Doubly_Linked_List list;
	bool Runing = true;
	int option = 0;
	while (Runing)
	{
		system("CLS");
		cout << "\t\t\t\t-----Doubly Linked List------\n";
		cout << "\t\t\t\t1-Add Node\n";
		cout << "\t\t\t\t2-Display List\n";
		cout << "\t\t\t\t3-Delete Mid Node If List Length is Odd\n";
		cout << "\t\t\t\t4-Delete Mid Two Nodes If List Length is Even\n";
		cout << "\t\t\t\t5-Update Value of Second Node\n";
		cout << "\t\t\t\t6-Insert Node at 2nd Position\n";
		cout << "\t\t\t\t7-Exit\n";
		cout << "Enter Option: ";
		cin >> option;
		switch(option) {
		case 1:
			char option;
			do{
				int v;
				cout<<"Enter Node Value: ";
				cin>>v;
				list.add_node(v);
				cout<<"Add one more Node?(1/0): ";
				cin>>option;
			}while(option=='1');
			break;
		case 2:
			list.display();
			getch();
			break;
		case 3:
			list.del_Mid_odd();
			getch();
			break;
		case 4:
			list.del_Mid_two_even();
			getch();
			break;
		case 5:
			int va;
			cout<<"Enter Value: ";
			cin>>va;
			list.Update_Second(va);
			getch();
			break;
		case 6:
			int dat;
			cout<<"Enter Value of Node: ";
			cin>>dat;
			list.Insert_At_Second(dat);
			getch();
			break;
		default:
			Runing = false;
			cout << "Press Any key to Continue...!";
			getch();
		}
	}
	return 0;
}
