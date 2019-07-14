
compile:
	g++ source/travel.cpp source/binomial.cpp main.cpp -o bin/main

buildlib:
	python3 setup.py build
