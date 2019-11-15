

clean:
	@rm -rf build

install:
	@env/bin/python3 setup.py install

build:
	@env/bin/python3 setup.py build
