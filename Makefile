SUBDIRS = src
CLEAN_SUBDIRS = $(addprefix clean_, $(SUBDIRS))

.PHONY: subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

$(CLEAN_SUBDIRS): clean_%:
	$(MAKE) -C $* clean

clean: $(CLEAN_SUBDIRS)