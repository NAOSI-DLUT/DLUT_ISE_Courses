// template hash set class
#ifndef  _HASHSET_H_  
#define  _HASHSET_H_ 
 
#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <stdexcept> 
 
using namespace std; 
 
// we do not compute prime numbers but use a table instead
static const int num_primes = 25;
static const unsigned long prime_list[] = 
        {
            53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317,
            196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917, 25165843,
            50331653, 100663319, 201326611, 402653189, 805306457
        };


template<class key_type, class hash_func, class key_equal> 
class  HashSet 
{ 
 
protected: 
    // hashtable entries  
    class Entry 
	{ 
        public: 
        key_type key; 
        bool used; 
 
        Entry() : used(false) {} 
    }; 
 
    int entries;      // number of entries 
    int prime;        // index to size table 
 
    vector<Entry> *ht; 
    hash_func hf;        // hash function on key_type 
    key_equal eq;        // equality predicate on key_type 
 
    int table_size()  const {return prime_list[prime];} 
    float load_factor() const {return float(size()) / table_size();} 
    int resize(); 
     
public: 
 
    HashSet() : entries(0), prime(0), ht(new vector<Entry>(prime_list[0])) {} 
           
    virtual ~HashSet()
	{  
		delete ht; 
	} 
 
    virtual int size() const {return entries;} 
    virtual bool search(const key_type& k); 
    virtual void insert(const key_type& k); 
    virtual void remove(const key_type& k); 
}; 
 
#endif 