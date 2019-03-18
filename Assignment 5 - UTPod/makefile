final: UtPodDriver.o UtPod.o song.o
	g++ -otest  UtPodDriver.o UtPod.o song.o
driver: UtPodDriver.cpp UtPod.h Song.h
	g++ UtPod_Driver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ UtPod.cpp
song.o: Song.cpp Song.h
	g++ Song.cpp