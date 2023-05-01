#include "doctest/doctest.h"

#include "SWektor.hh"

// TEST_CASE("Przypisywanie wartości rzeczywistych"){
//     SVector<double,3> x;

//     x.set_vector(0,4);
//     x.set_vector(1,-3);
//     x.set_vector(2,7);

//     CHECK(x.get_vector(0)==4);
//     CHECK(x.get_vector(1)==-3);
//     CHECK(x.get_vector(2)==7);
// }



// TEST_CASE("Dodawanie wektorów rzeczywistych"){
//     SVector<double,3> x,y,z;

//     x.set_vector(0,4);
//     x.set_vector(1,-3);
//     x.set_vector(2,7);

//     y.set_vector(0,1);
//     y.set_vector(1,8);
//     y.set_vector(2,-4);

//     z=x+y;

//     CHECK(z.get_vector(0)==5);
//     CHECK(z.get_vector(1)==5);
//     CHECK(z.get_vector(2)==3);
// }

// TEST_CASE("Odejmowanie wektorów rzeczywistych"){
//     SVector<double,3> x,y,z;

//     x.set_vector(0,4);
//     x.set_vector(1,-3);
//     x.set_vector(2,7);

//     y.set_vector(0,1);
//     y.set_vector(1,8);
//     y.set_vector(2,-4);

//     z=x-y;

//     CHECK(z.get_vector(0)==3);
//     CHECK(z.get_vector(1)==-11);
//     CHECK(z.get_vector(2)==11);
// }

// TEST_CASE("Mnożenie wektorów rzeczywistych przez skalar"){
//     SVector<double,3> x,z;
//     double y=-3;

//     x.set_vector(0,4);
//     x.set_vector(1,-3);
//     x.set_vector(2,7);

//     z=x*y;

//     CHECK(z.get_vector(0)==-12);
//     CHECK(z.get_vector(1)==9);
//     CHECK(z.get_vector(2)==-21);
// }


// TEST_CASE("Mnożenie dwóch wektorów rzeczywistych"){
//     SVector<double,3> x,y,z;

//     x.set_vector(0,4);
//     x.set_vector(1,-3);
//     x.set_vector(2,7);

//     y.set_vector(0,1);
//     y.set_vector(1,8);
//     y.set_vector(2,-4);

//     z=x*y;

//     CHECK(z.get_vector(0)==4);
//     CHECK(z.get_vector(1)==-24);
//     CHECK(z.get_vector(2)==-28);
// }


// TEST_CASE("Dzielenie wektorów rzeczywistych przez skalar"){
//     SVector<double,3> x,z;
//     double y=-2;

//     x.set_vector(0,16);
//     x.set_vector(1,-8);
//     x.set_vector(2,0);

//     z=x/y;

//     CHECK(z.get_vector(0)==-8);
//     CHECK(z.get_vector(1)==4);
//     CHECK(z.get_vector(2)==0);
// }

// TEST_CASE("Porównanie dwóch wektorów rzeczywistych"){
//     SVector<double,3> x,y;

//     x.set_vector(0,3);
//     x.set_vector(1,-3);
//     x.set_vector(2,7);

//     y.set_vector(0,3);
//     y.set_vector(1,-3);
//     y.set_vector(2,7);

//     CHECK(x==y);
// }

// TEST_CASE("Porównanie dwóch wektorów rzeczywistych"){
//     SVector<double,3> x,y;

//     x.set_vector(0,4);
//     x.set_vector(1,-3);
//     x.set_vector(2,7);

//     y.set_vector(0,3);
//     y.set_vector(1,3);
//     y.set_vector(2,7);

//     CHECK(!(x==y));
// }

// TEST_CASE("Odwrotność wektora rzeczywistego"){
//     SVector<double,3> x,y,z;

//     x.set_vector(0,3);
//     x.set_vector(1,-3);
//     x.set_vector(2,7);

//     y.set_vector(0,-3);
//     y.set_vector(1,3);
//     y.set_vector(2,-7);

//     z=x.odwrotnosc();

//     CHECK(z==y);
// }