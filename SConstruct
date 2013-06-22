class Module:
	def __init__(self, libName, include, libPath):
		self.libName = libName
		self.include = include
		self.libPath = libPath

def getLibName(x): return x.libName

irrlicht = Module('Irrlicht', 'dependencies/irrlicht-1.8/include', 'dependencies/irrlicht-1.8/lib/Linux')

libs = []
libs.append(irrlicht)
libs.append(Module('GL', None, None))
libs.append(Module('X11', None, None))
libs.append(Module('Xxf86vm', None, None))

env = Environment(CPPPATH=irrlicht.include)
env.Program(target='irrlicht-crawler', LIBPATH=irrlicht.libPath, LIBS=map(getLibName, libs), source=['src/main/c++/Main.cpp'])
