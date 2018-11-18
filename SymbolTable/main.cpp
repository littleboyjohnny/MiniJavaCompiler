class A {
public:
    virtual int get() = 0;
    virtual int set() = 0;
};

class B : public A {
private:
    int get();
};

int main()
{
    B b;
    main();
}

int foo()
{
    main();
}