//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//
 
#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>
#include <map>

// REQUIRES: string is a line from log file
// ENSURES: LogEntry object is given values from line of input file

LogEntry::LogEntry(String line) {
    //Use split to create LogEntry
    std::vector<String> parts = line.split(' ');
    if (parts.size() == 10) {
        host = parts[0];

    String result = parts[3].substr(1, parts[3].length()-1);
    std::vector<String> Dtg = result.split(':');

    date = Date(Dtg[0]);
    time = Time(Dtg[1],Dtg[2],Dtg[3]);

    request = parts[5] + " " + parts[6] + " " + parts[7];
    status = parts[8];
    if (parts[9] != "-") {
        number_of_bytes = stoi(parts[9]); 
    } else {
        number_of_bytes = 0;
    }
        
    }else{
        LogEntry();
    }  
    
}

// REQUIRES:
// ENSURES:
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    char ch[500];
    while(!in.eof()){
        in.getline(ch,500);
        LogEntry temp(ch);
        if(temp.gethost().length() > 0)
            result.push_back(temp);
    }
    return result;
}

// REQUIRES:
// ENSURES:
void output_all(std::ostream& out, const std::vector<LogEntry>&logentry) {
    for (const auto& entry : logentry) {
        out << entry << std::endl;
    }

}

// REQUIRES:
// ENSURES:
void by_host(std::ostream& out, const std::vector<LogEntry>& logs) {
    std::vector<std::pair<String, int> > host_counts;

    // Count the number of log entries for each host
    for (std::vector<LogEntry>::const_iterator it_entry = logs.begin(); it_entry != logs.end(); ++it_entry) {
        bool found = false;
        for (std::vector<std::pair<String, int> >::iterator it_count = host_counts.begin(); it_count != host_counts.end(); ++it_count) {

            if (it_count->first == it_entry->gethost()) {
                it_count->second++;
                found = true;
                break;
            }
        }
        if (!found) {
            host_counts.push_back(std::make_pair(it_entry->gethost(), 1));
        }
    }

    // Output the host counts to the ostream
    for (std::vector<std::pair<String, int> >::const_iterator it_count = host_counts.begin(); it_count != host_counts.end(); ++it_count) {
        out << it_count->first << ": " << it_count->second << std::endl;
    }


}
// REQUIRES:
// ENSURES:
int byte_count(const std::vector<LogEntry>& logs) {
    int sum = 0;
    
    for (const LogEntry& entry: logs) {
        sum = sum+ entry.getbytes();
    }
    
    return sum;
    
    return 0;
}
std::ostream& operator<<(std::ostream& out, const LogEntry& rhs){
    out << rhs.host << " "
       << rhs.date.getday()<< "/" << rhs.date.getmonth() << "/" << rhs.date.getyear() << ":"
       << rhs.time.gethour() << ":" << rhs.time.getminute() << ":" << rhs.time.getsecond() << " "
       << "\"" << rhs.getrequest() << "\" "
       << rhs.getstatus() << " "
       << rhs.getbytes();
    return out;
}

Time::Time(String H, String M, String S){
    hour = stoi(H);
    minute = stoi(M);
    second = stoi(S);
}

int stoi(const String& str) {
     
    int i = str.length();
    int number;
    int result = 0;
    for (int j = 0; j < i; ++j)
    {
        number = int(str[i - j - 1]) - int('0');
        result = number + result *10;
    }
    return result;

}

 Date::Date(String s){
    std::vector<String> result = s.split('/');
    day = result[0];
    month = result[1];
    year = stoi(result[2]);
}

void printIPs(const std::vector<LogEntry>& logEntries) {
    std::cout << "List of Unique IP Addresses:" << std::endl;

    // Map to store unique IP addresses and their occurrence count
    std::map<String, int> uniqueIPs;

    // Count occurrences of each IP address
    for (const LogEntry& entry : logEntries) {
        String host = entry.gethost();
        uniqueIPs[host]++;
    }

    // declaring iterators  
    std::map<String, int>::iterator it;
        
    for (it = uniqueIPs.begin(); it!=uniqueIPs.end(); ++it)
    {
        std::cout << it->first << " -- "; // print the IP
        std::cout << it->second << std::endl; // print appearance count
    }
}