#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
using namespace std;

template <typename T>
struct Int_Node
{
	T value;
	Int_Node<T> *pre, *next;
};

template <typename T>
class Link_List
{
	template <typename U>
	friend ostream &operator<<(ostream &output, const Link_List<U> &a){
		if(a.head!=NULL){
		Int_Node <T>*current = a.head;
		for(int i=0; i<a.size; i++){
			output<< current->value<<" ";
			current = current->next;
			if(current==NULL){
				break;
			}
		}	
	}
	return output;
	}  	// print all integers in the list
	template <typename U>
	friend istream &operator>>(istream &input, Link_List<U> &b){
	if(b.head==NULL && b.tail==NULL){
		Int_Node <T>*a = new Int_Node <T>;
		a->next = NULL;
		a->pre = NULL;
		input>>a->value;
		b.head = a;
		b.tail = a;
		b.size++;
		return input;
	}
	else if(b.tail==b.head && b.tail!=NULL){
		Int_Node <T>*a = new Int_Node <T>;
		a->next=NULL;
		a->pre = b.head;
		input>> a->value;
		b.tail = a;		
		b.head->next = a;		
		b.size++;
		return input;
	}
	else{	
		Int_Node <T>*a = new Int_Node <T>;
		b.tail->next = a;
		a->next = NULL;
		input>> a->value;
		a->pre = b.tail;
		b.tail = a;
		b.size++;
		return input;
	}
}			// input a value at the back of the list, like insert_node(val);

public:
	Link_List(){
		head = NULL;
		tail = NULL;
		size = 0;
	}										// default constructor
	Link_List(const Link_List &a){
		int temp = a.getSize();
		size = temp;
		temp = 0;
		if(a.head == NULL){
			head = NULL;
			tail = NULL;
	}
	else if(a.head == a.tail){
		Int_Node <T>*temp  = a.head;		
		Int_Node <T>*b  = new Int_Node<T>;
		b->pre = NULL;
		b->next = NULL;
		b->value = temp ->value;
		head = b;
		tail = b;
		delete temp;
	}
	else{
		Int_Node <T>*current = a.head;
		Int_Node <T>*b  = new Int_Node<T>;
		Int_Node <T> *temp = NULL;		
		head = b;		
		b->pre = NULL;
		for(int i=0; i<a.getSize()-1; i++){
			b->pre = temp;
			b->value = current->value;
			Int_Node <T>*c  = new Int_Node<T>;	
			b->next=c;
			current = current->next;
			temp = b;
			b = b->next;
		}
		b->value = current->value;
		b->next = NULL;
		tail = b;
	}
}
			// copy constructor
	~Link_List(){
	}
	int getSize() const{
		return size; 
	}
	
	const Link_List &operator=(const Link_List &a){
			size = a.getSize();
	
	if(a.head == NULL){
		head = NULL;
		tail = NULL;
	}
	else if(a.head == a.tail){
		Int_Node <T>*temp  = a.head;		
		Int_Node <T>*b  = new Int_Node<T>;
		b->pre = NULL;
		b->next = NULL;
		b->value = temp ->value;
		head = b;
		tail = b;
		delete temp;
	}
	else{
		Int_Node <T>*current = a.head;
		Int_Node <T>*b  = new Int_Node<T>;
		Int_Node <T> *temp = NULL;		
		head = b;
		for(int i=0; i<a.getSize()-1; i++){
			b->pre = temp;
			temp = b;
			b->value = current->value;
			Int_Node <T>*c  = new Int_Node<T>;	
			b->next=c;
			current = current->next;
			b = b->next;
		}
		b->value = current->value;		
		b->next = NULL;
		tail = b;
	}
	}		// assignment operator
	bool operator==(const Link_List &a) const{
		Int_Node <T>*current1 = head;
	Int_Node <T>*current2 = a.head;
	if(size!=a.size){
		return false;
	}
	for(int i=0; i<a.getSize(); i++){
		if(current1->value!=current2->value){
			return false;
		}
		current1 = current1->next;
		current2 = current2->next;
	}
	return true;
	}		// equality operator
	bool operator!=(const Link_List &right) const		// inequality operator
	{
		return !(*this == right);
	}

	T &operator[](int index){
			Int_Node <T>*current = head;	
	for(int i=0; i<index; i++){
		current = current->next;
	}
	return current->value;
	}							// subscript operator for non-const objects
	T operator[](int index) const{
			Int_Node <T>*current = head;	
	for(int i=0; i<index; i++){
	current = current->next;
	}
	return current->value;
	}						// subscript operator for const objects

	bool insert_node(T value){
		if(head==NULL && tail==NULL){
		Int_Node <T>*a = new Int_Node<T>;
		a->next = NULL;
		a->pre = NULL;
		a->value = value;
		head = a;
		tail = a;
		size++;
		return true;
	}
	else if(tail==head && tail!=NULL){
		Int_Node <T>*a = new Int_Node<T>;
		a->next=NULL;
		a->pre = head;
		a->value = value;
		tail = a;		
		head->next = a;		
		size++;
		return true;
	}
	else{	
		Int_Node <T>*a = new Int_Node<T>;
		tail->next = a;
		a->next = NULL;
		a->value = value;
		a->pre = tail;
		tail = a;
		size++;
		return true;
	}
	}							// insert an integer at the back of link list
	bool delete_node(){
			if(head==NULL){
		return false;
	}
	else if(tail == head){
		head = NULL;
		tail = NULL;
		size = 0;
		return true;
	}
	else{
		Int_Node <T> *p,*q;
		p = head;
		while (p->next->next!=NULL){
			p = p->next;
		}
		q = p->next;
		p->next = NULL;
		tail = p;		
		size = size -1;
		tail = p;
		return true;
	}
	}								// delete the last node
	bool insert_node(int index, T value){
		if(index==0){
		Int_Node <T>*a = new Int_Node<T> ;
		a->value = value;
		a->pre = NULL;
		a->next = head;
		head = a;
		size++;
		return true;
	}
	else if(index==size){
		Int_Node <T>*a = new Int_Node<T>;
		tail->next = a;
		a->next = NULL;
		a->value = value;
		a->pre = tail;
		size++;
		tail = a;
		return true;
	}
	else{
		Int_Node <T>*current = head;
		for(int i =0; i<index-1 ;i++){
			current = current->next;
		}
		Int_Node <T>*store = current->next;
		Int_Node <T>*b = new Int_Node<T> ;
		current->next = b;
		b->pre = current;
		b->value = value;
		b->next = store;
		store->pre = b;
		size++;
		return true;
	}
	}				// insert an integer after the i_th position
	bool delete_node(int index){
			if(index==0){
		Int_Node <T>*current = head->next;
		head = current;
		head->pre = NULL;
		size--;
		return true;
	}
	if((index+1)==size){
		delete_node();
	}
	else{
		Int_Node <T>*current = head;
		for(int i=0; i<index; i++){
			current = current->next;
		}
		Int_Node <T>*temp = current->next;
		Int_Node <T>*temp2 = current->pre;
		delete current;	
		temp2->next = temp;
		if(temp!=NULL){
			temp->pre = temp2;
		}
		size--;
		return true;
	}
	}					// delete the i_th node

private:
	int size;
	Int_Node<T> *head, *tail;								// pointer to the first and the last element of Link_List
};


#endif // LINK_LIST
