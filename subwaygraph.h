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

            void setConnection(graph_node* a, graph_node* b) {
                if (sharedTrain(a,b) == true) {
                    a->setOut(b);
                    b->setOut(a);
                }
            }

            //method for traversal
            
            //train to take between stops
            
            //under construction

            //size function

        private:
            graph_node* start;
            graph_node* current;
            int length;

    };
    //is 
}
//setconnection
//
//create link 