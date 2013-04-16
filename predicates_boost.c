#include "predicates.c"
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(predicates)
{
    using namespace boost::python;
    def("incircle", incircle);
}
