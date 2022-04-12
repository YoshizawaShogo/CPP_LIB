default: all

# C++プログラムのアーカイブ作成用のMakefileです

MAKEFLAGS ?= -j$(shell nproc)

INTERMEDIATE := ./build
$(shell mkdir -p $(INTERMEDIATE))

CXXSRCDIR := src
CXXSRC := $(wildcard $(addprefix $(CXXSRCDIR)/,*.cpp))
OBJS := $(CXXSRC:$(CXXSRCDIR)/%.cpp=$(INTERMEDIATE)/%.o)
DEPE := $(OBJS:%.o=%.d)
ARCHIVE := libmy.a

CXX := g++
CFLAGS := -O2 -g -MMD

# allとcleanはファイルではなくターゲットであると宣言する
.PHONY: all clean
all: $(ARCHIVE)

# アーカイブする
$(ARCHIVE): $(OBJS)
	ar r $@ $^
$(OBJS): build/%.o: $(CXXSRCDIR)/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $(filter %.cpp,$^) -MF $(patsubst %.o,%.d,$@)

# 中間ファイルをすべて消去する
clean:
	rm -rf $(INTERMEDIATE) $(ARCHIVE)
	
-include $(DEPE)
