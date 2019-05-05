################################################
# Draw pixel of image -- use plugin
# Create by: tyw66  2019/4/23
#################################################
TEMPLATE = subdirs
SUBDIRS  = \
		    mainwindow \
		    libs\
		    plugins\


QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -Wno-unused-parameter
QMAKE_CXXFLAGS += -Wno-unused-variable
