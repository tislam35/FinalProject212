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
        
        //For all A train between 145st and fulton street
        graph::graph_node* a = new graph_node("125street / Saint Nicholas Avenue ","AD");
        graph::graph_node* b = new graph_node("145street / Saint Nicholas Avenue ","AD");
        setConnection(a,b);
        
        graph::graph_node* c = new graph_node("59street / Columbus Circle ","AD12");
        graph::graph_node* d = new graph_node("125street / Saint Nicholas Avenue ","AD");
        setConnection(c,d);

        graph::graph_node* e = new graph_node("42street Port Authority Bus Terminal / 8 Avenue ","ANQRSW1237");
        graph::graph_node* f = new graph_node("59street Columbus Circle / 8 Avenue ","AD12");
        setConnection(e,f);

        graph::graph_node* g = new graph_node("34 Street-Penn Station / 8 Avenue ","ACE");
        graph::graph_node* h = new graph_node("42street Port Authority Bus Terminal / 8 Avenue ","ACENQRSW1237");
        setConnection(g,h);

        graph::graph_node* i = new graph_node("14 Street / 8 Avenue ","AE");
        graph::graph_node* j = new graph_node("34 Street-Penn Station / 8 Avenue ","AE");
        setConnection(i,j);

        graph::graph_node* k = new graph_node("West 4 Street / 8 Avenue ","ABCDEFM");
        graph::graph_node* l = new graph_node("14 Street / 8 Avenue ","ACE");
        setConnection(k,l);
        
        graph::graph_node* m = new graph_node("Canal Street / 6 Avenue ","AE");
        graph::graph_node* n = new graph_node("West 4 Street / 8 Avenue ","ABDEFM");
        setConnection(m,n);

        graph::graph_node* m = new graph_node("Chambers Street / Church Street ","ACE23NRW");
        graph::graph_node* n = new graph_node("Canal Street / 6 Avenue ","ACE");
        setConnection(m,n);

        graph::graph_node* o = new graph_node("Fulton Street / Broadway","ACJZ2345");
        graph::graph_node* p = new graph_node("Chambers Street / Church Street ","ACE23NRW");
        setConnection(o,p);

//For all C train between 145st and fulton street
        graph::graph_node* a0 = new graph_node("135street / Saint Nicholas Avenue ","BC");
        graph::graph_node* b0 = new graph_node("145street / Saint Nicholas Avenue ","ABCD");
        setConnection(a0,b0);
        
        graph::graph_node* a1 = new graph_node("125street / Saint Nicholas Avenue ","BC");
        graph::graph_node* b1 = new graph_node("135street / Saint Nicholas Avenue ","ABCD");
        setConnection(a1,b1);

        graph::graph_node* c1 = new graph_node("116 Street / 8 Avenue ","BC");
        graph::graph_node* d1 = new graph_node("125street / Saint Nicholas Avenue ","ABCD");
        setConnection(c1,d1);

        graph::graph_node* e1 = new graph_node("Cathedral Parkway (110 Street) / Central Park West ","BC");
        graph::graph_node* f1 = new graph_node("116 Street / 8 Avenue ","BC");
        setConnection(e1,f1);

        graph::graph_node* g1 = new graph_node("103 Street / Central Park West ","BC");
        graph::graph_node* h1 = new graph_node("Cathedral Parkway (110 Street) / Central Park West ","BC");
        setConnection(g1,h1);

        graph::graph_node* i1 = new graph_node("96 Street / Central Park West ","BC");
        graph::graph_node* j1 = new graph_node("103 Street / Central Park West ","BC");
        setConnection(i1,j1);

        graph::graph_node* k1 = new graph_node("86 Street / Central Park West ","BC");
        graph::graph_node* l1 = new graph_node("96 Street / Central Park West ","BC");
        setConnection(k1,l1);

        graph::graph_node* m1 = new graph_node("81 Street-Museum of Natural History / Central Park West ","BC");
        graph::graph_node* n1 = new graph_node("86 Street / Central Park West ","BC");
        setConnection(m1,n1);

        graph::graph_node* o1 = new graph_node("72 Street / Central Park West ","BC");
        graph::graph_node* p1 = new graph_node("81 Street-Museum of Natural History / Central Park West ","BC");
        setConnection(o1,p1);

        graph::graph_node* q1 = new graph_node("59street / Columbus Circle ","ABCD12");
        graph::graph_node* r1 = new graph_node("72 Street / Central Park West ","BC");
        setConnection(q1,r1);

        graph::graph_node* s1 = new graph_node("50street / 8 Avenue ","CE");
        graph::graph_node* t1 = new graph_node("59street / Columbus Circle ","ABCD12");
        setConnection(s1,t1);

        graph::graph_node* u1 = new graph_node("42street Port Authority Bus Terminal / 8 Avenue ","ACENQRSW1237");
        graph::graph_node* v1 = new graph_node("50street / 8 Avenue ","CE");
        setConnection(u1,v1);

        graph::graph_node* w1 = new graph_node("23 Street / 8 Avenue ","CE");
        graph::graph_node* x1 = new graph_node("34 Street-Penn Station / 8 Avenue ","ACE");
        setConnection(w1,x1);

        graph::graph_node* y1 = new graph_node("14 Street / 8 Avenue ","ACE");
        graph::graph_node* z1 = new graph_node("23 Street / 8 Avenue ","CE");
        setConnection(y1,z1);

        graph::graph_node* A1 = new graph_node("Spring Street / 6 Avenue ","CE");
        graph::graph_node* B1 = new graph_node("West 4 Street / 8 Avenue ","ABCDEFM");
        setConnection(A1,B1);

        graph::graph_node* C1 = new graph_node("Canal Street / 6 Avenue ","ACE");
        graph::graph_node* D1 = new graph_node("Spring Street / 6 Avenue ","CE");
        setConnection(C1,D1);

        return 0;
    }



