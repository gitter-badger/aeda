#ifndef DNI
#define DNI


namespace dra
{

class dni{
private:
    unsigned long int dni_;
public:
    dni(void);
    dni(unsigned long int dni);
    ~dni(void);

    unsigned long int& value(void);
    unsigned long int value(void) const;
};

}


#endif // DNI

