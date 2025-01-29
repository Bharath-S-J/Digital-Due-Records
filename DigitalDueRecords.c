#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>



/*
* Digital Due Records
* Author: Bharath S J
* Description: A digital ledger system for managing customer dues and store records
*/




/*
* Digital Due Records
* 
* Function Documentation:
*
* Authentication:
* authenticateUser() - Handles user login and first-time password setup
* resetPassword() - Allows changing the admin password
* recoverPassword() - Main menu for password recovery options
* recoverByColor() - Recover password using security question about color
* recoverByCar() - Recover password using security question about car
* recoverByFlower() - Recover password using security question about flower
* recoverByBank() - Recover password using security question about bank
*
* Record Management:
* addDueRecord() - Add a new customer due payment record
* deleteDueRecord() - Remove a customer's due record
* viewAllRecords() - Display all customer due records
* getRecordStats() - Show total records and sum of due amounts
* updateCustomerRecord() - Update a customer's payment or details
* updateAllCustomerDetails() - Update all information for a customer
* updateStoreDetails() - Modify store information
*
* Search Functions:
* searchRecords() - Menu for different search options
* searchByName() - Search customer records by name (admin)
* searchCustomerByName() - Search records by name (customer view)
* searchCustomerByDate() - Search records by date (customer view)
* viewRecordsByDate() - View all records for a specific date
*
* Sort Functions:
* sortRecords() - Menu for different sorting options
* sortByCustomerName() - Sort records alphabetically by customer name
* sortByDueAmount() - Sort records by amount due
* sortByDate() - Sort records by date
*
* Navigation:
* menu() - Main admin menu interface
* customerMenu() - Main customer menu interface
*
* Data Structure Helpers:
* displayLinkedRecords() - Display records stored in linked list
* addToLinkedList() - Add a record to the linked list structure
*/

int access = 2;
typedef struct customer
{
	char name[20];
	int duepayment, total;
	char date[15];
	char things_bought[100];
	char phonenumber[15];
	char time[10];
	struct customer *next;
} customer;

customer *head = NULL;

typedef struct passwd
{
	char password[10];
	char fav_color[10];
	char fav_car[10];
	char fav_flowers[10];
	char first_credit_card[10];
} passwd;

typedef struct storedetails
{
	char storename[30];
	char address[100];
	char num[15];

} storedetails;

void menu();
void authenticateUser();
void recoverPassword();
void deleteDueRecord(char name[]);
void resetPassword();
void sortRecords();
void customerMenu();
int main();
void addDueRecord();
void searchByName();
void updateAllCustomerDetails(char name[]);
void updateCustomerRecord();
void deleteDueRecord(char name[]);
void getRecordStats();
void displayLinkedRecords();
void addToLinkedList(char nam[], char dat[], char tim[], char pho[], int tot, int due, char thing[]);
void viewAllRecords();
void sortByDueAmount();
void sortByCustomerName();
void sortByDate();
void viewRecordsByDate();
void updateStoreDetails();
void searchRecords();
void resetPassword();
void authenticateUser();
void recoverByColor();
void recoverByCar();
void recoverByFlower();
void recoverByBank();
void searchCustomerByName();
void searchCustomerByDate();
void customerMenu();

// refract this function for best optimal code with less complexity
void addDueRecord()
{
	int temp1, temp2, i, j, temp3;
	char name1[20], things_bought1[40], temp4[20], temp5[10];
	char k = 'y';
	customer *c;
	storedetails s;
	FILE *bh, *bill, *store;

	c = (customer *)calloc(1, sizeof(customer));

	do
	{

		int num1, num2, num3 = 0;

		system("cls");
		system("color 6f");
		bh = fopen("DueCustomers.txt", "a+");

		printf("\n\t\t\t\t\t\t--------ADDING DUE RECORD IS IN PROCESS !!!!-----------\n\n\n\n");

		time_t t;
		time(&t);
		char *tim = ctime(&t);

		c->time[0] = tim[11];
		c->time[1] = tim[12];
		c->time[2] = tim[13];
		c->time[3] = tim[14];
		c->time[4] = tim[15];
		c->time[5] = '\0';

		c->date[0] = tim[8];
		c->date[1] = tim[9];
		c->date[2] = tim[10];
		c->date[3] = tim[4];
		c->date[4] = tim[5];
		c->date[5] = tim[6];
		c->date[6] = tim[7];
		c->date[7] = tim[20];
		c->date[8] = tim[21];
		c->date[9] = tim[22];
		c->date[10] = tim[23];
		c->date[11] = '\0';

		printf("\n\t\t\t Enter The Name Of The Customer : ");
		scanf(" %[^\n]s", name1);

		printf("\n\t\t\t Enter The Phone Number Of The Customer : ");
		scanf(" %[^\n]s", c->phonenumber);
		for (int i = 0; i < 10; i++)
		{
			if (c->phonenumber[i] >= '0' && c->phonenumber[i] <= '9')
			{
			}
			else
			{
				num3 = 1;
			}
		}
		while (strlen(c->phonenumber) != 10 || num3 != 0)
		{
			num3 = 0;
			printf("\n\t\t\t The Phone Number is Incorrect Try Again: ");
			printf("\n\t\t\t Enter The Phone Number Of The Customer : ");
			scanf(" %[^\n]s", c->phonenumber);
			for (int i = 0; i < 10; i++)
			{
				if (c->phonenumber[i] >= '0' && c->phonenumber[i] <= '9')
				{
				}
				else
				{
					num3 = 1;
				}
			}
		}
		printf("\n\t\t\t Enter What He/She bought : ");
		scanf(" %[^\n]s", things_bought1);

		printf("\n\t\t\t Enter The Total Amount : ");
		scanf(" %d", &c->total);

		printf("\n\t\t\t Enter The Amount Paid : ");
		scanf(" %d", &temp2);

		c->duepayment = c->total - temp2;
		for (k = 0; things_bought1[k] != '\0'; k++)
		{
			c->things_bought[0] = toupper(things_bought1[0]);
			if (name1[k - 1] == ' ')
			{
				c->things_bought[k] = toupper(things_bought1[k]);
				c->things_bought[k - 1] = things_bought1[k - 1];
			}
			else
				c->things_bought[k] = things_bought1[k];
		}
		c->things_bought[k] = '\0';

		for (j = 0; name1[j] != '\0'; j++)
		{
			c->name[0] = toupper(name1[0]);
			if (name1[j - 1] == ' ')
			{
				c->name[j] = toupper(name1[j]);
				c->name[j - 1] = name1[j - 1];
			}
			else
				c->name[j] = name1[j];
		}
		c->name[j] = '\0';

		store = fopen("store.txt", "r");
		bill = fopen(c->name, "w");

		while (fread(&s, sizeof(storedetails), 1, store))
		{

			fprintf(bill, "\n\t\t%s", s.storename);
			fprintf(bill, "\n\t\t-------------------------------------------------------------");
			fprintf(bill, "\n\t\tADDRESS : %s", s.address);
			fprintf(bill, "\n\t\t-------------------------------------------------------------");
			fprintf(bill, "\n\t\tPH NO   : %s", s.num);
			fprintf(bill, "\n\t\t-------------------------------------------------------------");
			fprintf(bill, "\n\n\t\tNAME           	: %s", c->name);
			fprintf(bill, "\n\t\tDATE             : %s", c->date);
			fprintf(bill, "\n\t\tTIME             : %s", c->time);
			fprintf(bill, "\n\t\tTHINGS BOUGHT    : %s", c->things_bought);
			fprintf(bill, "\n\t\tTOTAL AMOUNT     : %d", c->total);
			fprintf(bill, "\n\t\tAMOUNT PAID NOW  : %d", temp2);
			fprintf(bill, "\n\t\tREMAINING AMOUNT : %d", c->duepayment);
			fprintf(bill, "\n\n\t\t-----------------------------------------------------------");
			fprintf(bill, "\n\n\t\tTHANK YOU FOR CHOOSING OUR STORE");

			printf("\n\n\t\t\tBILL GENERATED IN THE NAME OF THE CUSTOMER AS BELOW\n\n\n");

			printf("\n\t\t%s", s.storename);
			printf("\n\t\t-------------------------------------------------------------");
			printf("\n\t\tADDRESS : %s", s.address);
			printf("\n\t\t-------------------------------------------------------------");
			printf("\n\t\tPH NO   : %s", s.num);
			printf("\n\t\t-------------------------------------------------------------");
			printf("\n\n\t\tNAME           	: %s", c->name);
			printf("\n\t\tDATE             : %s", c->date);
			printf("\n\t\tTIME             : %s", c->time);
			printf("\n\t\tTHINGS BOUGHT    : %s", c->things_bought);
			printf("\n\t\tTOTAL AMOUNT     : %d", c->total);
			printf("\n\t\tAMOUNT PAID NOW  : %d", temp2);
			printf("\n\t\tREMAINING AMOUNT : %d", c->duepayment);
			printf("\n\n\t\t-----------------------------------------------------------");
			printf("\n\n\t\tTHANK YOU FOR CHOOSING OUR STORE");

			strcpy(temp4, c->name);
			temp3 = c->duepayment;
		}
		fclose(store);
		fclose(bill);

		printf("\n\n\t\t\tBILL GENERATED IN THE NAME OF THE CUSTOMER ");

		fwrite(c, sizeof(customer), 1, bh);
		fclose(bh);

		printf("\n\n\n\n\t\t\t Do You Want To Add Another Record (y/n)");

		if (temp3 <= 0)
		{
			deleteDueRecord(temp4);
		}

	} while (getch() == 'y');
	menu();
}

void searchByName()
{

	int j;
	char name1[20], name2[20];
	char choice = 'y';
	customer c1;
	FILE *bh;
	system("color 9f");

	do
	{
		int found = 0;
		system("cls");

		printf("\n\t\t--------VIEWING DUE COSTOMER RECORD BY SEARCHING NAME!!!!-----------\n\n\n");
		printf("\n\n\t\tEnter Name Of The Costomer to Search : ");
		scanf(" %[^\n]c", name1);

		for (j = 0; name1[j] != '\0'; j++)
		{
			name2[0] = toupper(name1[0]);
			if (name1[j - 1] == ' ')
			{
				name2[j] = toupper(name1[j]);
				name2[j - 1] = name1[j - 1];
			}
			else
				name2[j] = name1[j];
		}
		name2[j] = '\0';

		bh = fopen("DueCustomers.txt", "r");

		while (fread(&c1, sizeof(customer), 1, bh))
		{

			if (strcmp(c1.name, name2) == 0)
			{
				found = 1;
				printf("\n\t\tNAME                YYYY MM DD     TIME      PHO-NU          TOTAL     DUE AMOUNT    THINGS BOUGHT                           \n\n");
				printf("\n\t\t%-20s%-15s%-10s%-15s", c1.name, c1.date, c1.time, c1.phonenumber);
				printf("%-10d%-15d%-40s", c1.total, c1.duepayment, c1.things_bought);
			}
		}

		if (found == 0)
		{

			system("cls");
			printf("\n\n\t\t------------------ERROR--------------------");
			printf("\n\n\t\tName Of the Costomer  Not Found.....\n\n\n");
			printf("\n\n\t\tThe Costomer name is Wrong!\n\t\tELSE\n\t\tThe Costomer have Cleard the Due Amount!");
		}

		fclose(bh);
		printf("\n\n\n\n\t\tDo you want to Search Again (y/n)");

	} while (getch() == 'y');
	menu();
}

void updateAllCustomerDetails(char name[])
{

	FILE *f1, *f2, *f3, *f4;
	customer c1;
	storedetails s;
	int amount1, amount2, temp, found, num1, num2;
	char thingsbought[50];
	system("cls");

	f1 = fopen("DueCustomers.txt", "r");
	f2 = fopen("temp.txt", "w");

	while (fread(&c1, sizeof(customer), 1, f1))
	{
		if (strcmp(c1.name, name) == 0)
		{

			found = 1;
			fflush(stdin);
			printf("\n\t\t-----------UPDATING THE COSTOMER RECORD BY SEARCHING NAME!!!!-----------\n\n\n\n");
			printf("\n\t\t\tThe Costomer Name is %s : ", c1.name);
			printf("\n\t\t\tThe Total Amount is %d : ", c1.total);
			printf("\n\t\t\tThe Due Amount is %d : ", c1.duepayment);

			time_t t;
			time(&t);
			char *tim = ctime(&t);

			c1.time[0] = tim[11];
			c1.time[1] = tim[12];
			c1.time[2] = tim[13];
			c1.time[3] = tim[14];
			c1.time[4] = tim[15];
			c1.time[5] = '\0';

			c1.date[0] = tim[8];
			c1.date[1] = tim[9];
			c1.date[2] = tim[10];
			c1.date[3] = tim[4];
			c1.date[4] = tim[5];
			c1.date[5] = tim[6];
			c1.date[6] = tim[7];
			c1.date[7] = tim[20];
			c1.date[8] = tim[21];
			c1.date[9] = tim[22];
			c1.date[10] = tim[23];
			c1.date[11] = '\0';

			printf("\n\t\t\t Enter What He/She bought : ");
			scanf(" %[^\n]s", thingsbought);
			strcat(c1.things_bought, " | ");
			strcat(c1.things_bought, thingsbought);

			printf("\n\t\t\t Enter The Total Amount For New Things Bought Now : ");
			scanf("%d", &amount1);

			printf("\n\t\t\t The Amount Paid Now : ");
			scanf("%d", &amount2);

			temp = c1.duepayment;
			c1.duepayment = c1.duepayment + (amount1 - amount2);
			c1.total = c1.total + amount1;

			f3 = fopen("store.txt", "r");
			f4 = fopen(c1.name, "w");

			while (fread(&s, sizeof(storedetails), 1, f3))
			{
				fprintf(f4, "\n\t\t%s", s.storename);
				fprintf(f4, "\n\t\t-------------------------------------------------------------");
				fprintf(f4, "\n\t\tADDRESS : %s", s.address);
				fprintf(f4, "\n\t\t-------------------------------------------------------------");
				fprintf(f4, "\n\t\tPH NO   : %s", s.num);
				fprintf(f4, "\n\t\t-------------------------------------------------------------");
				fprintf(f4, "\n\n\t\tNAME                    : %s", c1.name);
				fprintf(f4, "\n\t\tDATE                     : %s", c1.date);
				fprintf(f4, "\n\t\tTIME                     : %s", c1.time);
				fprintf(f4, "\n\t\tTHINGS BOUGHT            : %s", c1.things_bought);
				fprintf(f4, "\n\t\tTOTAL AMOUNT             : %d", c1.total);
				fprintf(f4, "\n\t\tPREVIOUS DUE AMOUNT      : %d", temp);
				fprintf(f4, "\n\t\tAMOUNT PAID NOW          : %d", amount2);
				fprintf(f4, "\n\t\tUPDATED REMAINING AMOUNT : %d", c1.duepayment);
				fprintf(f4, "\n\n\t\t-----------------------------------------------------------");
				fprintf(f4, "\n\n\t\tTHANK YOU FOR CHOOSING OUR STORE");

				printf("\n\n\t\t\tBILL GENERATED IN THE NAME OF THE CUSTOMER AS BELOW\n\n\n");

				printf("\n\t\t%s", s.storename);
				printf("\n\t\t-------------------------------------------------------------");
				printf("\n\t\tADDRESS : %s", s.address);
				printf("\n\t\t-------------------------------------------------------------");
				printf("\n\t\tPH NO   : %s", s.num);
				printf("\n\t\t-------------------------------------------------------------");
				printf("\n\n\t\tNAME                    : %s", c1.name);
				printf("\n\t\tDATE                     : %s", c1.date);
				printf("\n\t\tTIME                     : %s", c1.time);
				printf("\n\t\tTHINGS BOUGHT            : %s", c1.things_bought);
				printf("\n\t\tTOTAL AMOUNT             : %d", c1.total);
				printf("\n\t\tPREVIOUS DUE AMOUNT      : %d", temp);
				printf("\n\t\tAMOUNT PAID NOW          : %d", amount2);
				printf("\n\t\tUPDATED REMAINING AMOUNT : %d", c1.duepayment);
				printf("\n\n\t\t-----------------------------------------------------------");
				printf("\n\n\t\tTHANK YOU FOR CHOOSING OUR STORE");
			}
			fclose(f3);
			fclose(f4);
		}
		fwrite(&c1, sizeof(customer), 1, f2);
	}
	fclose(f1);
	fclose(f2);

	if (found)
	{
		f1 = fopen("DueCustomers.txt", "w");
		f2 = fopen("temp.txt", "r");
		while ((fread(&c1, sizeof(customer), 1, f2)) > 0)
		{
			fwrite(&c1, sizeof(customer), 1, f1);
		}
		fclose(f1);
		fclose(f2);
	}
	printf("\n\n\n\t\t\tPress any Key For Menu");
	getch();
	menu();
}

void updateCustomerRecord()
{
	int temptotal;
	int i, j, found = 0, amount, updatedamount, predueamount;
	char name1[20], name2[20], tempthings[100];
	;
	char billdate[15], billtime[10];
	customer c1;
	storedetails s;
	FILE *bh, *bh1, *bill, *store;
	system("color 1f");

	do
	{
		int num1, num2;
		found = 0;
		system("cls");
		printf("\n\t\t-----------UPDATING THE COSTOMER RECORD BY SEARCHING NAME!!!!-----------\n\n\n\n");
		printf("\t\t---------Enter Name Of The Costomer to Search : ");
		scanf(" %[^\n]s", name1);

		for (j = 0; name1[j] != '\0'; j++)
		{
			name2[0] = toupper(name1[0]);
			if (name1[j - 1] == ' ')
			{
				name2[j] = toupper(name1[j]);
				name2[j - 1] = name1[j - 1];
			}
			else
				name2[j] = name1[j];
		}
		name2[j] = '\0';

		bh = fopen("DueCustomers.txt", "r");
		bh1 = fopen("temp.txt", "w");

		while (fread(&c1, sizeof(customer), 1, bh))
		{

			if (strcmp(c1.name, name2) == 0)
			{

				found = 1;
				fflush(stdin);

				printf("\n\t\t\tThe Costomer Name is %s : ", c1.name);
				printf("\n\t\t\tThe Total Amount is %d : ", c1.total);
				printf("\n\t\t\tThe Due Amount is %d : ", c1.duepayment);
				printf("\n\n\n\t\t\t1) Update Only Amount ");
				printf("\n\t\t\t2) Update Every thing");

				if (getch() == '2')
				{
					updateAllCustomerDetails(c1.name);
				}
				printf("\n\n\t\t\tEnter The Amount Paid now : ");
				scanf("%d", &amount);
				predueamount = c1.duepayment;
				updatedamount = c1.duepayment - amount;
				strcpy(name1, c1.name);
				system("cls");
				c1.duepayment = updatedamount;
				temptotal = c1.total;

				time_t t;
				time(&t);
				char *tim = ctime(&t);

				c1.time[0] = tim[11];
				c1.time[1] = tim[12];
				c1.time[2] = tim[13];
				c1.time[3] = tim[14];
				c1.time[4] = tim[15];
				c1.time[5] = '\0';
				strcpy(billtime, c1.time);

				c1.date[0] = tim[8];
				c1.date[1] = tim[9];
				c1.date[2] = tim[10];
				c1.date[3] = tim[4];
				c1.date[4] = tim[5];
				c1.date[5] = tim[6];
				c1.date[6] = tim[7];
				c1.date[7] = tim[20];
				c1.date[8] = tim[21];
				c1.date[9] = tim[22];
				c1.date[10] = tim[23];
				c1.date[11] = '\0';

				strcpy(billdate, c1.date);

				strcpy(tempthings, c1.things_bought);
				if (updatedamount > 0)
				{
					printf("\n\n\t\t-----------DUE AMOUNT IS UPDATED-----------\n");
					printf("\n\n\t\tThe Amount Of the Costomer having a Name : %s has been Updated", c1.name);
					printf("\n\n\t\tThe Amount had to be paid is %d ", updatedamount);
				}
			}
			fwrite(&c1, sizeof(customer), 1, bh1);
		}
		fclose(bh);
		fclose(bh1);

		if (found)
		{
			bh = fopen("DueCustomers.txt", "w");
			bh1 = fopen("temp.txt", "r");
			while ((fread(&c1, sizeof(customer), 1, bh1)) > 0)
			{
				fwrite(&c1, sizeof(customer), 1, bh);
			}
			fclose(bh);
			fclose(bh1);
		}

		if (found != 0)
		{

			if (updatedamount <= 0)
			{
				printf("\n\n\t\t-----------------------DUE AMOUNT IS UPDATED-----------------------\n");
				printf("\n\n\t\t----------CONGRATULATIONS THE  DUE AMOUNT HAVE BEEN CLEARED--------\n");
				printf("\n\n\n\t\tBy the Costomer Named : %s ", name1);
				printf("\n\n\t\tThe Due Record Of The Costomer Named : %s Will be Deleted ", name1);
				if (updatedamount < 0)
				{
					printf("\n\n\n\t\tPlease Return %d rupees \n\t\tback to the Costomer Named : %s", -(updatedamount), name1);
				}
				deleteDueRecord(name1);
			}
			store = fopen("store.txt", "r");
			bill = fopen(name1, "w");

			printf("\n\n\t\t\tBILL GENERATED IN THE NAME OF THE CUSTOMER AS BELOW\n\n\n");

			while (fread(&s, sizeof(storedetails), 1, store))
			{
				fprintf(bill, "\n\t\t%s", s.storename);
				fprintf(bill, "\n\t\t-------------------------------------------------------------");
				fprintf(bill, "\n\t\tADDRESS : %s", s.address);
				fprintf(bill, "\n\t\t-------------------------------------------------------------");
				fprintf(bill, "\n\t\tPH NO   : %s", s.num);
				fprintf(bill, "\n\t\t-------------------------------------------------------------");
				fprintf(bill, "\n\n\t\tNAME                   	: %s", name1);
				fprintf(bill, "\n\t\tDATE                     : %s", billdate);
				fprintf(bill, "\n\t\tTIME                     : %s", billtime);
				fprintf(bill, "\n\t\tTHINGS BOUGHT            : %s", tempthings);
				fprintf(bill, "\n\t\tTOTAL AMOUNT             : %d", temptotal);
				fprintf(bill, "\n\t\tPREVIOUS DUE AMOUNT      : %d", predueamount);
				fprintf(bill, "\n\t\tAMOUNT PAID NOW          : %d", amount);
				fprintf(bill, "\n\t\tUPDATED REMAINING AMOUNT : %d", updatedamount);
				fprintf(bill, "\n\n\t\t-----------------------------------------------------------");
				fprintf(bill, "\n\n\t\tTHANK YOU FOR CHOOSING OUR STORE");

				printf("\n\t\t%s", s.storename);
				printf("\n\t\t-------------------------------------------------------------");
				printf("\n\t\tADDRESS : %s", s.address);
				printf("\n\t\t-------------------------------------------------------------");
				printf("\n\t\tPH NO   : %s", s.num);
				printf("\n\t\t-------------------------------------------------------------");
				printf("\n\n\t\tNAME                   	: %s", name1);
				printf("\n\t\tDATE                     : %s", billdate);
				printf("\n\t\tTIME                     : %s", billtime);
				printf("\n\t\tTHINGS BOUGHT            : %s", tempthings);
				printf("\n\t\tTOTAL AMOUNT             : %d", temptotal);
				printf("\n\t\tPREVIOUS DUE AMOUNT      : %d", predueamount);
				printf("\n\t\tAMOUNT PAID NOW          : %d", amount);
				printf("\n\t\tUPDATED REMAINING AMOUNT : %d", updatedamount);
				printf("\n\n\t\t-----------------------------------------------------------");
				printf("\n\n\t\tTHANK YOU FOR CHOOSING OUR STORE");
			}
			fclose(store);
			fclose(bill);
		}

		if (found == 0)
		{

			system("cls");
			printf("\n\t\t----Name Of the Due Costomer  Not Found.....\n\n\n");
			printf("\n\t\tThe Costomer name is Wrong!\n\t\tELSE\n\t\tThe Costomer have Cleard the Due Amount!");
		}
		printf("\n\n\n\t\t\tDo you want to Update For Another Costomer (y/n)");
	} while (getch() == 'y');
	menu();
}

void deleteDueRecord(char name[])
{

	int found = 0;
	char *k = name;
	customer c1;
	FILE *bh, *bh1;
	bh = fopen("DueCustomers.txt", "r");
	bh1 = fopen("temp.txt", "w");

	while (fread(&c1, sizeof(customer), 1, bh))
	{
		if (strcmp(c1.name, k) == 0)
		{
			found = 1;
		}
		else
			fwrite(&c1, sizeof(customer), 1, bh1);
	}

	fclose(bh);
	fclose(bh1);

	if (found == 1)
	{
		bh = fopen("DueCustomers.txt", "w");
		bh1 = fopen("temp.txt", "r");
		while (fread(&c1, sizeof(customer), 1, bh1))
		{
			fwrite(&c1, sizeof(customer), 1, bh);
		}
		fclose(bh);
		fclose(bh1);
		printf("\n\n\n\t\tThe Due Record Of This Costomer is Deleted Successfully\n");
	}
}

void getRecordStats()
{

	int total = 0, i, j, n1;
	customer c1, *c;
	FILE *bh;
	system("cls");
	system("color 5f");
	printf("\n\t\t--------VIEWING NUMBER OF  DUE COSTOMERS AND TOTAL DUE PAYMENT !!!!-----------\n\n\n");
	bh = fopen("DueCustomers.txt", "r");
	if (bh == NULL)
	{
		printf("\n\n\n\t\tYOU HAVE NOT ADDED ANY RECORD PLEASE ADD BEFORE VIEWING \n\n\n");
		printf("\t\t-----press any key for menu------");
		getch();
		menu();
	}

	fseek(bh, 0, SEEK_END);
	int n = ftell(bh) / sizeof(customer);

	printf("\n\n\t\tNo of due costomers = %d\n", n);
	fclose(bh);

	bh = fopen("DueCustomers.txt", "r");
	fseek(bh, 0, SEEK_END);

	n1 = ftell(bh) / sizeof(customer);
	rewind(bh);

	c = (customer *)calloc(n1, sizeof(customer));
	for (i = 0; i < n1; i++)
		fread(&c[i], sizeof(customer), 1, bh);
	fclose(bh);

	for (i = 0; i < n1; i++)
	{
		total = total + c[i].duepayment;
	}
	printf("\n\t\tThe total Due Amount By All The Costomers is : %d", total);
	printf("\n\n\n\n\t\t-----------PRESS ANY KEY FOR MENU-------------\n");
	getch();
	menu();
}

void displayLinkedRecords()
{

	customer *c1;
	c1 = head;
	printf("\n\t\tNAME                YYYY MM DD     TIME      PHO-NU         TOTAL     DUE AMOUNT    THINGS BOUGHT                           \n\n");
	while (c1 != NULL)
	{
		printf("\n\t\t%-20s%-15s%-10s%-15s", c1->name, c1->date, c1->time, c1->phonenumber);
		printf("%-10d%-15d%-40s", c1->total, c1->duepayment, c1->things_bought);
		c1 = c1->next;
	}
}

void addToLinkedList(char nam[], char dat[], char tim[], char pho[], int tot, int due, char thing[])
{
	customer *ne, *ptr;
	ne = (customer *)calloc(1, sizeof(customer));
	strcpy(ne->name, nam);
	strcpy(ne->date, dat);
	strcpy(ne->time, tim);
	strcpy(ne->phonenumber, pho);
	strcpy(ne->things_bought, thing);
	ne->duepayment = due;
	ne->total = tot;
	ne->next = NULL;
	if (head == NULL)
	{
		head = ne;
	}
	else
	{
		ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = ne;
	}
}

void viewAllRecords()
{

	customer c1;
	FILE *bh;
	system("cls");
	system("color 5f");
	printf("\n\t\t-------------VIEWING DUE RECORD IS IN PROCESS !!!!-------------\n\n\n");
	bh = fopen("DueCustomers.txt", "r");
	if (bh == NULL)
	{
		printf("\n\n\n\t\tYOU HAVE NOT ADDED ANY RECORD PLEASE ADD BEFORE VIEWING \n\n\n");
		printf("\t\t-----press any key for menu------");
		getch();
		menu();
	}
	printf("\n\t\tNAME                YYYY MM DD     TIME      PHO-NU         TOTAL     DUE AMOUNT    THINGS BOUGHT                           \n\n");
	while (fread(&c1, sizeof(customer), 1, bh))
	{
		printf("\n\t\t%-20s%-15s%-10s%-15s", c1.name, c1.date, c1.time, c1.phonenumber);
		printf("%-10d%-15d%-40s", c1.total, c1.duepayment, c1.things_bought);
	}
	fclose(bh);

	printf("\n\n\n\n\t\t----------PRESS ANY KEY FOR MENU------------\n");
	getch();
	menu();
}

void sortByDueAmount()
{

	free(head);
	head = NULL;
	int i, j = 0, n;
	char sort_to_file;
	customer *c, *temp, c1;
	system("cls");
	system("color 8f");
	FILE *bh;
	bh = fopen("DueCustomers.txt", "r");
	fseek(bh, 0, SEEK_END);
	n = ftell(bh) / sizeof(customer);
	rewind(bh);
	while (fread(&c1, sizeof(customer), 1, bh))
	{
		addToLinkedList(c1.name, c1.date, c1.time, c1.phonenumber, c1.total, c1.duepayment, c1.things_bought);
	}
	fclose(bh);
	temp = head;
	for (i = 1; i <= n; i++)
	{
		j = 0;
		temp = head;
		while (temp->next != NULL)
		{

			if ((temp->duepayment) < (temp->next->duepayment))
			{
				j = 1;
				strcpy(c1.date, temp->date);
				strcpy(c1.time, temp->time);
				strcpy(c1.phonenumber, temp->phonenumber);
				strcpy(c1.things_bought, temp->things_bought);
				strcpy(c1.name, temp->name);
				c1.duepayment = temp->duepayment;
				c1.total = temp->total;

				strcpy(temp->date, temp->next->date);
				strcpy(temp->time, temp->next->time);
				strcpy(temp->phonenumber, temp->next->phonenumber);
				strcpy(temp->things_bought, temp->next->things_bought);
				strcpy(temp->name, temp->next->name);
				temp->duepayment = temp->next->duepayment;
				temp->total = temp->next->total;

				strcpy(temp->next->date, c1.date);
				strcpy(temp->next->time, c1.time);
				strcpy(temp->next->phonenumber, c1.phonenumber);
				strcpy(temp->next->things_bought, c1.things_bought);
				strcpy(temp->next->name, c1.name);
				temp->next->duepayment = c1.duepayment;
				temp->next->total = c1.total;
			}

			temp = temp->next;
		}
		if (j == 0)
		{
			break;
		}
	}
	printf("\n\t\t--------VIEWING LIST OF  DUE COSTOMERS BY SORTING DUE AMOUNT !!!!-----------\n\n\n");
	displayLinkedRecords();

	printf("\n\n\n\t\t\tDo you Want to sort Permanently in to the file (y/n)");
	if (getch() == 'y')
	{
		system("cls");
		system("color 3f");
		bh = fopen("DueCustomers.txt", "w");
		temp = head;
		while (temp != NULL)
		{

			fwrite(temp, sizeof(customer), 1, bh);
				temp = temp->next;
		}
		fclose(bh);

		printf("\n\t\t\tThe Information Is successfully sorted in the file");
		printf("\n\n\n\t\t\tPRESS 'm' TO GET IN TO THE MENU PAGE (OR) PRESS ANY KEY TO GET IN TO THE SORT PAGE");
		if (getch() == 'm')
		{
			menu();
		}
		else
		{
			sortRecords();
		}
	}
	printf("\n\n\n\t\t\tPRESS 'm' TO GET IN TO THE MENU PAGE (OR) PRESS ANY KEY TO GET IN TO THE SORT PAGE");
	if (getch() == 'm')
	{
		menu();
	}
	else
	{
		sortRecords();
	}
}

void sortByCustomerName()
{

	free(head);
	head = NULL;
	int i, j, n;
	customer *c, *temp, c1;
	FILE *bh;
	system("cls");
	system("color 8f");
	bh = fopen("DueCustomers.txt", "r");
	fseek(bh, 0, SEEK_END);
	n = ftell(bh) / sizeof(customer);
	rewind(bh);
	while (fread(&c1, sizeof(customer), 1, bh))
	{
		addToLinkedList(c1.name, c1.date, c1.time, c1.phonenumber, c1.total, c1.duepayment, c1.things_bought);
	}
	fclose(bh);
	temp = head;
	for (i = 1; i <= n; i++)
	{
		j = 0;
		temp = head;
		while (temp->next != NULL)
		{

			if ((strcmp(temp->name, temp->next->name)) > 0)
			{
				j = 1;
				strcpy(c1.date, temp->date);
				strcpy(c1.time, temp->time);
				strcpy(c1.phonenumber, temp->phonenumber);
				strcpy(c1.things_bought, temp->things_bought);
				strcpy(c1.name, temp->name);
				c1.duepayment = temp->duepayment;
				c1.total = temp->total;

				strcpy(temp->date, temp->next->date);
				strcpy(temp->time, temp->next->time);
				strcpy(temp->phonenumber, temp->next->phonenumber);
				strcpy(temp->things_bought, temp->next->things_bought);
				strcpy(temp->name, temp->next->name);
				temp->duepayment = temp->next->duepayment;
				temp->total = temp->next->total;

				strcpy(temp->next->date, c1.date);
				strcpy(temp->next->time, c1.time);
				strcpy(temp->next->phonenumber, c1.phonenumber);
				strcpy(temp->next->things_bought, c1.things_bought);
				strcpy(temp->next->name, c1.name);
				temp->next->duepayment = c1.duepayment;
				temp->next->total = c1.total;
			}

			temp = temp->next;
		}
		if (j == 0)
		{
			break;
		}

		temp = head;
	}
	printf("\n\t\t--------VIEWING LIST OF  DUE COSTOMERS BY SORTING COSTOMERS NAME !!!!-----------\n\n\n");
	displayLinkedRecords();
	printf("\n\n\n\t\t\tDo you Want to sort Permanently in to the file (y/n)");
	if (getch() == 'y')
	{
		system("cls");
		system("color 3f");
		bh = fopen("DueCustomers.txt", "w");
		temp = head;
		while (temp != NULL)
		{
			fwrite(temp, sizeof(customer), 1, bh);
			temp = temp->next;
		}
		fclose(bh);
		printf("\n\n\n\t\t\tThe Information Is successfully sorted in the file");
		printf("\n\n\n\t\t\tPRESS 'm' TO GET IN TO THE MENU PAGE (OR) PRESS ANY KEY TO GET IN TO THE SORT PAGE");
		if (getch() == 'm')
		{
			menu();
		}
		else
		{
			sortRecords();
		}
	}
	printf("\n\n\n\t\t\tPRESS 'm' TO GET IN TO THE MENU PAGE (OR) PRESS ANY KEY TO GET IN TO THE SORT PAGE");
	if (getch() == 'm')
	{
		menu();
	}
	else
	{
		sortRecords();
	}
}

void sortByDate()
{

	free(head);
	head = NULL;
	int i, j, n;
	customer *c, *temp, c1;
	FILE *bh;
	system("cls");
	system("color 8f");
	bh = fopen("DueCustomers.txt", "r");
	fseek(bh, 0, SEEK_END);
	n = ftell(bh) / sizeof(customer);
	rewind(bh);
	while (fread(&c1, sizeof(customer), 1, bh))
	{
		addToLinkedList(c1.name, c1.date, c1.time, c1.phonenumber, c1.total, c1.duepayment, c1.things_bought);
	}
	fclose(bh);
	temp = head;
	for (i = 1; i <= n; i++)
	{
		j = 0;
		temp = head;
		while (temp->next != NULL)
		{

			if ((strcmp(temp->date, temp->next->date)) > 0)
			{
				j = 1;
				strcpy(c1.date, temp->date);
				strcpy(c1.time, temp->time);
				strcpy(c1.phonenumber, temp->phonenumber);
				strcpy(c1.things_bought, temp->things_bought);
				strcpy(c1.name, temp->name);
				c1.duepayment = temp->duepayment;
				c1.total = temp->total;

				strcpy(temp->date, temp->next->date);
				strcpy(temp->time, temp->next->time);
				strcpy(temp->phonenumber, temp->next->phonenumber);
				strcpy(temp->things_bought, temp->next->things_bought);
				strcpy(temp->name, temp->next->name);
				temp->duepayment = temp->next->duepayment;
				temp->total = temp->next->total;

				strcpy(temp->next->date, c1.date);
				strcpy(temp->next->time, c1.time);
				strcpy(temp->next->phonenumber, c1.phonenumber);
				strcpy(temp->next->things_bought, c1.things_bought);
				strcpy(temp->next->name, c1.name);
				temp->next->duepayment = c1.duepayment;
				temp->next->total = c1.total;
			}

			temp = temp->next;
		}
		if (j == 0)
		{
			break;
		}
	}
	printf("\n\t\t--------VIEWING LIST OF  DUE COSTOMERS BY SORTING COSTOMERS BY DATE !!!!-----------\n\n\n");

	displayLinkedRecords();

	printf("\n\n\n\t\t\tDo you Want to sort Permanently in to the file (y/n)");
	if (getch() == 'y')
	{
		system("cls");
		system("color 3f");
		bh = fopen("DueCustomers.txt", "w");
		temp = head;
		while (temp != NULL)
		{
			fwrite(temp, sizeof(customer), 1, bh);
			temp = temp->next;
		}
		fclose(bh);

		printf("\n\n\n\t\t\tThe Information Is successfully sorted in the file");
		printf("\n\n\n\t\t\tPRESS 'm' TO GET IN TO THE MENU PAGE (OR) PRESS ANY KEY TO GET IN TO THE SORT PAGE");
		if (getch() == 'm')
		{
			menu();
		}
		else
		{
			sortRecords();
		}
	}
	printf("\n\n\n\t\t\tPRESS 'm' TO GET IN TO THE MENU PAGE (OR) PRESS ANY KEY TO GET IN TO THE SORT PAGE");
	if (getch() == 'm')
	{
		menu();
	}
	else
	{
		sortRecords();
	}
}

void viewRecordsByDate()
{
	int j, num1;
	char date[15];
	char choice = 'y';
	customer c1;
	FILE *bh;
	system("color 3f");
	do
	{
		int found = 0;
		system("cls");
		printf("\n\t\t---------VIEWING ALL DUE COSTOMERS RECORD IN PERTICULAR DATE!!!!-----------\n\n\n");
		printf("\n\t\t---------Enter Date to Search -----------: ");
		printf("\n\t\t Enter The Date In [DD MMM YYYY] : ");
		scanf(" %[^\n]s", date);
		num1 = strlen(date);
		while (num1 != 11)
		{
			printf("\n\t\t Enter The Date In Correct Format [DD MMM YYYY] : ");
			scanf(" %[^\n]s", date);
			num1 = strlen(date);
		}

		printf("\n\t\tNAME                YYYY MM DD     TIME      PHO-NU         TOTAL     DUE AMOUNT    THINGS BOUGHT                           \n\n");
		bh = fopen("DueCustomers.txt", "r");
		while (fread(&c1, sizeof(customer), 1, bh))
		{
			if (strcmp(c1.date, date) == 0)
			{
				found = 1;
				printf("\n\n\t\t%-20s%-15s%-10s%-15s", c1.name, c1.date, c1.time, c1.phonenumber);
				printf("%-10d%-15d%-40s", c1.total, c1.duepayment, c1.things_bought);
			}
		}
		fclose(bh);
		if (found == 0)
		{

			system("cls");
			printf("\n\t\t\t-----------------ERROR---------------\n\n\n");
			printf("\n\t\t\t-------------Date Not Found----------\n\n\n");
			printf("\n\t\t\t----please Check The Date You Have Entered!--");
		}
		printf("\n\n\n\t\t\tDo you want to Search Again (y/n)");
	} while (getch() == 'y');
	menu();
}

void sortRecords()
{
	system("cls");
	system("color 6f");
	printf("\n\t\t\t--------VIEWING LIST OF  DUE COSTOMERS BY SORTING COSTOMERS NAME/DUE AMOUNT/DATE !!!!-----------\n\n\n");
	printf("\n\n\t\t\t[1] : View Due Record By Sorting  Names  (Temporary/permanent)\n");
	printf("\n\n\t\t\t[2] : View Due Record By Sorting  Due Amount (Temporary/permanent)\n");
	printf("\n\n\t\t\t[3] : View Due Record By Sorting  Date  (Temporary/permanent)\n");
	printf("\n\n\t\t\t[0] : Go Back To Menu  \n");
	switch (getch())
	{
	case '1':
		sortByCustomerName();
		break;
	case '2':
		sortByDueAmount();
		break;
	case '3':
		sortByDate();
		break;
	case '0':
		menu();
		break;
	default:

		system("cls");
		printf("\n\n\n\t\t\t-----------------ERROR----------------\n\n\n");
		printf("\n\n\n\t\t\t----Plese Enter From 0 to 3 only----");
		printf("\n\n\n\t\t\t------press any key To Go Back------");
		getch();
		sortRecords();
	}
}

void updateStoreDetails()
{

	FILE *store;
	storedetails *r;
	system("cls");
	int num3 = 0;
	r = (storedetails *)calloc(1, sizeof(storedetails));
	store = fopen("store.txt", "r");
	fread(r, sizeof(storedetails), 1, store);
	printf("\n\n\t\tTHESE ARE THE DETAILS WHICH YOU ADDED BEFORE ----\n\n");
	printf("\n\n\t\tENTER YOUR PREVIOUS STORE NAME : %-30s", r->storename);
	printf("\n\n\t\tENTER YOUR PREVIOUS STORE ADDRESS : %-100s", r->address);
	printf("\n\n\t\tENTER YOUR PREVIOUS PHONE NUMBER : %-15s", r->num);

	fclose(store);
	r = (storedetails *)calloc(1, sizeof(storedetails));
	store = fopen("store.txt", "w");
	printf("\n\n\t\tPLEASE ENTER ALL THE DETAILS ASKED ABOUT YOUR STORE ----\n\n");
	printf("\n\n\t\tENTER YOUR NEW STORE NAME : ");
	scanf(" %[^\n]s", r->storename);
	printf("\n\n\t\tENTER YOUR NEW STORE ADDRESS : ");
	scanf(" %[^\n]s", r->address);
	printf("\n\n\t\tENTER YOUR NEW PHONE NUMBER : ");
	scanf(" %[^\n]s", r->num);
	for (int i = 0; i < 10; i++)
	{
		if (r->num[i] >= '0' && r->num[i] <= '9')
		{
		}
		else
		{
			num3 = 1;
		}
	}
	while (strlen(r->num) != 10 || num3 != 0)
	{
		num3 = 0;
		printf("\n\t\t\t The Phone Number is Incorrect Try Again: ");
		printf("\n\t\t\t Enter The Phone Number : ");
		scanf(" %[^\n]s", r->num);
		for (int i = 0; i < 10; i++)
		{
			if (r->num[i] >= '0' && r->num[i] <= '9')
			{
			}
			else
			{
				num3 = 1;
			}
		}
	}

	fwrite(r, sizeof(storedetails), 1, store);
	fclose(store);
	printf("\n\n\n\t\tTHE DETAILS HAVE BEEN UPDATED SUCCESSFULLY: ");
	printf("\n\n\n\t\t-------------Press Any Key To Continue------------------");
	getch();
	menu();
}

void searchRecords()
{

	system("cls");
	printf("\t\t\t-----------WELCOME TO SEARCH USING NAME/DATE--------------------\n\n");
	printf("\n\t\t\t[1] : View All the Due Costomers In Perticular Date\n");
	printf("\n\t\t\t[2] : Search the Costomer By Name\n");
	printf("\n\t\t\t[0] : menu\n");
	printf("\n\n\t\t\tenter your choice------\n");
	switch (getch())
	{
	case '1':
		viewRecordsByDate();
		break;
	case '2':
		searchByName();
		break;
	case '0':
		menu();
		break;
	default:
		system("cls");
		printf("\n\n\n\t\t\t-----------------ERROR----------------\n\n\n");
		printf("\n\n\n\t\t\t----Plese Enter From 1 to 2 only----");
		printf("\n\n\n\t\t\t------press any key To Go Back------");
		getch();
		searchRecords();
	}
}

void menu()
{

	free(head);
	head = NULL;
	system("cls");
	system("color 2f");
	printf("\t\t\t-----------*****************************--------------------\n\n");
	printf("\t\t\t-----------WELCOME TO DIGITAL DUE RECORDS--------------------\n\n");
	printf("\t\t\t-----------*****************************--------------------\n\n\n\n");
	printf("\n\t\t\t[1] : Add Due Record\n");
	printf("\n\t\t\t[2] : View Due Record\n");
	printf("\n\t\t\t[3] : View Number of Due costomers----AND Total due Amount By All the Costomers\n");
	printf("\n\t\t\t[4] : Update The DueAmount/Details by Name\n");
	printf("\n\t\t\t[5] : View Due Record By Sorting  Names/Due Amount/Date  (Temporary/permanent)\n");
	printf("\n\t\t\t[6] : Search the Costomer By Name/Perticular Date\n");
	printf("\n\t\t\t[7] : Password Change\n");
	printf("\n\t\t\t[8] : Change Store Details\n");
	printf("\n\t\t\t[0] : EXIT\n");
	switch (getch())
	{
	case '1':
		addDueRecord();
		break;
	case '2':
		viewAllRecords();
		break;
	case '3':
		getRecordStats();
		break;
	case '4':
		updateCustomerRecord();
		break;
	case '5':
		sortRecords();
		break;
	case '6':
		searchRecords();
		break;
	case '7':
		resetPassword();
		break;
	case '8':
		updateStoreDetails();
		break;
	case '0':
		exit(0);
		break;
	default:

		system("cls");
		printf("\n\n\n\t\t\t-----------------ERROR----------------\n\n\n");
		printf("\n\n\n\t\t\t----Plese Enter From 0 to 8 only----");
		printf("\n\n\n\t\t\t------press any key To Go Back------");
		getch();
		menu();
	}
}

void resetPassword()
{
	int normal = 0, special = 0, numerical = 0, flag1;

	int i = 2, found = 0, k;
	char password2[10];
	passwd p;
	system("color 5f");
	FILE *p1;
	do
	{
		system("cls");
		printf("\n\n\t\t\t---------WELCOME TO PASSWORD RE SETTING---------\n\n\n\n");
		p1 = fopen("password.bin", "rb");

		printf("\n\n\t\tEnter The Password : ");
		for (k = 0; k < 8; k++)
		{
			password2[k] = getch();
			printf("*");
		}
		password2[k] = '\0';

		while (fread(&p, sizeof(passwd), 1, p1))
		{
			if (strcmp(password2, p.password) == 0)
			{
				found = 1;
				fclose(p1);
				printf("\n\n\n\t\t---------------ACCESS GRANTED----------------");
				printf("\n\n\n\t\t---------YOUR PASSWORD IS CORRECT------------");
				p1 = fopen("password.bin", "wb");
				fflush(stdin);
				printf("\n\n\t\tPLEASE ENTER ALL THE DETAILS WHICH HAS LESS THAN 11 CHARACTERS ----\n\n");
				do
				{
					flag1 = 0;
					printf("\n\n\t\tENTER PASSWORD : ");
					for (k = 0; k < 8; k++)
					{
						password2[k] = getch();
						printf("*");
					}
					password2[k] = '\0';
					normal = special = numerical = 0;
					for (k = 0; k < 8; k++)
					{
						if ((password2[k] >= 'a' && password2[k] >= 'z') || (password2[k] >= 'A' && password2[k] >= 'Z'))
						{
							normal++;
						}
						else if (password2[k] >= '0' && password2[k] >= '9')
						{
							numerical++;
						}
						else
						{
							special++;
						}
					}
					if (special == 0 || numerical == 0)
					{
						printf("\n\n\t\tENTER STRONG PASSWORD!-------");
						printf("\n\n\t\tSHOULD CONTAIN MIN OF ONE NUMBER AND SPECIAL CHARECTER");
						flag1 = 1;
					}
				} while (flag1 == 1);
				strcpy(p.password, password2);
				printf("\n\n\t\tNOW ADD DETAILS FOR PASSWORD RECOVERY");
				printf("\n\n\t\tENTER YOUR FAVORITE COLOUR NAME: ");
				scanf(" %[^\n]s", p.fav_color);
				printf("\n\n\t\tENTER YOUR FAVORITE CAR NAME : ");
				scanf(" %[^\n]s", p.fav_car);
				printf("\n\n\t\tENTER YOUR FAVORITE FLOWER NAME : ");
				scanf(" %[^\n]s", p.fav_flowers);
				printf("\n\n\t\tENTER YOUR BANK NAME WHO PROVIDED YOUR FIRST CREDIT CARD: ");
				scanf(" %[^\n]s", p.first_credit_card);
				fwrite(&p, sizeof(passwd), 1, p1);
				fclose(p1);
				printf("\n\n\t\t-----CONGRATULATIONS PASSWORD RESETED SUCCESSFULLY--------\n");
				printf("\n\n\t\tPress Any Key To Continue");
				getch();
				menu();
			}
			else
			{

				system("cls");
				printf("\n\n\n\t\t----------------------ERROR------------------");
				printf("\n\n\n\t\t-----------------PASSWORD WRONG-------------");
				printf("\n\n\n\n\t\t------------------ACCESS DENIED-------------");
			}
		}
		printf("\n\n\n\n\t\tYOU ONLY LEFT %d CHANCE LEFT", i);
		i--;
		getch();
	} while (i >= 0);
	if (i < 0)
	{
		printf("\n\n\n\n\t\tDo You Want To Go For Password Recovary (y/n)");
		if (getch() == 'y')
		{
			recoverPassword();
		}
		else
		{
			menu();
		}
	}
}

void authenticateUser()
{
	int normal = 0, special = 0, numerical = 0, flag1;

	char password1[15], password2[15];
	int flag = 0, i = 2, k;
	system("cls");
	system("color 4f");
	FILE *pass, *store;
	passwd *p, q;
	storedetails *r;
	if ((pass = fopen("password.bin", "rb")) && (pass != NULL))
	{
		fclose(pass);
		flag = 1;
	}
	if (flag == 0)
	{
		printf("\n\n\t\t\t-----------------WELCOME ADMIN------------------\n\n");
		printf("\n\n\t\t\t----------WELCOME TO PASSWORD SETTING----------\n\n");
		p = (passwd *)calloc(1, sizeof(passwd));
		printf("\n\n\t\tPLEASE ENTER ALL THE DETAILS WHICH HAS LESS THAN 11 CHARACTERS ----\n\n");
		printf("\n\n\t\tPLEASE ENTER THE PASSWORD WHICH HAS EXACTLY 8 CHARACTERS ----\n\n");

		do
		{
			flag1 = 0;
			printf("\n\n\t\tENTER PASSWORD : ");
			for (k = 0; k < 8; k++)
			{
				password2[k] = getch();
				printf("*");
			}
			password2[k] = '\0';
			normal = special = numerical = 0;
			for (k = 0; k < 8; k++)
			{
				if ((password2[k] >= 'a' && password2[k] >= 'z') || (password2[k] >= 'A' && password2[k] >= 'Z'))
				{
					normal++;
				}
				else if (password2[k] >= '0' && password2[k] >= '9')
				{
					numerical++;
				}
				else
				{
					special++;
				}
			}
			if (special == 0 || numerical == 0)
			{
				printf("\n\n\t\tENTER STRONG PASSWORD!-------");
				printf("\n\n\t\tSHOULD CONTAIN MIN OF ONE NUMBER AND SPECIAL CHARECTER");
				flag1 = 1;
			}
		} while (flag1 == 1);
		int num3 = 0;
		strcpy(p->password, password2);
		printf("\n\n\t\tNOW ADD DETAILS FOR PASSWORD RECOVERY");
		printf("\n\n\t\tENTER YOUR FAVORITE COLOUR NAME: ");
		scanf(" %[^\n]s", p->fav_color);
		printf("\n\n\t\tENTER YOUR FAVORITE CAR NAME : ");
		scanf(" %[^\n]s", p->fav_car);
		printf("\n\n\t\tENTER YOUR FAVORITE FLOWER NAME : ");
		scanf(" %[^\n]s", p->fav_flowers);
		printf("\n\n\t\tENTER YOUR BANK NAME WHO PROVIDED YOUR FIRST CREDIT CARD: ");
		scanf(" %[^\n]s", p->first_credit_card);
		pass = fopen("password.bin", "wb");
		fwrite(p, sizeof(passwd), 1, pass);
		fclose(pass);
		printf("\n\n\n\t\t-----CONGRATULATIONS PASSWORD SET SUCCESSFULLY--------\n");
		r = (storedetails *)calloc(1, sizeof(storedetails));
		store = fopen("store.txt", "w");
		printf("\n\n\t\tPLEASE ENTER ALL THE DETAILS ASKED ABOUT YOUR STORE ----\n\n");
		printf("\n\n\t\tENTER YOUR STORE NAME : ");
		scanf(" %[^\n]s", r->storename);
		printf("\n\n\t\tENTER YOUR STORE ADDRESS : ");
		scanf(" %[^\n]s", r->address);
		printf("\n\n\t\tENTER YOUR YOUR PHONE NUMBER : ");
		scanf(" %[^\n]s", r->num);
		for (int i = 0; i < 10; i++)
		{
			if (r->num[i] >= '0' && r->num[i] <= '9')
			{
			}
			else
			{
				num3 = 1;
			}
		}
		while (strlen(r->num) != 10 || num3 != 0)
		{
			num3 = 0;
			printf("\n\t\t\t The Phone Number is Incorrect Try Again: ");
			printf("\n\t\t\t Enter The Phone Number : ");
			scanf(" %[^\n]s", r->num);
			for (int i = 0; i < 10; i++)
			{
				if (r->num[i] >= '0' && r->num[i] <= '9')
				{
				}
				else
				{
					num3 = 1;
				}
			}
		}
		fwrite(r, sizeof(storedetails), 1, store);
		fclose(store);
		printf("\n\n\n\t\t-------------Press Any Key To Continue------------------");
		getch();
		authenticateUser();
	}
	if (flag == 1)
	{
		do
		{
			pass = fopen("password.bin", "rb");
			system("cls");
			printf("\n\n\t\t---------ENTER THE PASSWORD--------- : ");
			for (k = 0; k < 8; k++)
			{
				password1[k] = getch();
				printf("*");
			}
			password1[k] = '\0';
			while (fread(&q, sizeof(passwd), 1, pass))
			{
				if (strcmp(password1, q.password) == 0)
				{
					printf("\n\n\n\t\t--------------ACCESS GRANTED----------------");
					printf("\n\n\n\t\t--------YOUR PASSWORD IS CORRECT------------");
					printf("\n\n\n\n\t\t-----------Press Any Key To Continue---------");
					fclose(pass);
					getch();
					menu();
				}
				else
				{

					system("cls");
					printf("\n\n\n\t\t----------------------ERROR--------------------");
					printf("\n\n\n\t\t-----------------PASSWORD WRONG---------------");
					printf("\n\n\n\t\t------------------ACCESS DENIED---------------");
				}
			}
			printf("\n\n\n\n\t\tYOU ONLY LEFT %d CHANCE LEFT", i);
			i--;
			if (i >= 0)
			{
				printf("\n\n\n\t\tDo You Want To Go For Password Recovary (y/n)");
				if (getch() == 'y')
				{
					recoverPassword();
				}
			}
		} while (i >= 0);
		exit(0);
	}
}

void recoverByColor()
{

	passwd p;
	FILE *pass;
	char temp[10];
	do
	{
		system("cls");
		system("color 5f");
		printf("\n\n\t\t---------WELCOME TO PASSWORD RECOVARY USING COLOUR-----------\n\n\n");
		pass = fopen("password.bin", "rb");
		printf("\n\n\t\tENTER YOUR FAVORITE COLOUR : ");
		scanf(" %[^\n]s", temp);
		while (fread(&p, sizeof(passwd), 1, pass))
		{
			if (strcmp(temp, p.fav_color) == 0)
			{
				printf("\n\n\n\t\t---------------ACCESS GRANTED-------------------");
				printf("\n\n\n\t\t-----YOUR FAVORITE COLOUR NAME IS CORRECT-------");
				printf("\n\n\n\t\tYOUR PASSWORD IS : %s", p.password);
				printf("\n\n\n\n\n\t\t------------Press Any Key To Continue-----------");
				fclose(pass);
				getch();
				authenticateUser();
			}
			else
			{

				system("cls");
				printf("\n\n\n\t\t--------------------ERROR-------------------");
				printf("\n\n\n\t\t--------FAVORITE COLOUR NAME IS WRONG------");
				printf("\n\n\n\t\t---------------ACCESS DENIED---------------");
				printf("\n\n\n\n\t\tYOU ONLY LEFT %d CHANCE LEFT", access);
				access--;
				if (access >= 0)
				{
					printf("\n\n\n\n\t\tDo You Want Choose Another Option For Password Recovary (y/n)");
					if (getch() == 'y')
					{
						recoverPassword();
					}
				}
			}
		}
	} while (access >= 0);
	exit(0);
}

void recoverByCar()
{

	passwd p;
	FILE *pass;
	char temp[10];
	do
	{
		system("cls");
		system("color 5f");
		printf("\n\n\t\t----------WELCOME TO PASSWORD RECOVARY USING CAR---------\n\n\n");
		pass = fopen("password.bin", "rb");
		printf("\n\n\t\tENTER YOUR FAVORITE CAR NAME : ");
		scanf(" %[^\n]s", temp);
		while (fread(&p, sizeof(passwd), 1, pass))
		{
			if (strcmp(temp, p.fav_car) == 0)
			{
				printf("\n\n\n\t\t---------------ACCESS GRANTED-----------------");
				printf("\n\n\n\t\t------YOUR FAVORITE CAR NAME IS CORRECT-------");
				printf("\n\n\n\t\tYOUR PASSWORD IS : %s", p.password);
				printf("\n\n\n\n\t\t------------Press Any Key To Continue----------");
				fclose(pass);
				getch();
				authenticateUser();
			}
			else
			{

				system("cls");
				printf("\n\n\t\t--------------------ERROR--------------------");
				printf("\n\n\t\t-------YOUR FAVORITE CAR NAME IS WRONG------");
				printf("\n\n\t\t--------------ACCESS DENIED-----------------");
				printf("\n\n\n\n\t\tYOU ONLY LEFT %d CHANCE LEFT", access);
				access--;
				if (access >= 0)
				{
					printf("\n\n\n\n\t\tDo You Want Choose Another Option For Password Recovary (y/n)");
					if (getch() == 'y')
					{
						recoverPassword();
					}
				}
			}
		}
	} while (access >= 0);
	exit(0);
}

void recoverByFlower()
{

	passwd p;
	FILE *pass;
	char temp[10];
	do
	{
		system("cls");
		system("color 5f");
		printf("\n\n\t\t------------WELCOME TO PASSWORD RECOVARY USING YOUR FLOWER NAME----------\n\n\n");
		pass = fopen("password.bin", "rb");
		printf("\n\n\t\tENTER FAVORITE FLOWER NAME : ");
		scanf(" %[^\n]s", temp);
		while (fread(&p, sizeof(passwd), 1, pass))
		{
			if (strcmp(temp, p.fav_flowers) == 0)
			{
				printf("\n\n\t\t------------------ACCESS GRANTED--------------------");
				printf("\n\n\t\t-------YOUR FAVORITE FLOWER NAME IS CORRECT---------");
				printf("\n\n\t\tYOUR PASSWORD IS : %s", p.password);
				printf("\n\n\n\n\t\t--------------Press Any Key To Continue-------------");
				fclose(pass);
				getch();
				authenticateUser();
			}
			else
			{

				system("cls");
				printf("\n\n\n\t\t---------------------ERROR--------------------");
				printf("\n\n\n\t\t------YOUR FAVORITE FLOWER NAME IS WRONG-----");
				printf("\n\n\n\t\t----------------ACCESS DENIED----------------");
				printf("\n\n\n\n\t\tYOU ONLY LEFT %d CHANCE LEFT", access);
				access--;
				if (access >= 0)
				{
					printf("\n\n\n\n\t\tDo You Want Choose Another Option For Password Recovary (y/n)");
					if (getch() == 'y')
					{
						recoverPassword();
					}
				}
			}
		}
	} while (access >= 0);
	exit(0);
}

void recoverByBank()
{

	passwd p;
	FILE *pass;
	char temp[10];
	do
	{
		system("cls");
		system("color 5f");
		printf("\n\n\t\t------------WELCOME TO PASSWORD RECOVARY USING YOUR BANK NAME-----------\n\n");
		pass = fopen("password.bin", "rb");
		printf("\n\n\t\tBANK NAME WHO PROVIDED YOUR FIRST CREDIT CARD : ");
		scanf(" %[^\n]s", temp);
		while (fread(&p, sizeof(passwd), 1, pass))
		{
			if (strcmp(temp, p.first_credit_card) == 0)
			{
				printf("\n\n\n\t\t---------------ACCESS GRANTED-----------------");
				printf("\n\n\n\t\t---------YOUR BANK NAME IS CORRECT------------");
				printf("\n\n\n\t\tYOUR PASSWORD IS : %s", p.password);
				printf("\n\n\n\n\t\t----------Press Any Key To Continue-----------");
				fclose(pass);
				getch();
				authenticateUser();
			}
			else
			{
				system("cls");
				printf("\n\n\n\t\t---------------------ERROR-------------------");
				printf("\n\n\n\t\t-----------YOUR BANK NAME IS WRONG----------");
				printf("\n\n\n\t\t----------------ACCESS DENIED---------------");
				printf("\n\n\n\n\t\tYOU ONLY LEFT %d CHANCE LEFT", access);
				access--;
				if (access >= 0)
				{
					printf("\n\n\n\n\t\tDo You Want Choose Another Option For Password Recovary (y/n)");
					if (getch() == 'y')
					{
						recoverPassword();
					}
				}
			}
		}
	} while (access >= 0);
	exit(0);
}

void recoverPassword()
{

	system("cls");
	printf("\n\n\t\t---------WELCOME TO PASSWORD RECOVARY---------\n\n");
	printf("\n\n\t\t[1] : YOUR FAVORITE COLOUR : ");
	printf("\n\n\t\t[2] : YOUR FAVORITE CAR NAME : ");
	printf("\n\n\t\t[3] : YOUR FAVORITE FLOWER NAME : ");
	printf("\n\n\t\t[4] : YOUR BANK NAME WHO PROVIDED YOUR FIRST CREDIT CARD: ");
	printf("\n\n\t\t[5] : EXIT : ");
	printf("\n\n\n\n\t\t------------ENTER YOUR CHOICE-----------------");
	switch (getch())
	{
	case '1':
		recoverByColor();
		break;
	case '2':
		recoverByCar();
		break;
	case '3':
		recoverByFlower();
		break;
	case '4':
		recoverByBank();
		break;
	case '5':
		exit(0);
		break;
	default:

		system("cls");
		printf("\n\n\t\t\t--------------------ERROR------------------\n\n\n");
		printf("\n\n\t\t\tPlese Enter From 1 to 5 only");
		printf("\n\n\t\t\tpress any key To Go Back");
		getch();
		recoverPassword();
	}
}

void searchCustomerByName()
{

	int j;
	char name1[20], name2[20];
	char choice = 'y';
	customer c1;
	FILE *bh;
	system("color 9f");
	do
	{
		int found = 0;
		system("cls");
		printf("\n\t\t--------VIEWING DUE COSTOMER RECORD BY SEARCHING NAME!!!!-----------\n\n\n");
		printf("\n\n\t\tEnter Name Of The Costomer to Search : ");
		scanf(" %[^\n]c", name1);
		for (j = 0; name1[j] != '\0'; j++)
		{
			name2[0] = toupper(name1[0]);
			if (name1[j - 1] == ' ')
			{
				name2[j] = toupper(name1[j]);
				name2[j - 1] = name1[j - 1];
			}
			else
				name2[j] = name1[j];
		}
		name2[j] = '\0';
		bh = fopen("DueCustomers.txt", "r");
		while (fread(&c1, sizeof(customer), 1, bh))
		{
			if (strcmp(c1.name, name2) == 0)
			{
					found = 1;
					printf("\n\t\tNAME                YYYY MM DD     TIME      PHO-NU          TOTAL     DUE AMOUNT    THINGS BOUGHT                           \n\n");
					printf("\n\t\t%-20s%-15s%-10s%-15s", c1.name, c1.date, c1.time, c1.phonenumber);
					printf("%-10d%-15d%-40s", c1.total, c1.duepayment, c1.things_bought);
			}
		}
		if (found == 0)
		{

				system("cls");
				printf("\n\n\t\t------------------ERROR--------------------");
				printf("\n\n\t\tName Of the Costomer  Not Found.....\n\n\n");
				printf("\n\n\t\tThe Costomer name is Wrong!\n\t\tELSE\n\t\tThe Costomer have Cleard the Due Amount!");
		}
		fclose(bh);
		printf("\n\n\n\n\t\tDo you want to Search Again (y/n)");
	} while (getch() == 'y');
	customerMenu();
}

void searchCustomerByDate()
{
	int num1;
	int j;
	char date[15];
	char choice = 'y';
	customer c1;
	FILE *bh;
	system("color 3f");
	do
	{
		int found = 0;
		system("cls");
		printf("\n\t\t---------VIEWING ALL DUE COSTOMERS RECORD IN PERTICULAR DATE!!!!-----------\n\n\n");
		printf("\n\t\t---------Enter Date to Search [DD MM YYYY]-----------: ");
		printf("\n\t\t Enter The Date In [DD MMM YYYY] : ");
		scanf(" %[^\n]s", date);
		num1 = strlen(date);
		while (num1 != 11)
		{
			printf("\n\t\t Enter The Date In Correct Format [DD MMM YYYY] : ");
			scanf(" %[^\n]s", date);
			num1 = strlen(date);
		}

		printf("\n\t\tNAME                YYYY MM DD     TIME      PHO-NU         TOTAL     DUE AMOUNT    THINGS BOUGHT                    \n\n");
		bh = fopen("DueCustomers.txt", "r");

		while (fread(&c1, sizeof(customer), 1, bh))
		{

			if (strcmp(c1.date, date) == 0)
			{
				found = 1;
				printf("\n\n\t\t%-20s%-15s%-10s%-15s", c1.name, c1.date, c1.time, c1.phonenumber);
				printf("%-10d%-15d%-40s", c1.total, c1.duepayment, c1.things_bought);
			}
		}
		fclose(bh);

		if (found == 0)
		{

			system("cls");
			printf("\n\t\t\t-----------------ERROR---------------\n\n\n");
			printf("\n\t\t\t-------------Date Not Found----------\n\n\n");
			printf("\n\t\t\t----please Check The Date You Have Entered!--");
		}

		printf("\n\n\n\t\t\tDo you want to Search Again (y/n)");
	} while (getch() == 'y');
	customerMenu();
}

void customerMenu()
{

	system("cls");
	printf("\n\t\t\t-----------Welcome To View Your details-----------------\n\n\n");
	printf("\n\n\t\t\t[1] View details by name");
	printf("\n\n\t\t\t[2] View details by Perticular date");
	printf("\n\n\t\t\t[3] back");
	printf("\n\n\t\t\t[0] exit");
	printf("\n\n\n\t\t\tEnter your choice");
	switch (getch())
	{
	case '1':
		searchCustomerByName();
		break;
	case '2':
		searchCustomerByDate();
		break;
	case '3':
		main();
		break;
	case '0':
		exit(0);
		break;
	default:
		system("cls");
		printf("\n\n\n\t\t\t-----------------ERROR----------------\n\n\n");
		printf("\n\n\n\t\t\t----Plese Enter From 0 to 3 only----");
		printf("\n\n\n\t\t\t------press any key To Go Back------");
		getch();
		customerMenu();
	}
}

int main()
{

	system("cls");
	system("color 1f");
	printf("\n\t\t\t-----------Welcome-----------------\n\n\n");
	printf("\n\n\n\n\n\n\t\t\t[1] Customer\n\t\t\t[2] Admin\n\t\t\t[0] exit");
	printf("\n\n\n\n\n\n\t\t\tChoose your choice----");
	switch (getch())
	{
	case '1':
		customerMenu();
		break;
	case '2':
		authenticateUser();
		break;
	case '0':
		exit(0);
		break;
	default:
		system("cls");
		printf("\n\n\n\t\t\t-----------------ERROR----------------\n\n\n");
		printf("\n\n\n\t\t\t----Plese Enter From 0 to 2 only----");
		printf("\n\n\n\t\t\t------press any key To Go Back------");
		getch();
		main();
	}
	authenticateUser();
	menu();
	return 0;
}
