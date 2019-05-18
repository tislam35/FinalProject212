#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>

namespace final_Proj_212{
    class graph_node{
        public:
            graph_node(std::string a, std::vector<char> b){
                station = a;
                for(int i = 0; i < b.size(); i++){
                    trains.push_back(b[i]);
                }
                marked = false;
            }
            /**
            std::vector<graph_node*> getNext(){
                return next;
            }
            std::vector<graph_node*> getPrev(){
                return prev;
            }
            std::vector<graph_node*> getExpNext(){
                return expNext;
            }
            std::vector<graph_node*> getExpPrev(){
                return expPrev;
            }*/
            std::vector<graph_node*> getOut(){
                return out;
            }
            std::vector<char> getTrains(){
                return trains;
            }
            std::string stationName(){
                return station;
            }
            /**
            void setNext(graph_node* newConnection){
                next.push_back(newConnection)
            }
            void setPrev(graph_node* newConnection){
                prev.push_back(newConnection)
            }
            void setExpNext(graph_node* newConnection){
                expNext.push_back(newConnection)
            }
            void setExpPrev(graph_node* newConnection){
                expPrev.push_back(newConnection)
            }*/
            void setOut(graph_node* newConnection){
                out.push_back(newConnection)
            }
        private:
            std::vector<graph_node*> out;
            //std::vector<graph_node*> prev;
            //std::vector<graph_node*> expNext;
            //std::vector<graph_node*> expPrev;
            std::string station;
            std::vector<char> trains;
            bool marked;
    }
}