#include <exception>

class acceso_prohibido_t: public exception
{
	virtual const char* what() const throw(){
		return "Acceso fuera de rango";
	}
};

class vector_no_inicializado_t: public exception
{
	virtual const char * what() const throw(){
		return "Vector no inicializado";
	}
};

acceso_prohibido_t acceso_prohibido;
vector_no_inicializado_t vector_no_inicializado;

//......

double& vector_t::operator[](int i)
{
	try{
		return get_val(i);
	}
	catch(exception& c)
	{
		cout << c.what() << endl;
		return get_val(0);
	}
}

double& vector_t::get_val(int i)
{
	if((i>=0)&&(i<n))
		return base_[i];
	else
		throw acceso_prohibido;
}