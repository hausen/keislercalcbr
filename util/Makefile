
all: trigtable exptable logtable powtable

clean:
	rm -f trigtable exptable logtable powtable

%: %.c
	g++ -lm $< -o $@  
