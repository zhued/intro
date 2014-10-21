EXPENDABLES = run_chapter_3_examples run_chapter_3_examples.o chapter_3_question_5.o chapter_3_question_6.o chapter_3_question_25.o chapter_3_question_26.o

all:	
	@make $(EXPENDABLES)

run_chapter_3_examples:run_chapter_3_examples.o chapter_3_question_5.o chapter_3_question_6.o chapter_3_question_25.o chapter_3_question_26.o
	g++ -Wall -gstabs run_chapter_3_examples.o chapter_3_question_5.o chapter_3_question_6.o chapter_3_question_25.o chapter_3_question_26.o -o run_chapter_3_examples

# make object file (ends in .o) with partial compilation of code for the main program
run_chapter_3_examples.o:run_chapter_3_examples.cxx
	g++ -Wall -gstabs -c run_chapter_3_examples.cxx -o run_chapter_3_examples.o

chapter_3_question_5.o:chapter_3_question_5.cxx
	g++ -Wall -gstabs -c chapter_3_question_5.cxx -o chapter_3_question_5.o

chapter_3_question_6.o:chapter_3_question_6.cxx
	g++ -Wall -gstabs -c chapter_3_question_6.cxx -o chapter_3_question_6.o

chapter_3_question_25.o:chapter_3_question_25.cxx
	g++ -Wall -gstabs -c chapter_3_question_25.cxx -o chapter_3_question_25.o

chapter_3_question_26.o:chapter_3_question_26.cxx
	g++ -Wall -gstabs -c chapter_3_question_26.cxx -o chapter_3_question_26.o

clean:
	rm $(EXPENDABLES)
