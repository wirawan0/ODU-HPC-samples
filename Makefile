#
# Sample programs for HPC onboarding
#
# The documents were compiled using markdown_py,
# a python implementation of markdown.

# FRONT_DOCS cover document files located in this subdirectory

FRONT_DOCS = CHANGELOG.html README.html


default: $(FRONT_DOCS)

all: $(FRONT_DOCS) docs.dir

# Formula for compiling a markdown text source to HTML file
%.html: %.md
	markdown_py -f $@ $<

# Compiles all the documentation in the docs/ subdirectory.
docs.dir:
	$(MAKE) -C docs all
