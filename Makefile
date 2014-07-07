NAME=keslercalcbr
TIFS=$(wildcard figuras/*/*.tif)
IMGS=$(TIFS:.tif=.pdf)

all: $(IMGS)
	pdflatex $(NAME)
	if [ -f $(NAME).ind ]; then mv $(NAME).ind $(NAME).oid; fi
	makeindex $(NAME)
	if [ -f $(NAME).oid ]; \
	then \
		diff -q $(NAME).ind $(NAME).oid > /dev/null; \
		if [ "$$?" -eq "1" ]; then \
			pdflatex $(NAME) ; \
		fi; \
	else \
		pdflatex $(NAME) ; \
	fi

figuras/%.pdf: figuras/%.tif
	tiff2pdf $< > $@

clean:
	rm -f *.aux *.log *.idx *.toc *.out *.ilg *.ind $(NAME).oid $(IMGS)
