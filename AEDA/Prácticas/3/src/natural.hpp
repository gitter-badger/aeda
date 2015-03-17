/** \file natural.hpp
  * \version 1.0
  * \date 17/03/2015
  * \author Daniel Ramos Acosta
  * \brief Header que contiene una clase que se usa para representar el tipo de número natural.
  * \code
  * //Código de ejemplo
  * <iostream>
  * 
  * int main(void){
        natural test1(9);
        natural test2(8);
        natural test3 = test1 + test2;
        std::cout << test3 << std::endl;
    }
  * \endcode
*/

#ifndef _NATURAL_HPP_
#define _NATURAL_HPP_

#include <iostream>

#include "number.hpp"
#include "exceptions.hpp"
//#include "debug.hpp"

/** Constante que guarda el valor mínimo, por el tipo de dato interno que se usa*/
#define NAT_MIN_VAL 0
/** Constante que guarda el valor máximo, por el tipo de dato interno que se usa*/
#define NAT_MAX_VAL 4294967295

namespace dra{
    /** Tipo interno usado por la clase dra::natural*/
	typedef long unsigned int natural_t;
    /** \brief Clase que se usa para representar el tipo de número natural.*/
	class natural;
}

class dra::natural: public dra::number{
    /**
        \class dra::natural
        \details
        Esta clase proporciona una interfaz para usar un número natural, de modo que lanza excepciones si se generan números que no son naturales, divisones por cero, etc. Internamente se usa un long unsigned int para guardar el número.
    */
private:
    dra::natural_t number_;
public:
    /** @name Constructores*/
    ///@{
    /** \brief Constructor por defecto */
    natural(void);
    /** \brief Constructor desde long long int*/
    natural(long long int);
    /** \brief Constructor de copia*/
    natural(const natural&);
    /** \brief Operador de asignación*/
    natural& operator=(const natural&);
    /** \brief Destructor*/
    ~natural(void);
    //@}

    /** @name Operadores aritméticos*/
    ///@{
    /** \brief Operador de suma*/
    dra::natural operator+(const dra::natural& nat) const;
    /** \brief Operador de resta*/
    dra::natural operator-(const dra::natural& nat) const;
    /** \brief Operador de multiplicación*/
    dra::natural operator*(const dra::natural& nat) const;
    /** \brief Operador de división*/
    dra::natural operator/(const dra::natural& nat) const;
    /** \brief Operador de módulo*/
    dra::natural operator%(const dra::natural& nat) const;
    //@}

    /** @name Operadores de incremento y decremento*/
    ///@{
    /** \brief Operador de incremento*/
    void operator++(int);
    /** \brief Operador de decremento*/
    void operator--(int);
    //@}

    /** @name Operadores de asignación compuestos*/
    ///@{
    /** \brief Operador de suma compuesto*/
    dra::natural operator+=(const dra::natural& nat);
    /** \brief Operador de resta compuesto*/
    dra::natural operator-=(const dra::natural& nat);
    /** \brief Operador de multiplicación compuesto*/
    dra::natural operator*=(const dra::natural& nat);
    /** \brief Operador de división compuesto*/
    dra::natural operator/=(const dra::natural& nat);
    /** \brief Operador de módulo compuesto*/
    dra::natural operator%=(const dra::natural& nat);
    //@}

    /** @name Operadores relacionales*/
    ///@{
    /** \brief Operador de igualdad*/
    bool operator==(const dra::natural& nat) const;
    /** \brief Operador de desigualdad*/
	bool operator!=(const dra::natural& nat) const;
    /** \brief Operador menor que*/
	bool operator<(const dra::natural& nat) const;
    /** \brief Operador mayor que*/
	bool operator>(const dra::natural& nat) const;
    /** \brief Operador menor o igual que*/
	bool operator<=(const dra::natural& nat) const;
    /** \brief Operador mayor o igual que*/
	bool operator>=(const dra::natural& nat) const;
    //@}

    /** @name Conversión de tipo*/
    ///@{
    /** \brief Conversión hacia el tipo natural_t*/
	explicit operator dra::natural_t();
    //@}

    /** @name Entrada/Salida*/
    ///@{
    /** \brief Inyección al stream de salida*/
    std::ostream& toStream(std::ostream& os) const;
    /** \brief Inyección al stream de entrada*/
    std::istream& fromStream(std::istream& is);
    //@}
};

//==============================================================================
//====================================== Constructores, destructores y operador=
//==============================================================================
dra::natural::natural(void):
number_(0)
{
    /**
        \details
        Por defecto, un objeto tipo natural vale 0
    */
}

dra::natural::natural(long long int num):
number_(0)
{
    /**
        \details
        En este constructor, se asigna el valor pasado por parámetro
        \param num Valor que tomará el natural
    */
    if(num < NAT_MIN_VAL)
        throw exception::underflow_error("Can't handle negative naturals");
    if(num > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL'");
    number_ = num;
}

dra::natural::natural(const natural& nat)
{
    /**
        \details
        Iguala el number_ interno de cada uno. No hace falta este método, ya que el del sistema hace lo mismo (iguala los atributos).
        \param nat Número natural al que se va a igualar
    */
    number_ = nat.number_;
}

dra::natural& dra::natural::operator=(const natural& nat)
{
    /**
        \details
        Simplemente iguala el number_ interno de cada uno. No hace falta este método, ya que el del sistema hace lo mismo (iguala los atributos).
        \param nat Número natural al que se va a igualar
    */
    number_ = nat.number_;
}

dra::natural::~natural(void)
{}

//==============================================================================
//======================================================= Operadores artiméticos
//==============================================================================
dra::natural dra::natural::operator+(const dra::natural& nat) const
{
    /**
        \details
        Método que realiza la operación suma
        \param nat Segundo miembro de la suma
        \return El resultado de la suma entre *this y nat.
    */
    if((number_ + nat.number_) > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL' in operator '+'");
    return number_ + nat.number_;
}

dra::natural dra::natural::operator-(const dra::natural& nat) const
{
    /**
        \details
        Método que realiza la operación resta
        \param nat Segundo miembro de la resta
        \return El resultado de la resta entre *this y nat.
    */
    if((number_ - nat.number_) < NAT_MIN_VAL)
        throw exception::underflow_error("Can't handle negative naturals in operator '-'");
    return number_ - nat.number_;
}

dra::natural dra::natural::operator*(const dra::natural& nat) const
{
    /**
        \details
        Método que realiza la operación multiplicación
        \param nat Segundo miembro de la multiplicación
        \return El resultado de la multiplicación entre *this y nat.
    */
    if((number_ * nat.number_) > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL' in operator '*'");
    return number_ * nat.number_;
}

dra::natural dra::natural::operator/(const dra::natural& nat) const
{
    /**
        \details
        Método que realiza la operación división
        \param nat Segundo miembro de la división
        \return El resultado de la división entre *this y nat.
    */
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '/'");
    return number_ / nat.number_;
}

dra::natural dra::natural::operator%(const dra::natural& nat) const
{
    /**
        \details
        Método que realiza la operación módulo
        \param nat Segundo miembro del módulo
        \return El resultado del módulo entre *this y nat.
    */
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '%'");
    return number_ % nat.number_;
}

//==============================================================================
//======================================== Operadores de incremento y decremento
//==============================================================================
void dra::natural::operator++(int)
{
    /**
        \details
        Método que realiza la operación incremento
        \return El resultado del incremento de *this.
    */
    if((number_ + 1) > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL' in operator '++'");
    number_++;
}

void dra::natural::operator--(int)
{
    /**
        \details
        Método que realiza la operación decremento
        \return El resultado del decremento de *this.
    */
    if((number_ -1) < NAT_MIN_VAL)
        throw exception::underflow_error("Can't handle negative naturals in operator '--'");
    number_--;
}
//==============================================================================
//========================================== Operadores de asignación compuestos
//==============================================================================
dra::natural dra::natural::operator+=(const dra::natural& nat)
{
    /**
        \details
        Método que realiza la operación suma compuesta
        \param nat Segundo miembro de la suma
        \return El resultado de la suma entre *this y nat, aparte *this será igual a la suma final.
    */
    if((number_ + nat.number_) > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL' in operator '+='");
    return number_ += nat.number_;
}

dra::natural dra::natural::operator-=(const dra::natural& nat)
{
    /**
        \details
        Método que realiza la operación resta compuesta
        \param nat Segundo miembro de la resta
        \return El resultado de la resta entre *this y nat, aparte *this será igual a la resta final.
    */
    if((number_ - nat.number_) < NAT_MIN_VAL)
        throw exception::underflow_error("Can't handle negative naturals in operator '-='");
    return number_ -= nat.number_;
}

dra::natural dra::natural::operator*=(const dra::natural& nat)
{
    /**
        \details
        Método que realiza la operación multiplicación compuesta
        \param nat Segundo miembro de la multiplicación
        \return El resultado de la multiplicación entre *this y nat, aparte *this será igual a la multiplicación final.
    */
    if((number_ * nat.number_) > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL' in operator '*='");
    return number_ *= nat.number_;
}

dra::natural dra::natural::operator/=(const dra::natural& nat)
{
    /**
        \details
        Método que realiza la operación división compuesta
        \param nat Segundo miembro de la división
        \return El resultado de la división entre *this y nat, aparte *this será igual a la división final.
    */
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '/='");
    return number_ /= nat.number_;
}

dra::natural dra::natural::operator%=(const dra::natural& nat)
{
    /**
        \details
        Método que realiza la operación módulo compuesta
        \param nat Segundo miembro del módulo
        \return El resultado del módulo entre *this y nat, aparte *this será igual al módulo final.
    */
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '%='");
    return number_ %= nat.number_;
}

//==============================================================================
//====================================================== Operadores relacionales
//==============================================================================
bool dra::natural::operator==(const dra::natural& nat) const
{
    /**
        \details
        Método que realiza la comparación de igualdad entre *this y nat
        \param nat Segundo miembro de la comparación
        \return Devuelve 1 si *this y nat son iguales.
    */
    return number_ == nat.number_;
}

bool dra::natural::operator!=(const dra::natural& nat) const
{
    /**
        \details
        Método que realiza la comparación de desigualdad entre *this y nat
        \param nat Segundo miembro de la comparación
        \return Devuelve 1 si *this y nat son distintos.
    */
    return number_ != nat.number_;
}

bool dra::natural::operator<(const dra::natural& nat) const
{
    /**
        \details
        Método que realiza la comparación si *this es menor que nat
        \param nat Segundo miembro de la comparación
        \return Devuelve 1 si *this es menor que nat.
    */
    return number_ < nat.number_;
}

bool dra::natural::operator>(const dra::natural& nat) const
{
    /**
        \details
        Método que realiza la comparación si *this es mayor que nat
        \param nat Segundo miembro de la comparación
        \return Devuelve 1 si *this es mayor que nat.
    */
    return number_ > nat.number_;
}

bool dra::natural::operator<=(const dra::natural& nat) const
{
    /**
        \details
        Método que realiza la comparación si *this es menor o igualque nat
        \param nat Segundo miembro de la comparación
        \return Devuelve 1 si *this es menor o igual que nat.
    */
    return number_ <= nat.number_;
}

bool dra::natural::operator>=(const dra::natural& nat) const
{
    /**
        \details
        Método que realiza la comparación si *this es mayor o igualque nat
        \param nat Segundo miembro de la comparación
        \return Devuelve 1 si *this es mayor o igual que nat.
    */
    return number_ >= nat.number_;
}

//==============================================================================
//=========================================================== Conversión de tipo
//==============================================================================
dra::natural::operator dra::natural_t()
{
    /**
        \details
        Convierte la clase dra::natural_t
        \return Devuelve *this convertido a dra::natural_t
        \see dra::natural_t
    */
    return number_;
}

//==============================================================================
//========================================================================== E/S
//==============================================================================
std::ostream& dra::natural::toStream(std::ostream& os) const
{
    /**
        \details
        Vuelca el número en el stream de salida
        \param os Stream de salida
        \return Devuelve el stream de salida
    */
    os << number_;
    return os;
}

std::istream& dra::natural::fromStream(std::istream& is)
{
    /**
        \details
        Vuelca el stream de entrada en la clase.
        \param is Stream de entrada
        \return Devuelve el stream de entrada
    */
    is >> number_;
    return is;
}

std::ostream& operator<<(std::ostream& os, dra::natural nat)
{
    /**
        \details
        Sobrecarca del operador << para la inyección de la clase en el stream de salida.
        \param os Stream de salida
        \param nat Objeto que se vuelca en el stream de salida
        \return Devuelve el stream de salida
    */
    nat.toStream(os);
    return os;
}

std::istream& operator>>(std::istream& is, dra::natural nat)
{
    /**
        \details
        Sobrecarca del operador >> para la inyección en la clase desde el stream de entrada
        \param is Stream de entrada
        \param nat Objeto en la que se vuelca el stream de entrada
        \return Devuelve el stream de entrada
    */
    nat.fromStream(is);
    return is;
}

#endif