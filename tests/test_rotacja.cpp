#include "doctest/doctest.h"

#include "Rotacja.hh"

// TEST_CASE("Obrót względem osi X"){
//     Wektor3D x,z;
//     MacierzObrotu y;
//     x.set_vector(0,0);
//     x.set_vector(1,0);
//     x.set_vector(2,1);

//     z=y.ObrotX(90,x);

//     CHECK(z.get_vector(0)==0);
//     CHECK(z.get_vector(1)==-1);
//     CHECK(z.get_vector(2)==0);
// }

// TEST_CASE("Obrót względem osi X"){
//     Wektor3D x,z;
//     MacierzObrotu y;
//     x.set_vector(0,0);
//     x.set_vector(1,1);
//     x.set_vector(2,0);

//     z=y.ObrotX(90,x);

//     CHECK(z.get_vector(0)==0);
//     CHECK(z.get_vector(1)==0);
//     CHECK(z.get_vector(2)==1);
// }

// TEST_CASE("Obrót względem osi X"){
//     Wektor3D x,z;
//     MacierzObrotu y;
//     x.set_vector(0,1);
//     x.set_vector(1,0);
//     x.set_vector(2,0);

//     z=y.ObrotX(90,x);

//     CHECK(z.get_vector(0)==1);
//     CHECK(z.get_vector(1)==0);
//     CHECK(z.get_vector(2)==0);
// }

// TEST_CASE("Obrót względem osi Y"){
//     Wektor3D x,z;
//     MacierzObrotu y;
//     x.set_vector(0,0);
//     x.set_vector(1,0);
//     x.set_vector(2,1);

//     z=y.ObrotY(90,x);

//     CHECK(z.get_vector(0)==1);
//     CHECK(z.get_vector(1)==0);
//     CHECK(z.get_vector(2)==0);
// }

// TEST_CASE("Obrót względem osi Y"){
//     Wektor3D x,z;
//     MacierzObrotu y;
//     x.set_vector(0,0);
//     x.set_vector(1,1);
//     x.set_vector(2,0);

//     z=y.ObrotY(90,x);

//     CHECK(z.get_vector(0)==0);
//     CHECK(z.get_vector(1)==1);
//     CHECK(z.get_vector(2)==0);
// }

// TEST_CASE("Obrót względem osi Y"){
//     Wektor3D x,z;
//     MacierzObrotu y;
//     x.set_vector(0,1);
//     x.set_vector(1,0);
//     x.set_vector(2,0);

//     z=y.ObrotY(90,x);

//     CHECK(z.get_vector(0)==0);
//     CHECK(z.get_vector(1)==0);
//     CHECK(z.get_vector(2)==-1);
// }

// TEST_CASE("Obrót względem osi Z"){
//     Wektor3D x,z;
//     MacierzObrotu y;
//     x.set_vector(0,0);
//     x.set_vector(1,0);
//     x.set_vector(2,1);

//     z=y.ObrotZ(90,x);

//     CHECK(z.get_vector(0)==0);
//     CHECK(z.get_vector(1)==0);
//     CHECK(z.get_vector(2)==1);
// }

// TEST_CASE("Obrót względem osi Z"){
//     Wektor3D x,z;
//     MacierzObrotu y;
//     x.set_vector(0,0);
//     x.set_vector(1,1);
//     x.set_vector(2,0);

//     z=y.ObrotZ(90,x);

//     CHECK(z.get_vector(0)==-1);
//     CHECK(z.get_vector(1)==0);
//     CHECK(z.get_vector(2)==0);
// }

// TEST_CASE("Obrót względem osi Z"){
//     Wektor3D x,z;
//     MacierzObrotu y;
//     x.set_vector(0,1);
//     x.set_vector(1,0);
//     x.set_vector(2,0);

//     z=y.ObrotZ(90,x);

//     CHECK(z.get_vector(0)==0);
//     CHECK(z.get_vector(1)==1);
//     CHECK(z.get_vector(2)==0);
// }