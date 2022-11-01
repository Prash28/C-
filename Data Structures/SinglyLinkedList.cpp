#include<iostream>
using namespace std;

class Node{ 			//Class representing a Node
	public:
		int key; 		//unique value that can be used to identify a node from other nodes.
		int data; 		//Data/value stored in a node.
		Node* next; 	//next stores the address of the next node in the linked lisr.
		
		Node(){  		//constructor
			key=0;
			data=0;
			next=NULL;
		}
		node(int k,int d){ 		//parameterized constructor
			key=k;
			data=d;
		}
};

class SinglyLinkedList{ 		//Class for the linked list.
	public:
		Node* head; 			//head is a pointer containing the address of the first node of the linked list.
		
		SinglyLinkedList(){ 	//constructor: here the head node points to NULL.
			head=NULL;
		}
		SinglyLinkedList(Node *n){ 			//parameterized constructor: here the address of first node is passed as parameter.
			head = n;
		}
		
		//1. Function to check whether the passed Key value is present in the linked list.
		Node* nodeExists(int k){ 
			Node* temp = NULL; 				//temp is a pointer initially pointing to NULL. 
			
			//This 'temp' pointer is used to store the address of the node having the required Key i.e which was passed as parameter
			//If the key is not found in the entire list, then the temp pointer will be pointing to NULL
			
			Node* ptr = head; 	//ptr is a pointer that stores the same address as the head pointer.
			while(ptr!=NULL) 	//Loop for traversing through the linked list.
			{
				if(ptr->key == k){ 	//if key value of the node the ptr pointer points currently to has the desired key.
					temp = ptr; 	//storing the address of the node in temp pointer.
				}
				ptr = ptr->next; 	//making the ptr pointer point to the next node in in the list.
			}
			return temp; 			//returning temp pointer which is of Node type. if key not found, NULL is returned.
		}
		
		//2. Append a node to a list.
		void appendNode(Node *n){
			if(nodeExists(n->key)!=NULL){ 	//checking if already the key exists, using the previously created function.
				cout<<"Node already exists with key value:"<<n->key<<", Append another node with different Key value"<<endl;
			}
			else{
				if(head == NULL){ //if the linked list is empty, we point the head pointer to this node which was passed as parameter.
					head = n;   //making the head point to the new node.
					cout<< "Node appended.";
				}
				else{
					Node *ptr = head; 		//creating a pointer ptr which points to the node same as the head pointer.
					
					//traversing the linked list until we reach the last node whose next will point to NULL.
					while(ptr->next != NULL){ 		//checking if node is pointing to any other node or NULL.
						ptr = ptr->next; 			//if pointing to a node, we will traverse to that node.
					}
					ptr->next = n;
					cout<<"Node Appended"<<endl;
				}
			}
		}
		
		//3. Prepend Node.
		void prependNode(Node* n){
			if(nodeExists(n->key)!=NULL){ 		//checking if already the key exists, using the previously created function.
				cout<<"Node already exists with key value:"<<n->key<<", Append another node with different Key value"<<endl;
			}
			else{
				n->next = head; 		//Prepend function is simple. just have to point the head node to the new node.
				head = n; 				//and point the next of new node to the initial first node.
				cout<<"Node Prepended"<<endl;
			}
		}
		
		/*4. Insert a node after a particular node in the list.
			 (key value is provided of the node after which we need to insert new node). */
		
		void insertNodeAfter(int k, Node* n){ 	//first argument is key as said above; 2nd argument is the new node to be inserted.
			Node *ptr = nodeExists(k); //storing the address of the node having the key 'k' in the pointer ptr.
			if(ptr==NULL){
				cout<<"No node exists with key value: "<<k<<endl; //if no node having 'k' as key exists.
			}
			else{
				if(nodeExists(n->key)!=NULL){ 		//checking if already the key of new node exists.
					cout<<"Node already exists with key value:"<<n->key<<", Append another node with different Key value"<<endl;
				}
				else{
					//here, new node is n.
					//ptr is pointing to the node after which we are inserting the new node.
					n->next = ptr->next; 		//storing next of node(pointed by ptr) in next of the new node.
					ptr->next = n; 			    //storing address of new node in next of node pointed by ptr.
				}
		}
	}
	
	//5. Delete Node by Key.
	
	void deleteNodeByKey(int k){ 			//passing key of the node to be deleted as paramater 
		if(head == NULL){			    //if the linked list is empty.    
			cout<<"Singly Linked List already empty. Can't delete"<<endl;
		}
		else if(head != NULL){
				if(head->key == k){ 			//if first node contains the key k, it is to be deleted.
					head = head->next; 			//storing the address of second node in head.
					cout<<"Node unlinked with key value: "<<k<<endl;
				}
				else{
					Node* temp = NULL;
					Node* prevptr = head; //points to the head node.
					Node* currentptr = head->next; //pointing to the node next to the header.
					while(currentptr != NULL){	   //traversing the linked list	.
						if(currentptr->key ==k){  //checking each node whether it has the desired key 'k'.
							temp = currentptr;    //storing the address of the node in temp pointer.
							currentptr = NULL; 	  //making currentptr as NULL to come out of the loop.
						}    
						else{
							prevptr = prevptr->next;  //if the current node doesnt have the key 'k', we move on to next next nodes.
							currentptr = currentptr->next; 
						}
					}
					/*   Once the node with key k is found i.e once the above loop breaks, the pointers 'currentptr' and 
						     'prevptr' point to the node to be deleted and it's previous node respectively.      */
						     
					if(temp!=NULL){  
						prevptr->next = temp->next; 		//linking the deleted node's previous node and next node.
						cout<<"Node Unlinked with key values: "<<k<<endl;
					}
					else{
						//temp will be NULL if a node with key 'k' doesn't exist.
						cout<<"Node doesn't exist with key value: "<<k<<endl; 
					}
				}
		}
	}
	//6. Update node
  void updateNodeByKey(int k, int d) { 			//passing the key of the node and the data to be updated with.

    Node * ptr = nodeExists(k); 				//checking whether the node with given key 'k' exists.
    if (ptr != NULL) {  
      ptr -> data = d; 							//updating the data of the node with data that was passed in the function.
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;  //if node with key 'k' not found.
    }

  }

  //7. Printing
  void printList() {
    if (head == NULL) {  				//if the linked list is empty.
      cout << "No Nodes in Singly Linked List";
    } else {
      cout << endl << "Singly Linked List Values : ";
      Node * temp = head;				//creating a temporary pointer pointing to first node initially.

      while (temp != NULL) {			///traversing through the linked list.
        cout << "(" << temp -> key << "," << temp -> data << ") --> ";
        temp = temp -> next;
      }
    }

  }

};

int main()
{
  SinglyLinkedList s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node(); /* dynamic memory allocation; new node is created in the Heap memory and n1 is a pointer to the object,
    						   not actually that object. This created node will be destroyed when the switch case statement loops
							   any no. of times. */
    
	//Node n1; 
	/*  if the node is using the above statement, when one loop completes, the created node will be destroyed, and a new node
		will be created in the next loop. */
    
	switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      s.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNodeByKey(key1, data1);

      break;
    case 6:
      s.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);
	
	return 0;
}
