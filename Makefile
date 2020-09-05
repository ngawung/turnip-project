#---------------------------------------------------------------------------------
# all subfolder name (order is important)
#---------------------------------------------------------------------------------
GAMEDIRS	:=	Ephemeral Game
SUBDIRS		:=	Vendor/nds_nflib/nflib $(GAMEDIRS)

all:
	@for dir in $(SUBDIRS) ; do \
		echo ============== $$dir ============== ; \
		echo "" ; \
		if test -e $$dir/Makefile ; then $(MAKE)  -C $$dir || { exit 1;} fi; \
		echo "" ; \
	done

#---------------------------------------------------------------------------------
# clean game build file
#---------------------------------------------------------------------------------
clean:
	@for i in $(GAMEDIRS); do if test -e $$i/Makefile ; then $(MAKE)  -C $$i clean || { exit 1;} fi; done;
	@echo Cleaning done....

#---------------------------------------------------------------------------------
# clean all build file
#---------------------------------------------------------------------------------
cleanall:
	@for i in $(SUBDIRS); do if test -e $$i/Makefile ; then $(MAKE)  -C $$i clean || { exit 1;} fi; done;
	@echo Cleaning done....