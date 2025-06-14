#include<bits/stdc++.h>

using namespace std ; 
void wc();
void ccwc(  string cond , string file_name ) ; 
void ccwc( string ip ) ; 
void count_bytes( ifstream& input ) ;
void count_lines( ifstream& input ) ;
void count_chars( ifstream& input ) ;
void count_words( ifstream& input ) ;
void reset_pos( ifstream& input ) ; 
void help() ; 

int main()
{
    wc();
}

void wc()
{
    string line ; 
    while(true)
    {
        cout << ">" ;
        getline(cin , line) ; 
        vector<string> content ; 
        istringstream iss(line) ;
        string line ; 
        while (iss >> line){
            content.push_back(line) ; 
        }
        if(content.size()==2) ccwc( content[1] ) ; 
        else if(content.size()==3) ccwc( content[1] , content[2] ) ;
        else break;
        content.clear();
    }
}

void reset_pos( ifstream& in_file )
{

    in_file.clear() ; 
    in_file.seekg(0) ; 

}

void ccwc( string cond , string file_name){
    
    ifstream in_file(file_name, ios::binary) ; 
    if(in_file.fail())
        return ; 
    if(cond == "-c") count_bytes(in_file) ; 
    else if(cond == "-l") count_lines(in_file) ;
    else if(cond == "-w") count_words(in_file) ; 
    else if(cond == "-m") count_chars(in_file) ; 

    cout << "  " << file_name << endl ; 
    in_file.close();

}

void ccwc( string ip ){

    if( ip == "--help" ) 
        {
            cout << "Usage: wc [OPTION]... [FILE]...\n"
               "Print newline, word, and byte counts for each FILE.\n"
               "Options:\n"
               "  -c, --bytes  print the byte counts\n"
               "  -m, --chars  print the character counts (same as byte counts in this implementation)\n"
               "  -l, --lines  print the newline counts\n"
               "  -w, --words  print the word counts\n"
               "  --help       display this help message\n"  ;
            return ; 
        }
    ifstream in_file(ip,ios::binary) ; 
    count_bytes( in_file );
    reset_pos(in_file);
    count_chars( in_file );
    reset_pos(in_file);
    count_words( in_file );
    reset_pos(in_file);
    count_lines( in_file );
    cout << "  " << ip << endl ; 
    in_file.close();
    
}

void count_bytes( ifstream& input ){

    string line ; int bytes = 0 ; 
    while(getline(input,line))
        bytes += line.size() + 1 ; 
    cout << bytes << "  " ; 

}

void count_lines( ifstream& input){

    string line ; int lines{0} ; 
    while( getline(input , line ) )
        lines++ ; 
    cout << lines << "  " ; 

}

void count_chars( ifstream& input ){

    string line ; int chars{0} ;
    while( getline( input,line ))
        chars += line.size() ;
    cout << chars << "  " ; 

}

void count_words( ifstream& input ){

    stringstream buff ; 
    buff << input.rdbuf() ; 
    string content {buff.str()} , word ;
    int words {0} ; 
    stringstream cinn(content) ; 
    while( cinn >> word )
        words++ ; 
    cout << words <<"  " ; 
}