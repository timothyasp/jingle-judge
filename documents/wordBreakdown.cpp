typedef string phone;


vector<string> findAllPermutations(string orthoPhrase) {
	vector<string> permutedPhrases;	
	
	vector<string> orthoWords = strTokOnWhitespace( orthoPhrase );
	vector<phone> sampaPhrase;

	for( string& orthoWord : orthoWords ) {
		vector<phone> sampaWord = getSampa( orthoWord );
		sampaPhrase.insert( sampaPhrase.end(), sampaWord.begin(), sampaWord.end() );
	}	

	vector<string> misheard = interpretPhrase( sampaPhrase );
	
	for( string& s : misheard ) {
		DDDDDDDDDDDEBUG(s);
	}	

	return misheard;

	//vector<string> phonemeBreakdown = getPhrasePhonemes(phrase);	
	//vector<PhoneWithIndex> origPhonePhrase = embedPhoneOrder(phonemeBreakdown);
	//for( PhoneWithIndex pi : origPhonePhrase ) {
	//}
	
	//get all words that start with first phoneme
	//for each of those words, run a parser on the rest of the phrase (recurse)
	
	
	//if I hit a dead end, where I still have phonemes left
	// --> for now, append "empty" and return it, as a debug tool
	
	
}
	
void DDDDDDDDDDDEBUG(string s) {
	cout << s << endl;	
}

vector<string> strTokOnWhitespace(string phrase) {
	assert(); //DE-PERLIFY!
	return split(/\s/); //split on any whitespace character
}

vector<string> interpretPhrase( vector<phone> sampaPhrase ) {
	vector<string> misheardOrthoPhrases;
	if( sampaPhrase.size() == 0 ) {
		misheardOrthoPhrases.push_back("");
		return misheardOrthoPhrases;
	}
	int offset = 0;
	string sampaStr = "";
	vector <phone> usedPhones;
	for ( phone& p : sampaPhrase ) {
		sampaStr += p;
		usedPhones.push_back(p);
		vector<string> orthoMatches = dictLookup( sampaStr );
		if ( orthoMatches.size() == 0 ) {
			misheardOrthoPhrases.push_back("DEADBEEF");
			return misheardOrthoPhrases;
		}
		for ( string& orthoWord : orthoMatches ) {
			vector<phone> sampaPharseTail( sampaPhrase.begin(), sampaPhrase.begin()+offset );
			vector<string> orthoLeaves = interpretPhrase ( sampaPhraseTail );
			if ( orthoLeaves.size() == 0 ) {
				misheardOrthoPhrases.push_back( orthoWord.append( "DEADBEEF" ) );
				return misheardOrthoPhrases;
			} else {
				for( string& orthoLeaf : orthoLeaves ) {
					misheardOrthoPhrases.push_back( orthoWord + orthoLeaf() );
				}
			}
			
			  
		}
		offset++;
	}
	return misheardOrthoPhrases;
}


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
/*	split sampa phrase
	$src_SAMPA =~ s/\s$//; #remove trailing whitespace;
	$src_SAMPA =~ s/^\s*//; # remove leading whitespace.
	
	print OUTFILE "$src_SAMPA\t";
	print OUTFILE ":\t";
	print "$src_SAMPA\t";

	@array_src_SAMPA = split (/[\$|%|\"]/, $src_SAMPA);
*/	
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


