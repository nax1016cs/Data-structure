#include "RBTree.h"
#include <iostream>
using namespace std;

RBTree::RBTree(){
  		null = new item;   
        null->color = 1;        
        null->key = 0;
        root = null;           
        root->parent = null;
}

RBTree:: ~RBTree(){
}

bool RBTree::insert(int key, string gender, int height, int weight){

    item *y = null;
    item *x = root;
    item *current = root;
    item *insert = new item;
    insert->key = key;
    insert->gender = gender;
    insert->height = height;    
	insert->weight = weight; 
	while(current !=null){
		if(key> current->key){
			current  = current->right;
		}
		else if(key< current->key){
			current = current->left;
		}
		else if(key == current->key){
			return false;
		}
	}
    while (x != null) {     
        y = x;
        if (insert->key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }

    insert->parent = y;

    if (y == null){
        this->root = insert;
    }
    else if (insert->key < y->key){
        y->left = insert;
    }
    else{
        y->right = insert;
    }
    

    insert->left = null;
    insert->right = null;
    insert->color = 0;             
        
    InsertFixedUpRBT(insert);      
    return true;
}

void RBTree::InsertFixedUpRBT(item *current){


    while (current->parent->color == 0) { 


        if (current->parent == current->parent->parent->left) { 
            item *uncle = current->parent->parent->right;
 
            if (uncle->color == 0) {
                current->parent->color = 1;
                uncle->color = 1;
                current->parent->parent->color = 0;             
                current = current->parent->parent;
            }
          
            else {  
                if (current == current->parent->right){     
                    current = current->parent;
                    LeftRotation(current);
                }
          
                current->parent->color = 1;                      
                current->parent->parent->color = 0;            
                RightRotation(current->parent->parent);
            }
        }
   
        else {  
            item *uncle = current->parent->parent->left;
      
            if (uncle->color == 0) {
                current->parent->color = 1;
                uncle->color = 1;
                current->parent->parent->color = 0;         
                current = current->parent->parent;
            }
          
            else {
                if (current == current->parent->left) {    
                    current = current->parent;
                    RightRotation(current);
                }
      
                current->parent->color = 1;
                current->parent->parent->color = 0;
                LeftRotation(current->parent->parent);
            }
        }
    }
    root->color = 1;    
}

void RBTree::LeftRotation(item *x){

    item *y = x->right;        

    x->right = y->left;       

    if (y->left != null){          
        y->left->parent = x;       
    }

    y->parent = x->parent;            

    if (x->parent == null){            
        root = y;          
    }         
    else if (x == x->parent->left){ 
        x->parent->left = y;        
    }
    else{                                
        x->parent->right = y;      
    }
    y->left = x;                   
    x->parent = y;                     
}


void RBTree::RightRotation(item *y){

    item *x = y->left;           

    y->left = x->right;         
    if (x->right != null){           
        x->right->parent = y;
    }
    x->parent = y->parent;                
                                        
    if (y->parent == null){              
        root = x;          
    }              
    else if (y == y->parent->left){ 
        y->parent->left = x;         
    }
    else{                                 
        y->parent->right = x;       
    }
    x->right = y;                   
    y->parent = x;                       
}

RBTree & RBTree ::operator[](int key){
	ptr=root;
	while(key!=ptr->key){
		if(key>ptr->key){
			ptr = ptr->right;
		}
		else{
			ptr = ptr->left;
		}
	}
	return *this;
}

string RBTree::getGender(){
	return ptr->gender;
}

int RBTree::getHeight(){
	return ptr->height;
}

int RBTree::getWeight(){
	return ptr->weight;
}



