music.pdf: music.tex staff1-crop.pdf staff2-crop.pdf staff3-crop.pdf
	pdflatex music.tex

staff1-crop.pdf: staff1.ly
	lilypond staff1.ly
	pdfcrop staff1.pdf
	
staff2-crop.pdf: staff2.ly
	lilypond staff2.ly
	pdfcrop staff2.pdf

staff3-crop.pdf: staff3.ly
	lilypond staff3.ly
	pdfcrop staff3.pdf
