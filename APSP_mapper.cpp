#include <iostream>
#include <string>
#include "sha1.h"
#define minlength 30
#define sep " "

using namespace std;

void DisplayMessageDigest(unsigned *message_digest);

int main(){
  string line;
  int counter =0;
  SHA1        sha;
  unsigned    message_digest[5];

  while (std::getline(cin,line)){
    if (line.length()< minlength) continue;
    for(int x=0;x<line.length()-minlength+1;x++){

      // Do hashing for Suffix
      sha.Reset();
      sha << line.substr(x,line.length()).c_str() ;
      if (!sha.Result(message_digest)){
	cerr << "ERROR-- could not compute message digest" << endl;
      }
      DisplayMessageDigest(message_digest);  // hash for suffix
      //cout<<line.substr(x,line.length())<<sep<<counter<<sep<<1<<endl;
      //cout<<line.substr(x,line.length())<<sep;
      cout<< line.length()-x  <<sep<<counter<<sep<<1<<endl;

      // Do hashing for Prefix
      sha.Reset();
      sha << line.substr(0,line.length()-x).c_str() ;
      if (!sha.Result(message_digest)){
	cerr << "ERROR-- could not compute message digest" << endl;
      }

      DisplayMessageDigest(message_digest);  // hash for prefix
      //cout<<line.substr(0,line.length()-x)<<sep<<counter<<sep<<2<<endl;
      //cout <<line.substr(0,line.length()-x)<<sep;
      cout << line.length()-x  <<sep<<counter<<sep<<2<<endl;
    }
    counter++;
  }
  return 0;

}


void DisplayMessageDigest(unsigned *message_digest)
{
    ios::fmtflags   flags;

    //cout << '\t';

    flags = cout.setf(ios::hex|ios::uppercase,ios::basefield);
    cout.setf(ios::uppercase);

    for(int i = 0; i < 5 ; i++)
    {
      cout << message_digest[i]; //<< ' ';
    }

    cout <<' ';// endl;
    
    cout.setf(flags);
}



