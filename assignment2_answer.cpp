#include <iostream>
#include <queue>
#include<string>
#include <vector>
#include<cstring>
#include<string.h>
#include <algorithm>
#include <cstdlib>
#define MAX 1000
using namespace std;
//---------------------------------------- Stack using Linked List. --------------------------------------------
// Class of the node .
template <class T> class Node
{
public:
   T data;
   Node *next;
};
// Creating a class STACK
template <class T> class TStackList
{
	Node <T> *top;
public:
      TStackList()
      {
	 top=NULL;
      }
      void Push(); // to insert an element
      void Pop();  // to delete an element
      void Show(); // to show the stack
};
//----------------------------------------
// PUSH Operation
template <class T> void TStackList <T> ::Push()
{
   T value;
   Node <T> *ptr;
   cout<<"\nPUSH Operation\n";
   cout<<"Enter a number to insert: ";
   cin>>value;
   ptr=new Node <T>;
   ptr->data=value;
   ptr->next=NULL;
   if(top!=NULL)
      ptr->next=top;
   top=ptr;
   cout<<"\nYeah! New item inserted :)";
}
//----------------------------------------
// POP Operation
template <class T> void TStackList <T> ::Pop()
{
   Node <T> *temp;
   if(top==NULL)
   {
      cout<<"\nOhh!! The stack is empty :(";
      return;
   }
   temp=top;
   top=top->next;
   cout<<"\nPOP Operation........\nPoped value is "<<temp->data;
   delete temp;
}
//----------------------------------------
// Show stack
template <class T> void TStackList <T> ::Show()
{
   Node <T> *ptr1=top;
   cout<<"\nThe stack is\n";
   while(ptr1!=NULL)
   {
      cout<<ptr1->data<<" ->";
      ptr1=ptr1->next;
   }
   cout<<"NULL\n";
}
//---------------------------------------- Reverse a string using stacks. --------------------------------------
class node
{
public:
   char data;
   node *next;
};

// Creating a class STACK
class stack
{
	node *top;
   public:
      stack()
      {
	 top=NULL;
      }
      void Push(char value);   // to insert an element
      char Pop();              // to delete an element
      string reverseArray();

};
// PUSH Operation
void stack::Push(char value)
{
   node *ptr;
   ptr=new node;
   ptr->data=value;
   ptr->next=NULL;
   if(top!=NULL)
      ptr->next=top;
   top=ptr;
}
// POP Operation
char stack::Pop()
{
   node *temp;
   if(top==NULL)
   {
      cout<<"\nThe stack is empty!!!";
      return NULL;
   }
   temp=top;
   char x = temp->data;
   top=top->next;
   delete temp;
   return x;
}
string reverseArray(){
    stack s;
    char chararray[100] = {'H','e','l','l','o',' ','W','o','r','l','e','d'};
    for (int i=0;i<strlen(chararray);i++){
        s.Push(*(chararray+i));
    }
	cout<<"\nString is inserted to the stack!!!\n";
	string reverseWord;
	for (int i =0; i<strlen(chararray);i++){
	    reverseWord.push_back(s.Pop());
	}
	cout << "String after reversing is : ";
	return reverseWord;
}
//---------------------------------------- Palindromes. --------------------------------------------------------
class strStack {
  int top1;
  int top2;
public:
  char x[MAX];     // Maximum size
  char y[MAX];     // Maximum size
  strStack() { top1 = -1;top2 = -1; }
  bool Push1 (char value);
  bool Push2 (char value);
  char Pop1();
  char Pop2();
  bool isEmpty_1();
  bool isEmpty_2();
  bool checkPalindrome(int len);
};
//----------------------------------------
bool strStack::Push1(char value)
{
    if (top1 >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        x[++top1] = value;
        cout << value << " pushed into stack\n";
        return true;
    }
}
//----------------------------------------
bool strStack::Push2(char value)
{
    if (top2 >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        y[++top2] = value;
        cout << value << " pushed into stack\n";
        return true;
    }
}
//----------------------------------------
char strStack::Pop1()
{
    if (top1 < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        char value = x[top1--];
        return value;
    }
}
//----------------------------------------
char strStack::Pop2()
{
    if (top2 < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        char value = y[top2--];
        return value;
    }
}
//----------------------------------------
bool strStack :: checkPalindrome(int len){

  for (int i = 0; i< len/2; i++){
    if (tolower(Pop1()) != tolower(Pop2())){
      return false;
    }
  }
  cout << "String is Palindrome . . . .";
  return true;
}
//----------------------------------------
static string removeSpaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}
//                                           ******* CALLING OF THE FUNCTION *******

//---------------------------------------- Implement a stack using a singly linked list. ----------------------------------------
//===============================================================================================================================
/*
int main()
{
   TStackList <int> s;
   int choice;
   while(1)
   {
      cout<<"\n-----------------------------------------------------------";
      cout<<"\n\t\t STACK USING LINKED LIST \n\n";
      cout<<"1:PUSH \n2:POP \n3:DISPLAY STACK \n4:EXIT";
      cout<<"\nEnter your choice(1-4): ";
      cin>>choice;
      switch(choice)
      {
       case 1:
	  s.Push();
	  break;
       case 2:
	  s.Pop();
	  break;
       case 3:
	  s.Show();
	  break;
       case 4:
	  exit(0);
	  break;
       default:
	  cout<<"Please enter correct choice(1-4)!!";
	  break;
       }
   }
   return 0;
}
*/
//---------------------------------------- Reverse a string using stacks. ----------------------------------------
//================================================================================================================
/*
int main(){
    cout << reverseArray();
}
*/
//---------------------------------------- Check Palindromes using 2 stacks. -------------------------------------
//================================================================================================================
/*
int main()
{
  class strStack s;
  string str = "Murder for a jar of redrum";
  str = removeSpaces(str);
  int len = removeSpaces(str).length();
  if (len%2==0){
    for (int i = len/2; i < len ; i++){
      s.Push1(str[i]);
    }
    for (int i = len/2; i >= 0 ; i--){
      s.Push2(str[i]);
    }
  }
  else{
    for (int i = len/2; i < len ; i++){
      s.Push1(str[i]);
    }
    for (int i = len/2; i >= 0 ; i--){
      s.Push2(str[i]);
    }
  }
  s.checkPalindrome(len);
  return 0;
}
*/
//---------------------------------------- Implement a stack using a queue -------------------------------------
//==============================================================================================================
/*
int main()
{
    queue <int> q;
    int count;
    int choice;
    cout << "1. Push into a stack .\n";
    cout << "2. Pop into a stack .\n";
    cout << "3. Print the stack. \n";
    cout << "4. Exit the program. \n";
    do{
        cout << "Enter the choice ? \n";
        cin >> choice;
        switch (choice){
        case 1:
            {
                int data;
                cout << "Enter the item to push ? \n";
                cin >> data;
                q.push(data);
                count++;
                break;
            }
        case 2:
            {
                if (q.empty()){
                    cout << "Queue is empty !";
                }
                else{
                    for (int i=0;i<count-1;i++){
                        int k = q.front();
                        q.pop();
                        q.push(k);
                    }
                    count--;
                    cout << "Popped item is " << q.front() << "\n";
                    q.pop();
                }
                break;
            }
        case 3:
            {
                if (q.empty()){
                    cout << "Stack is empty !! /n";
                }
                else{
                    for(int i=0;i<count;i++){
                        cout << q.front() << " ";
                        q.push(q.front());
                        q.pop();
                    }
                }
                break;
            }
        case 4:
            {
              return 0;
            }
        default:
            {
                cout << "please Enter a valid choice !! ";
            }
    }
}while(choice != 4);
return 0;
}
*/
//=======================================================================================
