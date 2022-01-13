#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *link;
};
typedef struct node * NODE;
NODE ins_front(int item,NODE first)
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	temp->info=item;
	temp->link=first;
	return temp;
}
int countnodes(NODE first)
{
	NODE cur;
	int ct=0;
	cur=first;
	while(cur!=NULL)
	{
		ct++;
		cur=cur->link;
	}
	return ct;
}
NODE concatenate(NODE first,NODE second)
{
	NODE cur;
	if(first==NULL)
		return second;
	if(second==NULL)
		return first;
	cur=first;
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=second;
	return first;
}
NODE reverse(NODE first)
{
	NODE temp,cur;
	if(first==NULL)
		return first;
	temp=NULL;
	while(first!=NULL)
	{	
		cur=first;
		first=first->link;
		cur->link=temp;
		temp=cur;
	}
	return temp;
}
void view(NODE first)
{
	NODE cur;
	if(first==NULL)
	{
		printf("The list is empty\n");
		return;
	}
	cur=first;
	printf("The contents of the list are\n");
	while(cur!=NULL)
	{
		printf("%d\n",cur->info);
		cur=cur->link;
	}
}
NODE del_info(int item,NODE first)
{
	NODE cur,temp,prev,next;
	if(first==NULL)
	{
		printf("The list is empty\n");
		return first;
	}
	if(item==first->info)
	{
		temp=first;
		first=first->link;
		printf("Item deleted is %d\n",temp->info);
		free(temp);
		return first;
	}
	prev=NULL;
	cur=first;
	while(cur!=NULL&&item!=cur->info)
	{
		prev=cur;
		cur=cur->link;
	}
	if(cur==NULL)
	{
		printf("Item not found\n");
		return first;
	}
	next=cur->link;
	prev->link=next;
	printf("Item deleted is %d\n",cur->info);
	free(cur);
	return first;
}
NODE ins_pos(int item,int pos,NODE first)
{
	NODE prev,cur,temp;
	int ct;
	temp=(NODE)malloc(sizeof(struct node));
	temp->info=item;
	temp->link=NULL;
	if(first==NULL)
		return temp;
	if(pos==1)
	{
		temp->link=first;
		return temp;
	}
	prev=NULL;
	cur=first;
	ct=1;
	while(cur!=NULL&&ct!=pos)
	{
		prev=cur;
		cur=cur->link;
		ct++;
	}
	if(ct!=pos)
	{
		printf("Invalid Position\n");
		free(temp);
		return first;
	}
	prev->link=temp;
	temp->link=cur;
	return first;
}
void main()
{
	int n1,n2,i,item,ch,ct1,ct2,pos;
	NODE first=NULL,second=NULL;
	printf("Enter the number of elements in list 1\n");
	scanf("%d",&n1);
	printf("Enter the elements\n");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&item);
		first=ins_front(item,first);
	}
	printf("Enter the number of elements in list 2\n");
	scanf("%d",&n2);
	printf("Enter the elements\n");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&item);
		second=ins_front(item,second);
	}	
	for(;;)
	{
		printf("1.Count\n2.Concatenate\n3.Reverse List1\n4.Reverse List2\n5.Display List1\n6.Display List2\n7.Delete Info in list1\n8.Delete Info in list2\n9.Insert Position in list1\n10.Insert Position in list2\n11.Exit\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ct1=countnodes(first);
				ct2=countnodes(second);
				printf("Number of nodes in list1 is %d and list 2 is %d\n",ct1,ct2);
				break;
			case 2:first=concatenate(first,second);
				break;
			case 3:first=reverse(first);
				break;
			case 4:second=reverse(second);
				break;
			case 5:view(first);
				break;
			case 6:view(second);
				break;
			case 7:printf("Enter the item to be deleted\n");
				scanf("%d",&item);
				first=del_info(item,first);
				break;
			case 8:printf("Enter the item to be deleted\n");
				scanf("%d",&item);
				second=del_info(item,second);
				break;
			case 9:printf("Enter the item and position to be inserted\n");
				scanf("%d%d",&item,&pos);
				first=ins_pos(item,pos,first);
				break;
			case 10:printf("Enter the item and position to be inserted\n");
				scanf("%d%d",&item,&pos);
				second=ins_pos(item,pos,second);
				break;
			case 11:exit(0);
		}
	}
}

				
