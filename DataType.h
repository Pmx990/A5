#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef DATATYPE_H
#define DATATYPE_H
class upc{
private:
	string key;
	string value;

public:
	upc();
	upc(string k, string v);
	string rAll();
	string rValue();
	string rKey();
	bool operator<(const upc& t);
	bool operator>(const upc& t);
	bool operator==(const upc& t); 
	bool operator==( upc& t); 
	int operator%(const int num);
	friend ostream& operator <<(ostream& os, const upc& t);
};
#endif

/*
template<>
class hash<upc>{
	public:
		size_t operator()(const upc & item){
			static hash<string> hf;
			string k = item.rKey();
			int i = atoi(k.c_str());
			return hf(item.)
		}
};

size_t myhash(const HashedObj &x){
	static hash<HashedObj> hf;
	return hf(x) % 1000();
}*/