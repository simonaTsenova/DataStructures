/**
*
* Implementation of Template Binary Search Tree DS
* With a method to BUILD BST from given array
* @author Simona Tsenova
* @compiler VC
*
*/

#pragma once
#ifndef BST_H
#define BST_H

#include "DynamicArray.h"

template <typename Type>
struct TreeNode {
	Type data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(Type data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	TreeNode(Type data, TreeNode* left, TreeNode* right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

template <class Type>
class BST
{
private:
	TreeNode<Type>* root;

	//Helping functions that are called from the public ones
	void insert(const Type& data, TreeNode<Type>* parent);

	TreeNode<Type>* search(const Type& data, TreeNode<Type>* parent);
	bool remove(const Type& data, TreeNode<Type>*& node);

	//Returns the minimum node in node's left subtree
	TreeNode<Type>* findMinNode(TreeNode<Type>* node);

	//Recursively builds the tree from given array and elements index
	void buildTree(const DynamicArray<Type>& array, int start, int end);

	//Used in the destructor to destroy all nodes of the tree
	void destroyTree(TreeNode<Type>* root);

public:
	BST();
	~BST();

	//Function that inserts a new node to the tree
	void insert(const Type& data);

	//Function that searches for a node of type Type in the tree
	TreeNode<Type>* search(const Type& data);

	//Function that removes an element from the tree
	void remove(const Type& data);

	//Function that creates a perfectly balanced tree from a given sorted dynamic array
	void createTree(DynamicArray<Type>& array);

	TreeNode<Type>* getRoot();
};

#endif // !1

