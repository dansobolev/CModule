from distutils.core import setup, Extension

module1 = Extension( 'matrixMulti', sources = ['matrixMulti.c'] )

setup( name = 'matrixMulti',
       version = '1.1',
       description = 'This is a first package',
       ext_modules = [module1]
     )