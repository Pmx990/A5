#include "DataType.h"
#include <iostream>
#include <sstream>
#include <fstream>


upc::upc(){
	key = "defult";
	value = "defult";
}

upc::upc(string k, string v){
	this->key = k;
	this->value = v;
}

string upc:: rAll(){
	return key + "," + value;
}

string upc::rValue(){
	return value;
}

string upc::rKey(){
	return key;
}

bool upc::operator<(const upc &t){
	return key<t.key;
}
//the tree will use the key to do the comparsion

bool upc::operator>(const upc &t){
	return key>t.key;
}

bool upc::operator==(const upc &t){
	return key==t.key;
}

bool upc::operator==(upc &t){
	return key==t.key;
}

int upc::operator%(int num){
	int temp;
	stringstream stream;
	stream<<key;
	stream>>temp;
	stream.clear();
	return (temp%num);
}

ostream& operator <<(ostream& os, const upc& t){
	cout<<t.value;
	return os;
}

