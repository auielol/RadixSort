#include "main.h"

int main()
{
	printf("\n*-*-* SEARCH LIST *-*-*\n");
	
	menu();
}

int menu()
{
	int select;
	
	printf("\n[1] CREATE NEW LIST");
	printf("\n[2] DISPLAY LIST");
	printf("\n[3] SORT LIST");
	printf("\n[4] EXIT\n");
	
	printf("\nSELECTION: ");
	scanf("%d", &select);
	
	getSelection(select);
}

int getSelection(int select)
{
	int key;
	
	switch (select)
	{
		case 1:
			{
				system("cls");
				
				createList();
				
				printf("\nLIST CREATION SUCCESSFUL\n");
				
				break;
			}
		case 2:
			{
				system("cls");
				
				displayList();
				break;
			}
		case 3:
			{
				system("cls");
				
				radixSort();
				
				break;
			}
		case 4:
			{
				system("cls");
				
				printf("\nEXITING PROGRAM\n");
				
				return 0;
			}
		default:
			{
				printf("INVALID INPUT");
				return menu();
			}
	}
	
	return menu();
}

void createList()
{
	struct node *newNode, *temp;
    int data, i, count = 0;
    
    head = (struct node *)malloc(sizeof(struct node));
    
    time_t t;
	srand((unsigned) time(&t));
	
	data = rand() %101;

    head->data = data;
    head->next = NULL;

    temp = head;

    for(i=2; i <= 10; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            
            break;
        }
        else
        {
            data = rand() %101;

            newNode->data = data;
            newNode->next = NULL;

            temp->next = newNode;
            temp = temp->next; 
        }
    }
}

void radixSort()
{
    int i, k, digit, leastSig, mostSig, pass;
      
    struct node *rear[10], *front[10], *p;
    
    pass = 0;
    
    leastSig = 1;
      
    mostSig = maxDig(head);
    
    if (head == NULL)
    {
    	printf("\nLIST IS NOT CREATED\n");
	}
    else
    {
    	printf("\n*-*-* SORT TRAVERSAL *-*-*");
    
    	for(k = leastSig; k <= mostSig; k++)
    	{
    		printf("\n");
    		display();
    		
    		if (pass == 0)
    		{
    			printf("|| Unsorted List");
			}
			else
			{
				printf("|| Pass %d", pass);
			}
    	
    		for(i = 0; i <= 9; i++)
    		{
        		rear[i] = NULL;
        		front[i] = NULL;
    		}
        
    		for(p = head; p != NULL; p = p->next)
    		{
        		digit = findDig(p->data, k);
            
        		if(front[digit] == NULL) 
        		{
            		front[digit] = p;
        		}
        		else
        		{
            		rear[digit]->next = p;
        		}
        		rear[digit] = p;
   			}
            
        	i = 0;
            
        	while(front[i] == NULL)
        	{
            	i++;
        	}
            
        	head = front[i];
        
        	while(i < 9) 
        	{
            if(rear[i + 1] != NULL)
            {
                rear[i]->next = front[i + 1];
            }
            else
            {
                rear[i + 1] = rear[i];
            }
            i++;
        	}
        	rear[9]->next = NULL;
        
        	pass++;
    	}
    
    printf("\n");
    display();
    printf("|| Pass %d\n", pass);
	}
}

int maxDig()
{
	int temp = 0, digit = 0;
	
    struct node *p = head;
      
    while(p != NULL)
    {
        if(p ->data > temp)
        {
            temp = p->data;
        }
        p = p->next ;
    }
    while(temp != 0)
    {
        digit++;
        temp = temp / 10;
    }
    return(digit);
}

int findDig(int number, int k)
{
    int term, i;
    
    for(i = 1; i <= k; i++)
    {
        term = number % 10;
        number = number / 10;
    }
    return(term);
}

bool search(int key)
{
	int location = 1;
	
	struct node *temp = head;
	
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			printf("\nDATA FOUND ON NODE %d\n", location);
			
			return true;
		}
		
		temp = temp->next;
		location++;
	}
	
	return false;
}

void display()
{
	struct node *temp;
	
	temp = head;
	
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void displayList()
{
	int count = 1;
	
	struct node *temp;
	
	if(head == NULL)
    {
        printf("\nList is empty.\n");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data %d = %d\n", count, temp->data);
            temp = temp->next;
            
            count++;
        }
    }
}
