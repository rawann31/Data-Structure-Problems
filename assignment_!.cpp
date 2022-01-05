#include <iostream>
#include <string>
#include<string.h>
using namespace std;
//-------------------------------------------------------------------(SLL)----------------------------------------------------------------------
// class node
class Node{
public:
  Node* next;
  string data;
  virtual void TSortedList(){}
  virtual void insertNewNode(string dataOfNode){}
};
Node* head;
//-------------------------
class SortSinglyList : public Node{
  void TSortedList(){
  string temp;
  Node *current;
    for(int i=0;i<4;i++){
        current = head;
        for (int j= 1; j<4; j++){
            if ((current->data) < ((current->next)-> data)){
                temp = current->data;
                current->data = (current->next)-> data;
                (current->next)-> data = temp;
            }
            current = current-> next;
            if (current == NULL){break;}
        }
    }
    current = head;
    for (int k = 0; k < 4;k++){
      cout << current->data << "\t";
      current = current->next;
    }
  }
//-------------------------
  void insertNewNode(string dataOfNode){
  Node* new_node = new Node();
  new_node->next = NULL;
  new_node->data = dataOfNode;
  if (head == NULL){
    head = new_node;
    return;
    }
  Node *current = head;
  while (current-> next != NULL){
    current = current-> next;
    }
  current-> next = new_node;
  }
};
//-------------------------------------------------------------------(DLL)----------------------------------------------------------------------
class node{
public:
  node* next;
  node* prev;
  int data;
};
class SNode{
public:
  SNode* next;
  int data;
};
node* head1;
//-------------------------------------------------
class DuplicateManipuationList : public node{
public:
  void insertNewNode(int dataOfNode){
    node* new_node = new node();
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = dataOfNode;
    if (head1 == NULL){
      head1 = new_node;
      return;
    }
    node *current = head1;
    while (current-> next != NULL){
      current = current-> next;
    }
    new_node->prev = current;
    current-> next = new_node;
  }
//-------------------------------------------------
int removeDuplicates(SNode* temp){
    node* current = head1;
    int x = 0;
    while(current != NULL){
      if (head1->data == temp->data){
          head1 = current->next;
          current->next->prev = NULL;
          current->next = NULL;
          current = head1;
          x++;
          continue;
      }
      while(current->data != temp->data){
        if (current->next == NULL && current->data != temp->data){
          return x;
        }
        current = current->next;
      }
      if (current->next == NULL && current->data == temp->data){
         (current->prev)->next = NULL;
         current->prev = NULL;
         x++;
         return x;
      }
      (current->prev)->next = current->next;
      (current->next)->prev = current->prev;
      current->prev = NULL;
      node *del = current;
      current = current->next;
      del->next = NULL;
      x++;
      delete del;
    }
  return x;
  }
};
//------------------------------------------------------------------(ARRAY)---------------------------------------------------------------------
// Function that insert an element in a full array .
void fullArrayInsert(int *fullArray, int *newArray){
    for (int i = 0; i< 5;i++){
        *(newArray+i) = *(fullArray+i);
    }
    cout << "Write an element you want to insert : ";
    cin >> *(newArray+5);

}
//-------------------------
// Function that insert an element in a non full array .
void notFullarrayInsert(int *notFullArray){
    cout << "Write an element you want to insert : ";
    cin >> *(notFullArray+5);
}
//-------------------------
// Function that sort the array in descending order .
void arraySort(int *array){
    for (int i = 1; i <6; i++){
    int temp = array[i];
    int j = i - 1;
    while(j>=0 && temp > array[j]){
      array[i] = array[j];
      j--;
      }
      array[j+1] = temp;
    }
    // Another algorithm :
    /**
    int temp ;
    for(int i =1;i<8;i++){
        for (int j = i-1 ; j>=0;j--){
          temp = *(array+j+1);
            if (temp > *(array+j)){
            *(array+j+1) = *(array+j);
            *(array+j) = temp;
           }
        }
    }**/
}
//-------------------------
// Function that insert an element in its right position in a non sorted array .
void InsertionSort(int *array){
    int newElement;
    cout <<"Write a new an element to insert it in the sorted array : ";
    cin >> newElement;
    for (int i = 1 ;i<7;i++){
        if (newElement > *array){
            for(int j = 6;j>0;j--){
                array[j] = array[j-1];
            }
            *array = newElement;
            break;
        }
        if (newElement < *(array+5)){
            *(array+6) = newElement;
            break;
        }
        else if ((*(array)) >= newElement  && *(array+i) <= newElement ) {
            for (int j = 6; j > i ; j--){
                array [j] = array [j-1];
            }
            *(array+i) = newElement;
            break;
        }
    }
}
//-------------------------
void deleteElement(int* array){
    int order;
    cout << "Write element order you want to delete (1 => First , 2 => Second , . . . ): " ;
    cin >> order;
    for (int i=0;i<7;i++){
        if (i == (order-1)){
            for(int j = i; j<7;j++){
                array[j] = array[j+1];
            }
            break;
        }
    }
    cout <<endl<<endl;
    cout << "--------------------------------------------------------------------------"<<endl;
    cout << "Array After deleting is : ";
    for (int i = 0; i<6;i++){
        cout<<*(array+i)<<"\t";
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------(SLL)---------------------------------------------------------------------
/*
int main(){
    Node* bptr;
    SortSinglyList d;
    bptr = &d;
    bptr->insertNewNode("orange");
    bptr->insertNewNode("apple");
    bptr->insertNewNode("banana");
    bptr->insertNewNode("zebra");
    bptr->TSortedList();
    return 0;
}
*/
//-------------------------------------------------------------------(DLL)----------------------------------------------------------------------
/*
int main() {
  node bptr;
  DuplicateManipuationList dptr;
  dptr.insertNewNode(7);
  dptr.insertNewNode(15);
  dptr.insertNewNode(3);
  dptr.insertNewNode(2);
  dptr.insertNewNode(1);
  dptr.insertNewNode(3);
  dptr.insertNewNode(7);
  dptr.insertNewNode(15);
  dptr.insertNewNode(15);
  //--------------------------
  SNode* new_node1 = new SNode();
  new_node1->data = 7;
  SNode* new_node2 = new SNode();
  new_node2->next = NULL;
  new_node2->data = 15;
  new_node1->next = new_node2;
  new_node2 = NULL;
  //--------------------------
  new_node1->data = dptr.removeDuplicates(new_node1);
  (new_node1->next)->data = dptr.removeDuplicates(new_node1->next);
  cout << "Times that 7 appears is  : " << new_node1->data << "\n";
  cout << "Times that 15 appears is : " <<(new_node1->next)-> data << "\n";
  node* current = head1;
  cout << endl<<"List after remove duplicate is :  " << current->data << " , " << current->next->data << " , " << current->next->next->data << "\t";
  return 0;
}
*/
//------------------------------------------------------------------(ARRAY)---------------------------------------------------------------------

int main()
{
    int choice;
    int arrayFull[5] = {80,200,40,1000,930};       // Full array with size 5 .
    int arrayNotFull[10] = {80,200,40,1000,930};   // Not full array (Size = 10 , elements = 5)
    int arrayNew[15]={};                  //  We will allocate this larger array and copy elements from the old (Full) array to this new one .
    cout << "----------------------------- You have 2 arrays with elements {80,200,40,1000,930} in the order -----------------------"<<endl<<endl;
    cout << "1 => Full Array with size 5" <<"\t"<<", 2 => Not Full Array with size 10" <<endl;
    cout <<"Do you want an element to add in a full array or not a full array ? Write (1 or 2)  ";
    cin >> choice;
    switch (choice){
    case 1:
        cout <<endl<<endl;
        cout << "--------------------------------------------------------------------------"<<endl;
        cout << "Array before sorting is : ";
        for(int i = 0; i< 5; i++){
            cout << arrayFull[i] << "\t";
        }
        cout <<endl;
        fullArrayInsert(arrayFull, arrayNew);   // Insert element in a full array .
        arraySort(arrayNew);                    // Sort the array in descending order .
        cout <<endl<<endl<<endl;
        cout << "--------------------------------------------------------------------------"<<endl;
        cout << "Array After sorting is :  ";
        for(int i = 0; i< 6; i++){
            cout << arrayNew[i] << "\t";
        }
        cout <<endl<<endl;
        InsertionSort(arrayNew);
        cout <<endl<<endl;
        cout << "--------------------------------------------------------------------------"<<endl;
        cout << "Array After sorting is :  ";
        for(int i = 0; i< 7; i++){
            cout << arrayNew[i] << "\t";
        }
        cout <<endl<<endl;
        cout << "--------------------------------------------------------------------------"<<endl;
        deleteElement(arrayNew);
        break;
    case 2:
        cout <<endl<<endl;
        cout << "--------------------------------------------------------------------------"<<endl;
        cout << "Array before sorting is : ";
        for(int i = 0; i< 5; i++){
            cout << arrayNotFull[i] << "\t";
        }
        cout <<endl<<endl;
        notFullarrayInsert(arrayNotFull);      // Insert element in a not full array .
        arraySort(arrayNotFull);               // Sort the array in descending order .
        cout <<endl<<endl;
        cout << "--------------------------------------------------------------------------"<<endl;
        cout << "Array After sorting is : ";
        for(int i = 0; i< 6; i++){
            cout << arrayNotFull[i] << "\t";
        }
        cout <<endl<<endl;
        InsertionSort(arrayNotFull);
        cout <<endl<<endl;
        cout << "--------------------------------------------------------------------------"<<endl;
        cout << "Array After sorting is : ";
        for(int i = 0; i< 7; i++){
            cout << arrayNotFull[i] << "\t";
        }
        cout <<endl<<endl;
        cout << "--------------------------------------------------------------------------"<<endl;
        deleteElement(arrayNotFull);
        break;
    }
    return 0;
}

