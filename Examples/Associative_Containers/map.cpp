#include <iostream>
#include <map>

/*
K t; V u;
std::map<K,V> m;           // std::map<K,V>::value_type is std::pair<const K,V>

m.insert( std::pair<const K,V>(t,u) );      // 1
m.insert( std::map<K,V>::value_type(t,u) ); // 2
m.insert( std::make_pair(t,u) );            // 3
But the are not really the same... [1] and [2] are actually equivalent. In both cases the code creates a temporary object of the same type (std::pair<const K,V>) and passes it to the insert function.
The insert function will create the appropriate node in the binary search tree and then copy the value_type part from the argument to the node. The advantage of using value_type is that, well, value_type always
matches value_type, you cannot mistype the type of the std::pair arguments!

The difference is in [3]. The function std::make_pair is a template function that will create a std::pair. The signature is:

template <typename T, typename U>
std::pair<T,U> make_pair(T const & t, U const & u );
I have intentionally not provided the template arguments to std::make_pair, as that is the common usage. And the implication is that the template arguments are deduced from the call, in this case to be T==K,U==V,
so the call to std::make_pair will return a std::pair<K,V> (note the missing const). The signature requires value_type that is close but not the same as the returned value from the call to std::make_pair.
Because it is close enough it will create a temporary of the correct type and copy initialize it. That will in turn be copied to the node, creating a total of two copies.

This can be fixed by providing the template arguments:

m.insert( std::make_pair<const K,V>(t,u) );  // 4

n C++11, with variadic templates and perfect forwarding there is a new way of adding elements into a container by means of emplacing (creating in place). The emplace functions in the different containers do basically the same thing: instead of getting a source from which to copy into the container, the function takes the parameters that will be forwarded to the constructor of the object stored in the container.

m.emplace(t,u);               // 5
In [5], the std::pair<const K, V> is not created and passed to emplace, but rather references to the t and u object are passed to emplace that forwards them to the constructor of the value_type subobject inside the data structure. In this case no copies of the std::pair<const K,V> are done at all, which is the advantage of emplace over the C++03 alternatives. As in the case of insert it will not override the value in the map.

*/
