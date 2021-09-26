from distutils.core import setup, Extension

name = "state"
version = "0.8"

ext_modules = Extension(name='_state', sources=["state.i", "state.cpp"], language='c++')

setup(name=name, version=version, ext_modules=[ext_modules])
