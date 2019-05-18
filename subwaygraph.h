#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include "graph_node.h"

namespace graph {
    class subway_graph {
        public:
            subway_graph(graph_node* a) {
                start = a;
                current = a;
            }

            void setCurrent(graph_node* a) {
                current = a;
            }

            bool sharedTrain(graph_node* a, graph_node *b) {
                std::vector<char> stationA = a->getTrains();
                std::vector<char> stationB = b->getTrains();
                for (int i=0;i<stationA.size();i++) {
                    for (int j=0;j<stationB.size();j++) {
                        if (stationA[i] == stationB[j]) {
                            return true;
                        }
                    }
                }
                
                std::cout << "Invalid connection" << std::endl;
                return false;
            }

            bool compareName(std::string target, graph_node* A) {    
                if (A->stationName() == target) {
                    return true;
                }       
                else {
                    return false;
                }
            }

            void setConnection(graph_node* a, graph_node* b) {
                if (sharedTrain(a,b) == true) {
                    a->setOutAdd(b);
                    b->setOutAdd(a);
                }
            }

            std::vector<char> routeTo(std::string start, std::string target) {

            }
            
            //method for searching to see if a station exists in a subway map            

            bool searchFor(std::string target, subway_graph source) {
                for (int i=0;i<current->getOut().size();i++) {              //check surrounding stations to see if any matches hit, if so return true and end the recursion
                    if (compareName(target, current->getOut()[i]) == true) {     
                        return true;
                    }
                }
                current->setMarked();                                       //since surrounding stations have been checked, this station is marked off so that it is not recurred on (otherwise it would be an endless recursion)
                for (int i=0;i<current->getOut().size();i++) {
                    if (current->getOut()[i]->getMarked() == false) {       //checks if the station about to recur on is marked or not to prevent endless recursion using the previous line
                        subway_graph temp(current->getOut()[i]);
                        if (searchFor(target, temp) == true) {
                            return true;
                        }
                    }
                }
                return false;
            }

            //train to take between stops
            
            //under construction

            //size function

        private:
            graph_node* start;
            graph_node* current;
            int length;

    };
}
