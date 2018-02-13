#include <cassert>
#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <vector>


using namespace std;

#include "Data.h"

#include "IIterator.h"
//------------------------------------------------------------------------------
#include "Iterator.h"
//--------------X---------------------------------------------------------------
#include "Container.h"
//------------------------------------------------------------------------------

#include "Collection.h"


int main() {
    try {

        A* a1 = new A("bmw");
        A* a2 = new A("honda");
        A* a3 = new A("mazda");


        //------------------------------------------------------

        CollectionStl<A*, list> collList;
        collList.Add(a1);
        collList.Add(a2);
        collList.Add(a3);

        cout  << " collection on template list  : \n";
        collList.Print();

        CollectionStl<A*, vector> collVector;
        collVector.Add(a1);
        collVector.Add(a2);
        collVector.Add(a3);

        cout  << " collection on  template vector : \n";
        collVector.Print();
        //collVector.Next();
        //A *a = *collVector.Get();

    }

    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
    }
    catch (...) {
        cerr << "exception\n";
    }
}


