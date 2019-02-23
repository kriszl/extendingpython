from distutils.core import setup, Extension;

module1 = Extension('extensionmodule',
sources=['extensionmodule.c']);

setup (name = 'extensionmodule',
version = '0.1',
description ='An example module for Python implemented in C',
ext_modules = [module1]);