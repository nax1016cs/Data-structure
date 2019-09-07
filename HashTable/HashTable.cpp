#include <iostream>
#include <cstdlib>
#include <string >
#include "HashTable.h"
using namespace std;

HashTable::HashTable(){
	for(int i =0; i<9973; i++){
		Hashtable[i] = new item;
		Hashtable[i]->key = "empty";
		Hashtable[i]->gender = "empty";
		Hashtable[i]->height = -1;
		Hashtable[i]->weight = -1;	
		Hashtable[i]->next = NULL;									
	}
	ptr = Hashtable[0];
}

HashTable::~HashTable(){
}

int HashTable::hash(string key){
	int index=0;
	int temp;
	int i=0;
	for( i=0; i<key.length(); i++){
		temp = key[i];
		index = index + 3*pow(temp,4);
	}
	index = index   % 9973;
	return index;
}


HashTable & HashTable :: operator[](string key){
	int index;
	index =  hash(key);
	ptr = Hashtable[index];
	while(ptr->key !=key){
		ptr= ptr->next;
	}
	return *this;
}

void HashTable::addItem(string key,string gender, int height, int weight){

	int index = hash(key);
	
	if(Hashtable[index]->key == "empty"){
		Hashtable[index]->key = key;
		Hashtable[index]->gender = gender;
		Hashtable[index]->height = height;
		Hashtable[index]->weight = weight;
	}
	else{
		ptr = Hashtable[index];
		item* n = new item ;
		n->key = key;
		n->gender = gender;
		n->height = height;
		n->weight = weight;
		n->next = NULL;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = n;
		
	}
}

string HashTable::getGender(){
	return ptr->gender;
} 

int HashTable::getHeight(){
	return ptr->height;
}

int HashTable::getWeight(){
	return ptr->weight;
}

