#include <iostream>
#include <string>

using std::string;

float get_gc_content(const string& dna){
    float gc_count = 0;

    for (int letter = 0; letter < dna.length(); letter++){
        if (dna[letter] == 'G' || dna[letter] == 'C'){
            gc_count++;
        }
    }

    return gc_count / dna.length();
}

string get_reverse_string(string dna){
    string reversed_dna;

    for (int letter = dna.length() -1; letter > -1; letter--){
        reversed_dna = reversed_dna + dna[letter];
    }

    return reversed_dna;
}

string get_dna_complement(string dna){
    string reversed_dna = get_reverse_string(dna);
    string complement_dna;

    for (int letter = 0; letter < reversed_dna.length(); letter++){
        switch(reversed_dna[letter]){
            case 'A':
                complement_dna = complement_dna + 'T';
                break;
            case 'T':
                complement_dna = complement_dna + 'A';
                break;
            case 'C':
                complement_dna = complement_dna + 'G';
                break;
            case 'G':
                complement_dna = complement_dna + 'C';
                break;
            default:
                complement_dna = complement_dna + reversed_dna[letter];
        }
    }

    return complement_dna;
}
