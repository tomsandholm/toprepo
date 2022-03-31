bin_PROGRAMS = toprepo
toprepo_SOURCES = toprepo.c

clean-local:
	make uninstall

chk-pointers:
	@echo "##### current submodule status"
	git submodule status --recursive
	top=$$(pwd); for x in $$(git submodule status --recursive | \
	  awk '/^+/ {print $$2}') ; do \
	  echo "x is $$x"; \
	  cd $$x; \
	  cd ..; \
	  git add $$(basename $$x); \
          git commit -m 'new pointer'; \
          git push; \
	  done; \
	  cd $$top
