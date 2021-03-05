import numpy
from setuptools import setup
from Cython.Build import cythonize

setup(
	name="test_prime",
	ext_modules = cythonize("test_prime.pyx"),
	include_dirs=[numpy.get_include()]
)
