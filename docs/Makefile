#
# Sample programs for HPC onboarding
#

DOCS = matmul1.html


all default: $(DOCS)


# Formula for compiling a markdown text source to HTML file
%.html: %.md
	markdown_py -f $@ $<

