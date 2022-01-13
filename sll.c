#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node 
{
	char USN[20];
	char name[20];
	char dept[20];
	int sem;
	char phno[20];
	struct node *link;
};
typedef struct node * NODE;
NODE ins_front(char usn[],char name[],char dept[],int sem,char phno[],NODE first)
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	strcpy(temp->USN,usn);
	strcpy(temp->name,name);
	strcpy(temp->dept,dept);
	temp->sem=sem;
	strcpy(temp->phno,phno);
	temp->link=first;
	return temp;
}
NODE ins_rear(char usn[],char name[],char dept[],int sem,char phno[],NODE first)
{
	NODE temp,cur;
	temp=(NODE)malloc(sizeof(struct node));
	strcpy(temp->USN,usn);
	strcpy(temp->name,name);
	strcpy(temp->dept,dept);
	temp->sem=sem;
	strcpy(temp->phno,phno);
	temp->link=NULL;
	if(first==NULL)
		return temp;
	cur=first;
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=temp;
	return first;
}
NODE del_front(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("The list is empty\n");
		return first;
	}
	temp=first;
	first=first->link;
	printf("Student data deleted are\nUSN=%s\nName=%s\nDept=%s\nSem=%d\nPhno=%s\n",temp->USN,temp->name,temp->dept,temp->sem,temp->phno);
	free(temp);
	return first;
}
NODE del_rear(NODE first)
{
	NODE prev,cur;
	if(first==NULL)
	{
		printf("The list is empty\n");
		return first;
	}
	if(first->link==NULL)
	{
		printf("Student data deleted are\nUSN=%s\nName=%s\nDept=%s\nSem=%d\nPhno=%s\n",first->USN,first->name,first->dept,first->sem,first->phno);
		free(first);
		return NULL;
	}
	prev=NULL;
	cur=first;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	prev->link=NULL;
	printf("Student data deleted are\nUSN=%s\nName=%s\nDept=%s\nSem=%d\nPhno=%s\n",cur->USN,cur->name,cur->dept,cur->sem,cur->phno);
	free(cur);
	return first;
}
void view(NODE first)
{
	NODE cur;
	int ct=0;
	if(first==NULL)
	{
		printf("The list is empty\nNumber of nodes in the list is %d\n",ct);
		return;
	}
	cur=first;
	printf("Contents of the list are\n");
	while(cur!=NULL)
	{
		ct++;
		printf("USN=%s\nName=%s\nDept=%s\nSem=%d\nPhno=%s\n",cur->USN,cur->name,cur->dept,cur->sem,cur->phno);
		cur=cur->link;
	}
	printf("Number of nodes in the list is %d\n",ct);
}
void main()
{
	int n,i,ch,sem;
	char usn[20],name[20],dept[20],phno[20];
	NODE first;
	first=NULL;
	printf("Enter the number of students\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the details\n");
		scanf("%s%s%s%d%s",usn,name,dept,&sem,phno);
		first=ins_front(usn,name,dept,sem,phno,first);
	}
	for(;;)
	{
		printf("1.Insert Front 2.Insert Rear 3.Delete Front 4.Delete Rear 5.Display 6.Exit\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the details\n");
				scanf("%s%s%s%d%s",usn,name,dept,&sem,phno);
				first=ins_front(usn,name,dept,sem,phno,first);
				break;
			case 2:printf("Enter the details\n");
				scanf("%s%s%s%d%s",usn,name,dept,&sem,phno);
				first=ins_rear(usn,name,dept,sem,phno,first);
				break;
			case 3:first=del_front(first);
				break;
			case 4:first=del_rear(first);
				break;		
			case 5:view(first);
				break;
			case 6:exit(0);
		}
	}
}

		
