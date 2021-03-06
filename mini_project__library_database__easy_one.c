//library management system
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>

void insertnode();
void deletenode();
void searchnode();
void view();
int menu();

struct books
{
	int serialnumber, studentid;
	char bookname[20], issuedby[20];
	struct books*link;
};
struct books*start = NULL;
struct books*createnode() //making node
{
	struct books*n;
	n = (struct books*)malloc(sizeof(struct books));
	return(n);
}
void insertnode()//inserting node
{
	struct books*temp, *t;
	temp = createnode();
	printf("Enter information about the book\n");
	printf("Enter book serial number - ");
	scanf_s("%d", &temp->serialnumber);
	fflush(stdin);
	printf("Enter student ID - ");
	scanf_s("%d", &temp->studentid);
	printf("Student name - ");
	fflush(stdin);
	scanf_s("\n");
	gets(temp->issuedby);
	printf("Enter book name - ");
	fflush(stdin);
	scanf_s("\n");
	gets(temp->bookname);
	printf("\nPress Anything to continue\n");
	temp->link = NULL;
	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		t = start;
		while (t->link != NULL)
		{
			t = t->link;
		}
		t->link = temp;
	}
}

void searchnode()//linearsearch
{
	//seraching from serial of book
	struct books *t;
	int sno;
	t = start;
	if (start==NULL)
	{
		printf("No books in the system\n");
		return 0;
	}
	printf("Enter book Serial number - ");
	scanf_s("%d", &sno);
	if (start->link == NULL)
	{
		printf("Serial Number\t");
		printf("Student ID\t");
		printf("Student Name\t");
		printf("Book name\t");
		printf("\n");
		printf("%d\t", start->serialnumber);
		printf("\t%d\t", start->studentid);
		printf("\t%s\t", start->issuedby);
		printf("\t%s\t", start->bookname);
		printf("\n");
	}
	else
	{
		while (t->link != NULL)
		{
			if (sno == t->serialnumber)
			{
				printf("Serial Number\t");
				printf("Student ID\t");
				printf("Student Name\t");
				printf("Book name\t");
				printf("\n");
				printf("\t%d\t", t->serialnumber);
				printf("\t%d\t", t->studentid);
				printf("\t%s\t", t->issuedby);
				printf("\t%s\t", t->bookname);
				printf("\n");
				return 0;
			}
			t = t->link;
		}
		printf("Search unsuccessfull Book not found\n");
	}
	printf("\nPress anything to continue");
}
void deletenode()//deleting books/node
{
	struct books *del, *viewdel, *prev, *temp;
	int sno;
	printf("Enter Book serial number which you want to return - ");
	scanf_s("%d", &sno);
	if (start == NULL)//no book in database
	{
		printf("No books are in the system\n");
		return 0;
	}
	else if (start->serialnumber == sno)//node next to start
	{
		viewdel = start;
		printf("\nBook with serialnumber %d retured\n", viewdel->serialnumber);
		del = start;
		start = start->link;
		free(del);//freeing memory
		return 0;
	}
	temp = start;
	prev = temp;
	while (temp != NULL && temp->serialnumber != sno)//looking for previous node of node to be deleted to deleted
	{
		prev = temp;
		temp = temp->link;
	}
	if (temp == NULL)//serial number not in database
	{
		printf("No book with serial number %d is present in the database\n", sno);
		return;
	}
	prev->link= temp->link;
	free(temp);//freeing memory
	free(prev);//freeing memory
	printf("Book returned successfully\n");
	printf("\nPress anything to continue");
}
void view()//display database
{
	struct books*node;
	if (start == NULL)//no books
	{
		printf("No Books in the database\n");
	}
	else
	{
		node = start;
		printf("\n\t\tLibary Managment System\n");
		printf("Serial Number\t");
		printf("Student ID\t");
		printf("Student Name\t");
		printf("Book name\t");
		printf("\n");
		while (node != NULL)
		{
			printf("%d\t", node->serialnumber);
			printf("\t%d\t", node->studentid);
			printf("\t%s\t", node->issuedby);
			printf("\t%s\t", node->bookname);
			printf("\n");
			node = node->link;
		}
	}
	printf("\nPress anything to continue");
}
int menu()//choices
{
	int choice;
	printf("\t\t\t###########################################################################");
  printf("\n\t\t\t############                                                   ############");
  printf("\n\t\t\t############      Library management System Project in C       ############");
  printf("\n\t\t\t############                                                   ############");
  printf("\n\t\t\t###########################################################################");
  printf("\n\t\t\t---------------------------------------------------------------------------\n");
  printf("\n\t\t\t----------------------------------------------------------------------------");
	printf("\n\n\n\n");
  printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
  printf("\n\t\t\t\t       =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=        ");
  printf("\n\t\t\t\t       =                 WELCOME                   =        ");
  printf("\n\t\t\t\t       =                   TO                      =        ");
  printf("\n\t\t\t\t       =             Mayank and Ayush              =        ");
  printf("\n\t\t\t\t       =                 LIBRARY                   =        ");
	printf("\n\t\t\t\t       =                MANAGEMENT                 =        ");
  printf("\n\t\t\t\t       =                 SYSTEM                    =        ");
  printf("\n\t\t\t\t       =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=        ");
  printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
  printf("\n\n\n\n");
  //printf("Welcome to Mayank and Ayush Libary Managment System\n");
	printf("Choose from the below options-:\n\n");
	printf("To issue book\t\t    Enter 1\n");
	printf("Return book\t\t    Enter 2\n");
	printf("Search for an issued book   Enter 3\n");
	printf("Display all issused books   Enter 4\n");
	printf("To exit\t\t\t    Enter 5\n");
	printf("\n\nEnter your choice: ");
	scanf_s("%d", &choice);
	return choice;
}
int main()
{
	while (1)
	{
		switch (menu())
		{
		case 1:
			insertnode();
			break;
		case 2:
			deletenode();
			break;
		case 3:
			searchnode();
			break;
		case 4:
			view();
			break;
		case 5:
			printf("\nThank You for visting\n");
			exit(0);
		default:
			printf("Wrong choice\n");
			exit(1);
		}
		_getch();
		system("cls");
	}
	_getch();
	return 0;
}