import os, sys

from distutils.core import setup, Extension
from distutils import sysconfig

cpp_args = ['-std=c++14'] 

ext_modules = [
    Extension(
    'ex4',
        ['funcs.cpp', 'ex4.cpp'],
        include_dirs=['pybind11/include'],
    language='c++',
    extra_compile_args = cpp_args,
    ),
]

setup(
    name='ex4',
    version='0.0.1',
    author='Cliburn Chan',
    author_email='cliburn.chan@duke.edu',
    description='Example',
    ext_modules=ext_modules,
)
