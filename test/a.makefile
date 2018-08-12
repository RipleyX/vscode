cc = clang++
prom = 1
src = 1.cpp
     
$(prom): $(src)
	$(cc) $(src) -o $(prom) -g -Wall -static-libgcc -fcolor-diagnostics -std=c++17
