#include <iostream>

// クラステンプレート
template <typename Type, typename Type2>
class TemplateClass {
public:
    // コンストラクタ
    TemplateClass(Type number1, Type2 number2) :
        Number1(number1), Number2(number2) {
    }

    Type Min()
    {
        if (Number1 < Number2)
            return static_cast<Type>(Number1);
        else
            return static_cast<Type>(Number2);
    }

private:
    Type Number1;
    Type2 Number2;
};

int main() {
    TemplateClass<int, float> intFloatTemplate(100, 50.0f);
    TemplateClass<int, double> intDoubleTemplate(80, 20.0);
    TemplateClass<float, int> floatIntTemplate(2.0f, 18);
    TemplateClass<float, double> floatDoubleTemplate(11.0f, 3.5);
    TemplateClass<double, int> doubleIntTemplate(234.0, 123);
    TemplateClass<double, float> doubleFloatTemplate(400.1, 500.2f);

    std::cout << "int(100) と float(50.0f) を比べて小さい数字を返す："
        << intFloatTemplate.Min() << std::endl;

    std::cout << "int(80) と double(20.0) を比べて小さい数字を返す："
        << intDoubleTemplate.Min() << std::endl;

    std::cout << "float(2.0f) と int(18) を比べて小さい数字を返す："
        << floatIntTemplate.Min() << std::endl;

    std::cout << "float(11.0f) と double(3.5) を比べて小さい数字を返す："
        << floatDoubleTemplate.Min() << std::endl;

    std::cout << "double(234.0) と int(123) を比べて小さい数字を返す："
        << doubleIntTemplate.Min() << std::endl;

    std::cout << "double(400.1) と float(500.2f) を比べて小さい数字を返す："
        << doubleFloatTemplate.Min() << std::endl;

    return 0;
}
