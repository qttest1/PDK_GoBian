#
# -= Makefile for module compile =-
#
# Usage:
# . Name this file as "Makefile";
#   Put it in the same directory as module's source code.
# . Change the ROOT definition, if necessary;
#   Make it point to the root of the software tree.
# . Define the Module Name in MOD as you like;
#   There should be NO duplicated module names in the whole project.
# . List all files want to be compiled in ASMS and/or SRCS;
#   Including files, such as header files, must NOT be listed here.
# . List all library files this module may depends on in LIBS.
# . Give a new name in SMOD, if want to include sub-directories;
#   Write the linkage information at the end of file.
#

# Destination of definition files
ROOT = ../../..

# Module Name
MOD = OSAL_PTHREAD

# List of source files
ASMS =
SRCS = sysrpc.c osal_linux.c linux_osal_timer.c select_timer.c srpc.c cbuffer.c

# List of library files
LIBS =

# List of sub-modules
# Note: Can NOT be the same name as sub-directories.
SMOD =

# Following lines are the common description for all projects.
# Do NOT modify anything, unless you know what you are doing.
include ${ROOT}/src/path.def
include ${ROOT}/src/compiler.def

#CFLAGS := ${C32FLAGS}

OBJS = ${ASMS:.S=.o} ${SRCS:.c=.o}
SMOD_ = ${SMOD:=_}

all : ${MOD}.mk
	${MAKE} -f ${MOD}.mk ${OBJS} ${SMOD}
	cp -f ${OBJS} ${LIBS} ${LIB_DIR}
	echo ${OBJS} ${LIBS} \\ > ${LIB_DIR}/${MOD}.lst
	echo ${MOD}.lst \\ >> ${LIB_DIR}/list.mod
	echo ${MOD}.lst \\ >> ${LIB_DIR}/list.sdk
	
${MOD}.mk : ${ASMS} ${SRCS}
	cp -f Makefile $@
	chmod +w $@
	${CC} ${CFLAGS} -M ${ASMS} ${SRCS} >> $@

clean : ${SMOD_}
	rm -f ${OBJS} ${MOD}.mk
	cd ${LIB_DIR}; \
	  echo rm -f \\ > rm.sh; \
	  cat ${MOD}.lst >> rm.sh; \
	  sh < rm.sh; \
	  rm -f rm.sh ${MOD}.lst

rebuild: clean all
# End of common description.

# Construct of sub-modules

# Deconstruct of sub-modules
