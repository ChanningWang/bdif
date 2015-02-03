#include <iostream>
#include <thread>
#include <fstream>
#include <stdio.h>
#include <time.h>

#include "Scrubber.hpp"

using namespace std;


int main(int argc, char *argv[]) {

	string sourceFile="data.txt";
	if(argc==2){
		sourceFile=argv[1];
	}

	Scrubber scrubber(sourceFile);
	scrubber.sort();

//    Record r1("20140804:14:00:13.010000",2,4);
//    Record r2("20140804:14:00:13.085000",4,3);
//    Record r3("20150804:14:00:13.010000",0,9);
//
//    list<Record> list1;
//    list1.push_back(r1);
//    list1.push_back(r2);
//    list1.push_back(r3);
//
//    list1.sort();
//    std::list<Record>::iterator it;
//
//    for (it=list1.begin(); it!=list1.end(); ++it)
//        std::cout << ' ' << *it;
//
//
//    cout<<(r1>=r3)<<endl;
//    cout<<(r1<=r3)<<endl;
//    cout<<(r1>r2)<<endl;
//    cout<<(r1<r2)<<endl;
//    cout<<(r1==r2)<<endl;





return 0;
}
