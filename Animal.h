#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
public:
    virtual void sound() const = 0; // 純粋仮想関数（ポリモーフィズム）
    virtual ~Animal() {}            // 仮想デストラクタ
};

#endif
