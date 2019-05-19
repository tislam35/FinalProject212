#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include "graph_node.h"

namespace graph{
    class subway_graph {
        public:
            subway_graph(graph_node* a) {
                start = a;
                current = a;
                found = false;
            }

            graph::graph_node* getStart(){
                return start;
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
                //std::cout << "Invalid connection" << std::endl;
                return false;
            }

            std::vector<graph::graph_node*> returnPath(){
                return path;
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
                }
            }

            //will return a shared train
            char getSharedTrain(graph_node* a, graph_node* b){
                std::vector<char> trainsA = a->getTrains();
                std::vector<char> trainsB = b->getTrains();
                for (int i=0; i < trainsA.size(); i++) {
                    for (int j = 0; j < trainsB.size(); j++) {
                        if (trainsA[i] == trainsB[j]) {
                            return trainsA[i];
                        }
                    }
                }
            }

            //will return a vector of trains to take
            void routeTo(std::string first, std::string target) {
                //first i need to find the location of the 2 stations and store them in a graph_node*
                graph::graph_node* a = findLink(start,first);
                graph::graph_node* b = findLink(start,target);
                std::vector<char> trainsa = a->getTrains();
                std::vector<char> trainsb = b->getTrains();
                //if they share a train then i can just look for a train they share and print that
                if(sharedTrain(a,b) == true){
                    char ans = getSharedTrain(a,b);
                    std::cout << "Take the " << ans << " train to get to " << target << " from " << first << std::endl;
                }
                //getting here means that they do not have a train in common and transfers will be needed
                else{
                    getPath(a,target);
                    found = false;
                    //now i have the path in private variable path, path[0] is the target node
                    std::cout << "To get from " << first << " to " << target << ":\nTake the ";
                    for(int i = path.size()-2; i > 0; i--){
                        graph::graph_node* previo = path[i+1];
                        graph::graph_node* curren = path[i];
                        std::string theName = curren->stationName();
                        char ans = getSharedTrain(curren,previo);
                        std::cout << ans << " train to " << theName << "\nThen take the ";
                    }
                    char last1 = getSharedTrain(path[0],path[1]);
                    std::cout << last1 << " train to " << target << std::endl;
                    path.clear();
                }
            }

            //overloaded version of routeTo that doesnt throw bad::alloc
            void routeTo(graph_node* a, graph_node* b) {
                std::vector<char> trainsa = a->getTrains();
                std::vector<char> trainsb = b->getTrains();
                std::string first = a->stationName();
                std::string target = b->stationName();
                //if they share a train then i can just look for a train they share and print that
                if(sharedTrain(a,b) == true){
                    char ans = getSharedTrain(a,b);
                    std::cout << "Take the " << ans << " train to get to " << target << " from " << first << std::endl;
                }
                //getting here means that they do not have a train in common and transfers will be needed
                else{
                    getPath(a,target);
                    found = false;
                    //now i have the path in private variable path, path[0] is the target node
                    std::cout << "To get from " << first << " to " << target << ":\nTake the ";
                    for(int i = path.size()-2; i > 0; i--){
                        graph::graph_node* previo = path[i+1];
                        graph::graph_node* curren = path[i];
                        std::string theName = curren->stationName();
                        char ans = getSharedTrain(curren,previo);
                        std::cout << ans << " train to " << theName << "\nThen take the ";
                    }
                    char last1 = getSharedTrain(path[0],path[1]);
                    std::cout << last1 << " train to " << target << std::endl;
                    path.clear();
                }
            }

            //a search method for getting the pointer to a target string
            /**
            graph::graph_node* findLink(graph_node* first, std::string target){
                graph_node* temper = first;
                current = first;
                if(current->stationName().compare(target) == 0){
                    return current;
                    std::cout << current->stationName() << "\n" << target;
                }
                else{
                    current->setMarked();
                    std::vector<graph_node*> links = current->getOut();
                    for(int i = 0; i < links.size(); i++){
                        graph_node* temp = links[i];
                        if(temp->getMarked() == false){
                            findLink(temp, target);
                        }
                    }
                }
                temper->resetMarked();
            }*/

            graph::graph_node* findLink(graph_node* a, std::string target) {
                for (int i=0;i<a->getOut().size();i++) {              //check surrounding stations to see if any matches hit, if so return true and end the recursion
                    if (compareName(target, a->getOut()[i]) == true) {
                        //std::cout << "name found" << std::endl;
                        //std::cout << a->getOut()[i]->stationName() << std::endl;
                        a->resetMarked();
                        return a->getOut()[i];
                    }
                }
                a->setMarked();                                       //since surrounding stations have been checked, this station is marked off so that it is not recurred on (otherwise it would be an endless recursion)
                for (int i=0;i<a->getOut().size();i++) {
                    if (a->getOut()[i]->getMarked() == false) {       //checks if the station about to recur on is marked or not to prevent endless recursion using the previous line
                        if (searchFor(a->getOut()[i],target) == true) {
                            a->resetMarked();
                            return findLink(a->getOut()[i],target);
                        }
                    }
                }
            }

            //function to store a vector of graph_node*s that represent the path from start to target in the private variable called path
            void getPath(graph_node* first, std::string target){
                graph_node* temper = first;
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
                if(found){
                    path.push_back(temper);
                }
                temper->resetMarked();
            }
            
            bool searchFor(graph_node* a, std::string target) {
                for (int i=0;i<a->getOut().size();i++) {              //check surrounding stations to see if any matches hit, if so return true and end the recursion
                    if (compareName(target, a->getOut()[i]) == true) {
                        //std::cout << "name found" << std::endl;
                        //std::cout << a->getOut()[i]->stationName() << std::endl;
                        return true;
                    }
                }
                a->setMarked();                                       //since surrounding stations have been checked, this station is marked off so that it is not recurred on (otherwise it would be an endless recursion)
                for (int i=0;i<a->getOut().size();i++) {
                    if (a->getOut()[i]->getMarked() == false) {       //checks if the station about to recur on is marked or not to prevent endless recursion using the previous line
                        if (searchFor(a->getOut()[i],target) == true) {
                            return true;
                        }
                    }
                }
                return false;
            }

            //underConstruction function
            /*
            void underConstruction(std::string target, subway_graph source) {
                if (searchFor(target, source) == true) {
                    findLink(start,target);
                    for (int i=0;i<current->getOut().size();i++) {
                        for (int j=0;j<current->getOut().size();j++) {
                            if ((sharedTrain(current->getOut()[i], current->getOut()[j]) == true) && (i != j)) {
                                //connect the two links in question, and then remove the link of current from them:
                                current->getOut()[i]->setOutAdd(current->getOut()[j]);
                                current->getOut()[j]->setOutAdd(current->getOut()[i]);
                                //link removal needs to go here, and possible decrement of i and j if we're changing the vector size? WIP
                            }
                            else {continue;}
                        }
                    }
                    //you need to iterate through the vector of links, and for each position, link it to every other link of the current node.  
                        //only do so if the two links we are looking at have matching trains, use the bool compareTrains
                }
                else {
                    throw std::out_of_range(std::string("Station does not exist"));
                }
            }*/
      
        
            //size function

        private:
            graph::graph_node* start;
            graph::graph_node* current;
            //the two variable below are intended for the getPath function
            bool found;
            std::vector<graph_node*> path;
    };
}