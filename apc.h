#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


typedef struct list{
  int data;
  struct list *prev;
  struct list *next;
}node;

#define SUCCESS 0
#define FAILURE -1


void usage_message();

int cla_validation(int argc,char *argv[]);
int create_list(char *opr,node **head,node **tail);

int insert_first(node **head,node **tail,int data);
int insert_last(node **head,node **tail,int data);
int delete_list(node **head,node **tail);
void print_list(node *head);

int list_length(node *head);
int add_zeros(node **head,node **tail ,int lan);





int addition(node *tail1,node *tail2,node **headR,node **tailR);
int subtraction(node *tail1,node *tail2,node **headR,node **tailR);
int multiplication(node *tail1,node *tail2,node **headR,node **tailR);
int division(node *head1,node *head2,node **headR,node **tailR);

