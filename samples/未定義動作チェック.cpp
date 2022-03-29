// 参考サイト: https://rsk0315.hatenablog.com/entry/2019/09/10/213859
// 結論: 未定義動作(オーバーフローなど)は絶対にしないように

#include <iostream>

bool f(int x) {
    std::cout << "x = " << x << std::endl;
    std::cout << "x+1 = " << x+1 << std::endl;

    // -O0, -O2 ののどちらでも試験済み
    // オーバーフローが未定義な事に起因して常にtrue
    // x < x + 1
    // x - x < x - x + 1
    // 0 < 1
    // true
    if (!(x < x+1)) return false; //この行をコメントアウトしてもアセンブリコードは同じであった
    return true;
}

int main() {

    //機械目線(bit演算)では正しいが、
    //人間目線(数学)ではおかしい
    bool a = f(0x7fffffff);
    std::cout << "x < x+1 => " << a << std::endl << std::endl;

    //機械目線(bit演算)でおかしいが、
    //人間目線(数学)では正しい
    a = f(0xffffffff);
    std::cout << "x < x+1 => " << a << std::endl;

    //ifが一定の基準で真偽を判断せず、
    //常にtrueが返っていると考えられる
    return 0;
}