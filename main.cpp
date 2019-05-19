#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include "subwaygraph.h"


    int main() {

        //some basic test code for constructing a graph_node, works confirmed
        std::vector<char> test;
        test.push_back('A');
        test.push_back('B');
        for (int i=0;i<2;i++) {
            std::cout<<test[i]<<std::endl;
        }           

        graph::graph_node dog("125th St", "test");
        //std::cout << dog.getTrains()[0] << std::endl;
        

        return 0;
    }



