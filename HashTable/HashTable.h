#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <cstdlib>
#include <string >
#include <math.h> 
#include <iostream>
using namespace std;


class HashTable{
	public:
		HashTable();
		~HashTable();
		int hash(string key);
		void addItem(string key,string gender, int height, int weight);
		HashTable &operator [](string key);
		string getGender();
		int getHeight();
		int getWeight();
	private:
		struct item{
		string key;
		string gender;
		int height;
		int weight;
		item *next;
		};
		item* ptr;
		item* Hashtable[9973];
		
};

#endif
