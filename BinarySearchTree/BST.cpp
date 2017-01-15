/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Simona Tsenova
* @idnumber 61946
* @task 4
* @compiler VC
*
*/

#include "stdafx.h"
#include <iostream>
#include "BST.h"
using namespace std;

template <class Type>
BST<Type>::BST()
{
	this->root = NULL;
}

template <class Type>
BST<Type>::~BST()
{
	destroyTree(this->root);
}

template<class Type>
void BST<Type>::insert(const Type& data)
{
	//Adds new node to the tree
	if (this->root != NULL)
	{
		insert(data, this->root);
	}
	//If the tree is empty, create a root node
	//and assign data
	else
	{
		this->root = new TreeNode<Type>(data);
	}
}
template <class Type>
TreeNode<Type>* BST<Type>::search(const Type& data)
{
	//Recursively searching the tree for data
	//starting from the root (top down)
	return search(data, this->root);
}

template <class Type>
void BST<Type>::remove(const Type& data)
{
	//Recursively searching the tree for data
	//and removing it if found
	remove(data, this->root);
}

template<class Type>
void BST<Type>::insert(const Type& data, TreeNode<Type>* parent)
{
	//If data object is smaller than parent node's data
	//search down the left subtree to insert the new data there
	if (parent->data > data)
	{
		//If left child is null, add the new node as parent's left child
		if (parent->left == NULL)
		{
			parent->left = new TreeNode<Type>(data);
		}
		//If left child is not null, go down its left subtree to insert the data
		else
		{
			insert(data, parent->left);
		}
	}
	//If data object is larger than parent node's data
	//search down the right subtree to insert the new data there
	else if (parent->data < data)
	{
		//If right child is null, insert new data as right child
		if (parent->right == NULL)
		{
			parent->right = new TreeNode<Type>(data);
		}
		//If right child is not null
		//search down the right subtree to insert the new node there
		else
		{
			insert(data, parent->right);
		}
	}
}

//Returns the node where data is found at
//or NULL if such node is not found
template <class Type>
TreeNode<Type>* BST<Type>::search(const Type& data, TreeNode<Type>* parent)
{
	if (parent == NULL)
	{
		return NULL;
	}
	else
	{
		if (data == parent->data)
		{
			return parent;
		}
		//If data is smaller than parent's data
		//search in the left subtree for the searched data
		else if (data < parent->data)
		{
			return search(data, parent->left);
		}
		//If data is larger than parent's data
		//search in the right subtree for the searched data
		else if (data > parent->data)
		{
			return search(data, parent->right);
		}
	}
}

template<class Type>
TreeNode<Type>* BST<Type>::findMinNode(TreeNode<Type>* node)
{
	TreeNode<Type>* min = node;
	
	//Search down for the minimum node of the left subtree
	//until a leaf is reached
	while (min->left != NULL)
	{
		min = min->left;
	}

	return min;
}

template <class Type>
bool BST<Type>::remove(const Type& data, TreeNode<Type>*& node)
{
	if (node == NULL)
	{
		return false;
	}
	//If data is smaller than node's data
	//the data to be removed is in the left subtree
	else if (data < node->data)
	{
		return remove(data, node->left);
	}
	//If data is larger than node's data
	//the data to be removed is in the right subtree
	else if (data > node->data)
	{
		return remove(data, node->right);
	}
	//If node is the current element 
	//of the tree to be removed
	else if (data == node->data)
	{
		//Node is leaf
		if (node->left == NULL && node->right == NULL)
		{
			delete node;
			node = NULL;
		}
		//Node has 1 child
		else if (node->left == NULL)
		{
			//Create temporary node to point to the current node
			TreeNode<Type>* temp = node;
			//Assign current node with its right child
			node = node->right;
			//Delete temporary node
			delete temp;
		}
		else if (node->right == NULL)
		{
			TreeNode<Type>* temp = node;
			node = node->left;
			delete temp;
		}
		//Node has 2 children
		else
		{
			//Find the minimum element of the node's right child's left subtree
			//and assign a temporary node to point to the element
			TreeNode<Type>* min = findMinNode(node->right);
			//Assign node's data to the minimum element's data
			node->data = min->data;
			//Recursively remove the minimum node found
			//which is either a leaf or a 1 child node
			return remove(min->data, node->right);
		}

	}
	return true; //Last if case doesn't have a return type
}

template<class Type>
TreeNode<Type>* BST<Type>::getRoot()
{
	return this->root;
}

//The array from the arguments must be sorted
//so to build a binary search tree.
template<class Type>
void BST<Type>::buildTree(const DynamicArray<Type>& array, int start, int end)
{
	if (start > end)
	{
		return;
	}

	//Find middle element in array's position
	int middle = (start + end) / 2;

	//Insert miidle element in the tree
	insert(array[middle]);

	//Recursively build subtree from the left part of the array
	buildTree(array, start, middle - 1);
	//Recursively build subtree from the right part of the array
	buildTree(array, middle + 1, end);
}

template<class Type>
void BST<Type>::destroyTree(TreeNode<Type>* root)
{
	if (root->left != NULL)
	{
		destroyTree(root->left);
	}
	if (root->right != NULL)
	{
		destroyTree(root->right);
	}
	delete root;
	root = NULL;
}

template<class Type>
void BST<Type>::createTree(DynamicArray<Type>& array)
{
	int size = array.getUsedElements() - 1;
	buildTree(array, 0, size);
}
