
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <assert.h>

using namespace std;

typedef string phone ;


vector<string> findAllPermutations(string orthoPhrase);
void DDDDDDDDDDDEBUG(string s);
vector<string> strTokOnWhitespace(string phrase);
vector<string> interpretPhrase( vector<phone> sampaPhrase );
vector<phone> getSampa( string orthoWord );
string queryDBforSAMPA( string orthoWord );
vector<phone> parseSAMPAintoPhonemes( string sampaString );
vector<string> dictLookup( string sampaStr ); 


int main() {
   return 0;
}


vector<string> findAllPermutations(string orthoPhrase) {
	vector<string> permutedPhrases;	
	
	vector<string> orthoWords = strTokOnWhitespace( orthoPhrase );
	vector<phone> sampaPhrase;

   for (int i = 0; i < orthoWords.size(); i++) {
      string orthoWord = orthoWords[i];
		vector<phone> sampaWord = getSampa( orthoWord );
		sampaPhrase.insert( sampaPhrase.end(), sampaWord.begin(), sampaWord.end() );
	}	

	vector<string> misheard = interpretPhrase( sampaPhrase );
	
	for (int i = 0; i < misheard.size(); i++) {
      string s = misheard[i];
      DDDDDDDDDDDEBUG(s);
	}	


	return misheard;

}
	
void DDDDDDDDDDDEBUG(string s) {
	cout << s << endl;	
}

//http://www.daniweb.com/software-development/cpp/threads/27905
vector<string> strTokOnWhitespace(string phrase) {
   string temp;
   stringstream ss(phrase);
   vector<string> tokens;
   
   //while (phrase >> temp) {
   while ( getline(ss, temp, ' ') ) {
      tokens.push_back(temp);
   }
   return tokens;
}

vector<phone> getSampa( string orthoWord ) {
   string sampaString = queryDBforSAMPA( orthoWord );
   vector<phone> sampaWord = parseSAMPAintoPhonemes( sampaString );
   return sampaWord;
}


string queryDBforSAMPA( string orthoWord ) {
   assert(0); // PUT SQL QUERY HERE
   return "";
}

vector<phone> parseSAMPAintoPhonemes( string sampaString ) {
   vector<phone> sampaSylls;
   assert(0); // break string into phonemes
   
   return sampaSylls;
}

vector<string> dictLookup( string sampaStr ) {
   vector<string> orthoMatches;
   assert(0); // PUT SQL QUERY HERE
   return orthoMatches;
}


vector<string> interpretPhrase( vector<phone> sampaPhrase ) {
	vector<string> misheardOrthoPhrases;
   
	if( sampaPhrase.size() == 0 ) {
		misheardOrthoPhrases.push_back("");
		return misheardOrthoPhrases;
	}
	
   string sampaStr = "";
	vector <phone> usedPhones;
   
   for (int i = 0; i < sampaPhrase.size(); i++) {
      phone p = sampaPhrase[i];
		sampaStr += p;
		usedPhones.push_back(p);
		vector<string> orthoMatches = dictLookup( sampaStr );
		if ( orthoMatches.size() == 0 ) {
			misheardOrthoPhrases.push_back("DEADBEEF");
			return misheardOrthoPhrases;
		}

      for (int i = 0; i < orthoMatches.size(); i++) {
         string orthoWord = orthoMatches[i];
			vector<phone> sampaPhraseTail( sampaPhrase.begin(), sampaPhrase.begin() + i );
			vector<string> orthoLeaves = interpretPhrase ( sampaPhraseTail );
			if ( orthoLeaves.size() == 0 ) {
				misheardOrthoPhrases.push_back( orthoWord.append( "DEADBEEF" ) );
				return misheardOrthoPhrases;
			} else {
                        
            for (int i = 0; i < orthoLeaves.size(); i++) {
               string orthoLeaf = orthoLeaves[i];
					misheardOrthoPhrases.push_back( orthoWord + orthoLeaf );
				}
            
			}
		}
	}
	return misheardOrthoPhrases;
}



/*
vector<string>  getPhrasePhonemes(string phrase) {
	vector<string> phrasePhones;;
	vector<string> words = split(/\s/); //split on any whitespace character

	for ( string s : words) {
		vector<string> sampleSylls = getSAMPAForPhrase(s);
		//append to end
		phrasePhones.insert( phrasePhones.end(), 
			sampaSylls.begin(), sampaSylls.end() );			
	}
	return phrasePhones;
}
string[] getSAMPAForPhrase(string orthoWord) {
	//lookup in dictionary
	split sampa phrase
	$src_SAMPA =~ s/\s$//; #remove trailing whitespace;
	$src_SAMPA =~ s#^\s*##; # remove leading whitespace.
	
	print OUTFILE "$src_SAMPA\t";
	print OUTFILE ":\t";
	print "$src_SAMPA\t";

	@array_src_SAMPA = split (/[\$|%|\"]/, $src_SAMPA);
	
	//return split sampa phrase
}


vector<PhoneWithIndex> embedPhoneOrder(vector<string> phones) {
	vector<PhoneWithIndex> toRet;
	int i = 0;
	for( string s : phones) {
		toRet.add( LocPhone(i++, s) );  
	}
	return toRet;
}
*/

