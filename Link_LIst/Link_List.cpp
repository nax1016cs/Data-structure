#include <iostream>
#include "Link_list.h"
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <typename T>
Link_List<T> ::Link_List(){
	head = NULL;
	tail = NULL;
	size = 0;
}

template <typename T>
Link_List<T> ::Link_List(const Link_List &a){
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

template <typename T>
Link_List<T> ::~Link_List(){
}

template <typename T>
int Link_List<T> ::getSize()const{
	return size;
}

template <typename T>
ostream &operator<<(ostream &output, const Link_List <T> &a){
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
}

template <typename T>
istream &operator >> (istream & input, Link_List<T> &b){
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
}



template <typename T>
const Link_List <T>   &Link_List<T> ::operator=(const Link_List <T>&a){
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
}

template <typename T>
bool Link_List<T> :: operator==(const Link_List &a) const{
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
}

template <typename T>
 T &Link_List<T>   ::operator[](int index){
	Int_Node <T>*current = head;	
	for(int i=0; i<index; i++){
		current = current->next;
	}
	return current->value;
}

template <typename T>
T Link_List<T> ::operator[](int index) const{
	Int_Node <T>*current = head;	
	for(int i=0; i<index; i++){
	current = current->next;
	}
	return current->value;
}

template <typename T>
bool Link_List<T> ::insert_node(T value){
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

}
template <typename T>
bool Link_List<T> :: insert_node(int index, T value){
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
}
template <typename T>
bool Link_List<T> ::delete_node(){
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
}
template <typename T>
bool Link_List<T> ::delete_node(int index){
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
}
