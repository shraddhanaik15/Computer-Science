#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int degree;
	int data;
	struct node *child, *parent, *sibling;
};
struct node* H = NULL;

struct node* MakeBinomialHeap()
{
	struct node* np;
	 np = NULL;
	return np;
}

struct node* CreateNode(int k)
{
	struct node* p;
	p = (struct node*)malloc(sizeof(struct node));
	p->data = k;
	return p;
}

int Binomial_heap_link(struct node* y, struct node* z)
{
	y->parent = z;
	y->sibling = z->child;
	z->child = y;
	z->degree = z->degree +1;
}

struct node* Binomial_Heap_Merge(struct node* H1, struct node* H2)
{
	struct node *H;
	H = MakeBinomialHeap();
	struct node* y;
	struct node* z;
	struct node* a;
	struct node* b;
	y = H1;
	z = H2;
	if(y!=NULL)
	{
		if(z!=NULL && (y->degree <= z->degree))
		{
			H=y;
		}
		else if(z!=NULL && y->degree > z->degree)
		{
			H = z;
		}
		else
			H=y;
	}
	else
		H = z;
		while(y!=NULL && z!=NULL)
		{
			if(y->degree < z->degree)
			{
				y = y->sibling;
			}
			else if(y->degree == z->degree)
			{
				a = y->sibling;
				y->sibling = z;
				y = a;
			}
			else
			{
				b = z->sibling;
				z->sibling = y;
				z=b;
			}
		}
		return H;
}

struct node* Binomial_Heap_Union(struct node* H1, struct node* H2)
{
	struct node* prev_x;
	struct node* next_x;
	struct node* x;
	struct node* H;
	H = MakeBinomialHeap();
	H = Binomial_Heap_Merge(H1,H2);
	if(H==NULL)
	{
		return H;
	}
		prev_x = NULL;
		x = H;
		next_x = x->sibling;
	while(next_x!= NULL)
	{
		if((x->degree != next_x->degree)||(next_x->sibling !=NULL && x->degree == (next_x->sibling)->degree))
		{
			prev_x = x;
			x = next_x;
		}
		else
		{
			if(x->data <= next_x->data)
			{
				x->sibling = next_x->sibling;
				Binomial_heap_link(next_x, x);
			}
			else
			{
				if(prev_x == NULL)
				{
					H = next_x;
				}
				else
				{
					prev_x->sibling=next_x;
				}
					Binomial_heap_link(x, next_x);
					x = next_x;
				
			}
		}
		next_x = x->sibling;

	}
	return H;
}

struct node* Binomial_Heap_Insert(struct node* H, struct node* x)
{
	struct node* H1;
	H1 = MakeBinomialHeap();
	x->parent = NULL;
	x->sibling = NULL;
	x->child = NULL;
	x->degree = 0;
	H1 = x;
	H = Binomial_Heap_Union(H,H1);
	return H;
}

int display(struct node* H)
{
	struct node* p;
	if(H==NULL)
		return 0;
	p = H;
	while(p!=NULL)
	{
		printf("%d\t", p->data);
		display(p->child);
		p=p->sibling;
	}
		
}



int main()
{
	int i, n, m, choice;
	struct node* np;
	H=NULL;
	do
	{
		printf("1.Insert Element\n2.Display\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("\nEnter no of elements\n");
					scanf("%d", &n);
					printf("\nEnter the elements\n");
					for(i=1;i<=n;i++)
					{
						scanf("%d", &m);
						np = CreateNode(m);
						H = Binomial_Heap_Insert(H, np);
					}
					break;
			case 2: display(H);
					printf("\n");
					break;
		}
	}
	while(choice!=3);

	return 1;
}
