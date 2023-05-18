#include "hashset.h"

using namespace std;

template <class key_type, class hash_func, class key_equal>
bool HashSet<key_type, hash_func, key_equal>::search(const key_type& k) 
{
    int p = hf(k) % table_size();   
   
    while ((*ht)[p].used)
	{   
        if (eq((*ht)[p].key, k))
		{   
            return true;   
        }   
        p++;   
        if (p == table_size())
		{   
            p = 0; 
        }   
    }     
    return false;   
}

template <class key_type, class hash_func, class key_equal>
void HashSet<key_type, hash_func, key_equal>::remove(const key_type& k)
{
	int p = hf(k) % table_size();   
    while ((*ht)[p].used) 
	{   
        if (eq((*ht)[p].key, k)) 
		{    
            (*ht)[p].used = false;   
            entries--;   
            break;   
        }   
        p++;   
        if (p == table_size())
		{   
            p = 0;  
		}   
    }   
}

template <class key_type, class hash_func, class key_equal>
void HashSet<key_type, hash_func, key_equal>::insert(const key_type& k) 
{
    if (load_factor() > 0.75) 
	{   
        resize();   
    }      
    int pp = hf(k) % table_size();   
    int p = pp;      
    while (p < table_size() && (*ht)[p].used) 
	{   
        p++;   
    }          
    if (p == table_size())
	{   
        p = 0;   
    }         
    while ((*ht)[p].used) 
	{   
        p++;   
    }      
    (*ht)[p].key = k;   
    (*ht)[p].used = true;   
    entries++; 
}

template <class key_type, class hash_func, class key_equal>
int HashSet<key_type, hash_func, key_equal>::resize() 
{

    if (prime == num_primes - 1)
	{
        cerr << "maximal table size reached, aborting ... " << endl;
        exit(2);
    }

    int mm = prime_list[prime];
    prime++;
    int m = prime_list[prime];
    vector<Entry>* ptr = new vector<Entry>(m);

    for (int i = 0; i < mm; ++i)
	{

        if ((*ht)[i].used==1)
		{
            key_type kk = (*ht)[i].key;

            int p = hf(kk) % m;

            while (p < m && (*ptr)[p].used==1) 
			{
                p++;
            }
            if (p == m) 
			{
                p = 0;
            }
            while ((*ptr)[p].used==1) 
			{
                p++;
            }

            (*ptr)[p].key = kk;
            (*ptr)[p].used = 1;
        }
    }
    delete ht;
    ht = ptr;
    return m;
}
