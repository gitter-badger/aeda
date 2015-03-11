#pragma once

#include <iostream>
#include <string>

class record_t
{
private:
	std::string dni_;
	std::string apellidos_;
	std::string nombre_;
	std::string fecha_nacimiento_;
public:
	record_t(void);
	virtual ~record_t(void);
	std::istream& read(std::istream& is);
	std::ostream& write(std::ostream& os) const;
	std::string get_dni(void);
	std::string get_apellidos(void);
	std::string get_nombre(void);
	std::string get_fecha_nacimiento(void);
};

std::string record_t::get_dni(void){return dni_;}
std::string record_t::get_apellidos(void){return apellidos_;}
std::string record_t::get_nombre(void){return nombre_;}
std::string record_t::get_fecha_nacimiento(void){return fecha_nacimiento_;}