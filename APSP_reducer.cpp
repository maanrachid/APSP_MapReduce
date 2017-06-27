#include <iostream>
#include <string>
#include <stdlib.h>
#include "sha1.h"
#define sep " "
#define SUFFSIZE 10000

using namespace std;


int main(){
  
  string line;
  string key,overlapsize,readnum,suffixOrprefix;
  string oldkey="oldkey";
  string oldoverlap="-1";
  int * suffixes = new int[SUFFSIZE];
  int * prefixes = new int[SUFFSIZE];
  int suffsize=0;int prefsize=0;


   while (std::getline(cin,line)){
     int firstspace = line.find_first_of(" ");
     int lastspace = line.find_last_of(" ");
     int secondspace = line.find(" ",firstspace+1);
     

     key= line.substr(0,firstspace);
     overlapsize = line.substr(firstspace+1,secondspace-firstspace-1); 
     readnum= line.substr(secondspace+1,lastspace-secondspace-1);
     suffixOrprefix=line.substr(lastspace+1,1);
     //cout << key <<sep<< overlapsize<<sep<<readnum<<sep<<suffixOrprefix<<endl;
     //cout <<line <<endl;
     
     
     if (oldkey!="oldkey" && oldkey!=key){
       if (suffsize>0 && prefsize>0 && 
	   !(suffsize==1 && prefsize==1 && prefixes[0]==suffixes[0])){
	 
	 cout<< "Overlap size is "<<oldoverlap<<":"<<endl;
	 
	 cout<<"suffixes:";
	 for(int i=0;i<suffsize;i++) cout<<suffixes[i]<<" ";
	 cout<<endl;
	 cout<<"prefixes:";
	 for(int i=0;i<prefsize;i++) cout<<prefixes[i]<<" ";
	 cout<<endl;
       }
       oldkey = key;
       oldoverlap=overlapsize;
       suffsize=0;
       prefsize=0;
     }

     oldkey = key;
     oldoverlap=overlapsize;

     if (suffixOrprefix=="1") 
       suffixes[suffsize++]=atoi(readnum.c_str());
     else
       prefixes[prefsize++]=atoi(readnum.c_str());

   }

   if (oldkey!="oldkey"){
     if (suffsize>0 && prefsize>0 &&
	 !(suffsize==1 && prefsize==1 && prefixes[0]==suffixes[0])){
       cout<< oldkey<<":"<<endl;
       cout<<"suffixes:";
       for(int i=0;i<suffsize;i++) cout<<suffixes[i]<<" ";
       cout<<endl;
       cout<<"prefixes:";
       for(int i=0;i<prefsize;i++) cout<<prefixes[i]<<" ";
       cout<<endl;
     }

   }


  return 0;
}
