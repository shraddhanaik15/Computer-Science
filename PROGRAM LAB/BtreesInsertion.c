//BTREES INSERTION

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAX 3
#define true 1
#define false 0

int count;
struct BtreeNode
{
	int keys[MAX];
	int t;
	struct BtreeNode *c[MAX+1];
	int n;
	int leaf;
};

typedef struct BtreeNode BTreeNode;
BTreeNode *Root = NULL;


// Function to traverse all nodes in a subtree rooted with this node 
void traverse(BTreeNode *currN) 
{ 
     count++;
    // There are n keys and n+1 children, traverse through n keys 
    // and first n children 
    int i=0; 
    //printf("curn %d = %d n\n",count,currN->n);
    for (i = 0; i < currN->n; i++) 
    { 
        // If this is not leaf, then before printing key[i], 
        // traverse the subtree rooted with child C[i]. 
        if (currN->leaf == false)
        {
            traverse(currN->c[i]);
			printf(" %d ",currN->keys[i]); 
        }
        else
		{
        printf(" %d ",currN->keys[i]);
		}
    } 
  
    // Print the subtree rooted with last child 
    if (currN->leaf == false) 
	{
        traverse(currN->c[i]); 
	}
    
} 
  

void splitChild(int i,BTreeNode *y,BTreeNode *newroot)
{

	// Create a new node which is going to store (t-1) keys OF Y
   struct BtreeNode *z = (struct BtreeNode *)malloc(sizeof(struct BtreeNode));
   // printf("nodecreated\n");
    z->t = y->t;
	z->leaf = y->leaf;
	int rt = ((newroot->t)+1)/2;
    z->n = rt-1; 
  
    // Copy the last (t-1) keys of y to z
	int j; 
    for (j = 0; j < rt-1; j++) 
        z->keys[j] = y->keys[j+rt];

    // Copy the last t children of y to z 
    if (y->leaf == false) 
     { 
        for (j = 0; j < rt; j++) 
            z->c[j] = y->c[j+rt]; 
    } 
    // Reduce the number of keys in y 
    y->n = rt - 1; 
  
    // Since this node is going to have a new child, 
    // create space of new child 
    for (j = newroot->n; j >= i+1; j--) 
    {
		//printf("parentkeyshift\n");
        newroot->c[j+1] = newroot->c[j]; 
    }
  
    // Link the new child to this node 
    newroot->c[i+1] = z; 
  
    // A key of y will move to this node. Find the location of 
    // new key and move all greater keys one space ahead 
    for (j = (newroot->n)-1; j >= i; j--) 
        newroot->keys[j+1] = newroot->keys[j]; 
  
    // Copy the middle key of y to this node 
    newroot->keys[i] = y->keys[rt-1]; 
  
  //printf("keyroot %d",newroot->keys[i]);
    // Increment count of keys in this node 
    newroot->n = (newroot->n) + 1; 
    //printf("count of splitc")
}

void insertNonFull(int k,BTreeNode *y)
{

	int j = y->n;
	int i = j-1;
	if(y->leaf == true)
	{
		// The following loop does two things 
        // a) Finds the location of new key to be inserted 
        // b) Moves all greater keys to one place ahead 
        while (i >= 0 && y->keys[i] > k) 
        { 
            y->keys[i+1] = y->keys[i]; 
            i--; 
        } 
         // Insert the new key at found location 
        y->keys[i+1] = k; 
    	y->n = j+1; 
	}
	else // If this node is not leaf 
    { 
     // Find the child which is going to have the new key 
        while (i >= 0 && y->keys[i] > k) 
            i--; 
  
        // See if the found child is full
		int h = y->t; 
        if (y->c[i+1]->n == h) 
        { 
            // If the child is full, then split it 
            splitChild(i+1,y->c[i+1],y); 
            // After split, the middle key of C[i] goes up and 
            // C[i] is splitted into two.  See which of the two 
            // is going to have the new key 
            if (y->keys[i+1] < k) 
                i++; 
        } 
        insertNonFull(k,y->c[i+1]); // If root is not full, call insertNonFull for root 
    } 
} 

void Insert(int k)
{
	
	if(Root == NULL)
	{
		Root = (BTreeNode *)malloc(sizeof(BTreeNode));
		Root->t = MAX;
		Root->leaf = true;
		Root->keys[0] = k;
		Root->n = 1;
	}
	else //if root already made
	{
		if(Root->n== MAX)//if node is full
		{
			struct BtreeNode *s ;
			s = (struct BtreeNode *)malloc(sizeof(struct BtreeNode));
			s->t = MAX;
			s->leaf = false;
			s->n = 0;
			s->c[0] = Root;
			splitChild(0,Root,s);
			// New root has two children now.  Decide which of the 
            // two children is going to have new key 
            int i = 0; 
            if (s->keys[0] < k) 
            {
                i++; 
            }
        	insertNonFull(k,s->c[i]); 
           // Change root 
           Root = s; 
		}

		else 
        {
			insertNonFull(k,Root); 
		}
	}
}

int main()
{
	int ele;
	int choice,val;
   
    do
    {
        printf("\n1.Insert node in Btree.\n2.Display Btree.\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter key value\n");
                    scanf("%d",&val);
                    Insert(val);
                    break;
            case 2: printf("Btree formed\n");
                    traverse(Root);
                    break;
        }
   
    }
    while(choice!=3); 
	return 0;
}
