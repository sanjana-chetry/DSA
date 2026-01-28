//plane tickets Pairs<from,to>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

void printItenary(unordered_map<string,string>tickets){
    unordered_set<string>to;

    for(pair<string,string>ticket : tickets){// <from,to>
        to.insert(ticket.second);
    }

    string start="";
    for(pair<string,string>ticket : tickets){
        if(to.find(ticket.first)==to.end()){ //starting point
            start=ticket.first;
        }
    }

    //plane
    cout<<start<<"-->";
    while(tickets.count(start)){
        cout<<tickets[start]<<"-->";
        start=tickets[start];
    }
    cout<<"destination\n";
}
int main(){
    unordered_map<string , string> tickets;
    tickets["Chennai"]="Bengaluru";
    tickets["Mumbai"]="Delhi";
    tickets["Goa"]="Chennai";
    tickets["Delhi"]="Goa";
    printItenary(tickets);
    return 0;
}