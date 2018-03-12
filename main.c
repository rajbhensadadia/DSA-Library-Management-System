#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


//structures declaration
struct book
{
	int ID;
	char name[50];
	char author[30];
	char cat[20];
	int qty;
	int rackno;
};
struct issue_book
{
	int book_ID;
	char book_name[50];
	int s_rollno;
	char s_name[20];
	char issuedate [9];
	char duedate [9];
};
struct student
{
	int s_rollno;
	char s_name[20];
	int s_qty;
	int fine;
};
int main()
{
	int book_details();
	int issue_details(char*);
	int student_details();
	int choice;

	char duedate[9];

	printf("\n\n\n\n\n\t\t\t\tEnter Due Date(mm/dd/yy):");
	scanf("%s",duedate);

	while(1)
	{
		system("cls");
		printf("\n\n\n\n\t\xDB\xDB\xDB\xDb\xB2     MENU     \xDB\xDB\xDB\xDb\xB2");
		printf("\n\t\xDB\xDb\xB2 1.Book Details");
		printf("\n\t\xDB\xDb\xB2 2.Issue Details");
		printf("\n\t\xDB\xDb\xB2 3.Student Details");
		printf("\n\t\xDB\xDb\xB2 4.Close Application");
		printf("\n\t\xDB\xDb\xB2 Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				book_details();
				break;
			case 2:
				issue_details(duedate);
				break;
			case 3:
				student_details();
				break;
			case 4:
				return(0);
		}
	}
}
int book_details()
{
	struct book data;
	//function declaration
	void add_book();
	void edit_book();
	void delete_book();
	void search_book();
	void view_book_list();

	int choice;

	while(1)
    {
    	system("cls");
    	printf("\n\n\n\n\t\xDB\xDB\xDB\xDb\xB2 BOOK DETAILS \xDB\xDB\xDB\xDb\xB2");
		printf("\n\t\xDB\xDb\xB2 1. Add Book");
		printf("\n\t\xDB\xDb\xB2 2. Edit Book");
		printf("\n\t\xDB\xDb\xB2 3. Delete Book");
		printf("\n\t\xDB\xDb\xB2 4. Search Book");
		printf("\n\t\xDB\xDb\xB2 5. View Book List");
		printf("\n\t\xDB\xDb\xB2 6. Back");
		printf("\n\t\xDB\xDb\xB2 Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				add_book();
				break;
			case 2:
				edit_book();
				break;
			case 3:
				delete_book();
				break;
			case 4:
				search_book();
				break;
			case 5:
				view_book_list();
				break;
			case 6:
				return(0);
		}
	}
}
void add_book()
{
	FILE *fp = NULL;
	struct book i;

	fp=fopen("book.dat","ab");

	if(fp != '\0')
	{
		system("cls");
    	printf("\n\n\n\n\t\xDB\xDB\xDB\xDb\xB2 ENTER BOOK DETAILS \xDB\xDB\xDB\xDb\xB2");
		printf("\n\t\xDB\xDB\xB2 Book Id: ");
		scanf("%d",&i.ID);
		printf("\t\xDB\xDb\xB2 Book Name: ");
		scanf("\n");
		gets(i.name);
		printf("\t\xDB\xDb\xB2 Author Name: ");
		scanf("\n");
		gets(i.author);
		printf("\t\xDB\xDb\xB2 Book Category: ");
		scanf("%s",i.cat);
		printf("\t\xDB\xDb\xB2 Rack No: ");
		scanf("%d",&i.rackno);
		printf("\t\xDB\xDb\xB2 Book Quantity: ");
		scanf("%d",&i.qty);
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\tFile is not found");
	}
	fwrite(&i,sizeof(i),1,fp);
	fclose(fp);
}
void edit_book()
{
	void book_detail_printer(struct book);
	int book_data_counter();

	FILE *fin = NULL;
	FILE *fout = NULL;

	struct book i;
	int bookid,count=0;

	fin=fopen("book.dat","rb");
	fout=fopen("copied.dat","wb");

	if(fin != '\0')
	{
		system("cls");
		printf("\n\n\n\n\t");
		printf("Enter Book ID which you want to EDIT");
		scanf("%d",&bookid);
		fread(&i,sizeof(i),1,fin);
		while(!feof(fin))
		{
			if(i.ID==bookid)
			{
				system("cls");
				book_detail_printer(i);
				printf("\n\t\xDB\xDB\xDB\xDb\xB2 EDIT BOOK DETAILS \xDB\xDB\xDB\xDb\xB2");
				printf("\n\t\xDB\xDb\xB2 Book Id: ");
				scanf("%d",&i.ID);
				printf("\t\xDB\xDb\xB2 Book Name: ");
				scanf("\n");
				gets(i.name);
				printf("\t\xDB\xDb\xB2 Author Name: ");
				scanf("\n");
				gets(i.author);
				printf("\t\xDB\xDb\xB2 Book Category(Thriller, Inspirational, Comedy, Drama): ");
				scanf("%s",i.cat);
				printf("\t\xDB\xDb\xB2 Rack No: ");
				scanf("%d",&i.rackno);
				printf("\t\xDB\xDb\xB2 Book Quantity: ");
				scanf("%d",&i.qty);
			}
			else
			{
				fwrite(&i,sizeof(i),1,fout);
				count++;
			}
			fread(&i,sizeof(i),1,fin);
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\t");
		printf("File is not found");
	}
	if(count==book_data_counter())
	{
		system("cls");
		printf("\n\n\n\n\t");
		printf(" Book Data not found! (please add it)");
	}
	else
	{
		printf("\n\tData is successfully edit");
	}


	fclose(fin);
	fclose(fout);

	remove("book.dat");
	rename("copied.dat","book.dat");

	int exit;
	printf("\n\n\n\t\xDB\xDb\xB2");
	printf("Press (0) for EXIT:");
	scanf("%d",&exit);
}
void delete_book()
{
	int book_data_counter();

	FILE *fin = NULL;
	FILE *fout = NULL;

	struct book i;

	int bookid,count=0;


	fin=fopen("book.dat","rb");
	fout=fopen("copied.dat","wb");

	if(fin != '\0')
	{
		system("cls");
		printf("\n\n\n\n\t");
		printf("Enter Book id which you want to delete: ");
		scanf("%d",&bookid);
		fread(&i,sizeof(i),1,fin);
		while(!feof(fin))
		{
			if(i.ID==bookid)
			{
				printf("\n\n\tA record with requested no found and deleted.");
			}
			else
			{
				fwrite(&i,sizeof(i),1,fout);
				count++;
			}
			fread(&i,sizeof(i),1,fin);
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\t");
		printf("File is not found");
	}
	if(count==book_data_counter())
	{
		system("cls");
		printf("\n\n\n\n\t");
		printf(" Book Data not found! (please add it)");
	}
	fclose(fin);
	fclose(fout);

	remove("book.dat");
	rename("copied.dat", "book.dat");

	int exit;
	printf("\n\n\n\t\xDB\xDb\xB2");
	printf("Press (0) for EXIT:");
	scanf("%d",&exit);
}
void search_book()
{
	void name_search();
     void id_search();
     void author_search();
	void cat_search();

	int choice;

	system("cls");
   	printf("\n\n\n\n\t\xDB\xDB\xDB\xDb\xB2 ENTER BOOK DETAILS \xDB\xDB\xDB\xDb\xB2");
    printf("\n\t\xDB\xDb\xB2 1.Search by BOOK name");
    printf("\n\t\xDB\xDb\xB2 2.Search by BOOK id");
    printf("\n\t\xDB\xDb\xB2 3.Search by BOOK author");
    printf("\n\t\xDB\xDb\xB2 4.Search by BOOK category(Thriller, Comedy, Drama, Inspirational)");
	printf("\n\t\xDB\xDb\xB2 Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {
		case 1:
        	name_search();
        	break;
		case 2:
        	id_search();
        	break;
		case 3:
        	author_search();
        	break;
		case 4:
        	cat_search();
        	break;
    }
}
void name_search()
{
    FILE *fp = NULL;
    char bookname[20];
    struct book i;
    int count=0;

    void book_detail_printer(struct book);
    int book_data_counter();

    fp=fopen("book.dat","rb");

    if(fp != '\0')
	{
		system("cls");
		printf("\n\n\n\t\xDB\xDb\xB2");
		printf(" Enter Book Name: ");
		scanf("%s",bookname);
		fread(&i,sizeof(i),1,fp);
		while(!feof(fp))
		{
			if(!strcmp(i.name,bookname))
			{
				book_detail_printer(i);
			}
			else
			{
				count++;
			}
			fread(&i,sizeof(i),1,fp);
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\tFile is not found");
	}
	if(count==book_data_counter())
	{
		system("cls");
		printf("\n\n\n\n\tBook Data not found! (please add it)");
	}

	fclose(fp);
	int exit;
	printf("\n\n\n\t\xDB\xDb\xB2");
	printf("Press (0) for EXIT:");
	scanf("%d",&exit);

}
void author_search()
{
    FILE *fp = NULL;
    char nameauthor[20];
    struct book i;
    int count=0;

    void book_detail_printer(struct book);
    int book_data_counter();

    fp=fopen("book.dat","rb");

    if(fp != '\0')
	{
		system("cls");
		printf("\n\n\n\t\xDB\xDb\xB2");
		printf(" Enter Author Name");
		scanf("%s",nameauthor);
		fread(&i,sizeof(i),1,fp);
		while(!feof(fp))
		{
			if(!strcmp(i.author,nameauthor))
			{
				book_detail_printer(i);
			}
			else
			{
				count++;
			}
			fread(&i,sizeof(i),1,fp);
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\tFile is not found");
	}
	if(count==book_data_counter())
	{
		system("cls");
		printf("\n\n\n\n\tBook Data not found! (please add it)");
	}

	fclose(fp);
	int exit;
	printf("\n\n\n\t\xDB\xDb\xB2");
	printf("Press (0) for EXIT:");
	scanf("%d",&exit);
}
void cat_search()
{
    FILE *fp = NULL;
    char bookcategory[20];
    struct book i;
    int count=0;

    void book_detail_printer(struct book);
    int book_data_counter();

    fp=fopen("book.dat","rb");

    if(fp != '\0')
	{
		system("cls");
		printf("\n\n\n\t\xDB\xDb\xB2");
		printf(" Enter Book Category:");
		scanf("%s",bookcategory);
		fread(&i,sizeof(i),1,fp);
		while(!feof(fp))
		{
			if(!strcmp(i.cat,bookcategory))
			{
				book_detail_printer(i);
			}
			else
			{
				count++;
			}
			fread(&i,sizeof(i),1,fp);
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\tFile is not found");
	}
	if(count==book_data_counter())
	{
		system("cls");
		printf("\n\n\n\n\tBook Data not found! (please add it)");
	}

	fclose(fp);
	int exit;
	printf("\n\n\n\n\t\xDB\xDb\xB2");
	printf("Press (0) for EXIT:");
	scanf("%d",&exit);
}
void id_search()
{
    FILE *fp = NULL;
    int bookid;
    struct book i;
    int count=0;

    void book_detail_printer(struct book);
    int book_data_counter();

    fp=fopen("book.dat","rb");

    if(fp != '\0')
	{
		system("cls");
		printf("\n\n\n\n\t\xDB\xDb\xB2");
		printf(" Enter Book ID:");
		scanf("%d",&bookid);
		fread(&i,sizeof(i),1,fp);
		while(!feof(fp))
		{
			if(i.ID==bookid)
			{
				book_detail_printer(i);
			}
			else
			{
				count++;
			}
			fread(&i,sizeof(i),1,fp);
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\tFile is not found");
	}
	if(count==book_data_counter())
	{
		system("cls");
		printf("\n\n\n\n\tBook Data not found! (please add it)");
	}

	fclose(fp);
	int exit;
	printf("\n\n\n\t\xDB\xDb\xB2");
	printf("Press (0) for EXIT:");
	scanf("%d",&exit);
}
void view_book_list()
{
	FILE *fp = NULL;
	struct book i;
	void book_detail_printer(struct book);

	fp=fopen("book.dat","rb");

	system("cls");
	if(fp != '\0')
	{
		fread(&i,sizeof(i),1,fp);
		while(!feof(fp))
		{
			book_detail_printer(i);
			fread(&i,sizeof(i),1,fp);
		}
	}
	else
	{
		printf("File is not found");
	}
	fclose(fp);
	int exit;
	printf("\n\n\n\n\t\xDB\xDb\xB2");
	printf("Press (0) for EXIT:");
	scanf("%d",&exit);
}
void book_detail_printer(struct book i)
{
	printf("\t---------------------------------------------------------------------\n");
	printf("\tBook ID|Book Name      |Author Name    |Category  |Rack no.|Quantity|\n");
	printf("\t---------------------------------------------------------------------\n");
	printf("\t%7d|%-15s|%-15s|%-10s| %7d|%8d|\n",i.ID,i.name,i.author,i.cat,i.rackno,i.qty);
}
int issue_details(char *duedate)
{
	struct issue_book;

	void issue_book(char*);
	void cancel_issue();
	void check_issue();

	int choice;

	while(1)
	{
		system("cls");
    	printf("\n\n\n\n\t\xDB\xDB\xDB\xDb\xB2 ISSUE DETAILS \xDB\xDB\xDB\xDb\xB2");
		printf("\n\t\xDB\xDb\xB2 1.Issue a book");
		printf("\n\t\xDB\xDb\xB2 2.Cancel Issued Data");
		printf("\n\t\xDB\xDb\xB2 3.Issued details of particular book");
		printf("\n\t\xDB\xDb\xB2 4.Back");
		printf("\n\t\xDB\xDb\xB2 Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				issue_book(duedate);
				break;
			case 2:
				cancel_issue();
				break;
			case 3:
				check_issue();
				break;
			case 4:
				return(0);
		}
	}
}
void issue_book(char *duedate)
{
	void qty_changer(int,int);
	void s_qty_changer(int,int);

	FILE *fbook = NULL;
	FILE *fstudent = NULL;
	FILE *fp = NULL;
	struct student k;
	struct book j;
	struct issue_book i;

	char filename[10];

	int bookid,rollno;

	system("cls");
	printf("\n\n\n\n\t\xDB\xDb\xB2 Enter Book ID");
	scanf("%d",&bookid);

	itoa(bookid, filename, 10);

	fp=fopen(filename,"ab");
	fbook=fopen("book.dat","rb+");
	fstudent=fopen("student.dat","rb+");

	if(fbook != '\0')
	{
		printf("\n\t\xDB\xDb\xB2 Enter Student Rollno : ");
		scanf("%d",&rollno);

		fread(&k,sizeof(k),1,fstudent);
		while(!feof(fstudent))
		{
			if(k.s_rollno==rollno)
			{
				if(k.s_qty<2)
				{
					printf("\n\t\xDB\xDb\xB2 Roll no: %d",k.s_rollno);
					printf("\t\xB2 Student Name: %s",k.s_name);
					i.s_rollno=k.s_rollno;
					strcpy(i.s_name,k.s_name);

					fread(&j,sizeof(j),1,fbook);
					while(!feof(fbook))
					{
						if(j.ID==bookid)
						{
							printf("\n\t\xDB\xDb\xB2 Book ID: %d",j.ID);
							printf("\t\xB2 Book Name: %s",j.name);
							i.book_ID=j.ID;
							strcpy(i.book_name,j.name);
						}
						fread(&j,sizeof(j),1,fbook);
					}
					fclose(fbook);

					printf("\n\tBook is Issued");
				}

				else
				{
					system("cls");
					printf("\n\n\n\n\tStudent has issued 2 books");
				}
			}
			fread(&k,sizeof(k),1,fstudent);
		}
		fclose(fstudent);

		_strdate(i.issuedate);
		strcpy(i.duedate,duedate);
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\tFile is not found");
	}

	fwrite(&i,sizeof(i),1,fp);
	fclose(fp);
	qty_changer(bookid,1);
	s_qty_changer(rollno,1);

	int exit;
	printf("\n\n\n\t\xDB\xDb\xB2");
	printf("Press (0) for EXIT:");
	scanf("%d",&exit);
}
void cancel_issue()
{
	void qty_changer(int,int);
	void s_qty_changer(int,int);

	FILE *fin = NULL;
	FILE *fout = NULL;

	struct issue_book i;

	int rollno;

	int bookid;

	char filename[10];

	system("cls");
	printf("\n\n\n\n\t\xDB\xDb\xB2 Enter Book ID");
	scanf("%d",&bookid);

	itoa(bookid,filename, 10);

	fin=fopen(filename,"rb");
	fout=fopen("copied.dat","wb");

	if(fin != '\0')
	{
		printf("\n\t\xDB\xDb\xB2 Enter Student Rollno to cancel return book");
		scanf("%d",&rollno);
		fread(&i,sizeof(i),1,fin);
		while(!feof(fin))
		{
			if(i.s_rollno=rollno)
			{
				system("cls");
				printf("\n\n\n\n\tA record with requested no found and deleted.");
			}
			else
			{
				fwrite(&i,sizeof(i),1,fout);
			}
			fread(&i,sizeof(i),1,fin);
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\tFile is not found");
	}
	fclose(fin);
	fclose(fout);

	remove(filename);
	rename("copied.dat", filename);

	qty_changer(bookid,2);
	s_qty_changer(rollno,2);
	int exit;
	printf("\n\n\n\t\xDB\xDb\xB2");
	printf("Press (0) for EXIT:");
	scanf("%d",&exit);
}
void check_issue()
{
	FILE *fp=NULL;
	struct issue_book i;

	char filename[10];

	system("cls");
	printf("\n\n\n\n\t\xDB\xDb\xB2 Enter Book ID ");
	scanf("%s",filename);  // CHECK: BOOK ID INSTEAD OF FILENAME

	fp=fopen(filename,"rb");

	if(fp != '\0')
	{
		fread(&i,sizeof(i),1,fp);
		while(!feof(fp))
		{
			printf("\t--------------------------------------------------------------------------------------\n");
			printf("\tBook ID|Book Name      |Student Rollno.    |Student Name      |Issue Date |Due Date  |\n");
			printf("\t--------------------------------------------------------------------------------------\n");
			printf("\t%7d|%-15s|%19d|%-18s|%10s|%10s|\n",i.book_ID,i.book_name,i.s_rollno,i.s_name,i.issuedate,i.duedate);
			fread(&i,sizeof(i),1,fp);
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\tFile is not found");
	}
	fclose(fp);

	int exit;
	printf("\n\n\n\t\xDB\xDb\xB2");
	printf("Press (0) for EXIT:");
	scanf("%d",&exit);
}
void qty_changer(int bookid,int checker)
{
	FILE *fin = NULL;
	FILE *fout = NULL;

	struct book i;

	fin=fopen("book.dat","rb");
	fout=fopen("copied.dat","wb");

	fread(&i,sizeof(i),1,fin);
	while(!feof(fin))
	{
		if(i.ID==bookid)
		{
			if(checker==1)
				i.qty--;
			else if(checker==2)
				i.qty++;
			fwrite(&i,sizeof(i),1,fout);
		}
		else
		{
			fwrite(&i,sizeof(i),1,fout);
		}
		fread(&i,sizeof(i),1,fin);
	}
	fclose(fin);
	fclose(fout);

	remove("book.dat");
	rename("copied.dat","book.dat");
}
void s_qty_changer(int rollno,int checker)
{
	FILE *fin = NULL;
	FILE *fout = NULL;

	struct student i;

	fin=fopen("student.dat","rb");
	fout=fopen("copied.dat","wb");

	fread(&i,sizeof(i),1,fin);
	while(!feof(fin))
	{
		if(i.s_rollno==rollno)
		{
			if(checker==1)
				i.s_qty++;
			else if(checker==2)
				i.s_qty--;
			fwrite(&i,sizeof(i),1,fout);
		}
		else
		{
			fwrite(&i,sizeof(i),1,fout);
		}
		fread(&i,sizeof(i),1,fin);
	}
	fclose(fin);
	fclose(fout);

	remove("student.dat");
	rename("copied.dat","student.dat");
}
int student_details()
{
	struct student;
	int choice;

	void add_student();
	void student_fine();
	void student_search();

	while(1)
	{
		system("cls");
    	printf("\n\n\n\n\t\xDB\xDB\xDB\xDb\xB2 STUDENT DETAILS \xDB\xDB\xDB\xDb\xB2");
		printf("\n\t\xDB\xDb\xB2 1.Add student details");
		printf("\n\t\xDB\xDb\xB2 2.Add Fine charges to student");
		printf("\n\t\xDB\xDb\xB2 3.Student search");
		printf("\n\t\xDB\xDb\xB2 4.Back");
		printf("\n\t\xDB\xDb\xB2 Enter your choice");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				add_student();
				break;
			case 2:
				student_fine();
				break;
			case 3:
				student_search();
				break;
			case 4:
				return(0);
		}
	}
}
void add_student()
{
	FILE *fp = NULL;
	struct student i;

	fp=fopen("student.dat","ab");

	if(fp != '\0')
	{
		system("cls");
    	printf("\n\n\n\n\t\xDB\xDB\xDB\xDb\xB2 ENTER STUDENT DETAILS \xDB\xDB\xDB\xDb\xB2");
		printf("\n\t\xDB\xDB\xB2 Student Rollno.: ");
		scanf("%d",&i.s_rollno);
		printf("\t\xDB\xDB\xB2 Student Name: ");
		scanf("\n");
		gets(i.s_name);
		i.s_qty=0;
		i.fine=0;
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\tFile is not found");
	}
	fwrite(&i,sizeof(i),1,fp);
	fclose(fp);
}
void student_fine()
{
	FILE *fin = NULL;
	FILE *fout = NULL;

	struct student i;

	int rollno;

	int money;

	fin=fopen("student.dat","rb");
        fout=fopen("copied.dat","wb");

	if(fin != '\0')
	{
		system("cls");
		printf("\n\n\n\n\tEnter student Roll no. who to pay Fine");
		scanf("%d",&rollno);
		fread(&i,sizeof(i),1,fin);
		while(!feof(fin))
		{
			if(i.s_rollno==rollno)
			{
				system("cls");
				printf("\n\t\xDB\xDB\xB2 Roll no: %d",i.s_rollno);
				printf("\n\t\xDB\xDB\xB2 Student Name: %s",i.s_name);
				printf("\n\t\xDB\xDB\xB2 Enter fine to pay");
				scanf("%d",&money);

				i.fine+=money;

				fwrite(&i,sizeof(i),1,fout);
			}
			else
			{
				fwrite(&i,sizeof(i),1,fout);
			}
			fread(&i,sizeof(i),1,fin);
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\tFile is not found");
	}

	fclose(fin);
	fclose(fout);

	remove("student.dat");
	rename("copied.dat","student.dat");
}
void student_search()
{
	FILE *fp = NULL;

	struct student i;

	int rollno;


	fp=fopen("student.dat","rb");

	if(fp != '\0')
	{
		system("cls");
		printf("\n\n\n\n\tEnter Student Rollno");
		scanf("%d",&rollno);
		fread(&i,sizeof(i),1,fp);
		while(!feof(fp))
		{
			if(i.s_rollno==rollno)
			{
				printf("\t-------------------------------------------------------------\n");
				printf("\tStudent Rollno. |Student Name      |Book Issued |Fine Paied |\n");
				printf("\t-------------------------------------------------------------\n");
				printf("\t%16d|%-18s|%12d|%11d|\n",i.s_rollno,i.s_name,i.s_qty,i.fine);
			}
			fread(&i,sizeof(i),1,fp);
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\tFile is not found");
	}
	fclose(fp);
	int exit;
	printf("\n\n\n\t\xDB\xDb\xB2");
	printf("Press (0) for EXIT:");
	scanf("%d",&exit);
}
int book_data_counter()
{
	FILE *fp;
	int count=0;

	struct book i;

	fp=fopen("book.dat","rb");

	fread(&i,sizeof(i),1,fp);
	while(!feof(fp))
	{
		count++;
		fread(&i,sizeof(i),1,fp);
	}
	fclose(fp);

	return count;
}
int student_data_counter()
{
	FILE *fp;
	int count=0;

	struct student i;

	fp=fopen("student.dat","rb");

	fread(&i,sizeof(i),1,fp);
	while(!feof(fp))
	{
		count++;
		fread(&i,sizeof(i),1,fp);
	}
	fclose(fp);

	return count;
}
