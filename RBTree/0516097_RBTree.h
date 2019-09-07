#ifndef RBTREE
#define RBTREE
#include <iostream>
using namespace std;
class RBTree{
		struct item{
		int key;
		string gender;
		int color; 
		int height;
		int weight;
		item * left;
		item * right;
		item * parent;
		};
	public:
		RBTree();
		~RBTree();
   		bool insert(int key, string gender,int height, int weight);
		RBTree &operator [](int key);
		string getGender();
		int getWeight();
		int getHeight();
    	void LeftRotation(item *current);
    	void RightRotation(item *current);
    	void InsertFixedUpRBT(item *current);

	private:
		item* ptr;
		item* root;
		item* null;
};

#endif
