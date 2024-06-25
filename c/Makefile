IDIR = include
SDIR = src
TDIR = test
EDIR = expe
ODIR = obj
BDIR = bin
DDIR = docs

CC = gcc
CFLAGS = -Wall -Wextra -I$(IDIR) -c

PROG = $(BDIR)/gameoflife
TEST = $(BDIR)/runtest
EXPE = $(BDIR)/expe

_DEPS = grid.h cells.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = grid.o cells.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_TEST_SRC = test.c test_cells.c test_grid.c
TEST_OBJ = $(patsubst %,$(ODIR)/%,$(_TEST_SRC:.c=.o))

# Phony targets
.PHONY: all run memorycheck test testmemorycheck expe clean delete deletetest deleteresult deletedoc cleanall doc

# Default target
all : $(PROG) $(TEST) $(EXPE)

run : all
	$(PROG) $(rows) $(cols) $(num_alive_cells) $(num_generations)

memorycheck : all
	valgrind $(PROG) $(rows) $(cols) $(num_alive_cells) $(num_generations)

test: $(TEST)
	$(TEST)

testmemorycheck : $(TEST)
	valgrind $(TEST)

expe: $(EXPE)
	$(EXPE) ../benchmarks/grid.txt

clean :
	rm -f $(ODIR)/*.o

delete :
	rm -f $(PROG)

deletetest :
	rm -f $(TEST)

deleteresult :
	rm -f $(EDIR)/expe_result.txt

deletedoc :
	rm -rf $(DDIR)/*

cleanall: clean delete deletetest deleteresult deletedoc

doc :
	doxygen Doxyfile

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -o $@ $<

$(ODIR)/%.o: $(TDIR)/%.c $(DEPS)
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -o $@ $<

$(ODIR)/%.o: $(EDIR)/%.c $(DEPS)
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -o $@ $<

$(PROG): $(OBJ) $(ODIR)/main.o
	@mkdir -p $(BDIR)
	$(CC) -o $@ $^ -lm

$(TEST): $(OBJ) $(TEST_OBJ)
	@mkdir -p $(BDIR)
	$(CC) -o $@ $^ -lm

$(EXPE): $(OBJ) $(ODIR)/expe.o
	@mkdir -p $(BDIR)
	$(CC) -o $@ $^ -lm
