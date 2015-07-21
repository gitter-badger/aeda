#include "clave_record.hpp"

class clave_record_fecha_nacimiento_t:public clave_record_t
{
public:
	clave_record_fecha_nacimiento_t(record_t* r);
	virtual ~clave_record_fecha_nacimiento_t(void);
	virtual void generate_clave(void);
};