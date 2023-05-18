// #pragma once
#ifndef  _DICTIONARY_H_ 
#define  _DICTIONARY_H_

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <fstream>

#include "hashset.h"
#include "hashset.cpp"

using namespace std;

class hash_function
{
public:
    hash_function() {}    	           
    unsigned int operator()( const string& s )  const;
};

class equality
{
public:
    equality() {}
    bool  operator()( const string& A, const string& B )  const;
};

class Dictionary: public HashSet<string, hash_function, equality>
{
public:
	Dictionary(string strFilename) : HashSet<string, hash_function, equality>()
	{
		ifstream inf(strFilename.c_str());
		if (!inf)
		{
			cout << "Could not open dictionary:" << strFilename << "\n";
			return;
		}
		while (inf)
		{
			string line;
			getline(inf, line);
			insert(line);
		}
	}
};

#endif
