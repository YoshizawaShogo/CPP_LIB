default: all

# C++プログラム作成用Makefileのテンプレです

# make コマンド使用時に使用されるオプション
MAKEFLAGS ?= -j$(shell nproc)

# .oファイルや.dファイルを収容するディレクトリ
INTERMEDIATE := ./build
$(shell mkdir -p $(INTERMEDIATE))

# CXXSRCDIR内のすべての.cppファイルをコンパイル対象とする
CXXSRCDIR := src
CXXSRC := $(wildcard $(addprefix $(CXXSRCDIR)/,*.cpp))

# .oファイル, .dファイルの名前取得
OBJS := $(CXXSRC:$(CXXSRCDIR)/%.cpp=$(INTERMEDIATE)/%.o)
DEPE := $(OBJS:%.o=%.d)

## 自作したライブラリの情報
# ライブラリが有るディレクトリ
LIBDIR := ./lib
LDFLAGS := -L$(LIBDIR)
# ヘッダファイルがあるディレクトリ
INCLUDE := -I$(LIBDIR)/src
# ライブラリの名前(libmy.a)
LIBS := -lmy


# 使用するコンパイラ
CXX := g++
# コンパイル時のオプション
CFLAGS := -O2 -MMD -g $(INCLUDE)
# コンパイルされた実行ファイル
program := $(INTERMEDIATE)/program

# allとcleanはファイルではなくターゲットであると宣言する
.PHONY: all clean

# コンパイルする
all: $(program)
# 実行する
run: all
	./$(program)

# ファイルの依存関係
$(program): $(OBJS)
	$(MAKE) -C $(LIBDIR)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)
	@echo --*----------------------------*--
	@echo
$(OBJS): build/%.o: $(CXXSRCDIR)/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $(filter %.cpp,$^) -MF $(patsubst %.o,%.d,$@)

# 中間ファイルをすべて消去する
clean:
	$(MAKE) $@ -C $(LIBDIR)
	rm -rf $(INTERMEDIATE) $(program)

# ヘッダファイルを含む依存関係を取得
-include $(DEPE)

