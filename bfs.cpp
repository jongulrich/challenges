#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;


typedef struct Node
{
  int data;
  Node *left;
  Node *right;
} Node;


Node* newNode(int data) 
{ 
	// Allocate memory for new node  
	Node* node = (Node*)malloc(sizeof(Node)); 

	// Assign data to this node 
	node->data = data; 

	// Initialize left and right children as NULL 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 


queue<int> bfs(Node* node)
{
	queue<int> finalq;
	queue<Node*> activeq;
	Node* root = node;
	Node* cur = root;
	
	finalq.push(cur->data);
	
	while (cur != NULL)
	{
		if (cur->left != NULL )
		{
			activeq.push(cur->left);
			finalq.push(cur->left->data);
		}
		if (cur->right != NULL )
		{
			activeq.push(cur->right);
			finalq.push(cur->right->data);
		}
		
		free(cur);
		cur = NULL;
		cur = activeq.front();
		activeq.pop();
	}
	
	return finalq;
}

/*
BFS
		100
	 50, 	 200
  25,   75,      350
  
desired result: 100, 50, 200, 25, 75, 350
*/
int main (int argc, char** argv)
{

	Node* root = newNode(100);
	Node* tmp = root;
	root->left = newNode(50);
	root->right = newNode(200);
	tmp = root->left;
	tmp->left = newNode(25);
	tmp->right = newNode(75);
	tmp = root->right;
	tmp->right = newNode(350);
	
	
	queue<int> myqueue = bfs(root);
    while (myqueue.front())
    {
    	cout << myqueue.front() << " ";
    	myqueue.pop();
    }
    cout << endl;
    
    return 0;

}
