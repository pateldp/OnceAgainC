#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct entry{
	int value;
	int key;
};

struct entry *array;
int capacity=5;
int size=0;

int hashtable(int key)
{
	return (key % capacity);
}
int chk_prime(int n)
{
	if(n % 2 == 0)
	{
		n++;
	}
	for(;!if_prime(n);n+=2);
	return n;
}

int if_prime(int n)
{
	int i;
	if(n==1 || n==0)
	{
		return 0;
	}
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
void init_array()
{
	int i;
	capacity = chk_prime(capacity);
	array= (struct entry*)malloc(capacity * sizeof(struct entry));
	for(i=0;i<capacity;i++)
	{
		array[i].key=0;
		array[i].value=0;
	}
}
void insert_key(int key)
{
	int index= hashtable(key);
	if(array[index].value==0)
	{
		array[index].key=key;
		array[index].value=1;
		size++;
		printf("\n Entered key (%d) \n", key);
	}
	else if(array[index].key==key)
	{
		printf("\n already present key (%d) \n",key);
		array[index].value += 1;
	}
	else
	{
		printf("\n key not added\n");
	}

}
void del_element(int key)
{
	int index = hashtable(key);
	if(array[index].value==0)
	{
		printf("\n key does not exist\n");
	}
	else
	{
		array[index].key=0;
		array[index].value=0;
		size--;
		printf("\n key (%d) deleted\n",key);
	}
}
void display()
{
	int i;
	for(i=0;i<capacity;i++)
	{
		if(array[i].value == 0)
		{
			printf("\n Array[%d] has no element \n",i);
		}
		else
		{
			printf("\n Array[%d] has elements:\n key(%d) and value(%d) \t",i,array[i].key,array[i].value);
		}
	}
}
int size_of_hashtable()
{
	return size;
}

void main()
{
	int choice,key,value,n,c;;
	//clrscr();

	init_array();
	do
	{
		printf("\n Implementation of hash table in C \n\n");
		printf("MENU: \n1.Inserting item in the Hash table"
				"\n2.Removing item from the Hash table"
				"\n3.check the size of hash table"
				"\n4.Display a Hash table"
				"\n\n Please enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Inserting element in hash table\n");
			       printf("enter key: \t");
			       scanf("%d",&key);
			       insert_key(key);
			       break;
			case 2:printf("Deleting in hash table\n Enter the key to delete: ");
			       scanf("%d",&key);
			       del_element(key);
			       break;
			case 3:n=size_of_hashtable();
			       printf("size of Hash tble is: %d\n",n);
			       break;
			case 4:display();
				break;

			default: printf("wrong input\n");	       
		}
		printf("\n Do you want to contiune: (press 1)\t");
		scanf("%d",&c);

	}while(c==1);
//	getc();
}
