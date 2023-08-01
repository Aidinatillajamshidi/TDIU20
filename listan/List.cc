#include "List.h"
#include <iostream>
#include <iomanip>
#include <utility>
#include <sstream>

//Lägga allt i rätt ordning i slutändan
//Skapa en copy funktion

/////////////////////////////////////////////////////////////////////////////
//Konstruktor
Sorted_list::Sorted_list()
  :firstptr{nullptr}, lastptr{nullptr}
{
}

Sorted_list::~Sorted_list() //Rensar minnet
{
  if(empty() == false)
    {
      Node* temp{firstptr};
      
      while(temp != lastptr)
	{
	  temp = temp -> nextptr;
	  delete temp -> prevptr;
	}
    }
}

Sorted_list::Sorted_list(Sorted_list const& list) //lvalue
{
  for(int i{0}; i < list.class_size(); i++)
    {
      insert(list.compare(i));
    }
}

Sorted_list::Sorted_list(Sorted_list && list) //rvalue
{
  std::swap(list.firstptr, firstptr);
  std::swap(list.lastptr, lastptr);
}

Sorted_list::Sorted_list(std::initializer_list<int> const &list)
  : Sorted_list()
{
  for(int i : list)
    {
      insert(i);
    }
}

Sorted_list& Sorted_list::operator=(Sorted_list const& list)
{
  Sorted_list temp{list};

  std::swap(firstptr, temp.firstptr);
  std::swap(lastptr, temp.lastptr);
  std::swap(sorted_size, temp.sorted_size);
  
  return *this;
}

Sorted_list& Sorted_list::operator=(Sorted_list && list)
{
  std::swap(list.firstptr, firstptr);
  std::swap(list.lastptr, lastptr);
  std::swap(list.sorted_size, sorted_size);

  return *this;
}

Sorted_list::Node::Node(Node* nextptr, Node* prevptr, int list)
  :nextptr{nextptr}, prevptr{prevptr}, node_size{list}
{
}
/////////////////////////////////////////////////////////////////////////////   
bool Sorted_list::empty() const
{
  if(firstptr == nullptr)
    {
      return true;
    }
  else
    { 
      return false;
    }
}

void Sorted_list::copy(Sorted_list const& list)
{
  if(list.lastptr -> node_size == list.firstptr -> node_size)
    {
    return;
    }
  Node* posptr = list.lastptr -> prevptr;
  
  while(posptr != list.firstptr)
    {
      insert(posptr -> node_size);
      posptr = posptr -> prevptr;
    }
  if(posptr == list.firstptr)
    {
      insert(posptr -> node_size);
    }
}

int Sorted_list::compare(int const& list) const
{
  if(list < class_size())
    {
      Node* temp{firstptr};

      for(int i{0}; i < list; i++)
	{
	  temp = temp -> nextptr;
	}
      return temp -> node_size;
    }
  else
    {
      throw std::logic_error("Innehållet stämmer inte med listan");
    }
}

void Sorted_list::remove(int const& pos)
{
  Node* temp = firstptr;

  for (int i = pos; i > 0; i--){
    temp = temp->nextptr;
  }

  if (temp->prevptr == nullptr && temp->nextptr == nullptr){
    delete temp;
    firstptr = nullptr;
    lastptr = nullptr;

  } else if (temp->nextptr == nullptr){
    lastptr = temp->prevptr;
    lastptr->nextptr = nullptr;
    delete temp;
  } else if (temp->prevptr == nullptr) {
    firstptr = temp->nextptr;
    firstptr->prevptr = nullptr;
    delete temp;
  } else {
    temp->prevptr->nextptr = temp->nextptr;
    delete temp;
  }
  sorted_size--;
}

int Sorted_list::class_size() const
{
  return sorted_size;
}

void Sorted_list::insert(int const& data)
{
  if(empty() == true)
    {
      firstptr = new Node {nullptr, nullptr, data};
      lastptr = firstptr;
    }
  else
    {
      Node* temp{firstptr};
      
      if (data < temp -> node_size)
	{
	  firstptr = new Node{temp, nullptr, data};
	  temp -> prevptr = firstptr;
	}
      else
	{
	  while(data > temp -> node_size && temp -> nextptr != nullptr)
	    {
	      temp = temp -> nextptr;
	    }
	  if(temp -> node_size >= data)
	    {
	      Node* temp1{temp};
	      
	      temp = temp -> prevptr;
	      temp -> nextptr = new Node{temp1, temp, data};
	      temp1 -> prevptr = temp -> nextptr;
	    }
	  else
	    {
	      temp -> nextptr = new Node{nullptr, temp, data};
	      lastptr = temp -> nextptr;
	    }
	}          
    }
  sorted_size++;
}

std::ostream& operator<<(std::ostream& ostr, Sorted_list const& list)
{
  for(int i{0}; i < list.class_size(); i++)
    {
      ostr << list.compare(i);

      if((i+1) != list.class_size())
	{
	  ostr << " ";
	}
    }
  return ostr;
}
//////////////////////////////////////////////////////////////////////////////
//Gammal kod för säkerhet
/*
void Sorted_list::clear()
{
  Node* posptr{firstptr};
  
  while(posptr != lastptr)
    {
      posptr = posptr -> nextptr;
      delete firstptr;
      firstptr = posptr;
    }
  lastptr -> prevptr = nullptr;
  delete lastptr;
}
*/
