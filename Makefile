CC=gcc
AR=ar
OBGECT_LIB_CLASS_LOOPS_A= basicClassification.o advancedClassificationLoop.o
OBGECT_LIB_CLASS_REC_A= basicClassification.o advancedClassificationRecursion.o
OBGECT_LIB_CLASS_LOOPS_SO= basicClassification.o advancedClassificationLoop.o
OBGECT_LIB_CLASS_REC_SO= basicClassification.o advancedClassificationRecursion.o
FLAGS=-g -Wall

all:loops recursives recursived loopd mains maindloop maindrec

loops: libclassloops.a
recursives: libclassrec.a
recursived:libclassloops.so
loopd:libclassrec.so

libclassloops.a:$(OBGECT_LIB_CLASS_LOOPS_A) 
	$(AR) -rcs libclassloops.a $(OBGECT_LIB_CLASS_LOOPS_A)
libclassrec.a:$(OBGECT_LIB_CLASS_REC_A)
	$(AR) -rcs libclassrec.a $(OBGECT_LIB_CLASS_REC_A)
libclassloops.so:$(OBGECT_LIB_CLASS_LOOPS_SO) 
	$(CC) -shared -o libclassloops.so $(OBGECT_LIB_CLASS_LOOPS_SO)
libclassrec.so:$(OBGECT_LIB_CLASS_REC_SO) 
	$(CC) -shared -o libclassrec.so $(OBGECT_LIB_CLASS_REC_SO)

basicClassification.o: basicClassification.c NumClass.h 
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h 
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h 
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

mains: main.o libclassrec.a 
	$(CC) $(FLAGS) -o mains main.o libclassrec.a
maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so 
maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

 clean:
	rm -f *.o *.a *.so mains maindloop maindrec