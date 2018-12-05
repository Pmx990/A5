#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

template <typename hashedObj>

class hashTable
{
    int bucket;
    //list<hashedObj> *table;
    vector<list<hashedObj>> table;

public:
    hashTable(int size = 100);
    //hashTable(const hashTable& aTable);
   // hashTable& hashTable::operator = (const hashTable& aTable){
      //  hashTable(aTable);
   // }
   //~hashTable();
    bool insertItem(long long int key, hashedObj & val);
    bool find(const long long int key);
    //find will only return if found or not
    bool search(const long long int key);
    //search will output the result
    int hashFunction(long long int x) {
    long long int result = x % bucket;
    return (result);
    }
};

/*template<typename hashObj>
hashTable<hashObj>::hashTable(const hashTable& aTable){
    aTable.table = table;
}*/

template<typename hashedObj>
hashTable<hashedObj>::hashTable(int size_t) {
    this->bucket = size_t;
    table.reserve(size_t);
    table.resize(size_t);
    //table = new vector<list<hashedObj>>[bucket];
}
/*
template<typename hashedObj>
hashTable<hashedObj>::~hashTable(){
    table.clear();
}*/

template<typename hashedObj>
bool hashTable<hashedObj>::insertItem(long long int key, hashedObj & val) {
    int index = hashFunction(key);
    list<hashedObj> tempList = table[index];
    if (find(key)) {
        return false;
    }
    val = to_string(key) + "," + val;
    tempList.push_back(val);
    table[index] = tempList;
    //cout<<tempList.empty()<<"sp"<<endl;

    return true;

}
template <typename hashedObj>
bool hashTable<hashedObj>::find(const long long  int key) {
    //ListItr<hashedObj> itr;
    int index = hashFunction(key);
    const list<hashedObj> & tempList = table[index];

    // typename std::list<hashedObj>::iterator it;
    //cout<<"1";
    long long int tempInt;
    string keyTemp;
    string value;
    //cout<<tempList.empty()<<" ";
    for (auto const & i : tempList) {
        //string a = i;
        stringstream stream;
        stream << i;
        getline(stream, keyTemp, ',');
        getline(stream, value);
        stream.clear();
        stream << keyTemp;
        stream >> tempInt;
        //cout<<tempInt<<" ";
        if (tempInt == key) {
            return true;
        }
    }
    //cout<<"3";
    return false;
    //typename list<hashedObj>::const_iterator it = tempList.begin();
}

template <typename hashedObj>
bool hashTable<hashedObj>::search(const long long  int key) {
    //ListItr<hashedObj> itr;
    int index = hashFunction(key);
    const list<hashedObj> & tempList = table[index];

    // typename std::list<hashedObj>::iterator it;
    //cout<<"1";
    long long int tempInt;
    string keyTemp;
    string value;
    //cout<<tempList.empty()<<" ";
    for (auto const & i : tempList) {
        //string a = i;
        stringstream stream;
        stream << i;
        getline(stream, keyTemp, ',');
        getline(stream, value);
        stream.clear();
        stream << keyTemp;
        stream >> tempInt;
        //cout<<tempInt<<" ";
        if (tempInt == key) {
            cout << value;
            return true;
        }
    }
    return false;
}

/*
    for(;!(it==tempList.end()  );++it){
        cout<<"aaa ";
        if(it != tempList.end()){
            cout<<"aaa ";
            //cout<<tempList.end()<<endl;
            return true;
            }
        else{
            cout<<"aaa ";
            return false;
        }
    i++;
    }




template<class hashedObj>
bool hashTable<hashedObj>::find(const hashedObj & val){
    int index = hashFunction(val);
    const list<hashedObj> & tempList = table[index];
    //list<hashedObj>::const_iterator it = tempList.cbegin();

    for(int i;i<tempList.size() ;i++){
        if(tempList != val){
            cout<<val;
            return true;
        }
    else{
        cout<<"The value "<<val<<" is not found";
        return false;
}
}
}*/


/*
#ifndef SEPARATE_CHAINING_H
#define SEPARATE_CHAINING_H

#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;


int nextPrime( int n );

// SeparateChaining hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items

template <typename hashedObj>
class hashTable
{
  public:
    explicit hashTable( int size = 1000 ) : currentSize{ 0 }
      { theLists.resize( 1000 ); }

    bool contains( const hashedObj & x ) const
    {
        auto & whichList = theLists[ myhash( x ) ];
        return find( begin( whichList ), end( whichList ), x ) != end( whichList );
    }

    void makeEmpty( )
    {
        for( auto & thisList : theLists )
            thisList.clear( );
    }

    bool insert( const hashedObj & x )
    {
        auto & whichList = theLists[ myhash( x ) ];
        if( find( begin( whichList ), end( whichList ), x ) != end( whichList) )
            return false;
        whichList.push_back( x );

            // Rehash; see Section 5.5
        if( ++currentSize > theLists.size( ) )
            rehash( );

        return true;
    }

    bool insert( hashedObj && x )
    {
        auto & whichList = theLists[ myhash( x ) ];
        if( find( begin( whichList ), end( whichList ), x ) != end( whichList ) )
            return false;
        whichList.push_back( std::move( x ) );

            // Rehash; see Section 5.5
        if( ++currentSize > theLists.size( ) )
            rehash( );

        return true;
    }

    bool remove( const hashedObj & x )
    {
        auto & whichList = theLists[ myhash( x ) ];
        auto itr = find( begin( whichList ), end( whichList ), x );

        if( itr == end( whichList ) )
            return false;

        whichList.erase( itr );
        --currentSize;
        return true;
    }

  private:
    vector<list<hashedObj>> theLists;   // The array of Lists
    int  currentSize;

    void rehash( )
    {
        vector<list<hashedObj>> oldLists = theLists;

            // Create new double-sized, empty table
        theLists.resize( nextPrime( 2 * theLists.size( ) ) );
        for( auto & thisList : theLists )
            thisList.clear( );

            // Copy table over
        currentSize = 0;
        for( auto & thisList : oldLists )
            for( auto & x : thisList )
                insert( std::move( x ) );
    }

    size_t myhash( const hashedObj & x ) const
    {
        static hash<hashedObj> hf;
        return hf( x ) % theLists.size( );
    }
};

#endif

*/