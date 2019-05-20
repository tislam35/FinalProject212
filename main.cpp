#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include "subwaygraph.h"

    int main() {
        
        //construction of a station, initialized by giving the name of station followed by the trains it has, without any spaces
        //other way to do this : save the station name and trains in file and use for loop to call out each one and connect each of them.
        graph::graph_node* s19 = new graph::graph_node("145 St", "ABCD");        
        graph::graph_node* s18 = new graph::graph_node("135 St", "BC");
        graph::graph_node* s17 = new graph::graph_node("125 St", "ABCD");
        graph::graph_node* s16 = new graph::graph_node("116 St", "BC");
        graph::graph_node* s15 = new graph::graph_node("110 St", "BC");
        graph::graph_node* s14 = new graph::graph_node("103 St", "BC");
        graph::graph_node* s13 = new graph::graph_node("96 St", "BC");
        graph::graph_node* s12 = new graph::graph_node("86 St", "BC");
        graph::graph_node* s11 = new graph::graph_node("81 St", "BC");
        graph::graph_node* s10 = new graph::graph_node("72 St", "BC");
        graph::graph_node* s9 = new graph::graph_node("59 St", "ABCD1");
        graph::graph_node* s8 = new graph::graph_node("50 St", "CE");
        graph::graph_node* s20 = new graph::graph_node("42 St", "ACE");
        graph::graph_node* s7 = new graph::graph_node("7 Av", "BDE");
        graph::graph_node* s6 = new graph::graph_node("5 Av", "EM");
        graph::graph_node* s5 = new graph::graph_node("Lexington Av", "EM");
        graph::graph_node* s4 = new graph::graph_node("Court Sq-23", "EM");
        graph::graph_node* s3 = new graph::graph_node("Queens Plaza", "EMR");
        graph::graph_node* s2 = new graph::graph_node("Jackson Hts Roosevelt Av", "EFMR7");
        graph::graph_node* s1 = new graph::graph_node("Elmhurst Av", "MR");
        
        //creating the subway_graph object that performs more complex methods on the whole map of station nodes
        graph::subway_graph theMap(s5);

        //setConnection establishes an undirected link between two stations so that other functions may utilize them correctly
        theMap.setConnection(s1,s2);                                
        theMap.setConnection(s2,s3);
        theMap.setConnection(s3,s4);
        theMap.setConnection(s4,s5);
        theMap.setConnection(s5,s6);
        theMap.setConnection(s6,s7);
        theMap.setConnection(s7,s8);
        theMap.setConnection(s7,s9);
        theMap.setConnection(s9,s8);
        theMap.setConnection(s9,s20);
        theMap.setConnection(s8,s20);
        theMap.setConnection(s9,s17);
        theMap.setConnection(s9,s10);
        theMap.setConnection(s10,s11);
        theMap.setConnection(s11,s12);
        theMap.setConnection(s12,s13);
        theMap.setConnection(s13,s14);
        theMap.setConnection(s14,s15);
        theMap.setConnection(s15,s16);
        theMap.setConnection(s16,s17);
        theMap.setConnection(s17,s19);
        theMap.setConnection(s17,s18);

        //theMap.routeTo("Lexington Av", "59 St");                        
        
        //theMap.routeTo("Lexington Av", "59 St")
        theMap.getPath(s1, "145 St");
        /*std::vector<graph::graph_node*> a = theMap.returnPath();
        for(int i = 0; i < a.size(); i++){
            std::cout << a[i]->stationName() << std::endl;
        }*/

        theMap.routeTo(s1,s19);                                         //routeTo displays a potential route to take between 2 stations, an example of how
                                                                        //our data structure can be used to create more complex functions that could be valuable for end users                                        

        if ((theMap.searchFor(theMap.getStart(), "145 St")) == true) {  //searchFor traverses the entire graph and finds a station whose name matches the target inputted  
            std::cout << "The station exists" << std::endl;
        }

        graph::graph_node* test = theMap.findLink(theMap.getStart(), "125 St");     //findLink is similar to searchFor, but returns the entire node itself (while searchFor is just a boolean value)

        theMap.displayStations(s9);                                //displayStations examines a particular station in the graph and displays all of its connections/edges
        
        return 0;
    }



