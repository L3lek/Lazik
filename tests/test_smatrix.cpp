#include "doctest/doctest.h"

#include "SWektor.hh"
#include "SMacierz.hh"

// TEST_CASE("Przypisywanie wartości rzeczywistych"){
//     SMatrix<double,3> x;
//     SVector<double,3> a,b,c;

//     a.set_vector(0,4);
//     a.set_vector(1,-3);
//     a.set_vector(2,7);
//     b.set_vector(0,2);
//     b.set_vector(1,-1);
//     b.set_vector(2,0);
//     c.set_vector(0,0);
//     c.set_vector(1,-3.4);
//     c.set_vector(2,342);

//     x.set_matrix(0,a);
//     x.set_matrix(1,b);
//     x.set_matrix(2,c);

//     CHECK(x.get_matrix(0)==a);
//     CHECK(x.get_matrix(1)==b);
//     CHECK(x.get_matrix(2)==c);
// }

// TEST_CASE("Mnożenie macierzy rzeczywistej przez wektor"){
//     SMatrix<double,3> x;
//     SVector<double,3> a,b,c,d,e;

//     a.set_vector(0,4);
//     a.set_vector(1,-3);
//     a.set_vector(2,7);
//     b.set_vector(0,2);
//     b.set_vector(1,-1);
//     b.set_vector(2,0);
//     c.set_vector(0,0);
//     c.set_vector(1,-3);
//     c.set_vector(2,4);
//     d.set_vector(0,1);
//     d.set_vector(1,2);
//     d.set_vector(2,3);

//     x.set_matrix(0,a);
//     x.set_matrix(1,b);
//     x.set_matrix(2,c);

//     e=x*d;

//     CHECK(e.get_vector(0)==19);
//     CHECK(e.get_vector(1)==0);
//     CHECK(e.get_vector(2)==6);
// }