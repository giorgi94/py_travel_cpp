from distutils.core import setup, Extension


module = Extension("myModule", sources=[
    "source/wrap.cpp",
    "source/binomial.cpp",
    "source/travel.cpp",
])

setup(name="PackageName", version="1.0",
      description="This is a package for myModule",
      ext_modules=[module])
