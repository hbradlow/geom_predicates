#include "predicates.c"
#include <boost/python.hpp>

int a(){
    return 3;
}

BOOST_PYTHON_MODULE(test_l)
{
    using namespace boost::python;
    def("a", a);
}
