MAKE := make -r
PROJECTS := cpp_file out_file test


all:$(PROJECTS)


$(PROJECTS):
	$(MAKE) -C $@

clean:
	@tput setaf 1;echo Entering directory $@; tput sgr0;
	@$(foreach i, $(PROJECTS), $(MAKE) -C $i clean;)

.PHONY: clean
.PHONY: $(PROJECTS)
.PHONY: all

