#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct node{
       char character;
       float percent_dist;
       struct node* right;
       struct node* left;
       string binarycode;
       };

 
void InsertionSort(struct node* array_of_pointers[], int size)
{       
         struct node* value;
         int i, j, counter;
     
         for(int i = 1; i < size; i++)
         {
                value = array_of_pointers[i]; 
                j = i-1;
                while ((j >= 0) && (array_of_pointers[j]->percent_dist > value->percent_dist))
                { 
                         array_of_pointers[j + 1] = array_of_pointers[j];
                         j--;
                }
                
                array_of_pointers[j+1] = value;                 
         }
       
} 
void GenerateCode(struct node* treeroot)
{       
        string backup;

        if(treeroot->left == NULL)
        {
             cout << treeroot->character << ": " << treeroot->binarycode << endl;
        }
        else
        {
             backup = treeroot->binarycode;
             backup.append(1, '0');
             treeroot->left->binarycode = backup;

             backup = treeroot->binarycode;
             backup.append(1, '1');
             treeroot->right->binarycode = backup;

             GenerateCode(treeroot->left);
             GenerateCode(treeroot->right);
        }
}


struct node* NewNode(char value, float percent_dist_value)
       {
       struct node* newnode = new node;
       newnode->character = value;
       newnode->percent_dist = percent_dist_value;
       newnode->left = NULL;
       newnode->right = NULL;

       return newnode;
       }

struct node* MakeHuffmanTree(struct node* array_of_pointers[], int size)
{
       int counter = 0;
       float temp;
       struct node* newnode;
       
       while(counter < size)
       {
                 temp =  array_of_pointers[counter]->percent_dist + array_of_pointers[counter+1]->percent_dist;     //add the two percent dist values

                 newnode = NewNode(';', temp);     //  make a new node

                 newnode->right = array_of_pointers[counter+1];
                 newnode->left = array_of_pointers[counter];
                 array_of_pointers[counter+1] = newnode;

                 InsertionSort(array_of_pointers, size);
                  
                 counter++;
       }

       return array_of_pointers[counter - 1];
}

int main()
{
  int counter = 0;
  int counter2 = 25;

  struct node* treeroot;
  struct node* newnode;

  float percent_dist_values[26] = {11.74, 8.65, 8.15, 7.97, 7.44, 7.42, 6.76, 5.94, 5.35, 4.13, 3.81, 3.22, 2.84, 2.77, 2.70, 2.15, 2.03, 1.65, 1.35, 1.09, 0.88, 0.85, 0.45, 0.29, 0.20, 0.19};
  char letters[26] = {'e', 'i', 's', 'a', 'r', 'n', 't', 'o', 'l', 'c', 'd', 'u', 'g', 'p', 'm', 'h', 'b', 'y', 'f', 'v', 'k', 'w', 'z', 'x', 'j', 'q'};
   
  struct node* array_of_pointers[26];

  while(counter < 26)       // create the array of pointers to nodes
  {
       newnode = NewNode(letters[counter], percent_dist_values[counter]);
       array_of_pointers[counter2] = newnode;
       counter2--;
       counter++;
   }
   
   treeroot = MakeHuffmanTree(array_of_pointers, 26);  // make the tree out of the list and return to the root pointer

   counter = 0;


 
   GenerateCode(treeroot);

   system("PAUSE");
   return 0;
}


