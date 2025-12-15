#include<iostream>
#include<string>
using namespace std ;
const int Max=100;
string title[Max];
string author[Max];
bool available[Max];
int bookcounter=0;

void initializeLibrary() {
 title[0] = "Artificial Intelligence: A Modern Approach";
 author[0] = "Stuart Russell & Peter Norvig";
 available[0] = true;
 title[1] = "C++ Primer";
 author[1] = "Stanley B. Lippman";
 available[1] = true;
 title[2] = "Digital Design and Computer Architecture";
 author[2] = "David Harris & Sarah Harris";
 available[2] = true;
 title[3] = "Data Structures and Algorithms in C++";
 author[3] = "Adam Drozdek";
 available[3] = true;
 title[4] = "Computer Networks";
 author[4] = "Andrew S. Tanenbaum";
 available[4] = true;
 bookcounter = 5; 
}

void addBook(){
  if(bookcounter>=Max){
   cout<<"The library is full.📚\n";
   return;
  }
 cout<<"Enter the name of the book✍️:";
 getline(cin,title[bookcounter]);
 cout << "Enter the author's name✍️:";
 getline(cin,author[bookcounter]);
 available[bookcounter]=true;
 bookcounter++;
 cout << "A book has been successfully added✅" << endl;
}

int searchBook(string name){
  for(int i=0;i<bookcounter;i++){
   if(title[i]==name){
   return i;}
  } return -1;
}

void borrowBook(){
 string name;
 cout << "Enter the name of the book✍️📖:";
 getline(cin,name);
 int index=searchBook(name);
 if(index==-1){
  cout << "The book is not available🙍." << endl;}
 else if(available[index]){
  available[index]=false;
 cout <<"The book has been borrowed successfully👍." << endl;}
 else{
 cout << "The book is already borrowed." << endl;
 cout << "Come another time🕰️." << endl;}
}

void returnBook(){
  string name;
  cout << "Enter the name of the book✍️: ";
  getline(cin, name);
  int index = searchBook(name);
  if (index == -1)
  cout << "Book not found.\n";
  else if (!available[index]) {
   available[index] = true;
   cout << "Book returned successfully ✅.\n";
 }
 else
 cout << "Book is already available.\n";
}

void displayBook(){
 if(bookcounter==0){
  cout << "There are no books🫣." << endl;
 return ;}
 for(int i=0;i<bookcounter;i++){
  cout << i+1<<"." << title[i]<<"-"<<author[i]<<"-"<<endl;
  if(available[i])
  cout << "Available." << endl;
  else
  cout << "Borrowed." << endl;
 }
}
 
int menu(){
 int choice;
 cout << "\tMenu:\n1-Add book.\n2-Search book🔎.\n3-Borrow book." << endl;
 cout << "4-Return book🔄📚.\n5-Display all books.\n6-Exit." << endl;
 cout << "\tChoice from the menu📋:";
 cin>>choice;
 return choice ;
}

int main(){
 initializeLibrary();
 int choice ;
 do{
  choice=menu();
  cin.ignore();
  switch(choice){
   case 1:{
    addBook();
   }break;
   case 2: {
    string name;
    cout << "Enter the book's name✍️: ";
    getline(cin, name);
    int index = searchBook(name);
    if (index == -1)
    cout << "The book is not available.\n";
    else {
     cout << title[index] << " - " << author[index] << " - ";
     if (available[index])
     cout << "Available\n";
     else
     cout << "Borrowed\n";
    }
   }break;
   case 3: borrowBook(); break;
   case 4: returnBook(); break;
   case 5: displayBook(); break;
   case 6: {cout << "Thank you for using my program! 😍.\n"; 
   cout << "\tLibrary supervisors:\n\tMenna Allah Mohsen.\n\tSomaya Anwar Salem.\n\tAisha Mohamed Samih.\n\tAisha Mohamed Rabie.\n\tAisha Ahmed Fattouh.\n ";
   }break;
   default: cout << "Incorrect choice.\n";
  }
 } while (choice != 6);
 return 0;
}
