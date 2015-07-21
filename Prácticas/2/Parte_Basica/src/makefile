natural: main_natural.cpp natural.cpp natural.hpp
	g++ -std=c++11 -fdiagnostics-color=auto main_natural.cpp natural.cpp -o ../bin/natural

integer: main_integer.cpp integer.cpp integer.hpp
	g++ -std=c++11 -fdiagnostics-color=auto main_integer.cpp integer.cpp -o ../bin/integer

rational: main_rational.cpp rational.cpp rational.hpp integer.cpp integer.hpp
	g++ -std=c++11 -fdiagnostics-color=auto main_rational.cpp rational.cpp integer.cpp -o ../bin/rational

real: main_real.cpp real.cpp real.hpp
	g++ -std=c++11 -fdiagnostics-color=auto main_real.cpp real.cpp -o ../bin/real
	
complex: main_complex.cpp complex.cpp complex.hpp real.cpp real.hpp
	g++ -std=c++11 -fdiagnostics-color=auto main_complex.cpp complex.cpp real.cpp -o ../bin/complex