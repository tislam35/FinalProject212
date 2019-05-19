#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include "graph_node.h"

namespace graph {
    class subway_graph {
        public:
            subway_graph(graph_node* a) {
                start = a;
                current = a;
                stations = 1;
                found = false;
            }

            void setCurrent(graph_node* a) {
                current = a;
            }

            //returns true iff two graph_nodes have atleast 1 train in common
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

            //adds a station to the graph
            void setConnection(graph_node* a, graph_node* b) {
                if (sharedTrain(a,b) == true) {
                    a->setOutAdd(b);
                    b->setOutAdd(a);
                    stations ++;
                }
            }

            //will return a vector of trains to take
            void routeTo(std::string first, std::string target) {
                std::vector<char> result;
                //first i need to find the location of the 2 stations and store them in a graph_node*
                graph::graph_node* a = findLink(first);
                graph::graph_node* b = findLink(target);
                std::vector<char> trainsa = a->getTrains();
                std::vector<char> trainsb = b->getTrains();
                //if they share a train then i can just look for a train they share and print that
                if(sharedTrain(a,b) == true){
                    for (int i=0; i < trainsa.size(); i++) {
                        for (int j = 0; j < trainsb.size(); j++) {
                            if (trainsa[i] == trainsb[j]) {
                                std::cout << "Take the " << trainsa[i] << "train to get to " << target << std::endl;
                                return;
                            }
                        }
                    }
                }
                //getting here means that they do not have a train in common and transfers will be needed
                //else{
                    //getPath(a,target);
                    //found = false;
                    //now i have the path in private variable path, ill finish this method tomorrow
                //}
            }

            //a search method for getting the pointer to a target string
            graph::graph_node* findLink(std::string target){
                if(current->stationName().compare(target) == 0){
                    return current;
                }
                else{
                    current->setMarked();
                    std::vector<graph_node*> links = current->getOut();
                    for(int i = 0; i < links.size(); i++){
                        graph_node* temp = links[i];
                        if(temp->getMarked() == false){
                            current = temp;
                            findLink(target);
                        }
                    }
                }
                current->resetMarked();
            }

            //function to store a vector of graph_node*s that represent the path from start to target in the private variable called path
            void getPath(graph_node* first, std::string target){
                current = first;
                if(current->stationName().compare(target) == 0)
                    found = true;
                else{
                    current->setMarked();
                    std::vector<graph_node*> links = current->getOut();
                    for(int i = 0; i < links.size(); i++){
                        graph_node* temp = links[i];
                        if(temp->getMarked() == false){
                            getPath(temp,target);
                        }
                        if(found)
                            break;
                    }
                }
                if(found)
                    path.push_back(current);
                current->resetMarked();
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

            
            //under construction

            //size function

        private:
            graph::graph_node* start;
            graph::graph_node* current;
            int stations;
            //the two variable below are intended for the getPath function
            bool found;
            std::vector<graph_node*> path;
    };
}
