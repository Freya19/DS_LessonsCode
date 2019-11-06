#ifndef LIST_H
#define LIST_H

class IteratorMismatchException
{};

template <typename Object>
class List
{
private:
    struct Node
    {
	   Object  data;
	   Node   *prev;
	   Node   *next;

	   Node( const Object & d = Object( ), Node *p = 0, Node *n = 0 )
		  : data( d ), prev( p ), next( n ) { }
    };

public:
    class const_iterator
    {
    public:
	   const_iterator( ) : current( 0 )
	   { }

	   const Object & operator* ( ) const
	   { return retrieve( ); }

	   const_iterator & operator++ ( )
	   {
		  current = current->next;
		  return *this;
	   }

	   const_iterator operator++ ( int )
	   {
		  const_iterator old = *this;
		  ++( *this );
		  return old;
	   }

	   bool operator== ( const const_iterator & rhs ) const
	   { return current == rhs.current; }
	   bool operator!= ( const const_iterator & rhs ) const
	   { return !( *this == rhs ); }

    protected:
	   const List<Object> *theList;
	   Node *current;

	   Object & retrieve( ) const
	   { return current->data; }


	   const_iterator(Node *p) : current(p)
	   {}

	   const_iterator( const List<Object> & lst, Node *p )
		  : theList( &lst ), current( p )
	   {
	   }

	   void assertIsValid( ) const
	   {
		  if( theList == 0 || current == 0 || current == theList->head )
			 throw IteratorOutOfBoundsException( );
	   }

	   friend class List<Object>;
    };


    class iterator : public const_iterator
    {
    public:
	   iterator( )
	   { }

	   Object & operator* ( )
	   { return retrieve( ); }
	   const Object & operator* ( ) const
	   { return const_iterator::operator*( ); }

	   iterator & operator++ ( )
	   {
		  current = current->next;
		  return *this;
	   }

	   iterator operator++ ( int )
	   {
		  iterator old = *this;
		  ++( *this );
		  return old;
	   }

    protected:
	   iterator( Node *p ) : const_iterator( p )
	   { }

	   friend class List<Object>;
    };

public:
    List( )
    { init( ); }

    ~List( )
    {
	   clear( );
	   delete head;
	   delete tail;
    }

    List( const List & rhs )
    {
	   init( );
	   *this = rhs;
    }

    const List & operator= ( const List & rhs )
    {
	   if( this == &rhs )
		  return *this;
	   clear( );
	   for( const_iterator itr = rhs.begin( ); itr != rhs.end( ); ++itr )
		  push_back( *itr );
	   return *this;
    }

    iterator begin()
    { return iterator(head->next);}
    const_iterator begin() const
    { return const_iterator(head->next);}
    iterator end()
    { return iterator(tail);}
    const_iterator end() const
    { return const_iterator(tail); }

    int size() const
    { return theSize; }
    bool empty() const
    { return size() == 0; }

    void clear()
    {
	   while(!empty())
		  pop_front();
    }

    Object & front( )
    { return *begin( ); }
    const Object & front( ) const
    { return *begin( ); }
    Object & back( )
    { return *--end( ); }
    const Object & back( ) const
    { return *--end( ); }
    void push_front( const Object & x )
    { insert( begin( ), x ); }
    void push_back( const Object & x )
    { insert( end( ), x ); }
    void pop_front( )
    { erase( begin( ) ); }
    void pop_back( )
    { erase( --end( ) ); }

    //// Insert x before itr.
    //iterator insert( iterator itr, const Object & x )
    //{
    //    itr.assertIsValid( );
    //    if( itr.theList != this )
    //        throw IteratorMismatchException( );
    //
    //    Node *p = itr.current;
    //    theSize++;
    //    return iterator( *this,
    //                     p->prev = p->prev->next = new Node( x, p->prev, p ) );
    //}

    // Insert x before itr.
    iterator insert( iterator itr, const Object & x )
    {
        Node *p = itr.current;
        theSize++;
        return iterator( p->prev = p->prev->next = new Node( x, p->prev, p ) );
    }

    // Erase item at itr.
    iterator erase( iterator itr )
    {
	   Node *p = itr.current;
	   iterator retVal( p->next );
	   p->prev->next = p->next;
	   p->next->prev = p->prev;
	   delete p;
	   theSize--;

	   return retVal;
    }

    iterator erase( iterator start, iterator end )
    {
	   for( iterator itr = from; itr != to; )
		  itr = erase( itr );

	   return to;
    }

private:
    int   theSize;
    Node *head;
    Node *tail;

    void init( )
    {
	   theSize = 0;
	   head = new Node;
	   tail = new Node;
	   head->next = tail;
	   tail->prev = head;
    }
};

#endif