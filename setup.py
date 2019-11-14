from distutils.core import setup, Extension


module = Extension("pytravel.lib", sources=[
    "pytravel/source/wrap.cpp",
    "pytravel/source/travel.cpp",
])

setup(
    name="PyTravel",
    version="1.0",
    packages=['pytravel'],
    description="travels through directories",
    ext_modules=[module],
    extra_compile_args=['-std=c++14']
)
