#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

namespace graph{
    class graph_node{
        public:
            graph_node(std::string a, std::string b){
                station = a;
                marked = false;
                for(int i = 0; i < b.size(); i++){
                    trains.push_back(b[i]);
                }
            }

            std::vector<graph_node*> getOut(){
                return out;
            }

            std::vector<char> getTrains(){
                return trains;
            }

            bool getMarked(){
                return marked;
            }

            std::string stationName(){
                return station;
            }

            //this will return the position of the target station in the vector of connected
            //stations or return -1 if the target station is not connected with the current one
            int getPos(graph_node* target){
                for(int i = 0; i < out.size(); i++){
                    if(out[i] == target)
                        return i;
                }
                return -1;
            }

            //adds a connection between 2 stations
            void setOutAdd(graph_node* newConnection){
                out.push_back(newConnection);
            }

            //deletes a connection between 2 stations
            void setOutDelete(int pos){
                out.erase(out.begin()+(pos-1));
            }

            //resets marked to false
            void resetMarked(){
                marked = false;
            }

        private:
            std::vector<graph_node*> out;
            std::string station;
            std::vector<char> trains;
            bool marked;
    };
}