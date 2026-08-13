//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//
 
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>

//
class Date {
public:
    Date(): day(""), month(""), year(0) {};
    Date(String);
    String getday() const { return day; };
    String getmonth() const { return month; };
    int getyear() const { return year; };

private:
    String  day, month;
    int year;
    
};

//
class Time {
  public:
    //default constructor
    Time(): hour(0), minute(0), second(0) {};
    Time(String, String, String);

    int gethour() const { return hour; };
    int getminute() const {return minute; };
    int getsecond() const { return second; };
  private:
    int  hour, minute, second;
    
};

// A single log entry
class LogEntry {
public:
    LogEntry(): host(""), request(""), status("") {};
    LogEntry(String);
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);
    String gethost() const { return host; };
    String getstatus() const { return status; };
    String getrequest() const{return request;};
    int getbytes() const { return number_of_bytes; };

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


//
// Free functions
//

std::vector<LogEntry>   parse (std::istream&);
void output_all  (std::ostream&, const std::vector<LogEntry>&);
void by_host (std::ostream&, const std::vector<LogEntry>&);
int byte_count (const std::vector<LogEntry>&);
int stoi(const String&);

//bonus
void printIPs(const std::vector<LogEntry>& );

#endif
