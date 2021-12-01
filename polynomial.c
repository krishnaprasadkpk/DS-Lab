#include<stdio.h>

#define MAX_TERMS 100
typedef struct{
float coeff;
int expo;
}polynomial;
polynomial terms[MAX_TERMS];
int avail=0;

void attach(float coefficient,int exponent)
{
 if(avail>=MAX_TERMS)
  {fprintf(stderr,"\ntoo many terms");exit(EXIT_FAILURE);}
 terms[avail].coeff=coefficient; 
 terms[avail].expo=exponent;
 avail++;
}

int COMPARE(int exp1, int exp2)
{
if(exp1>exp2)
  return 1;
else if(exp1<exp2)
  return -1;
else if(exp1==exp2)
  return 0;
}

void polyadd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
 float coefficient;
 *startD=avail;
 while(startA<=finishA&&startB<=finishB)
 {
  switch(COMPARE(terms[startA].expo, terms[startB].expo))
  {
   case 1:attach(terms[startA].coeff, terms[startA].expo);
   		startA++;
   		break;
   case -1:attach(terms[startB].coeff, terms[startB].expo);
   		startB++;
   		break;
   case 0:coefficient=terms[startA].coeff+terms[startB].coeff;
   		if(coefficient)
   		{
   		  attach(coefficient, terms[startA]);
   		  startA++;
   		  startB++;
   		  break;
   		}
  }
 }
 for(;startA<=finishA;startA++)
  attach(terms[startA].coeff,terms[startA].expo);
  *finishD=avail-1;
 }
 void main()
 {
  int i=0,n1,n2,startA=0,finishA,startB,finishB,startD,finishD,coefficient,exponent;
  printf("\nEnter number of terms in first Polynomial");
  scanf("%d",&n1);
  for(;i<n1;i++)
  {
   printf("Enter coefficient");
   scanf("%d",&coefficient);
   printf("Enter exponent");
   scanf("%d",&exponent);
   attach(coefficient,exponent);
  }
  finishA=avail-1;
  startB=avail;
  printf("\nEnter number of terms in second Polynomial");
  scanf("%d",&n2);
  for(i=0;i<n2;i++)
  {
   printf("Enter coefficient");
   scanf("%d",&coefficient);
   printf("Enter exponent");
   scanf("%d",&exponent);
   attach(coefficient,exponent);
  }
  finishB=avail-1;
 polyadd(startA,finishA,startB,finishB,&startD,&finishD);
 printf("first polynomial\n");
 for(i=startA;i<finishA;i++)
 {
  printf("%.2fx^%d+",terms[i].coeff,terms[i].expo);
 }
  printf("%.2fx^%d",terms[i].coeff,terms[i].expo);
 printf("\nsecond polynomial\n");
 for(i=startB;i<finishB;i++)
 {
  printf("%.2fx^%d+",terms[i].coeff,terms[i].expo);
 }
 printf("%.2fx^%d",terms[i].coeff,terms[i].expo);
 printf("\nresultant polynomial\n");
 for(i=startD;i<finishD;i++)
 {
  printf("%.2fx^%d+",terms[i].coeff,terms[i].expo);
 }
 printf("%.2fx^%d",terms[i].coeff,terms[i].expo);
}


