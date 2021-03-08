CXX := g++
CFLAGS := -m64 -I"${MKLROOT}/include" -pg

# Intel
LDFLAGS := -larmadillo \
	-L${MKLROOT}/lib/intel64 \
	-Wl,--no-as-needed \
	-lmkl_intel_lp64 \
	-lmkl_gnu_thread \
	-lmkl_core \
	-lgomp \
	-lpthread \
	-lm \
	-ldl

# Openblas
LDFLAGS := -larmadillo \
	-lopenblas \
	-lgomp \
	-lpthread \
	-lm \
	-ldl

TARGETS := test_local test_arma

.PHONY: all clean

all: $(TARGETS)

test_local: test.cpp
	g++ $(CFLAGS) $^ -o $@

test_arma: test_arma.cpp
	g++ $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGETS)
