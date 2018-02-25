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
    	 ContainerStl<int, list> contain;

//    	IteratorStl<int, list > *backItr 	= new IteratorStl<int, list>( contain );



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

        cout << " collection back iterator " << endl;
        CollectionBack<A*, list> collectionBack;
        collectionBack.Add(a1);
        collectionBack.Add(a2);
        collectionBack.Add(a3);

        collectionBack.Print();

        cout << " collection bidirection iterator " << endl;
        CollectionBiDir<A*, list> collectionBiDir;
        collectionBiDir.Add(a1);
        collectionBiDir.Add(a2);
        collectionBiDir.Add(a3);
        collectionBiDir.Print();



    }

    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
    }
    catch (...) {
        cerr << "exception\n";
    }
}


