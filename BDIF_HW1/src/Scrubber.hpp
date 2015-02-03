#include <string.h>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "Record.hpp"

using namespace std;
using namespace boost::algorithm;
using namespace UnitType;

class Scrubber{

public:



	//basic unit is kb, 10kb for test, final test 1gb
    long long bulk_size=10;
    UNIT unit=UNIT::KB;

    long long bulk_item;
    int bulk_number=0;

    string raw_file="data.txt";

    Scrubber(string raw_file){
    	this->raw_file=raw_file;
    	this->bulk_item=10000;
    }

    Scrubber(string raw_file,long long bulk_size, UNIT unit){
    	this->raw_file=raw_file;
       this->bulk_size=bulk_size;
       this->unit=unit;
       switch(unit) {
            case UNIT::GB   : this->bulk_item=bulk_size*1000000000; break;
            case UNIT::MB : this->bulk_item=bulk_size*1000000; break;
            case UNIT::KB  : this->bulk_item=bulk_size*1000; break;
       }

    }

	void sort() {
		string line;
		list<Record> bulk_list;
		std::ifstream fileStream(raw_file);
		std::vector<string> strs;
		int counter = 0;
		Record r;


		cout <<"Bulk_Item Number: "<<bulk_item<<endl;

		while (getline(fileStream, line, '\n')) {
			if (counter <= this->bulk_item) {
				trim(line);
				boost::split(strs, line, boost::is_any_of(","));
				r = Record(strs[0], strs[1], strs[2]);
				bulk_list.push_back(r);
				counter++;
				//cout <<counter<<"-"<<line<<endl;
			} else {
               counter=0;
               loadIntoFile(bulk_list);

			}

		}

		if(counter>0){
           counter=0;
           loadIntoFile(bulk_list);
		}


	}

	void loadIntoFile(list<Record> & buckList){
		std::list<Record>::iterator it;
        this->bulk_number++;
         std::stringstream bulkFile;
         bulkFile << "bulk"<<bulk_number<<".txt";
         std::string fileName = bulkFile.str();
         std::fstream fs(fileName, ios::out | ios::app | ios::binary);;

         buckList.sort();
         for (it=buckList.begin(); it!=buckList.end(); ++it){
                fs << *it;
         }
         cout << "Output to file: "<<fileName<<endl;
         fs.close();
	}

};

