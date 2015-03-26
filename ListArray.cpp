/**
*Lab3: List                               ListArray.cpp
*Claire Ujeneza & Christian Uwimana & Jerry Groom
*2/22/2015
*/

#include "ListArray.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <typename DataType>
List<DataType>::List(int maxNumber)
{
 maxSize=maxNumber;
 size=0;
 cursor=-1;
  dataItems=new DataType[maxSize];
}
//copy constructor
template <typename DataType>
List<DataType>::List(const List& source){
maxSize=source.maxSize;
size= source.size;
cursor=source.cursor;
dataItems = new DataType [maxSize];
    for ( int i = 0; i<size ; i++){
        dataItems[i]= source.dataItems[i];
    }
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& source)
{

  if (this!= & source){

    delete [] dataItems;
    size=source.size;
    maxSize=source.maxSize;
    cursor=source.cursor;
   dataItems=new DataType [maxSize];

  }
  for(int i=0;i<size;i++){
    dataItems[i]=source.dataItems[i];
  }

return *this;
}

template <typename DataType>
List<DataType>::~List()
{
    delete[] dataItems;
}
template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)
{
    if (size==maxSize)
		  throw logic_error("List is full");
	 else
	 {

           for(int i = size-1; i>cursor; i--){
            DataType initialI= dataItems[i] ;
            dataItems[i]=dataItems[i+1];
            dataItems[i+1]=initialI;
           }
        dataItems[cursor+1] = newDataItem;

size++;
cursor++;
	 }
}
//}
//    if (size==maxSize)
//		  throw logic_error("List is full");
//	 else
//	 {
//
//		 if (size!=0)
//		 {
//		//DataType temp=dataItems[cursor+1];
////		for(int i=size-1;i>cursor;i--){
////`
////
////		}
//             dataItems[cursor+1]=newDataItem;
//
//             cursor++;
//		 }
//		 else if(size==0)
//		 {
//		dataItems[0]=newDataItem;
//		 }
//
//size++;
////cursor++;
//	 }
//    }

template <typename DataType>
void List<DataType>::remove() throw (logic_error)
{
     if(size==0){
         throw logic_error("the list is empty");
     }else{
		 if (cursor == size-1)
		 {
			 size--;
			 gotoBeginning();
		 }
		 else
		 {
			 for (int i = cursor;i<size;i++)
			 {
				 dataItems[i]=dataItems[i+1];
			 }
		 size--;
		 }
	 }

}
template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{

 if(size==0){
        throw logic_error("The List is full");
 }
 else{


        dataItems[cursor]=newDataItem; //Set the dataItems cursor Index value = to newDataItems value.
 }
}


template <typename DataType>
void List<DataType>::clear()
{

	size  = 0;
	cursor=0;

}
template <typename DataType>
bool List<DataType>::isEmpty() const        // isEmpty
{

   if(size==0)
		return true;
	else
		return false;
}


template <typename DataType>            // is full method
bool List<DataType>::isFull() const
{
  if(size!= MAX_LIST_SIZE)
		return false;
	else
		return true;
}

template <typename DataType>
void List<DataType>::gotoBeginning()   throw (logic_error)        //go to the beginning
{
    if(size==0){
        throw logic_error("The List is empty");
    }
    else{
        cursor = 0;
    }

}

template <typename DataType>
void List<DataType>::gotoEnd()     throw (logic_error)             //go to the end
{
    if(size==0){
        throw logic_error("The List is empty");
    }
    else{
        cursor = size - 1;
    }
}


template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{

if(size==0){
    throw logic_error("The List is empty");
}
else{
    if(cursor<size-1){
        cursor++;
        return true;
    }
}
return false;
}


template <typename DataType>
bool List<DataType>::gotoPrior()   throw (logic_error)
{
    if(isEmpty()){
    throw logic_error("The List is empty");
}
else{
  if(cursor!=0){
    cursor--;
    return true;
  }
}
return false;
}


template <typename DataType>
DataType List<DataType>::getCursor() const         throw (logic_error)
{

 if (isEmpty())
    throw logic_error("list is empty");
else
  return dataItems[cursor];

}



template <typename DataType>
void List<DataType>:: showStructure () const

// outputs the data items in a list. if the list is empty, outputs
// "empty list". this operation is intended for testing/debugging
// purposes only.

{
    int j;   // loop counter

    if ( size == 0 )
       cout << "empty list" << endl;
// The Ordered List code blows up below. Since this is just debugging
// code, we check for whether the OrderedList is defined, and if so,
// print out the key value. If not, we try printing out the entire item.
// Note: This assumes that you have used the double-inclusion protection
// in your OrderedList.cpp file by doing a "#ifndef ORDEREDLIST_CPP", etc.
// If not, you will need to comment out the code in the section under
// the "else", otherwise the compiler will go crazy in lab 4.
// The alternative is to overload operator<< for all data types used in
// the ordered list.
    else
    {
       cout << "size = " << size
            <<  "   cursor = " << cursor << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ ) {
	   if( j == cursor ) {
	      cout << "[";
              cout << dataItems[j]
#ifdef ORDEREDLIST_CPP
	      .getKey()
#endif
	      ;
	      cout << "]";
 	      cout << "\t";
	   }
	   else
	      cout << dataItems[j]
#ifdef ORDEREDLIST_CPP
	      .getKey()
#endif
	      << "\t";
       }
       cout << endl;
    }
}



