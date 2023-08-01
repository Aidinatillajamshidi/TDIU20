#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <sstream>
#include <initializer_list>
#include <iomanip>
#include <list>

//////////////////////////////////////////////////////////////////////////////
//Vår class
class Sorted_list
{ 
 public:

  Sorted_list(); //Konstruktor
  ~Sorted_list(); //Deconstructor. Förstör "instance" för att fria minne
  Sorted_list(Sorted_list const& list); //Copy
  Sorted_list(Sorted_list && list); //Move
  Sorted_list(std::initializer_list<int> const &list);
  Sorted_list& operator=(Sorted_list const &list); //Copy
  Sorted_list& operator=(Sorted_list && list); //Move
  
  bool empty() const;
  void copy(Sorted_list const& list);
  int compare(int const& list) const;
  void remove(int const& pos);
  int class_size() const;
  void insert(int const& data);
 private:
//////////////////////////////////////////////////////////////////////////////
//Vår dubbellänkade class
  class Node
  {
  public:
    Node(Node* nextptr, Node* prevptr, int list);
    Node* nextptr{nullptr};
    Node* prevptr{nullptr};
    int node_size;
  };
//////////////////////////////////////////////////////////////////////////////
  Node* firstptr{nullptr};
  Node* lastptr{nullptr};
  int sorted_size{};
};

std::ostream& operator<<(std::ostream& ostr, Sorted_list const& list);

#endif
//////////////////////////////////////////////////////////////////////////////
//Gammal kod för säkerhet
//void clear();
