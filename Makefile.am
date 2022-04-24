bin_PROGRAMS = toprepo
toprepo_SOURCES = toprepo.c
branch=main

clean-local:
	make uninstall

chk-pointers:
	./check-pointers

update:
	git submodule update --init --recursive
	git submodule foreach --recursive "git checkout $(branch)"
	git submodule foreach --recursive "git pull"
