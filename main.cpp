#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Kendaraan
{
public:
    std::string merk;
    void suara()
    {
        std::cout << "kendaraan suara" << std::endl;
    }
};

class Motor : public Kendaraan
{
public:
    std::string model;
    void suara()
    {
        std::cout << "motor suara" << std::endl;
    }
};

class Hewan
{
public:
    virtual void suara()
    {
        std::cout << "hewan suara" << std::endl;
    }
};

class Anjing : public Hewan
{
public:
    void suara() override
    {
        std::cout << "anjing suara" << std::endl;
    }
};

class Kucing : public Hewan
{
public:
    void suara() override
    {
        std::cout << "kucing suara" << std::endl;
    }
};

template <typename T>
T print(T t)
{
    return t * t;
}

template <class Y>
class X
{
public:
    Y display(Y y)
    {
        return y * *y;
    }
};

class Kompleks {
 public:
    int real;
    int imag;

    Kompleks(int r, int i) : real(r), imag(i) {}

    Kompleks operator + (const Kompleks& right_hand_side){
        return Kompleks(real + right_hand_side.real, imag + right_hand_side.imag);
    }
   
};

int main()
{
    Motor motor1;
    motor1.merk = "honda";
    motor1.model = "kawasaki";
    motor1.suara();
    motor1.Kendaraan::suara();

    Hewan *hewan = new Anjing();
    hewan->suara();
    Hewan *hewan2 = new Kucing();
    hewan2->suara();

    Kompleks k1(2, 3);
    Kompleks k2(4, 5);
    Kompleks k3 = k1 + k2;
    std::cout << k3.real << " " << k3.imag << std::endl;

    std::cout << print(90) << std::endl;
    long long x = 1, y = 0, z = 3;

    auto lambda = [x, &z]()
    {
        std::cout << x;
        std::cout << z << std::endl;
    };

    z = 5;
    lambda();
    std::vector<long long> numbers = {x, y, z};
    std::for_each(numbers.begin(), numbers.end(), [](int x)
                  { std::cout << x << std::endl; });
    return 0;
}
