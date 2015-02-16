#!/bin/bash
# s/cmr10/Times New Roman/g; 

if [ ! -d /tmp/tmp.latex ]
then
  mkdir /tmp/tmp.latex
fi

cat <<EOF > /tmp/tmp.latex/tmp.tex
\documentclass[12pt]{article}
\usepackage[T1]{fontenc}
\usepackage[utf8]{inputenc}
\usepackage[portuguese,brazil]{babel}
\usepackage{mathptmx}
\usepackage{amsmath,amssymb}

\pagestyle{plain}
\pagenumbering{gobble}

\\begin{document}
EOF

cd /tmp/tmp.latex
cat >> tmp.tex
echo "\\end{document}" >> tmp.tex
rm -f tmp.dvi
latex -interaction=nonstopmode tmp.tex > /dev/null 2>&1
if [ -f tmp.dvi ]
then
  dvisvgm -b0 -s tmp.dvi | sed -e 's/psyr/Times New Roman/g; s/ptmri8r/Times New Roman;font-style:italic/g; s/ptmr8r/Times New Roman/g; s/cmmi10/Times New Roman/g; s/㐀/−/g;' 2> /dev/null
else
  echo "ERROR running latex!"
  exit 1
fi
