#include <iostream>
using namespace std;

int main() {
// The bitwise operators take operands of integral type that they use as a collection
// of bits. These operators let us test and set individual bits. Note: use usigned types with bitwise operators.
// Operator     Function        Use
// ~ bitwise    NOT             ~expr
// <<           left shift      expr1 << expr2 inserts 0-valued bits on the right
// >>           right shift     expr1 >> expr2 inserts 0-valued bits on the left or result is implementation defined.
// &            bitwise AND     expr1 & expr2 the bit is 1 if both operands contain 1; otherwise, the result is 0.
// ^            bitwise XOR     expr1 ^ expr2 1 if either but not both operands contain 1; otherwise, the result is 0.
// |            bitwise OR      expr1 | expr2 the bit is 1 if either or both operands contain 1; otherwise, the result is 0.
    unsigned char bits1 = 0233;
    bits1 << 8; // bits promoted to int and then shifted left by 8 bits
    cout << bits1 + 10 << "  " << bits1 + 5 << "   " << bits1 + 100 << endl;

    unsigned char bits2 = 0233;
    bits2 << 23; // ok: sign bit is unchanged
    cout << bits2 + 1 << endl;

    unsigned char bits3 = 0233;
    bits3 >> 30; //right shift 3 bits, 3 right-most bits discarded
    cout << bits3 + 0 << endl;


    unsigned char bits = 0227; // 1 0 0 1 0 1 1 1
    ~bits;// ) generates a new value with the bits of its operand inverted. Each 1 bit is set to 0; each 0 bit is set to 1.
    //1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0 1 0 0 0

    unsigned char bits12 = 0;
    unsigned char bits21 = 100;
    cout << ((bits12 & bits21) ? "equal" : "not equal") << endl;
    
    //sizeof
    cout << sizeof(bits12) << "  " << sizeof(bits21) << endl;
    return 0;
    }