//
//  main.cpp
//  PhoneBook_Directory.CSN_302work
//
//  Created by Lovedeep Singh on 18/08/18.
//  Copyright © 2018 Lovedeep. All rights reserved.
//

//
//  main.c
//  Phonebook_Directory_Work.CSN_302
//
//  Created by Lovedeep Singh on 18/08/18.
//  Copyright © 2018 Lovedeep. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 26
char econtact[10];char temp[10];
struct pnode
{
  struct pnode *hash[MAX];
  int is_end;
  char contact[10];
};
typedef struct pnode pnode;
pnode * root;pnode * crawl;
pnode * make()
{
   pnode * node=(pnode*) malloc(sizeof(pnode));
   for(int i=0;i<MAX;i++)
      node->hash[i]=NULL;
   node->is_end=0;
   return node;
}

void add(pnode**root,char*name,char*contact){
  if(!*root){
     *root=make();
   }
  crawl=*root;
  while(*name){
       if(!crawl->hash[*name-'a']){
          crawl->hash[*name-'a']=make();
       }
       crawl=crawl->hash[*name-'a'];
       name++;
  }
  if(!crawl->is_end){
     crawl->is_end=1;
     strcpy(crawl->contact,contact);
     }
}

void del(pnode**root,char*name){
     if(!*root)
       return;
     crawl=*root;
     while(*name){
         if(!crawl->hash[*name-'a'])
         return;
         crawl=crawl->hash[*name-'a'];
         name++;
     }
     crawl->is_end=0;
}

void find(pnode**root,char*name){
     if(!*root){
        printf("\nNOT FOUND");return;
     }
     crawl=*root;
     while(*name){
          if(!crawl->hash[*name-'a']){
          printf("\nNOT FOUND");return;
          }
          crawl=crawl->hash[*name-'a'];
          name++;
     }
     if(!crawl->is_end){
        printf("\nNOT FOUND");return;
     }
     printf("%s",crawl->contact);
     return;
}

int is_end(pnode*root){
    if(root->is_end)
       return 1;
    else
       return 0;
}

void display_all(pnode* root, char temp[], int level){
     if (is_end(root)){
         temp[level] = '\0';
         printf("%s\t",temp);
         printf("%s\n",root->contact);
     }
     for (int i=0;i<MAX;i++){
          if (root->hash[i]){
              temp[level] = i+'a';
              display_all(root->hash[i],temp,level+1);
          }
     }
}

int main(){
  printf("PHONE_BOOK");
  int choice;
  do{
     char name[10];
     char extern econtact[10];
     printf("\n\n1. ADD \n2. FIND \n3. DELETE \n4. DISPLAY ALL \n5. QUIT \n: ");
     scanf("%d",&choice);
     switch(choice){
       case 1:printf("\nNAME: ");
              scanf("%s",name);
              printf("\nNUMBER: ");
              scanf("%s",econtact);
              add(&root,name,econtact);
              break;
       case 2:printf("\nNAME: ");
              scanf("%s",name);
              find(&root,name);
              break;
       case 3:printf("\nNAME: ");
              scanf("%s",name);
              del(&root,name);
              break;
       case 4:display_all(root,temp,0);
       case 5:break;
       default:break;
     }
   }while(choice!=5);
  return 1;
}
