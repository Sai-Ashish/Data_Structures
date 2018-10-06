#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

void inorder(struct node *node)
{
	if (node!=NULL)
	{
		inorder(node->left);
		printf("%d\n",node->key);
		inorder(node->right);
	}
}

void preorder(struct node *node)
{
	if (node!=NULL)
	{
		printf("%d\n",node->key);
		preorder(node->left);
		preorder(node->right);
	}
}

void postorder(struct node *node)
{
	if (node!=NULL)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d\n",node->key);
	}
}


struct node* newnode(int key)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> key = key;
	temp->left=temp->right=NULL;
	return temp;
}

struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
   	if(root== NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

struct node* insert(struct node* node,int key){
	
	// root is null 
	if (node == NULL)
		return newnode(key);

	// Key is greater than root's key
	else if(key> node->key)
		 node->right = insert(node->right, key);  
	
	// Key is smaller than root's key
	else
		 node->left = insert(node->left, key); 

	return node;
}

struct node* delete(struct node* node,int key)
{
	if (node==NULL){
		return node;
	}
	if(key>(node->key))

		node->right=delete(node->right,key);

	else if(key<(node->key))

		node->left =delete(node->left ,key);

	else
	{
		if (node->left==NULL)
		{
			struct node* temp= node->right;
			free(node);
			return temp;
		}
		else if (node->left==NULL)
		{
			struct node* temp= node->left;
			free(node);
			return temp;
		}
		else
		{
			struct  node* temp = node->right;
			while(temp->left!=NULL){
				temp=temp->left;
			}
			node->key=temp->key;
			node->right=delete(node->right,temp->key);
		}
	}return node;
}
