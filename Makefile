default: all

# C++プログラム作成用Makefileのテンプレです

MAKEFLAGS ?= -j$(shell nproc)

INTERMEDIATE := ./build
$(shell mkdir -p $(INTERMEDIATE))

CXXSRCDIR := src
CXXSRC := $(wildcard $(addprefix $(CXXSRCDIR)/,*.cpp))
OBJS := $(CXXSRC:$(CXXSRCDIR)/%.cpp=$(INTERMEDIATE)/%.o)
DEPE := $(OBJS:%.o=%.d)
LIBDIR := ./lib
LDFLAGS := -L$(LIBDIR)
INCLUDE := -I$(LIBDIR)/src
LIBS := -lmy
program := program

CXX := g++
CFLAGS := -O2 -MMD -g $(INCLUDE)

# allとcleanはファイルではなくターゲットであると宣言する
.PHONY: all clean

# 実行する
all: $(program)
run: all
	./$(program)
# コンパイルする
$(program): $(OBJS)
	$(MAKE) -C $(LIBDIR)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)
$(OBJS): build/%.o: $(CXXSRCDIR)/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $(filter %.cpp,$^) -MF $(patsubst %.o,%.d,$@)

# 中間ファイルをすべて消去する
clean:
	$(MAKE) $@ -C $(LIBDIR)
	rm -rf $(INTERMEDIATE) $(program)
	
-include $(DEPE)

