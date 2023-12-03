APP_NAME = analysistool
SUBDIRS = ./lib$(APP_NAME) ./$(APP_NAME)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	rm */out -rf
	rm out -rf
run:
	./out/$(APP_NAME)

.PHONY: all $(SUBDIRS)
