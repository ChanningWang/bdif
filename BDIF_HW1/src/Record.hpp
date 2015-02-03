#include <iostream>
#include <thread>
#include <fstream>
#include "Utils.hpp"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost::algorithm;

class Record{


public:
  string timestamp;
  float price;
  int units;

  Record(){
   price=0;
   units=0;
  }
  Record(string str,float price,int units){
	  this->timestamp=str;
	  this->price=price;
	  this->units=units;
  }

  Record(string str,string price,string units){
  	  this->timestamp=str;
  	  this->price= boost::lexical_cast<float>(price);
  	  this->units=boost::lexical_cast<int>(units);
    }



   bool operator<( const Record& other) const
      {
          if(Utils::cmp(this->timestamp,other.timestamp)<0){
        	  return true;
          }else{
        	  return false;
          }
      }



   bool operator>=( const Record& other) const
          {
             return !(*this < other);
          }

  bool operator<=(const Record& other)
          {
             return !(other<*this);
          }

  bool operator>(const Record& other)
        {
	      return !(*this<=other);
        }

  bool operator==(const Record& other)
            {
                if(Utils::cmp(this->timestamp,other.timestamp)==0){
              	  return true;
                }else{
              	  return false;
                }
            }

  bool operator!=(const Record& other)
              {
                 return !(*this==other);
              }

  friend ostream &operator<<( ostream &output,
                                         const Record &D )
        {
           //output << "Timestamp : " << D.timestamp << " Price : " << D.price <<" Unit : " << D.units<<endl;
	      output << D.timestamp << "," << D.price <<"," << D.units<<"\n";
           return output;
        }




};
