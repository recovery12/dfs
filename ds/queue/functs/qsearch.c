#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define MAX          50

/********* DATA-STRUCTURE DEFINITION *********/
typedef struct queue3
{
   int        front, rear;
   int        items[MAX];
} Queue;

void initialize(Queue *q)
{
   q->front = MAX-1;
   q->rear = MAX-1;
   return ;
}

int isempty(Queue *q)
{
   return q->front == q->rear;
}

int isfull(Queue *q)
{
   return q->rear == q->front;
}

void insert(Queue *q, int val)
{
   if (q->rear == MAX-1)
   {
      q->rear = 0;
   }
   else
   {
      q->rear++;
   }

   if (isfull(q))
   {
      printf("Queue is full, can't insert more elements.\n");
      q->rear--;
      return ;
   }
   q->items[q->rear] = val;

   return ;
}

int delete(Queue *q)
{
   int        hold;

   if (isempty(q))
   {
      printf("Queue is empty, can't delete any elements.\n");
      return -1;
   }
   else
   {
      if (q->front == MAX-1)
      {
         q->front = 0;
      }
      else
      {
         q->front++;
      }
      hold = q->items[q->front];
   }

   return hold;
}

int qsearch(Queue *q, int val)
{
   int        index = q->front;

   if (isempty(q))
   {
      printf("Queue is empty, can't display any elements.\n");
      return -2;
   }
   else
   {
      while (index != q->rear)
      {
         if (index == MAX-1)
         {
            index = 0;
         }

         if (val == q->items[index])
         {
            return index;
         }
         index++;
      }
      printf("\n");
   }

   return -1;
}

/********* MAIN STARTS HERE *********/
int main()
{
   int       i, val;
   Queue     q;

   initialize(&q);

   for (i = 0; i < 53; i++)
   {
      insert(&q, i);
   }
   val = qsearch(&q, 53);
   printf("%d found \n", val);

   exit(0);
}
