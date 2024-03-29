/*!
  \file   disjoint_sets.cpp
  \author Dmitri Volper
  \par    email: dvolper\@digipen.edu
  \date   Tue 29 Jun 2010 09:03:15 PM PDT
  \brief  implementation of classes DisjointSets, Head, Node
*/
#include "disjoint_sets.h"

//class Node implementation
Node::Node( size_t const& value ) : value(value), next() {}

Node* Node::Next() const { return next; }

void  Node::SetNext( Node* new_next ) { next = new_next; }

size_t Node::Value() const { return value; }

std::ostream& operator<< (std::ostream& os, Node const& node) {
	os << "(" << node.value << " ) -> ";
	return os;
}

//class Head implementation
Head::Head( ) : counter(), first(), last() {} 

Head::~Head() {
  Node* runner = first;
  if (runner)
  {
    runner = first->Next();
    while (runner)
    {
      delete first;
      first = runner;
      runner = runner->Next();
    }
    delete first;
  }
}

size_t Head::Size() const      { return counter; }

void   Head::Reset()           { counter = 0; last = first = NULL; }

Node*  Head::GetFirst() const  { return first; }

Node*  Head::GetLast()  const  { return last; }

void   Head::Init( size_t value ) {
	first = last = new Node( value );
	counter = 1;
}

void   Head::Join( Head* pHead2 ) 
{
  if (last)
  {
    last->SetNext(pHead2->GetFirst());
  }
  else if (first)
  {
    first->SetNext(pHead2->first);
  }
  else
  {
    first = pHead2->first;
  }
  last = pHead2->GetLast();
  counter += pHead2->counter;
}

std::ostream& operator<< (std::ostream& os, Head const& head) {
	os << "[" << head.counter << " ] -> ";
	return os;
}

//class DisjointSets implementation
DisjointSets::DisjointSets( size_t const& capacity ) : 
	size(0),
	capacity(capacity),
	representatives(new size_t[capacity]),
	heads          (new Head[capacity])
{ }

DisjointSets::~DisjointSets() {
	delete [] heads;
	delete [] representatives;
}

void DisjointSets::Make( ) {
	if ( size == capacity ) throw "DisjointSets::Make(...) out of space";
	heads[size].Init( size );
	representatives[size] = size;
	++size;
}

void DisjointSets::Join( size_t const& id1, size_t const& id2 ) 
{
  if (representatives[id1] == representatives[id2])
  {
    return;
  }
  size_t first = id1;
  size_t second = id2;
  if (heads[representatives[first]].Size() > heads[representatives[second]].Size())
  {
    std::swap(first, second);
  }
  heads[representatives[second]].Join(&heads[representatives[first]]);
  heads[representatives[first]].Reset();
  representatives[representatives[first]] = representatives[second];//?? not sure
}

size_t DisjointSets::GetRepresentative( size_t const& id ) const {
	return representatives[id];
}

size_t DisjointSets::operator[]( size_t const& id ) const {
	return representatives[id];
}

std::ostream& operator<< (std::ostream& os, DisjointSets const& ds) {
	for (size_t i=0; i<ds.size; ++i ) {
		os << i << ":  ";
		Head *p_head = &ds.heads[i];
		os << *p_head;
		Node* p_node = p_head->GetFirst();
		while ( p_node ) {
			os << *p_node;
			p_node = p_node->Next();
		}
		os << "NULL (representative " << ds.representatives[i] << ")\n";
	}
	return os;
}
