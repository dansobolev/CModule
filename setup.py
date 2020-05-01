from distutils.core import setup, Extension

module1 = Extension( 
	'matrixMulti', # module name in interpreter
	sources = ['mult.c'] 
)

setup( 
	name = 'matrixMulti',
	version = '1.1',
	description = 'Simple matrix multiplication module',
	ext_modules= [module1]
)