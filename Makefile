#---------------------------------------------------------------------------------
# all subfolder name (order is important)
#---------------------------------------------------------------------------------
SUBDIRS:= nflib Ephemeral Game

all:
	@for dir in $(SUBDIRS) ; do \
		echo ============== $$dir ============== ; \
		echo "" ; \
		if test -e $$dir/Makefile ; then $(MAKE)  -C $$dir || { exit 1;} fi; \
		echo "" ; \
	done

clean:
	@for i in $(SUBDIRS); do if test -e $$i/Makefile ; then $(MAKE)  -C $$i clean || { exit 1;} fi; done;
	@echo Cleaning done....