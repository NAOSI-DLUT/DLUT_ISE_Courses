#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <iterator>
#include "dictionary.h"
#include "hashset.h"

using namespace std;

void create_suggestions(Dictionary& dict, string word)
{

    vector<string> suggestions;
    unsigned int i;
    char c;
    // transpose all adjacent letters
    for (i = 0; i < word.length() - 1; i++) 
	{
        string new_word(word);
        char temp = new_word[i];
        new_word[i] = new_word[i + 1];
        new_word[i + 1] = temp;

        if (dict.search(new_word)) 
		{
            suggestions.push_back(new_word);
        }
    }
    // remove each letter
    for (i = 0; i < word.length(); i++) 
	{
        string new_word(word);
        new_word.erase(i, 1);
        if (dict.search(new_word)) 
		{
            suggestions.push_back(new_word);
        }
    }
    // replace each letter
    for (i = 0; i < word.length(); i++) 
	{
        for (c = 'a'; c <= 'z'; c++) 
		{

            string new_word(word);
            new_word.replace(i, 1, 1, c);
            if (dict.search(new_word)) 
			{
                suggestions.push_back(new_word);
            }
        }
    }
    // insert a letter at each position
    for (i = 0; i < word.length(); i++)
	{
        for (c = 'a'; c <= 'z'; c++) 
		{

            string new_word(word);
            new_word.insert(i, 1, c);
            if (dict.search(new_word)) 
			{
                suggestions.push_back(new_word);
            }
        }
    }
    vector<string> unique_suggestions;
    insert_iterator< vector<string> > ins(unique_suggestions,unique_suggestions.begin());

    unique_copy(suggestions.begin(), suggestions.end(),ins);
	
	for(vector<string>::iterator p = unique_suggestions.begin(); p != unique_suggestions.end(); p++)
               cout <<"\t\t" << *p << endl;
}

void lower( string& s )    
{    
	// Ensures that a word is lowercase
    for (unsigned int i = 0; i<s.length(); i++)    
    {   
        s[i] = tolower(s[i]);   
    }   
} 
string strip_punct( const string& s )    
{   
	// Remove any single trailing
    // punctuation character from a word.
    if ( ispunct(s[s.length() - 1]) )    
    {   
        return s.substr (0, s.length() - 1);   
    }   
    else    
    {   
        return s;   
    }   
}  

void check_spelling( ifstream& in, Dictionary& dict )    
{   
   
    int line_number = 0;   
   
    while (in)    
    {     
        line_number++;  
        
		string line;   
        getline(in, line);   
        
		stringstream ss (stringstream::in | stringstream::out);   
        ss << line;   
        
		string word;   
        while (ss >> word)    
        {   
            lower( word );   
            word = strip_punct( word );   
            if( dict.search( word ) )  continue;    
            cout << "line " << line_number << ": '" << word << "'" << endl;   
            cout << "\t" << "suggestions:" << endl;   
            create_suggestions( dict, word );   
        } 

    }

}  

int main()    
{   
    string filename = "./test.txt";   
    ifstream inf(filename);   
    if (! inf)    
    {   
        cerr << "Could not open " << "text.txt" << "\n";   
        return EXIT_FAILURE;   
    }   
    cout << "Loading dictionary, this may take awhile...\n";   
   
    Dictionary d("./wordlist.txt");   
   
    check_spelling(inf, d);   
   
    inf.close();   
   
    system("pause");   
   
    return EXIT_SUCCESS;      
}
